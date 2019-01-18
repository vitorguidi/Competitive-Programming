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
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;
const ll mod=1e9+7;
int m[9][9];
bool check(int x,int y){
	int i,j,v[10];
	
	ms(v,0); 

	for(i=x;i<x+3;i++)
		for(j=y;j<y+3;j++){
			v[m[i][j]]=1;
		} 
	
	frr(i,9)
		if(!v[i])
			return false;
	
	return true;	
}

int main(){
	fastio; 
	int t; 
	cin>>t;
	string s; 
	while(t--){
		getline(cin,s);
		
		fr(i,9){
			getline(cin,s);
			fr(j,9)
				m[i][j]=s[j]-'0';
		}
		int v[10];
		bool ok=1; 

		fr(i,9){
			ms(v,0);
			fr(j,9)
				v[ m[i][j] ]=1; 
			
			frr(j,9)
				if(!v[j]){
					ok=0;
				}

		}
		
		fr(i,9){
			ms(v,0);
			fr(j,9)
				v[ m[j][i] ]=1; 
			
			frr(j,9)
				if(!v[j])
					ok=0;

		}

		for(int i=0;i<=6;i+=3)
			for(int j=0;j<=6;j+=3){
				if(! check(i,j))
					ok=0;
			}

		if(ok)
			cout<<"Valid"<<endl; 
		else 
			cout<<"Invalid"<<endl;		


	}
}