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
const ll MOD = 1e9+7;

string s; 
string base = "happiness";
int len;

int main(){

	fastio;

	getline(cin,s);

	len = s.size();

	vi occur;
	int cnt  = 0;

	if(len<9){
		cout << "YES" << endl;
		cout << "1 2" << endl;
		return 0;
	}

	for(int i=1;i+8<=len;i++){

		bool flag = true;

		for(int j=0;j<=8;j++){
			if(s[i+j-1]!=base[j])
				flag=false;
		}

		if(flag){
			cnt++;
			occur.pb(i);
		}
	}


	if(cnt==0){

		cout << "YES" << endl;
		
		int ini=0;
		while(s[ini]!='p' && ini<len)
			ini++;

		if(ini==len){
			cout << "1 2" << endl;
			return 0;
		}

		int ini2=ini+1;
		while(ini2<len && s[ini2]!='p')
			ini2++;
		
		if(ini2==len){
			cout <<  "1 2" << endl;
			return 0;
		}


		cout << ini+1 <<" " << ini2+1 << endl;

	}

	else if(cnt==1){
		cout << "YES" << endl;
		cout << occur[0] << " " << occur[0]+1 << endl;
	}
	else if(cnt==2){
		cout << "YES" << endl;
		cout << occur[0] << " " << occur[1]+1 << endl;
	}
	else
		cout << "NO" << endl;

}