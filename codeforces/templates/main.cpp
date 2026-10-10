#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
bool calc = true;

const int factoSize = 1000000;
vector<long long> fact(factoSize + 1);

long long power(long long base, long long exp) {
  long long res = 1;
  base %= mod;
  while (exp > 0) {
    if (exp % 2 == 1)
      res = (res * base) % mod;
    base = (base * base) % mod;
    exp /= 2;
  }
  return res;
}

long long modInverse(long long n) { return power(n, mod - 2); }

bool isPalindrome(const string &s, int left, int right) {
  while (left < right) {
    if (s[left++] != s[right--])
      return false;
  }
  return true;
}

void calcFact() {
  calc = false;
  fact[0] = 1;
  for (long long i = 1; i <= factoSize; i++) {
    fact[i] = (i * fact[i - 1]) % mod;
  }
}
int sumOfSqOfDig(int n) {
  int sum = 0;
  while (n > 0) {
    int dig = n % 10;
    n = n / 10;
    sum += (dig * dig);
  }
  return sum;
}
void solve() {
  int mod = 998244353;
  int n, m, r, c;
  cin >> n >> m >> r >> c;
  
  cout << 0 << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // solve();

  int t = 0;
  if (cin >> t) {
    while (t > 0) {
      solve();
      t--;
    }
  }
  return 0;
}