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

int v[300300];
int acum[300300];
int n,k;

bool check(int amt){

	for(int i=1;i<=n-k+1;i++){
		int quantos = acum[i+amt-1]-acum[i-1];
		int quero = amt;
		if(quero-quantos<=k)
			return true;
	}

	return false;

}

int main(){
    
	fastio;

	cin >> n >> k;

	frr(i,n){
		cin >> v[i];
		acum[i]+=acum[i-1]+v[i];
	}

	int ini=1;
	int end=n;

	int best=0;

	while(ini<=end){

		int mid = (ini+end)/2;

		if(check(mid)){
			best=max(best,mid);
			ini=mid+1;
		}
		else
			end=mid-1;

	}

	cout << best << endl;

	for(int i=1;i<=n-best+1;i++){
		
		int tem = acum[i+best-1]-acum[i-1];
		
		if(tem+k>=best){
			for(int j=i;j<=i+best-1;j++)
				v[j]=1;
			break;
		}

	}

	for(int i=1;i<=n;i++)
		cout << v[i] << " ";
	gnl;

}

