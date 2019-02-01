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
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

vi ans;
int lps[412345];
vi deltav,deltaq;

void build(){
	int i=1;
	int j=0;
	int m=deltaq.size();
	lps[0]=0;

	while(i<m){
		if(deltaq[j]==deltaq[i]){
			j++;
			lps[i]=j;
			i++;
		}
		else{
			if(j==0){
				lps[i]=0;
				i++;
			}
			else
				j=lps[j-1];
		}
	}
}

void kmp(){
	build();
	int i,j;
	i=j=0;
	int n=deltav.size();
	int m=deltaq.size();

	while(i<n){
		if(deltaq[j]==deltav[i]){
			j++;
			i++;
			if(j==m){
				ans.pb(i-j);
				j=lps[j-1];
			}
		}
		else{
			if(j==0)i++;
			else
				j=lps[j-1];
		}
	}
}


int main(){
	fastio;
	int n;
	cin>>n;
	vi v,q;

	if(n==1){
		cout<<"possible"<<endl;
		return 0;
	}

	int x;
	fr(i,n){
		cin>>x;
		v.pb(x);
	}
	sort(all(v));
	
	fr(i,n)
		v.pb(v[i]);

	fr(i,n){
		cin>>x;
		q.pb(x);
	}
	sort(all(q));
	
	//delta
		
	frr(i,v.size()-1){
		deltav.pb((v[i]-v[i-1]+360000)%360000);
	}

	frr(i,q.size()-1){
		deltaq.pb((q[i]-q[i-1]+360000)%360000);
	}

	kmp();
	if(ans.size())
		cout<<"possible"<<endl;
	else
		cout<<"impossible"<<endl;

}
