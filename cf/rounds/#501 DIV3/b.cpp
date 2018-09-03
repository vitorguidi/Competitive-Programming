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

int main(){
    
    int n;
    string s,t,aux1,aux2;
    cin >> n;

    getline(cin,s);
    getline(cin,s);
    getline(cin,t);
    
    aux1=s;aux2=t;
    sort(all(aux1));sort(all(aux2));
    
    if(aux1!=aux2){
    	cout << -1 << endl;
    	return 0;
    }

    vi ans;

    fr(i,n){

    	if(s[i]==t[i])
    		continue;    	
    	
    	int ind=0;
    	
    	for(int j=i;j<n;j++){
    		if(s[j]==t[i]){
    			ind=j;
    			break;
    		}
    	}

    	for(int j=ind-1;j>=i;j--){
    		ans.pb(j+1);
    		swap(s[j],s[j+1]);
    	}
    }

    cout << ans.size() << endl;
    fr(i,ans.size())
    	cout << ans[i] << " ";
    gnl;

}

