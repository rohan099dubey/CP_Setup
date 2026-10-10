# CP — Competitive Programming Workspace

A minimal VS Code + C++ setup for solving Codeforces problems on Windows. One keypress
compiles the file you're looking at, feeds it `input.txt`, and writes `output.txt` next to it.
A small PowerShell script scaffolds each new problem from a template.

## Layout

```
CP/
├── new.ps1                         # scaffold a new problem folder
├── .vscode/
│   ├── tasks.json                  # "Compile & Run Current File" build task
│   ├── run.bat                     # the actual g++ compile + run-with-redirect
│   ├── settings.json               # compiler path for the C/C++ extension
│   └── c_cpp_properties.json       # IntelliSense config
├── .build/                         # compiled binaries (git-ignored)
└── codeforces/
    ├── templates/
    │   ├── main.cpp                # default starter (copied by new.ps1)
    │   ├── debug.cpp               # starter with debug() macros + timing
    │   └── stkr.cpp                # same macro header, kept as reference
    └── contests/
        └── <contest>/<problem>/    # e.g. 2050/A/
            ├── main.cpp
            ├── input.txt           # paste the sample input here
            └── output.txt          # written by the run task
```

## Requirements

- **Windows** with **PowerShell**
- **g++** on `PATH` — this setup was built against [MSYS2](https://www.msys2.org/) UCRT64
  (`C:\msys64\ucrt64\bin\g++.exe`). Install the toolchain with:
  ```
  pacman -S mingw-w64-ucrt-x86_64-gcc
  ```
  Then add `C:\msys64\ucrt64\bin` to your `PATH`.
- **VS Code** with the [C/C++ extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
- `code` on `PATH` (so `new.ps1` can open the file it creates)

If your compiler lives somewhere else, update `C_Cpp.default.compilerPath` in
[.vscode/settings.json](.vscode/settings.json) and the g++ path in
[.vscode/tasks.json](.vscode/tasks.json) (the debug build task). `run.bat` just calls
`g++` from `PATH`, so it needs no edit.

## Usage

### 1. Create a problem

From the repo root:

```powershell
.\new.ps1 2050 A
```

This creates `codeforces/contests/2050/A/` with `main.cpp` (copied from
`codeforces/templates/main.cpp`), empty `input.txt` and `output.txt`, and opens `main.cpp`
in VS Code. Re-running it on an existing problem is safe — it never overwrites files.

### 2. Paste the sample input

Put the problem's sample input into that folder's `input.txt`.

### 3. Compile and run

With `main.cpp` focused, press **`Ctrl` + `Shift` + `B`**. It:

1. compiles the current file with `g++ -std=c++17 -O2 -Wall -Wextra -Wshadow`
2. puts the binary at `.build/run.exe`
3. runs it with `input.txt` as stdin and `output.txt` as stdout

Compiler errors show up in the Problems panel. Open `output.txt` side by side with
`input.txt` to check your answer.

Because stdout is redirected, `cout` goes to the file while `cerr` still reaches the
terminal — which is why the debug template prints to `cerr`.

## Keyboard shortcuts

| Keys | Action |
| --- | --- |
| `Ctrl` + `Shift` + `B` | **Compile & run the current file** — this is the one you'll use all contest. It's VS Code's built-in *Run Build Task*, and the run task is marked `"isDefault": true`, so it fires with no picker. |
| `Ctrl` + `Shift` + `P` → `Tasks: Run Task` | Pick a task by name — use this for the `g++.exe build active file (debug)` task, which builds with `-g` for the debugger instead of running. |
| `F5` | Debug the current file (needs a `launch.json`; not included here). |

### Want a dedicated key instead of `Ctrl+Shift+B`

Add this to your user `keybindings.json` (**Ctrl+Shift+P** → *Preferences: Open Keyboard
Shortcuts (JSON)*). The `args` string must match the task's `label` in
[.vscode/tasks.json](.vscode/tasks.json) exactly, or VS Code silently falls back to
showing the task picker:

```json
{
  "key": "ctrl+shift+f9",
  "command": "workbench.action.tasks.runTask",
  "args": "Codeforces: Compile & Run Current File"
}
```

## Templates

| File | What it gives you |
| --- | --- |
| `main.cpp` | Fast I/O, multi-test `solve()` loop, modular `power`/`modInverse`, factorial precompute, a palindrome check |
| `debug.cpp` | `ll`/`all(x)`/`sz(x)` style macros, a variadic `debug(...)` printer that compiles away under `ONLINE_JUDGE`, and runtime printed to `cerr` |
| `stkr.cpp` | Same macro header as `debug.cpp`, kept as a reference solution |

`new.ps1` always copies `main.cpp`. To start from a different template, copy it by hand:

```powershell
Copy-Item codeforces\templates\debug.cpp codeforces\contests\2050\A\main.cpp
```

Using `debug(...)` is free on the judge: Codeforces defines `ONLINE_JUDGE`, so the macro
expands to nothing there and the `cerr` output never costs you anything.

### A note on `main.cpp`'s driver

The default `main()` reads a leading test count and loops:

```cpp
int t = 0;
if (cin >> t) { while (t > 0) { solve(); t--; } }
```

For a single-test problem with no leading `t`, call `solve()` directly instead (the
commented-out line above it).

## What's git-ignored

`.build/`, `*.exe`, `*.o` — see [.gitignore](.gitignore). Solutions, inputs and outputs
are committed, so the repo doubles as a record of what you've solved.

## Adapting it for another judge

Nothing in `run.bat` is Codeforces-specific; only the paths in `new.ps1` are. To add,
say, AtCoder, copy `new.ps1` and point `$dir` at `atcoder\contests\...`.
