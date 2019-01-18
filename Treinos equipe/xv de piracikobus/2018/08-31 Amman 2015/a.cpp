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

int main(){

	int T;
	cin >> T;

	while(T--){
		int n;
		cin >> n;
		string cam,aux;
		int s = 0, p = 2000;

		fr(i,n){
									
			cin >> aux;
			int aux1,aux2;
			cin >> aux1 >> aux2;
			//dbg(aux1);
			//dbg(s);

			if (aux1 == s && aux2 < p){
				p = aux2;
				cam = aux;
			}

			else if (aux1 > s){
				s = aux1;
				p = aux2;
				cam = aux;
			}
			
		}

		cout << cam << endl;
		
	}

	return (0);

}