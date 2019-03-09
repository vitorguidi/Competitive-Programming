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

	string s; cin >> s;
	int k; cin >> k;

	int snow = 0;
	int cane = 0;

	for(auto x : s){
		if(x=='*')	snow++;
		if(x=='?')	cane++;
	}	

	int len = s.size();
	int actual_len = len-snow-cane;

	if(actual_len==k){
		for(auto x : s){
			if(x!='*' && x!='?')	cout << x;
		}
		gnl;
		return 0;
	}

	if(actual_len>k){
		if(actual_len-snow-cane>k){
			cout << "Impossible" << endl;
			return 0;
		}
	}

	if(actual_len<k){
		if(!snow){
			cout << "Impossible" << endl;
			return 0;
		}
	}

	string aux;

	if(actual_len>k){

		for(auto x : s){

			if(x!='?' && x!='*')	aux.pb(x);
			else if(actual_len>k){
				actual_len--;
				aux.pop_back();
			}

		}

		cout << aux << endl;
		return 0;

	}

	if(actual_len<k){

		for(auto x : s){
			if(x!='?' && x!='*')	aux.pb(x);
			
			else if(actual_len<k){
				if(x=='?')	continue;
				else{
					char cara = aux[aux.size()-1];
					while(actual_len<k){
						aux.pb(cara);
						actual_len++;
					}
				}
			}

		}

		cout << aux << endl;
		return 0;


	}

}