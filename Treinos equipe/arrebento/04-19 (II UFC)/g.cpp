#include <bits/stdc++.h>
using namespace std;

int main(){

    int na=0,nb=0;
    string cap;
    
    cin >> cap;
    int s = cap.size();
    
    if(s%2 == 1 || cap[0]=='B' || cap[s-1]=='A'){
        cout << "Nao" << endl;
        return 0;
    }
    
    for(int i=0;i<s;i++){
        if(cap[i]=='A') na++;
        else    nb++;
    }  
    
    if(na==nb)  cout << "Sim" << endl;
    else        cout << "Nao" << endl;
   
    return 0;   
    
}


