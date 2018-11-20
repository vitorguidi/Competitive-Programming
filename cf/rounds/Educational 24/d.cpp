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

	int n,a; cin >> n >> a;
	vi v(n);

	set<pii>freq;
	map<int,int> id;
	set<int> colors;

	fr(i,n){
		cin >> v[i];
		if(v[i]!=a)	colors.insert(v[i]);
		freq.insert({0,v[i]});
	}

	fr(i,n){

		int cara = v[i];

		freq.erase({id[cara],cara});
		id[cara]++;
		freq.insert({id[cara],cara});
		
		if(cara==a){

			while(!freq.empty()){
			
				pii lol = *freq.begin();
				int atual = lol.snd;
			
				if(id[atual]<id[a]){
					colors.erase(atual);
					freq.erase(freq.begin());
				}
				else
					break;

			}
		}

	}

	if(colors.empty())
		cout << -1 << endl;
	else
		cout << *colors.begin() << endl;

}

