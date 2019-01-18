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
#define LAU cout << "LAW" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int v[110];

int main(){

	int t;
	cin >> t;

	while(t--){
		
		int n;
		cin >> n;
		
		ms(v,0);
		
		string s;
		getline(cin,s);
		getline(cin,s);
		
		frr(i,n){
			if(s[i-1]=='*'){
				v[i-1]=1;
				v[i+1]=1;
				v[i]=1;
			}
		}

		int cnt=0;
		
		frr(i,n){
			if(!v[i]){
				cnt++;
				v[i]=v[i+1]=v[i+2]=1;
			}
		}

		cout << cnt << endl;

	}



}