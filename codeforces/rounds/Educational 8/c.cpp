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

int main(){
    
	fastio;

	int len,k; cin >> len >> k;

	string s; cin >> s;

	string ori = s;

	int sum = 0;

	fr(i,len)
		sum+=max(abs('z'-s[i]),s[i]-'a');

	if(k>sum){
		cout << -1 << endl;
		return 0;
	}

	fr(i,len){
		if(!k)	break;
		bool desce = false;
		bool sobe = true;
		if(s[i]-'a'>='z'-s[i])	desce=true;
		else					sobe=true;
		if(desce){
			int delta = min(k,s[i]-'a');
			k-=delta;
			s[i]-=delta;
		}
		else{
			int delta = 'z'-s[i];
			delta=min(delta,k);
			k-=delta;
			s[i]+=delta;
		}
	}

	cout << s << endl;

}

