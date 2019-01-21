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
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

int main(){

	fastio;
	int n;
	cin >> n;
	set<int> s;
	set<int> t;
	int ans[110];
	set<int> f;


	if(n%2){
		int k =(n+1)/2;
		
		fr(i,k){
			if(i == 0){
				cout << "Q "<<1<< ' '<< k <<endl;
				cout.flush();
				fr(j,k){
					int a;
					cin >> a;
					s.insert(a);
				}
 			}
 			else{
 				cout << "Q " << 1 + i << ' '<< k + i << endl;
 				cout.flush();
 				fr(j,k){
 					int a;
 					cin >> a;
 					t.insert(a);
 				}
 			
 				for(auto it: s){
 					if(t.find(it) == t.end()){
 						ans[i] = it;
 						f.insert(it);
 	//					dbg(it);
 					}
 				}

 				for(auto it : t){
 					if(s.find(it) == s.end()){
 						ans[k+i] = it;
 						f.insert(it);
 	//					dbg(it);
 					}
 				}

 				s.clear();
 				for(auto it: t){
 					s.insert(it);
 				}
 				t.clear();
 			}
		}

		frr(i,n){
			if(f.find(i) == f.end()){
				ans[k] = i;
			}
		}
		cout << "A ";
		frr(i,n)
			cout << ans[i] << ' ';
		gnl;
		cout.flush();

	}
	else{
		int k =(n)/2;
		set<int> l;
		
		fr(i,k){
			if(i == 0){
				cout << "Q "<<1<< ' '<< k<<endl;
				cout.flush();
				fr(j,k){
					int a;
					cin >> a;
					s.insert(a);
					l.insert(a);
				}
 			}
 			else{
 				cout << "Q " << 1 + i << ' '<< k + i << endl;
 				cout.flush();
 				fr(j,k){
 					int a;
 					cin >> a;
 					t.insert(a);
 					if(f.find(a) == f.end())
 						l.insert(a);
 				}
 			
 				for(auto it: s){
 					if(t.find(it) == t.end()){
 						ans[i] = it;
 						f.insert(it);
 						l.erase(it);
 	//					
 					}
 				}

 				for(auto it : t){
 					if(s.find(it) == s.end()){
 						ans[k+i] = it;
 						f.insert(it);
 						l.erase(it);
 	//					
 					}
 				}

 				s.clear();
 				for(auto it: t){
 					s.insert(it);
 				}
 				t.clear();
 			}
		}

		ans[n/2] = *(l.begin());
		f.insert(*l.begin());

		frr(i,n){
			if(f.find(i) == f.end()){
				ans[n] = i;
			}
		}

		cout << "A ";
		frr(i,n)
			cout << ans[i] << ' ';
		gnl;
		cout.flush();

	}

}
