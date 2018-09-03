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

#define gnl cout << endl
#define olar cout << "olar" << endl
#define gottagofast ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int v[200200];
int memo[200200][3];
int n;

int pd(int ind, int mod){

	if(ind==n)
		return 0;

	int &pdm=memo[ind][mod];

	if(pdm!=-1)
		return pdm;

	if( (v[ind]+mod)%3 == 0)
		return pdm=1+pd(ind+1,0);

	return pdm=max( pd(ind+1, (mod+v[ind]%3) ) , pd(ind+1,0));

}

int main(){

	string s;
	getline(cin,s);
    
    n=s.size();
    
    fr(i,n)
    	v[i]=(s[i]-'0')%3;
    ms(memo,-1);
    cout << pd(0,0) << endl; 

}

