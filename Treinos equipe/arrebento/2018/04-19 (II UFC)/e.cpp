#include <bits/stdc++.h>
using namespace std;

int institutes[100001], somas[100001];

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> institutes[i];
        somas[i] = somas[i-1] + institutes[i]; 
    }
    for(int j = 0; j < m; j++){
        int a, b;
        cin >> a >> b;
        int s = somas[b] - somas[a-1];
        if(s%2 == 0) cout << "Sim" << endl;
        else cout << "Nao" << endl; 
    }
}
