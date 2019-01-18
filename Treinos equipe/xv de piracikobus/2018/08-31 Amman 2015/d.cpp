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

int matr[1001][1001];
int memo[1001];
int v[1123];
int n,k;

void pd1 (){
	int i,j;
	for(i=0;i<n;i++){
		if (v[i] != v[i+1])
			matr[i][i+1] = 1;
	}

	for(i=0;i<n;i++){
		for (j = i+2;j<n;j++){
			if (matr[i][j-1] == 1 && v[j]!=v[j-1])
				matr[i][j] = 1;
		}
	}
}

int pd2(int at){
	if (at >= n) return (0);

	if (memo[at] == -1){
		memo[at] = INF;
		frr(i,k){
			if ((at + i -1 < n) &&!matr[at][at + i - 1]) 
				memo[at] = min(memo[at],1 + pd2(at + i));
		}

	}

	return(memo[at]);	
}


int main(){
	int T;
	cin >> T;
	while(T--){
		ms(memo,-1);
		ms(matr,0);
		string s;
		cin >> n;
		cin >> k;
		getline(cin,s);
		getline(cin,s);
		//dbg(s);
		fr(i,n)
			v[i] = s[i] - '0';
		pd1();
		cout << pd2(0) - 1 << endl;

		//fr(i,n){
		//	fr(j,n)
		//		cout << matr[i][j] << ' ';
		//	cout << endl;
		//}		

	}

	return(0);


}