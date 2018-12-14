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

bool solve(int a, int b, int a1, int b1, int a2, int b2){

	bool flag = 0;

	if(a1+a2<=a && max(b1,b2)<=b)
		flag=1;

	if(max(a1,a2)<=a && b1+b2<=b)
		flag=1;

	return flag;

}

int main(){

	fastio;

	int a,b;
	int a1,b1;
	int a2,b2;
	
	cin >> a >> b >> a1 >> b1 >> a2 >> b2;

	int flag = 0;

	flag|= solve(a,b, a1,b1, a2,b2);
	flag|= solve(a,b, a1,b1, b2,a2);

	flag|= solve(a,b, b1,a1, a2,b2);
	flag|= solve(a,b, b1,a1, b2,a2);

	flag|= solve(b,a, a1,b1, a2,b2);
	flag|= solve(b,a, a1,b1, b2,a2);

	flag|= solve(b,a, b1,a1, a2,b2);
	flag|= solve(b,a, b1,a1, b2,a2);


	if(flag)
		puts("YES");
	else
		puts("NO");

}