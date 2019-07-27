#include <iostream>
#include <string>
#include <vector>

using namespace std;

void encrypt(string &s, int n) {
    int mod, max, l;
    for(char &c : s) {
        int d = static_cast<int>(c);
        bool f = true;

        if (d >= 65 && d <= 90) {
            mod = 65;
            max = 90;
            l = 26;
        }
        else if (d >= 97 && d <= 122) {
            mod = 97;
            max = 122;
            l = 26;
        }
        else if (d >= 48 && d <= 57) {
            mod = 48;
            max = 57;
            l = 10;
        }
        else f = false;

        if (f) {
            if (d+n > max) {
                int i = (d+n-max) % l;
                if (i > 0) d = mod + ((d+n-max) % l) - 1;
                else d = max;
            } 
            else if (d+n < mod) {
                int x = (mod - (d+n));
                if (x > l) x = x % l;
                d = max - x + 1;
            }
            else d = d+n;
            c = static_cast<char>(d);
        }
    }
}

int main(int argc, const char** argv) {
    string s;
    int n;
    getline(cin, s);
    cin >> n;
    encrypt(s, n);
    cout << s << endl;
}

//2017IMT_069

// #include <iostream>

// using namespace std;

// int main() {
//   char s[100001];
//   int k, i;
//   cin >> s;
//   cin >> k;
//   for (i = 0; s[i] != '\0'; i++) {
//     if (s[i] > 47 && s[i] < 58) //|| s[i]>64 && s[i]<91 || s[i]>96 && s[i]<123)
//       s[i] = (s[i] - 48 + k) % 10 + 48;
//     else if (s[i] > 64 && s[i] < 91) {
//       s[i] = (s[i] - 65 + k) % 26 + 65;
//     } else if (s[i] > 96 && s[i] < 123)
//       s[i] = (s[i] - 97 + k) % 26 + 97;

//   }
//   cout << s;
//   return 0;
// }