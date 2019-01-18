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
#define LAU cout << "LAW" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int memo[1010][1010];
int acum[1010];

string aux = "AHIMOTUVWXY";
string s;

bool check(char x){
	
	fr(i,11){
		if(x==aux[i])
			return true;
	}

	return false;

}

int pd(int i,int j){	//checa palindromo

	if(i>=j)
		return 1;

	int &pdm=memo[i][j];
	if(pdm!=-1)
		return pdm;

	if(s[i]==s[j])
		return pdm=pd(i+1,j-1);
	else
		return pdm=0;

}


int main(){

	int t; cin >> t;

	string nil;
	getline(cin,nil);

	while(t--){
	
		getline(cin,s);
		s="X"+s;

		ms(acum,0);

		int len = s.size();
		len--;

		ms(memo,-1);

		frr(i,len)
			if(!check(s[i]))
				acum[i]=1;

		frr(i,len)
			acum[i]=acum[i]+acum[i-1];

		int cnt = 0;

		frr(i,len){
			for(int j=i;j<=len;j++){
				int aux = acum[j]-acum[i-1];
				if(aux)
					continue;
				if(pd(i,j))
					cnt=max(cnt,j-i+1);
			}
		}

		cout << cnt << endl;

	}
	
}