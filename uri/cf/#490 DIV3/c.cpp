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
#define pq priority_queue
#define grtp greater< pair<int,int> >

#define gnl cout << endl
#define olar cout << "olar" << endl
#define gottagofast ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int main(){
	    
    int n,k,v[26];
    string s;
    ms(v,0);
    cin >> n >> k;
    getchar();
    getline(cin,s);
    fr(i,n){
    	v[s[i]-'a']++;
    }
    int cnt=k;
    int ini=0;
    while(cnt){
    	if(v[ini]){
    		cnt--;
    		v[ini]--;
    	}
    	else
    		ini++;
    }
	string ans;   
	for(int i=n-1;i>=0;i--){
		if(v[ s[i]-'a' ]){
			v[ s[i]-'a' ]--;
			ans.pb(s[i]);
		}
	}

	reverse(ans.begin(),ans.end());
	cout << ans << endl;
}

