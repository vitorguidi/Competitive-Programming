#include <bits/stdc++.h>
using namespace std;

int coins, mx;

int main(){
    int n, m;
    cin >> n >> m;
    string s[1000];
    for(int i = 0; i < n; i++){
        cin >> s[i];
        for(int j = 0; j < m; j++){
            if(i%2 == 0){
                if(s[i][j] == '.') coins++;
                else if(s[i][j] == 'L'){
                    mx = max(coins, mx);
                    coins = 0;
                }
            }
            else{
                if(s[i][m-j-1] == '.') coins++;
                else if(s[i][m-j-1] == 'L'){
                    mx = max(coins, mx);
                    coins = 0;
                }
            }
        }
    }
    mx = max(coins, mx);
    cout << mx << endl;
}
