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
#define olar cout << "olar" << endl
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int v[110][110];
int used[110][110];

int main(){
    
	fastio;

	int n,k; cin >> n >> k;

	if(n*n<k){
		cout << -1 << endl;
		return 0;
	}

	
	fr(i,n){
		fr(j,n){

			if(!k)	break;
			if(used[i][j])	continue;

			if(i==j){
				v[i][j]=1;
				used[i][j]=1;
				k--;
				continue;
			}

			if(k>1){
				v[i][j]=v[j][i]=1;
				used[i][j]=used[j][i]=1;
				k-=2;
				continue;
			}

			if(k==1){
				for(int l=0;l<n;l++){
					if(used[l])	continue;
					if(!k)	break;
					used[l][l]=1;
					k--;
					v[l][l]=1;
				}
			}

		}
	}

	fr(i,n){
		fr(j,n){
			cout << v[i][j] << " ";
		}
		gnl;
	}

}

