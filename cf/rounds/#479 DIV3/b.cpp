#include "bits/stdc++.h"
using namespace std;

#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define priority_queue pq
#define vi vector<int>
#define vii vector<pair<int,int>>
#define grtp greater<pair<int,int>

#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)
#define ms(x, v) memset(x, v, sizeof x)
#define all(x)	x.begin(),x.end()

#define dbg(x) cout << #x << " = " << x << endl
#define gnl cout << endl
#define olar() cout << "olaarr" << endl

const int INF = 0x3f3f3f3f;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main(){

	string x;
	char aux[2],r1[2];
	int cnt,n,ans;
	int s=x.size();

	cin >> n;
	getchar();
	getline(cin,x);
	ans=0;

	for(int i=0;i<n-1;i++){
		cnt=0;
		for(int j=i;j<n-1;j++){
			if(x[j]==x[i] && x[j+1]==x[i+1])	cnt++;
		}
		if(cnt>ans){
			ans=cnt;
			r1[0]=x[i];
			r1[1]=x[i+1];
		}
	}

	cout << r1[0] << r1[1] << endl;
	
}