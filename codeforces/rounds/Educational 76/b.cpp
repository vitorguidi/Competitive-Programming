#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin >> t;
  while(t--){
    long long int x,y;
    cin >> x >> y;
    int auxx = x;
    if(auxx%2 && auxx>1)  auxx--;
    while(auxx>0 && auxx%2==0 && auxx<y){
      auxx/=2;
      auxx*=3;
      if(auxx%2 && auxx>3) auxx--;
    }
    if(auxx>=y)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
