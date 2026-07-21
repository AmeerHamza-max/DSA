#include <iostream>
#include <string>
using namespace std;

bool repeatedSubstringPattern(string s) {
    int n = s.length();

    // Try every possible substring length
    for (int len = 1; len <= n / 2; len++) {

        // Substring length must divide the string length
        if (n % len != 0)
            continue;

        // Take the first substring
        string sub = s.substr(0, len);

        string temp = "";

        // Repeat the substring
        for (int i = 0; i < n / len; i++) {
            temp += sub;
        }

        // Compare with original string
        if (temp == s)
            return true;
    }

    return false;
}

int main() {
    string s;
    cin >> s;

    if (repeatedSubstringPattern(s))
        cout << "true";
    else
        cout << "false";

    return 0;
}