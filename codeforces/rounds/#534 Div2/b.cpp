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


int main(){
    
	fastio;
	string s;
	cin >> s;

	int moves=0;

	while(!s.empty()){

	
		int ini=0;
		
		int len = s.size();
		int cnt =0;

		string aux;
		stack<char> q;
		
		while(ini<len){

			char x = s[ini];
			
			if(q.empty()){
				q.push(x);
				aux.pb(x);
			}
			else if(q.top()==x){
				cnt++;
				q.pop();
				aux.pop_back();
			}
			else{
				aux.pb(x);
				q.push(x);
			}
			ini++;
		}
		moves+=cnt;
		swap(aux,s);
		if(cnt==0)	break;
	}

	cout << (moves%2? "Yes" : "No") << endl;

}