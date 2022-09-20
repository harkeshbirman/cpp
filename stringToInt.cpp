#include<bits/stdc++.h>
using namespace std;

int converter(string s){  // recursive approach for creating stoi() function
    static int ans = 0;
    if(!s[0]){  // to break recursive loop
        int t = ans;
        ans = 0;
        return t;
    }
    else if(s[0] < 48 || s[0] > 57){ // to check validity of every character
        ans = 0;
        return -1;
    }
    else{ // for real conversion
        int num = s[0] - '0';
        ans = (ans * 10) + num;
        return converter(s.substr(1));
    }
}


int myAtoi(string s) {
    int i = 0;
    while(s[i] == ' '){  // to ignore forward spaces
        i++;
    }
    if((s[i] < 48 && s[i] != '-')|| s[i] > 57){   // to check validity of the string for conversion
        return -1;
    }
    if(s[i] == '-'){
        int t = converter(s.substr(i + 1));
        return t == -1 ? -1 : -1 * t;
    }
    return converter(s);
}

int main(){
    string s;
    getline(cin, s);
    int t = myAtoi(s);
    cout << t;
    
    return 0;
}
