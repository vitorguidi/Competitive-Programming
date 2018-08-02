#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, pot = 1, c = 0;
    cin >> n;
    while(pot <= n){
        pot = pot*2;
        c++;
    }
    cout << c << endl; 
}
