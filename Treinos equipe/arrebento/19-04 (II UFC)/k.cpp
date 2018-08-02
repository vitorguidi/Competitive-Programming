#include <bits/stdc++.h>
using namespace std;

int main(){
    int c = 1;
    string s;
    cin >> s;
    int l = s.size();
    for(int i = 0; i < l; i++){
        if(s[i] == s[i+1]){
            c++;
        }
        else{
            cout << s[i] << c;
            c = 1;           
        }
    }
    cout << endl;
    
}
