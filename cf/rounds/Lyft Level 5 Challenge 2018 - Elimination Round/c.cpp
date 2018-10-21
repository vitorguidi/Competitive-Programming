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

int v[100100],w[100100];
int op[100100];
int n; 

bool valid(int x){
	return x>=1 && x<=n;
}

int main(){
    
	fastio;

	cin >> n;

	frr(i,n){
		int x; cin >> x;
		v[x]=i;		//guarda a celula que numero x ocupa
		w[i]=x;		//guarda o numero que a celula i contem
	}

	for(int i=n;i>0;i--){			//i = numero atual
		for(int j=1;j<=n/i;j++){	//j*i = multiplos

			int a = v[i]+i*j;	//brutando todas as celulas que posso chegar
			int b = v[i]-i*j;	

			if(a>=1 && a<=n && w[a]>i && op[w[a]]==0)
				op[i]=1;
			
			if(b>=1 && b<=n && w[b]>i && op[w[b]]==0)
				op[i]=1;

		}

	}

	string ans;

	for(int i =1;i<=n;i++){
		if(op[w[i]])
			ans.pb('A');
		else
			ans.pb('B');
	}

	cout << ans << endl;


}

