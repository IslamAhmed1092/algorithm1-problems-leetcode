#include <bits/stdc++.h>
using namespace std;

string CodelandUsernameValidation(string str) {
    // code goes here
    int n = str.size();
    if(n < 4 || n > 25)
        return "false";
        
    regex reg("^[A-Za-z][A-Za-z0-9_]*[A-Za-z0-9]$");
    if(regex_match(str, reg)) {
        return "true";
    } else {
        return "false";
    }
    
    // if(!((str[0] >= 'A' && str[0] <= 'Z') 
    //         || (str[0] >= 'a' && str[0] <= 'z'))) {
    //     return "false";
    // }

    // if(str[n-1] == '_') {
    //     return "false";
    // }

    // for(int i = 1; i < n-1; i++) {
    //     if(
    //         !(
    //         (str[i] >= 'A' && str[i] <= 'Z') || 
    //         (str[i] >= 'a' && str[i] <= 'z') ||
    //         (str[i] == '_') ||
    //         (str[i] >= '0' && str[i] <= '9')
    //         )
    //     ) {
    //     return "false";
    //     }
    // }

    // return "true";
}


int main() {
    
    string str;
    cin>>str;
    cout<<CodelandUsernameValidation(str);
    return 0;
}