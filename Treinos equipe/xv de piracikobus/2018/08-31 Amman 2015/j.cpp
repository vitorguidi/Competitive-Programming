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

int age[20];
int amt[55];
int main(){

	int t;
	cin >> t;

	while(t--){

		int n,m;
		cin >> n >> m;
		
		ms(age,0);
		ms(amt,0);
		
		fr(i,n){
			int x; cin >> x;
			age[x]++;
		}
		
		fr(i,m){
			int x; cin >> x;
			amt[x]++;
		}

		int ini = 0;
		int ans = 0;
		int cnt = 0;
		
		for(int i=5;i<=15;i++){
			if(age[i])
				cnt++;
		}


		for(int i=5;i<=15;i++){

			if(age[i]==0)
				continue;
		
			while(ini<=50 && amt[ini]<age[i])
				ini++;
		
			if(ini>50)
				break;
		
			if(amt[ini]>=age[i])
				ans++;
		
			ini++;
		}


		if(ans==cnt)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}

}