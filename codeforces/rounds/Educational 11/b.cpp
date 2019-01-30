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

int main(){
    
	fastio;

	queue<int> lw,lc,rc,rw;

	int n,m; cin >> n >> m;

	int cnt = 0;
	int people=1;


	while(people<=m && cnt<2*n){

		if(cnt%2==0){
			cnt++;
			lw.push(people++);
		}

		else{
			cnt++;
			rw.push(people++);
		}

	}

	cnt=0;

	while(people<=m && cnt<2*n){

		if(cnt%2==0){
			cnt++;
			lc.push(people++);
		}

		else{
			cnt++;
			rc.push(people++);
		}

	}	

	cnt = 0;

	vi ans;

	while(m){

		if(cnt%4==0){
			cnt++;
			if(lc.empty())
				continue;
			int cara = lc.front();
			lc.pop();
			ans.pb(cara);
			m--;
		}

		else if(cnt%4==1){
			cnt++;
			if(lw.empty())
				continue;
			int cara = lw.front();
			lw.pop();
			ans.pb(cara);
			m--;
		}

		else if(cnt%4==2){
			cnt++;
			if(rc.empty())
				continue;
			int cara = rc.front();
			rc.pop();
			ans.pb(cara);
			m--;
		}

		else if(cnt%4==3){
			cnt++;
			if(rw.empty())
				continue;
			int cara = rw.front();
			rw.pop();
			ans.pb(cara);
			m--;
		}

	}

	for(auto x : ans)
		cout << x << " ";
	gnl;

}

