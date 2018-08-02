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

vi nodes[100100];
int memo[100100][2];
int pai[100100];

int pd(int v, int state){

	int &pdm=memo[v][state];
	
	if(pdm!=-1)
		return pdm;

	int ans1=0;	//escolho nao pintar o cara agora
	int ans2=1;	//escolho pintar o cara agora

	for (auto filho : nodes[v]){

		if(filho==pai[v])
			continue;

		pai[filho]=v;
		ans1+=pd(filho,0);	
		ans2+=pd(filho,1);

	}

	if(state)
		return pdm=min(ans1,ans2);

	return pdm=ans2;

}

int main(){

	int n;
	cin >> n;

	fr(i,n-1){
		int x,y;
		cin >> x >> y;
		nodes[x].pb(y);
		nodes[y].pb(x);
	}	

	ms(memo,-1);
	
	cout << pd(1,1) << endl;

}
