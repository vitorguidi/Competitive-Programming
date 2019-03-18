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

bool lucky(int x){

	do{
		int dig = x%10;
		x/=10;
		if(x!=4 && x!=7)	return false;
	}while(x!=0);
	return true;

}

int main(){
    
	fastio;

	int n;
	string s;
	cin >> n >> s;

	for(auto x : s){
		if(x!='4' && x!='7'){
			cout << "NO" << endl;
			return 0;
 		}
	}

	int s1 =0;
	int s2 = 0;

	for(int i=0;i<n/2;i++){
		s1+=s[i]-'0';
		s2+=s[n/2+i]-'0';
	}

	if(s1!=s2)	cout << "NO" << endl;
	else	cout << "YES" << endl;

}