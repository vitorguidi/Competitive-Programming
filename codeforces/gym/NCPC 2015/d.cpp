#include <bits/stdc++.h>
using namespace std;

int acum[101000];

int main(){

    int n,k;
    cin >> n >> k;

    for(int i=0;i<n;i++){
        int x; cin >> x;
        acum[x]++;
    }

    int aux = 0;
    int best = 0;

    for(int i=0;i<=100000;i++){
        int tmp = 0;
        for(int j=0;j<1000;j++)
            tmp+=acum[i+j];
        best=max(best,(tmp+k-1)/k);
    }

    cout << best << endl;

}