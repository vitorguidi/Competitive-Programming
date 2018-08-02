#include "bits/stdc++.h"
using namespace std;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)
#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;
typedef vector< vector<ll> > matrix;
const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;
const ll mod = 1e9+7;

int main(){

	string s,aux;
	getline(cin,s);
	int n1=0,n2=0;

	for(int i=0;i<s.size();i++){
		if(s[i]=='1')
			n1++;
		else if(s[i]=='2'){
			aux.pb(s[i]);
			n2++;
		}
		else
			aux.pb(s[i]);
	}


	if(n2==0){
		fr(i,n1)
		aux.pb('1');
		cout << aux << endl;
	}

	else{
		string aux2;
		int ini=0;

		fr(i,aux.size()){
			if(aux[i]!='2')
				aux2.pb(aux[i]);
			else{
				fr(j,n1)
					aux2.pb('1');
				aux2.pb(aux[i]);
				n1=0;
			}
		}

		cout << aux2 << endl;
		
	}


}