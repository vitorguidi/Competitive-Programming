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

string s;
int len;
int v[1010];

void rev(int ind){
	string a;
	for(int i=0;i<=ind;i++)
		a+=s[i];
	string b;
	for(int i=ind+1;i<s.size();i++)
		b+=s[i];
	reverse(all(a));
	s=a+b;
}


int main(){
    
	fastio;

	getline(cin,s);
	string p=s;

	sort(all(p));
	len=s.size();

	int ini=0;

	while(ini<len && p!=s){

		while(s[ini+1]==s[ini] && ini+1<len)
			ini++;

		rev(ini);
		v[ini]=1;

		ini++;

	}

	
	for(int i=0;i<len;i++)
		cout << v[i] << " ";
	gnl;

}

