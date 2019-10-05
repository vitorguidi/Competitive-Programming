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

#define endl "\n" 
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 
 
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;
 
const int INF = 0x3f3f3f3f;

int m[100100][30];
int acum[100100][30];

int qtd(char c,int a,int b){
	int cara = c - 'a';
	if(a == 0){
		return acum[b][cara];
	}
	else return acum[b][cara] - acum[a-1][cara];
}

int main(){

	fastio;
	string s;
	getline(cin,s);
	int n = s.size();
	ms(m,-1);

	int aux[27];
	ms(aux,-1);

	for(int i = 0;i < n;i++){
		fr(j,26){
			m[i][j] = aux[j];
			if(i!=0){
				acum[i][j] = acum[i-1][j];
			}
		}
		acum[i][s[i]-'a']++;

		char c = s[i];
		m[i][s[i] - 'a'] = -1;
		aux[s[i]-'a'] = i;
	}

	int ans = 0;

	fr(i,n){
		fr(j,26){
			if(s[i] == 'a' + j) continue;

			if(m[i][j] == -1) continue;
			if(qtd(s[i],m[i][j],i) == 1) ans++;
		}
	}

	cout << ans << endl;
	

	
 
}