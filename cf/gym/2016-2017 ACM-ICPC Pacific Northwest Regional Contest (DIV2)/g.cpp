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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;


char v[55][55];
int d[55][55];
string s;
int n,m;

int main(){
    
	cin >> n >> m;

    getline(cin,s);
    fr(i,n){
    	getline(cin,s);
    	fr(j,m)
    		v[i][j]=s[j];
    }

    fr(i,m){
    	fr(j,n){
    		for(int k=0;k<n-1;k++){
    			if(v[k][i]=='o' && v[k+1][i]=='.')
    				swap(v[k][i],v[k+1][i]);
    		}
    	}
    }

    fr(i,n){
    	fr(j,m)
    		cout << v[i][j];
    	gnl;
    }

}

