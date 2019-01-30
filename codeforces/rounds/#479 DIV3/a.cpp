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

	int n,k;

	cin >> n >> k;

	frr(i,k){
		if(n%10==0)	n=n/10;
		else	n--;
	}

	cout << n << endl;
	
}