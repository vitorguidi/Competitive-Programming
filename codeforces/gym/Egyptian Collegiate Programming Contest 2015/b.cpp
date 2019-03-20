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
#define all(x)	x.begin(),x.end()

#define gnl cout << endl
#define olar cout << "pira" << endl
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll; 

const int INF = 0x3f3f3f3f;

int v[110][4];int t; 

void go(){

	ms(v,-1);

	int m,q;
	cin >> q >> m;

	frr(i,m){

		frr(j,q){
			char x,a;
			cin >> x >> a;
			if(a=='T')	v[j][x-'A']=1;
			else		v[j][x-'A']=0;
		}

	}

	frr(i,q){

		bool flag = false;

		fr(j,4){
			if(v[i][j]==1){
				cout << char('A'+j);
				flag=true;
				break;
			}
		}

		if(flag && i!=q)	cout << " ";

		if(flag)	continue;

		int err = 0;
		fr(j,4)
			if(v[i][j]==0)	err++;

		if(err==3){
			fr(j,4){
				if(v[i][j]==-1){
					cout << char('A'+j);
					flag=true;
					break;
				}
			}
		}

		if(flag && i!=q)	cout << " ";
		if(flag)	continue;

		cout << "?";
		if(i!=q)	cout << " ";

	}

	if(t!=0)gnl;

}

int main(){

	fastio;

	cin >> t;
	while(t--)	go();
	
}