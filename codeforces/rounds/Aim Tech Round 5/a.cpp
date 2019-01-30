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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

char v[115][115];

int main(){
    
    int n,m;
    cin >> n >> m;

    string s;
    getline(cin,s);

    vii aux;

    frr(i,n){
    	getline(cin,s);
    	frr(j,m){
    		v[i][j]=s[j-1];
    		if(v[i][j]=='B')
    			aux.pb(mp(i,j));
    	}
    }

    pii ini = aux[0];
    pii end = aux[aux.size()-1];

    int l = (end.fst-ini.fst)/2;
    int x = ini.fst+l;
    int y = ini.snd+l;

    cout << x << " " << y << endl;
 

}

