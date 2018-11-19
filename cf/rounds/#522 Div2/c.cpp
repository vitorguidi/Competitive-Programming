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

pii prox[100100][10];
int memo[100100][10];
int v[100100];

int n;

int pd(int ind, int dig){

	if(ind==n)	return 0;

	int &pdm=memo[ind][dig];
	if(pdm!=-1)	return pdm;

	pdm=-INF;

	frr(i,5){			//dig = digito atual
						//i = prox digito

		if( v[ind]==v[ind+1] && dig==i )		continue;
		if( v[ind]<v[ind+1]  && dig>=i )		continue;
		if( v[ind]>v[ind+1]  && dig<=i )		continue;

		int aux = pd(ind+1,i);

		if(aux>pdm){
			pdm=aux;
			prox[ind][dig]={ind+1,i};
		}

	}

	return pdm;

}

int main(){
    
	fastio;

	cin >> n;

	frr(i,n)	cin >> v[i];

	ms(memo,-1);

	int dig = 0;
	int ans = -INF;

	frr(i,5){
		int aux = pd(1,i);
		if(aux>ans){
			ans=aux;
			dig=i;
		}
	}


	if(ans<0){
		cout << -1 << endl;
		return 0;
	}

	frr(i,n){
		cout << dig << " ";
		dig=prox[i][dig].snd;
	}
	gnl;


}

