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
    
	int n,k; cin >> n >> k;
	vector<char> stuff;
	string s;
	getline(cin,s);
	getline(cin,s);
	
	fr(i,s.size())
		stuff.pb(s[i]);
	
	sort(all(stuff));
	
	int amt=0,cnt=0,cur=-2;

	fr(i,stuff.size()){
		int letra = stuff[i]-'a';
		if(cnt==k)
			continue;
		if(letra>=cur+2){
			cnt++;
			cur=letra;
			amt+=letra+1;
		}
	}
	if(cnt<k)
		cout << -1 << endl;
	else
		cout << amt << endl;
	//if(cnt)

}

