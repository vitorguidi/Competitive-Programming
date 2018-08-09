#include <bits/stdc++.h>
using namespace std;

int dims[100000], foot[100001], chain[100001];
long long int distf, distc;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> dims[i];
    }
    for(int i = 0; i < n; i++){
        cin >> foot[i];
        distf = distf + (dims[i] - foot[i])*(dims[i] - foot[i]);
    }
    for(int i = 0; i < n; i++){
        cin >> chain[i];
        distc = distc + (dims[i] - chain[i])*(dims[i] - chain[i]);
    }
    if(distf <= distc) cout << "Yan" << endl;
    else cout << "MaratonIME" << endl;
}
