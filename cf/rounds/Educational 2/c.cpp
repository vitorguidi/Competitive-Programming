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

int freq[30];

int main(){

	fastio;

	string s; getline(cin,s);

	string good,bad;
	string left,right,mid;

	for(auto x : s)
		freq[x-'a']++;

	fr(i,26){
		fr(j,(freq[i]/2)*2)
			good.pb('a'+i);
		if(freq[i]%2)
			bad.pb('a'+i);
		freq[i]=0;
	}

	sort(all(good));
	sort(all(bad));

	for(auto x : bad)
		freq[x-'a']++;

	fr(i,26){
		fr(j,freq[i]){
			if(j%2==0)	left.pb('a'+i);
			else		right.pb('a'+i);
		}
	}

	reverse(all(right));

	string ans = left+right;

	int len = ans.size();
	fr(i,len){
		if(ans[i]!=ans[len-1-i]){
			char aux = min(ans[i],ans[len-1-i]);
			ans[i]=aux;
			ans[len-1-i]=aux;
		}
	}

	//ans eh a parte ruim palindromizada
	//good eh um palindromo par

	string aux = good + ans;

	left.clear();
	right.clear();

	sort(all(aux));

	ms(freq,0);

	for(auto x : aux)
		freq[x-'a']++;

	fr(i,26){
	
		if(!freq[i])	continue;


		char x = 'a'+i;

		if(freq[i]%2)	mid.pb(x);
		int amt = freq[i]/2;
	
		fr(j,amt){
			left.pb(x);
			right.pb(x);
		}
	
	}

	reverse(all(right));

	string printa = left + mid + right;

	cout << printa << endl;


}