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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int check[2200200];
vi primes;

bool is_pal(int x){

	string aux;
	while(x){
		aux.pb(x%2+'0');
		x/=2;
	}
	int len = aux.size();
	fr(i,(len+1)/2)
		if(aux[i]!=aux[len-1-i])
			return false;

	return true;

}

int to_num(string x){

	int base=1;
	int ans = 0;

	reverse(all(x));

	int len = x.size();

	fr(i,len)
		ans+=(x[i]-'0')*(1<<i);

	return ans;


}

string stringar(int x){
	string aux;
	while(x){
		aux.pb(x%2+'0');
		x/=2;
	}
	reverse(all(aux));
	return aux;

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);    

	for(int i=2;i<=2200000;i++){

		if(!check[i]){
			if(is_pal(i))
				primes.pb(i);
			for(int j=i;j<=220000;j+=i)
				check[j]=1;
		}

	}
    
	string s;

	while(cin>>s){
		int lol = to_num(s);
		auto it = lower_bound(all(primes),lol);
		cout << stringar(*it) << endl;
	}

}
