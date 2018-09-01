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

int pa[1010];
int pe[1010];
int ts[1010];
int pa2[1010];
int pe2[1010];
int ts2[1010];

int main(){

	int t;
	cin >> t;

	while(t--){
	
		int n;
		cin >> n;
	
		string s;
		getline(cin,s);
		getline(cin,s);
	
		int len = s.size();

		ms(pe,0);
		ms(pa,0);
		ms(ts,0);
		ms(pe2,0);
		ms(pa2,0);
		ms(ts2,0);

		for(int i=1;i<=len;i++){

			char lt=s[i-1];
			
			if(lt=='R'){
				pa[i]=1;
				ts2[i]=1;
			}
			else if(lt=='S'){
				pe[i]=1;
				pa2[i]=1;
			}
			else{
				ts[i]=1;
				pe2[i]=1;
			}
		}

		for(int i=1;i<=len;i++){
			
			pa[i]+=pa[i-1];
			pe[i]+=pe[i-1];
			ts[i]+=ts[i-1];

			pe2[i]+=pe2[i-1];
			pa2[i]+=pa2[i-1];		
			ts2[i]+=ts2[i-1];
		
		}

		ll ans = 0;

		for(int i=0;i<=len;i++){

			for(int j=0;j<=len-i;j++){
				
				int soma = 0;
				soma+=pe[i];
				soma+=pa[j+i]-pa[i];	
				soma+=ts[len]-ts[j+i];


				int soma2 = 0;
				soma2+=pe2[i];
				soma2+=pa2[j+i]-pa2[i];	
				soma2+=ts2[len]-ts2[j+i];


				if(soma>soma2)
					ans++;
				
			}
		}

		cout << ans << endl;
	
	}

}