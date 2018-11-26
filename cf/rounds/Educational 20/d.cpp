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

int k;
vi repo;

bool check(int sz){

	int len = repo.size();

	int ini=0;
	int cnt = 0;
	
	while(ini<len){

		int lol = 0;

		while(lol+repo[ini]<=sz && ini<len)
			lol+=repo[ini++];

		if(!lol)	return false;

		cnt++;

	}

	return cnt<=k;

}

int main(){
    
	fastio;

	cin >> k;
	string s; getline(cin,s); getline(cin,s);

	int len = s.size();

	fr(i,len)
	if(s[i]=='-' || s[i]==' ')
		s[i]='.';

	int ini=0;

	while(ini<len){

		int cnt=0;
		while(ini<len && s[ini]!='.'){
			cnt++;
			ini++;
		}

		if(ini==len){
			repo.pb(cnt);
			break;
		}

		cnt++;
		ini++;
		repo.pb(cnt);

	}

	int mx =0;

	for(auto x : repo)	mx=max(mx,x);

	int low = mx;
	int high = len;

	int mid;
	int best = INF;

	while(low<=high){			//busca binaria no width

		mid = (low+high)/2;

		if(check(mid)){
			best=min(mid,best);
			high=mid-1;
		}

		else
			low=mid+1;

	}	



	cout << best << endl;

}

