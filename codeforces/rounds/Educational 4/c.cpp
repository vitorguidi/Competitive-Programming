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
#define olar cout << "pira" << endl
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll; 

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

bool match(char x, char y){
	if ( (x=='{' && y=='}') || (y=='{' && x=='}') || (x=='(' && y==')') || (y=='(' && x==')') )	return true;;
	if( (x=='[' && y==']') || (y=='[' && x==']') || (x=='<' && y=='>') || (y=='<' && x=='>' ) ) return true;
	return false;
}



int main(){

	fastio;

	string s;
	cin >> s;

	int cost = 0;
	stack<char> pilha;

	for(auto x : s){

		if(x=='(' || x=='{' || x=='[' || x=='<'){
			pilha.push(x);
			continue;
		}

		else{
			if(pilha.empty()){
				puts("Impossible");
				return 0;
			}
			char aux = pilha.top();
			pilha.pop();
			if(!match(x,aux)) cost++;
		}

	}

	if(!pilha.empty()){
		puts("Impossible");
		return 0;
	}

	cout << cost << endl;
	
}