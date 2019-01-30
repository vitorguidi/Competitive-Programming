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

int amt[30];

int main(){
    
    int n,k; cin >> n >> k;
    string s;
    getline(cin,s);
    getline(cin,s);

    fr(i,n)
    	amt[ s[i]-'A' ]++;
    
    int cnt=0;
    int ans=INF;
    fr(i,k){
    	ans=min(ans,amt[i]);
    	if(amt[i])
    		cnt++;
    }

    if(cnt<k)
    	cout << 0 << endl;
    else
    	cout << ans*k << endl;

}

