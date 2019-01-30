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
int acum[100100][26];

int main(){
    
	fastio;

	string s;
	cin >> s;
	
	int n = s.size();

	frr(i,n)
		acum[i][s[i-1]-'a']++;

	fr(i,26)
		frr(j,n)
			acum[j][i]+=acum[j-1][i];


	int ini=n;
	int end=1;
	int best=n;

	while(ini>=end){

		int mid = (ini+end)/2;

		int seen[26];
		ms(seen,1);

		frr(i,n-mid+1){
			fr(j,26){
				int amt = acum[i+mid-1][j]-acum[i-1][j];
				if(amt==0)	seen[j]=0;
			}
		}

		bool flag = false;
		fr(i,26)
			if(seen[i])
				flag=true;

		if(flag){
			best=min(best,mid);
			ini=mid-1;
		}
		else
			end=mid+1;

	}

	cout << best << endl;

}

