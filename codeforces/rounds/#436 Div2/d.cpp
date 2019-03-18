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

int freq[200200];
int v[200200];
int taken[200200];

int main(){
    
	fastio;

	int n; cin >> n;
	int cnt =0 ;
	frr(i,n){
		cin >> v[i];
		freq[v[i]]++;
		if(freq[v[i]]>1)	cnt++;
	}

	vi falta;

	frr(i,n)
		if(!freq[i])	falta.pb(i);

	int ini=0;

	sort(all(falta));

	frr(i,n){

		if(freq[ v[i] ]==1)	continue;

		if(falta[ini]<v[i] || taken[v[i]]){
			freq[v[i]]--;
			v[i]=falta[ini++];
		}
		else	taken[v[i]]=1;

	}
	cout << cnt << endl;
	frr(i,n)	cout << v[i] << " ";
	gnl;

}