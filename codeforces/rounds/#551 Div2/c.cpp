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
const int MOD = 1e9+7;
 
int n;
string s;

bool balanced(string s){

	string aux;
	for(auto x : s)
		aux.pb(x);

	stack<char> q;

	for(auto x : s){
		if(x=='(')
			q.push(x);
		else{
			if(!q.empty())
				q.pop();
			else
				return false;
		}
	}

	return q.empty();

}

int main(){
 
	fastio;

	cin >> n >> s;

	if(n%2){
		cout << ":(" << endl;
		return 0;
	}

	int abre=0;
	int fecha=0;

	stack<int> abres;

	fr(i,n){
		if(s[i]=='(')
			abre++;
		else if(s[i]==')')
			fecha++;
		else{
			if(abre>n/2){
				s[i]=')';
				fecha++;
			}
			else{
				s[i]='(';
				abre++;
				abres.push(i);
			}
		}
	}

	while(abre>fecha){
		if(abres.empty()){
			cout << ":(" << endl;
			return 0;
		}
		int aux = abres.top();
		abres.pop();
		abre--;
		fecha++;
		s[aux]=')';
	}

	abre=0;
	fecha=0;

	fr(i,n-1){
		if(s[i]=='(')
			abre++;
		else
			fecha++;
		if(abre==fecha){
			cout << ":(" << endl;
			return 0;
		}
	}

	if(!balanced(s)){
		cout << ":(" << endl;
		return 0;
	}

	cout << s << endl;
 
}