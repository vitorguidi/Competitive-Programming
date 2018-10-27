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
const ll llINF = 0x3f3f3f3f3f3f3f;

int n;
string s;

bool check(int a, int b){

	int amt = b-a+1;
	int cnt[30];
	ms(cnt,0);

	for(int i=a;i<=b;i++)
		cnt[s[i]-'a']++;

	fr(i,26)
		if(cnt[i]>amt/2)
			return false;

	return true;

}

int main(){
    
	fastio;

	cin >> n >> s;

	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){

			if(!check(i,j))	continue;

			cout <<"YES" << endl;
			for(int k=i;k<=j;k++)
				cout << s[k];
			gnl;
			return 0;
			
		}
	}

	puts("NO");

}

