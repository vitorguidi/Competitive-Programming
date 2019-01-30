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

int acuml[200200];
int acumr[200200];

int main(){
    
	fastio;

	int n; cin >> n;
	string s; cin >> s;


	int ini=0;
	int best = 0;
	int gold=0;

	vi v;

	while(ini<n){
		int cnt=0;
		while(s[ini]=='G' && ini<n){
			cnt++;
			ini++;
			gold++;
		}
		if(cnt){
			best=max(best,cnt);
			v.pb(cnt);
		}
		cnt=0;
		while(s[ini]=='S' && ini<n){
			cnt--;
			ini++;
		}
		if(cnt)	v.pb(cnt);
	}

	for(int i=0;i+2<v.size();i++){
		int cara1 = v[i];
		int link = v[i+1];
		int cara2 = v[i+2];
		int sobra = gold -cara1-cara2;
		if(sobra && link==-1)		best=max(best,cara1+cara2+1);
		if(!sobra & link==-1)		best=max(best,cara1+cara2);
		if(link!=-1)				best=max({best,cara1+1,cara2+1});
	}

	cout << best << endl;


}