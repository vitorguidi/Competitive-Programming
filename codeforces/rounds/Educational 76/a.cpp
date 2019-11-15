#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin >> t;
  while(t--){
    int n,x,a,b;
    cin >> n >> x >> a >> b;
    if(a>b) swap(a,b);
    int gol = min(x,a-1);
    x-=gol;
    int gor = min(x,n-b);
    int xl = a -gol;
    int xr = b + gor;
    cout << xr - xl << endl;

  }
}
