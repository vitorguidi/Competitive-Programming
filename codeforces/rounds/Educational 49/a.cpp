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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int main(){
    
    #define fastio ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t; cin >> t;

    while(t--){

    	int n; cin >> n;
    	string s; getline(cin,s);getline(cin,s);

    	bool flag= true;

    	for(int i=0;i<(n+1)/2;i++){
    		int dist = abs(s[i]-s[n-1-i]);
    		if(dist!=0 && dist!=2)
    			flag=false;
    	}

    	if(flag)
    		cout << "YES" << endl;
    	else
    		cout << "NO" << endl;
    }

}

