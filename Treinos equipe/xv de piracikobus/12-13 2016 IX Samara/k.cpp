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

pii pal (string s){
	int i = 0;
	int j = s.size() - 1;

	while(i<j){
		if(s[i] != s[j]) return {i,j};
		i++;
		j--;
	}

	return {-1,-1};
}

int main(){

	fastio;
	string s;
	getline(cin,s);

	if(pal(s).fst == -1){
		cout <<"YES"<<endl;
		cout << (s.size())/2  + (s.size()%2)<< endl;
		return (0);
	}

	pii a = pal(s);

	int pula = a.fst;

	int p = 0;
	int q = s.size()-1;

	bool ok = true;

	while(p<q){
		if (p == pula) p++;
		if (p>= q) break;
		if(s[p] != s[q]) ok =false;
		p++;q--;
	}

	if (ok){
		cout <<"YES"<<endl;
		cout << pula + 1 << endl;
		return 0;
	}

	ok = true;
	p = 0;
	q = s.size() - 1;
	pula = a.snd;

	while(p < q){
		if (q == pula) q--;
		if (p>=q) break;
		if(s[p] != s[q]) ok =false;
		p++;q--;
	}

	if (ok){
		cout <<"YES"<<endl;
		cout << pula + 1 << endl;
		return 0;
	}

	cout <<"NO"<<endl;




}