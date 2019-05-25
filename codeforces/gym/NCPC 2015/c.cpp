#include <bits/stdc++.h>
using namespace std;

int main(){

    string s; cin >> s;

    string aux;
    int ini=0;

    for(int i=0;i<s.size();i++){

        if(i%3==0)
            aux+=("P");
        else if(i%3==1)
            aux+=("E");
        else
            aux+=("R");

    }

    int ans = 0;

    for(int i=0;i<s.size();i++)
        ans+= (s[i]!=aux[i]);

    cout << ans << endl;

}