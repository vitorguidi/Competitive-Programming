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
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;

void go(){

	int n; cin >> n;
	string s;  cin >> s;

	if(n==1){
		cout << 0 << endl;
		return;
	}

	if(s[0]=='>'){
		cout << 0 << endl;
		return;
	}

	if(s[n-1]=='<'){
		cout << 0 << endl;
		return;
	}

	int ini=0;
	int cntl=0;

	int ans = 0;

	while(ini<n && s[ini]=='<'){
		cntl++;
		ini++;
	}

	ini=n-1;
	int cntr=0;

	while(ini>=0 && s[ini]=='>'){
		cntr++;
		ini--;
	}

	cout << min(cntl,cntr) << endl;

}

int main(){
    
	fastio;

	int t; cin >> t;
	while(t--)	go();

}