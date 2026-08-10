#include <iostream>
#include <string>

using namespace std;

string removeOuterParentheses(string s) {

    string ans;
    int temp = 0;

    for (int i = 0; i < s.size(); i++) {

        if (s[i] == '(') {

            if (temp > 0)
                ans += s[i];

            temp++;
        }

        else if (s[i] == ')') {

            temp--;

            if (temp > 0)
                ans += s[i];
        }
        else continue;
    }

    return ans;
}

int main() {

    string s;
    getline(cin,s);

    cout << removeOuterParentheses(s);

    return 0;
}
