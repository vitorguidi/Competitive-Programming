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

int grid[5][5];

pii put_ver(){

	pii ans;

	for(int i=1;i<=4;i++){
		if(grid[1][i]==0){
			ans={1,i};
			grid[1][i]=1;
			break;
		}
	}

	int cnt = 0;
	for(int i=1;i<=4;i++){
		if(grid[1][i])	cnt++;
	}
	if(cnt==4){
		for(int i=1;i<=4;i++)
			for(int j=1;j<=2;j++)
				grid[j][i]=0;
	}

	return ans;

}

pii put_hor(){

	pii ans;

	if(grid[3][1]==0){
		grid[3][1]=1;
		return {3,1};
	}
	else{
		grid[3][1]=0;
		return {3,3};
	}

}

int main(){
    
	fastio;

	string s; cin >> s;

	for(auto x : s){
		pii ans;
		if(x=='0')	ans = put_ver();
		else		ans = put_hor();
		cout << ans.fst << " " << ans.snd << endl;
	}

}