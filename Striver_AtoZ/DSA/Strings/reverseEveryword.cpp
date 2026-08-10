#include<iostream>
#include<string>

using namespace std;

string reverseWords(string s) {

    string ans;
    string temp;

    int n = s.size();

    for (int i = n - 1; i >= 0; i--) {

        if (s[i] == ' ') {

            if (!temp.empty()) {
                reverse(temp.begin(), temp.end());
                ans += temp;
                ans += ' ';
                temp.clear();
            }
        }
        else {
            temp += s[i];
        }
    }

    // Process the first word
    if (!temp.empty()) {
        reverse(temp.begin(), temp.end());
        ans += temp;
    }

    return ans;
}

int main (){
    string s;
    getline(cin , s);
    cout<<reverseWords(s);
    return 0;
}
