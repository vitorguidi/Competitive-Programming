#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int mx=0,count=0, winner=0; 
    int aux;
    
    cin >> n;
   
    for(int i=0;i<n;i++){
        cin >> aux;
        if(mx<aux){
          mx=aux;
          winner=i;
          count = 1;
        }
        else if(mx == aux) count++;       
    }   
    
    if(count > 1) cout << "-1" << endl;
    else cout << winner+1 << endl;
    return 0;
}
