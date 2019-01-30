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
#define pira cout << "pira" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

string s,x;
int ls,lx;
int memo[55][55];

int pd(int i, int j){

	if(i==ls || j==lx)
		return 0;

	int &pdm=memo[i][j];
	if(pdm!=-1)
		return pdm;

	pdm=0;

	pdm=max(pdm,pd(i+1,j));
	pdm=max(pdm,pd(i,j+1));
	if(s[i]==x[j])
		pdm=max(pdm,1+pd(i+1,j+1));
	return pdm;

}

int main(){
    
    getline(cin,s);
    x= "abcdefghijklmnopqrstuvwxyz";
    ls=s.size();
    lx=x.size();

    ms(memo,-1);
    int lcs = pd(0,0);

    cout << 26-lcs << endl;

}

