#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define pq priority_queue
#define grtp greater< pair<int,int> >

#define gnl cout << endl
#define olar cout << "olar" << endl
#define gottagofast ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int main(){

	int n,m,v[505][505];
	cin >> n >> m;
	fr(i,n){
		fr(j,m){
			cin >> v[i][j];
		}
	}
	fr(i,n){

		int ini=0;
		while(v[i][ini]==0 && ini+1<m)
			ini++;

		for(int j=i+1;j<n;j++){
			for(int k=0;k<=ini;k++){
				if(v[j][k]!=0){
					cout << "N" << endl;
					return 0;
				}
			}
		}
	}

	cout << "S" << endl;

}