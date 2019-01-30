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

int main(){

	fastio;

	int v[110];
	int cnt[110];
	int occur[110];
	int index[110]; 

	ms(cnt,0);
	ms(occur,-1);

	int n; cin >> n;
	
	frr(i,n){	
		index[i]=1;
		cin >> v[i];		//le o elemento
		cnt[v[i]]++;		//incrementa contador dele
		if(cnt[v[i]]==1)	//se eh o primeiro do numero, guarda indice da primeira ocorrencia
			occur[v[i]]=i;
	}

	int unico=0;
	int resto=0;


	vi unique;
	vi rest;

	frr(i,100){
		if(!cnt[i])
			continue;
		else if(cnt[i]==1){
			unico++;
			unique.pb(occur[i]);
		}
		else if(cnt[i]>2){
			rest.pb(occur[i]);
			resto++;
		}
	}

	if(unico%2 && !resto){
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;

	if(unico%2==0){
		fr(i,unique.size()/2)
			index[unique[i]]=2;
		frr(i,n)
			cout << (index[i]==1 ? "A" : "B");
		gnl;
		}
	else{
		fr(i,unique.size()/2)
			index[unique[i]]=2;
		index[rest[0]]=2;
		frr(i,n)
			cout << (index[i]==1 ? "A" : "B");
		gnl;
	}

}