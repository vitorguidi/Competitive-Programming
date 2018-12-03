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

bool bis(int n){
	if(n%400==0) return true;
	if(n%100!=0 && n%4==0)
		return true;
	return false;
}

int main(){
    
	string s; cin >> s;

	int hora = (s[0]-'0')*10 + (s[1]-'0');
	int minuto = (s[3]-'0')*10 + (s[4]-'0');

	int delta; cin >> delta;



	int now = hora*60 + minuto + delta;

	int resto = now/(24*60);

	now-=resto*(24*60);

	hora = now/60;
	minuto = now%60;

	string h;

	do{
		char x = '0'+hora%10;
		hora/=10;
		h.pb(x);
	}while(hora);

	reverse(all(h));

	if(h.size()==1)	h="0"+h;

	string m;

	do{
		char x = '0'+minuto%10;
		minuto/=10;
		m.pb(x);
	}while(minuto);

	reverse(all(m));

	if(m.size()==1)	m="0"+m;

	string ans = h + ":" + m;

	cout << ans << endl;


}
