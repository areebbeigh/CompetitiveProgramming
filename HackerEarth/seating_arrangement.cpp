#include <iostream>

using namespace std;

int main() {
  int test, n, m, o;
  cin >> test;
  while (test--) {
    cin >> n;
    o = n / 12;
    if (n % 12 != 0) {
      m = 13 - n % 12;
      if (m == 1 || m == 12 || m == 6 || m == 7) {
        cout << m + 12 * o << " WS" << endl;
      }
      if (m == 11 || m == 2 || m == 5 || m == 8) {
        cout << m + 12 * o << " MS" << endl;
      }
      if (m == 3 || m == 10 || m == 4 || m == 9) {
        cout << m + 12 * o << " AS" << endl;
      }
    } else {
      cout << n - 11 << " WS" << endl;
    }
  }
  return 0;
}