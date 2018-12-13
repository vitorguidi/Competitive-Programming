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

int qr[20][22][22];

int ones[20];
int dist[20][20];

int memo[1<<20][20];
pii prox[1<<20][20];
int erase[1<<20][20];

int n,a;

int pd(int mask, int pivot){

	if(mask==(1<<n)-1)	return 0;

	int &pdm=memo[mask][pivot];
	if(pdm!=-1)	return pdm;

	pdm = INF;

	fr(i,n){

		if( (1<<i)&mask )	continue;

		int val = dist[pivot][i] + pd(mask|(1<<i),i);

		if(val<pdm){
			pdm=val;
			prox[mask][pivot]={mask|(1<<i),i};
			erase[mask][pivot]=0;
		}

		int alt = a+ones[i]+pd(mask|(1<<i),i);
		if(alt<pdm){
			pdm=alt;
			erase[mask][pivot]=1;
			prox[mask][pivot]={mask|(1<<i),i};
		}

	}

	return pdm;

}

int main(){

	fastio;

	cin >> n >> a;

	string s;
	getline(cin,s);

	fr(k,n){
		fr(i,21){
			getline(cin,s);
			fr(j,21){
				qr[k][i][j]=s[j]-'0';
				ones[k]+=qr[k][i][j];
			}
		}
		if(k!=n-1)	getline(cin,s);
	}

	fr(i,n)
		fr(j,n)
			fr(k,21)
				fr(l,21)
					dist[i][j]+=qr[i][k][l]!=qr[j][k][l];

	ms(memo,-1);

	int best=INF;
	int pivot=-1;
	int mask=0;

	fr(i,n){
		if(ones[i] + pd((1<<i),i)<best){
			best=ones[i]+pd(1<<i,i);
			pivot=i;
			mask=(1<<i);
		}
	}

	cout << best << endl;

	pii nxt;

	for(int i=0;i<n;i++){

		cout << pivot+1 << endl;


		if(erase[mask][pivot])
			cout <<"*"<< endl;


		nxt=prox[mask][pivot];
		mask=nxt.fst;
		pivot=nxt.snd;

	}

}

