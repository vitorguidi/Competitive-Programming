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

string aux;
vector<string> caras;

bool check(string x){

	int sum1=0;
	int sum2=0;
	fr(i,3)	sum1+=x[i]-'0';
	for(int i=3;i<6;i++)	sum2+=x[i]-'0';

	return sum1==sum2;

}

void fill(int ind){

	if(ind==6){
		if(check(aux))
			caras.pb(aux);
		return;
	}	

	fr(i,10){
		aux.pb('0'+i);
		fill(ind+1);
		aux.pop_back();
	}

}

int dist(string a, string b){

	int cnt=0;
	fr(i,6)	cnt+=a[i]!=b[i];
	return cnt;

}



int main(){
    
	fastio;

	string s; cin >> s;

	int cost = INF;

	fill(0);

	for(auto x : caras)
		cost=min(cost,dist(s,x));

	cout << cost << endl;

}

