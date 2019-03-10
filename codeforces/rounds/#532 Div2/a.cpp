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

int v[110];
int work[110];

int n,k;
int social;
int study;

bool valid(int x){
	return x>=1 && x<=n;
}

int go(int x){

	int t1=social;
	int t2 = study;

	for(int i=-100;i<=100;i++){
		int pos = x+k*i;
		if(!valid(pos))	continue;
		if(v[pos]==1)	t1--;
		else			t2--;
	}

	return abs(t1-t2);

}

int main(){
    
	fastio;
	cin >> n >> k;

	int ans = 0;

	frr(i,n){
		cin >> v[i];
		if(v[i]==1)	social++;
		else		study++;
	}

	frr(i,n)	ans=max(ans,go(i));

	cout << ans << endl;
	

}