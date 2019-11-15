#include <bits/stdc++.h>
using namespace std;

int freq[200200];
int antes[200200];
int table[200200];

void go(){
  int n; cin >> n;
  vector<int> v(n);

  memset(antes,-1,sizeof antes);
  memset(table,-1,sizeof table);
  memset(freq,0,sizeof freq);
  
  for(int i=0;i<n;i++){
    cin >> v[i];
    antes[i] = table[v[i]];
    table[v[i]]=i;
  }
  int best = 0x3f3f3f3f;
  int ini=0;
  for(int i=0;i<n;i++){
    if(antes[i]==-1) continue;
    best=min(best,i-antes[i]+1);
  }
  cout << (best==0x3f3f3f3f ? -1 : best) << endl;
}

int main() {

  int t; cin >> t;
  while(t--)  go();

}
