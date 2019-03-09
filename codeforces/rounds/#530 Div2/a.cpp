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

int stone[110];

int main(){
    
	fastio;

	int w,h;
	cin >> w >> h;
	int u1,d1;
	cin >> u1 >> d1;
	stone[d1]=u1;
	int u2,d2;
	cin >> u2 >> d2;
	stone[d2]=u2;

	for(int i=h;i>0;i--){
		w+=i;
		if(stone[i])	w=max(0,w-stone[i]);
	}

	cout << w << endl;

}