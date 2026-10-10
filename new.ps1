param([Parameter(Mandatory)][string]$Contest, [Parameter(Mandatory)][string]$Problem)
# Usage: .\new.ps1 2050 A   -> codeforces\contests\2050\A\{main.cpp,input.txt,output.txt}
$dir = Join-Path $PSScriptRoot "codeforces\contests\$Contest\$Problem"
New-Item -ItemType Directory $dir -Force | Out-Null
if (-not (Test-Path "$dir\main.cpp")) { Copy-Item "$PSScriptRoot\codeforces\templates\main.cpp" "$dir\main.cpp" }
foreach ($f in 'input.txt','output.txt') { if (-not (Test-Path "$dir\$f")) { New-Item "$dir\$f" | Out-Null } }
code "$dir\main.cpp"
