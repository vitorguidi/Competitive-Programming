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

struct trie
{
	int cnt,wrd;
	map<int,trie> m;
	trie(){
		cnt=0;wrd=0;
		m.clear();
	}
	void add(vi &s, int pos){// 0-par 1-impar
		cnt++;
		if(pos==0){
			wrd++;
			return;
		}
		int aux=s[pos];

		if(!m.count(aux))
			m[aux]=trie();

		m[aux].add(s,pos-1);
	}
	void remove(vi& s,int pos){
		cnt--;
		if(pos==0){
			wrd--;
			return;
		}
		int aux=s[pos];

		m[aux].remove(s,pos-1);
	}
	int find(vi &s,int pos){
	//	dbg(pos);
		if(pos==0)
			return wrd;
		int aux=s[pos];
	//	dbg(m.count(0));dbg(m.count(1));


		if(!m.count(aux) || m[aux].cnt==0)
			return 0;

		return m[aux].find(s,pos-1);
	}
	
};

int main(){
	fastio;
	int t;
	cin>>t;

	string q;
	vi v;
	ll num;

	trie arv=trie();

	while(t--){
	
		cin>>q>>num;
		
		v.resize(21);

		for(int i=20;i>=0;i--){
			v[i]=((num%10)%2);
			num/=10;
		}
		// for(auto x:v)
		// 	cout<<x;
		// gnl;

		if(q=="+"){
			arv.add(v,20);
		}
		else if(q=="-"){
			arv.remove(v,20);
		}
		else{
			cout<<(arv.find(v,20))<<endl;
		}


	}


}
