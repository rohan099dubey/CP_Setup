#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
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

pair<double, double> circumcenter(pair<double, double> A,
                                  pair<double, double> B,
                                  pair<double, double> C) {
  double x1 = A.first, y1 = A.second;
  double x2 = B.first, y2 = B.second;
  double x3 = C.first, y3 = C.second;

  double D = 2 * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));

  double x =
      ((x1 * x1 + y1 * y1) * (y2 - y3) + (x2 * x2 + y2 * y2) * (y3 - y1) +
       (x3 * x3 + y3 * y3) * (y1 - y2)) /
      D;

  double y =
      ((x1 * x1 + y1 * y1) * (x3 - x2) + (x2 * x2 + y2 * y2) * (x1 - x3) +
       (x3 * x3 + y3 * y3) * (x2 - x1)) /
      D;

  return {x, y};
}

double distBtwPnts(pair<double, double> A, pair<double, double> B) {
  double dx = A.first - B.first;
  double dy = A.second - B.second;

  return sqrt(dx * dx + dy * dy);
}

void solve() {
  /*
    Think inside the box :
    cout << <<'\n';
 */

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 0;

  if (cin >> t)
    while (t > 0) {
      solve();
      t--;
    }

  // solve();

  return 0;
}