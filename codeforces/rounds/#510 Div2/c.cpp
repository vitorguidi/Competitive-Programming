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
#define pira cout << "pira" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int main(){
    
	fastio;
	int n; cin >> n;

	set<int> pos;
	set<int> neg;
	set<int> nill;

	int last_nill=INF;
	int id = -INF;
	int mn = -INF;
	vi aux;
	aux.pb(INF);
	frr(i,n){
		int x; cin >> x;
		aux.pb(x);
		if(!x)
			nill.insert(i);
		else if(x>0)
			pos.insert(i);
		else{
			if(x>mn){
				mn=x;
				id=i;
			}
			neg.insert(i); 
		}
	}

	if(nill.size()){
		auto it = nill.end();
		it--;
		int last = *it;
		nill.erase(it);
		last_nill=last;
		while(!nill.empty()){
			it = nill.end();
			it--;
			cout << 1 << " " << *it << " " << last_nill << endl;
			nill.erase(it);
		}
	}		

	int num_neg=neg.size();
	if(num_neg%2){
		auto it = neg.find(id);
		if(last_nill!=INF)
			cout << 1 << " " << *it << " " << last_nill << endl;
		else
			cout << 2 << " " << *it << endl;
		neg.erase(it);
	}


	int total = neg.size()+pos.size();

	if(last_nill!=INF && total>=1)
		cout << 2 << " " << last_nill << endl;
	
	set<int> last;
	while(!neg.empty()){
		auto it = neg.end();
		it--;
		last.insert(*it);
		neg.erase(it);
	}
	while(!pos.empty()){
		auto it = pos.end();
		it--;
		last.insert(*it);
		pos.erase(it);
	}

	if(last.empty())
		return 0;

	auto lol = last.end();
	lol--;
	auto base = *lol;
	last.erase(lol);
	while(!last.empty()){
		auto it = last.end();
		it--;
		int cara = *it;
		cout << 1 << " " << cara << " " << base << endl;
		last.erase(it);
	}

}

