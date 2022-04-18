#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    string result = "";
    string temp = "";
    for (char c : s) {
        if(c == ' ') {
            result += temp + " ";
            temp = "";
        } else {
            temp.insert(0, 1, c);
        }
    }

    result += temp;
    
    return result;
}

int main() {
    string s;
    getline(cin, s);
    
    string result = reverseWords(s);

    cout<<result<<endl;
    return 0;
}