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

ll v1[300300],v2[300300];

int main(){

	fastio;
    
    int n1;
	cin >> n1;

	frr(i,n1){
		cin >> v1[i];
		v1[i]+=v1[i-1];
	}

	int n2;
	cin >> n2;
	frr(i,n2){
		cin >> v2[i];
		v2[i]+=v2[i-1];
	}


	if(v1[n1]!=v2[n2]){
		cout << -1 << endl;
		return 0;
	}

	int cnt=0;
	int endb=1;
	int enda=1;

	while(enda<=n1 && endb<=n2){
		
		while(v2[endb]!=v1[enda] && enda<=n1 && endb<=n2){


			if(v2[endb]>v1[enda])
				enda++;
			else if( v2[endb]<v1[enda])
				endb++;
			else
				break;

		
		}

	
		if(v2[endb]==v1[enda]){
			cnt++;		
			endb++;
			enda++;
		}
		
	}

	cout << cnt << endl;


}

