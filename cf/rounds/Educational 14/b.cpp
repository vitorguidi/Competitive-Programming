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
map<pair<char,char>,int> check;

void fill(){

	check[{'A','A'}]=1;
	check[{'H','H'}]=1;
	check[{'I','I'}]=1;
	check[{'M','M'}]=1;
	check[{'o','o'}]=1;
	check[{'O','O'}]=1;
	check[{'T','T'}]=1;
	check[{'U','U'}]=1;
	check[{'v','v'}]=1;
	check[{'V','V'}]=1;
	check[{'W','W'}]=1;
	check[{'w','w'}]=1;
	check[{'x','x'}]=1;
	check[{'X','X'}]=1;
	check[{'Y','Y'}]=1;

	check[{'b','d'}]=1;
	check[{'d','b'}]=1;
	check[{'p','q'}]=1;
	check[{'q','p'}]=1;

}

int main(){
    
	fastio;

	string s; cin >> s;
	int n = s.size();
	fill();

	fr(i,n){
		if(!check[{s[i],s[n-1-i]}] ){
			cout << "NIE" << endl;
			return 0;
		}
	}

	puts("TAK");

}

