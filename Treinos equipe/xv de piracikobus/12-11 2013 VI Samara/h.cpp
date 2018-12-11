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
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

int main(){

	fastio;

	vector<ll> star1,star2;
		
	int x1,y1,x2,y2,x3,y3;		
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;

	star1.pb( (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2) );
	star1.pb( (x2-x3)*(x2-x3)+(y2-y3)*(y2-y3) );
	star1.pb( (x1-x3)*(x1-x3)+(y1-y3)*(y1-y3) );
	
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;

	star2.pb( (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2) );
	star2.pb( (x2-x3)*(x2-x3)+(y2-y3)*(y2-y3) );
	star2.pb( (x1-x3)*(x1-x3)+(y1-y3)*(y1-y3) );

	sort(all(star2));

	bool flag = false;
	do{

		bool aux = true;

		if(star1[0]*star2[1]!=star2[0]*star1[1])	aux=false;		
		if(star1[0]*star2[2]!=star1[2]*star2[0])	aux=false;
		if(star1[1]*star2[2]!=star2[1]*star1[2])	aux=false;

		flag|=aux;

	}while(next_permutation(all(star2)));

	if(flag)	puts("YES");
	else		puts("NO");

}
