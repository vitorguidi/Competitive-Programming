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

ll cnt_s[30],cnt_t[30];
ll unk;

int main(){
    
	fastio;

	string s,t;
	cin >> s >> t;

	for(auto x : s){

		if(x!='?')
			cnt_s[x-'a']++;

		else
			unk++;

	}

	for(auto x : t)
		cnt_t[x-'a']++;

	ll ini=0;
	ll end = 1001000;

	ll best=0;

	while(ini<=end){

		ll mid = (ini+end)/2;

		ll precisa = 0;

		fr(i,26){

			ll need = mid*cnt_t[i];

			if(cnt_s[i]<need)
				precisa+=need-cnt_s[i];

		}

		if(precisa<=unk){

			best=max<ll>(best,mid);
			ini=mid+1;
		
		}
		else
			end=mid-1;


	}

	fr(i,s.size()){

		if(s[i]!='?')	continue;
		
		fr(j,26){
			
			if( best*cnt_t[j] > cnt_s[j] ){

				s[i]=j+'a';
				cnt_s[j]++;
				break;

			}

		}

	}

	fr(i,s.size())
		if(s[i]=='?')
			s[i]='a';
	
	cout << s << endl;


}