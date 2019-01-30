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

int main(){
    
	fastio;

	string s;
	int r,c;
	cin >> s;
	r=s[1]-'0';
	c=s[0]-'a'+1;

	int cnt=0;

	for(int i=-1;i<=1;i++){
		for(int j=-1;j<=1;j++){

			if(!i && !j)	continue;

			if(r+i>=1 && r+i<=8 && c+j>=1 && c+j<=8)
				cnt++;

		}
	}

	cout << cnt << endl;

}

