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

double pd[400000];
int fat[10];

string stringify(int x){

	string aux;
	do{
		aux.pb(char(x%10+'0'));
		x/=10;
	}while(x!=0);
	reverse(all(aux));
	return aux;

}

vi aux;

int getrank(string s){

	if(s.size()==0)	return 0;

	set<int> q;

	for(int i=0;i<s.size();i++)	q.insert(s[i]-'0');

	vi aux;
	for(auto x : q)	aux.pb(x);

	auto it = lower_bound(all(aux),s[0]-'0');
	int eu = it - aux.begin();

	map<int,int> freq;

	for(auto x : s)	freq[x-'0']++;

	int rank = 0;

	for(int i=0;i<eu;i++){
		freq[aux[i]]--;
		int tmp = fat[s.size()-1];
		for(auto x : freq)	tmp/=fat[x.snd];
		rank+=tmp;
	}

	string lol;
	for(int i=1;i<s.size();i++)	lol.pb(s[i]);

	return rank + getrank(lol);
	

}

int main(){

	fastio;

	int t; cin >> t;

	cout << setprecision(9) << fixed;

	fat[0]=1;
	for(int i=1;i<10;i++)	fat[i]=i*fat[i-1];

	while(t--){

		int x; cin >> x;
		string aux = stringify(x);
	
		string ult = aux;
		sort(all(ult));
		reverse(all(ult));

		int len = getrank(ult);
		int rank = getrank(aux);

		len++;
		rank++;

		// dbg(x);
		// dbg(rank);
		// dbg(len);

		pd[len]=1;

		for(int i=len-1;i>=rank;i--){
			pd[i]=(1.0/len)*pd[i+1];
			pd[i]+=pd[i+1];
		}

		if(len==rank)	cout << 0.0 << endl;
		else			cout << pd[rank]-pd[rank+1] << endl;

	}
	
}