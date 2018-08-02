#include <bits/stdc++.h>
using namespace std;

int dish[100001];

int main(){

    int n,t;
    int tn=0;
    int ty=0;
    int cy=0,cn=0;
    
    cin >> n >> t;
    int flag=1;
    
    for (int i=0;i<n;i++){
        cin >> dish[i];
        if(ty+dish[i]<=t && flag==1){
            cy++;
            ty+=dish[i];
        }
        else    flag=0;
        
    }
    
    for(int i=n-1;i>=0;i--){
        if(tn+dish[i]<=t){
            cn++;
            tn+=dish[i];
        }
        else    break;
    }

    
    if(cn>cy)   cout << "Nathan" << endl;
    else if(cn==cy) cout << "Empate" << endl;
    else            cout << "Yan" << endl;
    
    return 0;   
    
}
