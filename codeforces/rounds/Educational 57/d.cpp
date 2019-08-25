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
#define endl "\n"
 
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;

int n;
string s;
ll v[100100];

ll memo[100100][6];
set<char> danger;
char caga[5];

ll pd(int ind, int state){

	if(state==4)
		return 1e18;

	if(ind==n)
		return 0;

	ll &pdm=memo[ind][state];
	if(pdm!=-1)	return pdm;

	pdm=v[ind]+pd(ind+1,state);


	pdm=1e18;

	if(s[ind]!=caga[state])
		pdm=min(pdm,pd(ind+1,state));
	
	else{
		pdm=min(pdm,pd(ind+1,state)+v[ind]);
		pdm=min(pdm,pd(ind+1,state+1));
	}

	return pdm;
}

int main(){

	fastio;

	cin >> n >> s;
	fr(i,n)	cin >> v[i];

	danger.insert('h');
	danger.insert('a');
	danger.insert('r');
	danger.insert('d');

	ms(memo,-1);
	caga[0]='h';
	caga[1]='a';
	caga[2]='r';
	caga[3]='d';
	cout << pd(0,0) << endl;

}