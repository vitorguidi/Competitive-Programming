#include <bits/stdc++.h>
using namespace std;

vector<int> monstro;
vector<int> heroes;
int n,m;

void go() {
  
  monstro.clear();

  int n;
  cin >> n;
  
  for(int i=0;i<n;i++){
    int x; cin >> x;
    monstro.push_back(x);
  }  
  
  int m;
  cin >> m;
  heroes.clear();
  heroes.resize(n+1);
  
  for(int i=0;i<m;i++){
    int p,s;
    cin >> p >> s;
    heroes[s]=max(heroes[s],p);
  }

  for(int i=n-1;i>=0;i--)
    heroes[i]=max(heroes[i],heroes[i+1]);

  int ini = 0;
  int cnt = 0;

  while(ini<n){
    cnt++;
    int best = 0;
    int acum = 0;
    for(int amt=1;amt+ini-1<n;amt++){
      acum=max(acum,monstro[ini+amt-1]);
      if(heroes[amt]>=acum){
	best=amt;
      }
      else
	break;
    }
    if(best==0)	break;
    ini+=best;
  }
  
  cout << (ini==n ? cnt : -1) << endl;
}

int main() {
  int t; cin >> t;
  while(t--) go();
}
