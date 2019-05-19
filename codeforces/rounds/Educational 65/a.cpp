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
const int MOD = 1e9+7;

void go(){

    int n; cin >> n;
    string s; cin >> s;

    reverse(all(s));

    while(!s.empty() && s[n-1]!='8'){
        n--;
        s.pop_back();
    }

    if(s.size()>=11)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

}

int main(){

	fastio;

	int t; cin >> t;
    while(t--)  go();

}