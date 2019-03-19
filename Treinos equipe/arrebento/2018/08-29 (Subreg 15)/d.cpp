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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

map<int,string> var;
map<string,int> var2;

string m[110][110];

ll a[210][210],b[210];
ll x[210],aux[210];
ll col[210],lin[210];
ll l,c;

void solve(){

	string s;
	getline(cin,s);

	int cnt = 1;
	fr(i,210)
		x[i]=llINF;

	fr(i,l){
		fr(j,c){

			cin >> s;
			
			if(!var2[s]){
				var[cnt]=s;
				var2[s]=cnt;
				cnt++;
			}
			
			m[i][j]=s;
		}
		
		cin >> lin[i];
		getline(cin,s);
	
	}

	cnt--;

	fr(i,c)
		cin >> col[i];

	fr(i,l){
		
		ms(aux,0);
		
		fr(j,c)
			aux[ var2[m[i][j]] ]++;
		
		fr(j,c+l)
			a[i][j]=aux[j];

		b[i]=lin[i];

	}

	fr(i,c){
		
		ms(aux,0);

		fr(j,l)
			aux[ var2[ m[j][i] ] ]++;

		fr(j,c+l)
			a[i+l][j]=aux[j];

		b[i+l]=col[i];

	}

	int solved=0;

	while(solved<cnt){

		fr(i,c+l){
			
			int known=0;
			int unknown=0;

			frr(j,cnt){

				if(!a[i][j])
					continue;
				if(x[j]!=llINF)
					known++;
				if(x[j]==llINF)
					unknown++;
			
			}

			if(unknown==1){

				ll sum=0;
				
				frr(j,cnt){
					if(x[j]!=llINF)
						sum+=x[j]*a[i][j];
				}

				frr(j,cnt){
					if(x[j]==llINF && a[i][j]){
						x[j]=(b[i]-sum)/a[i][j];
						solved++;
						break;					
					}
				}
				
			}
		
		}

	}

	vector<pair<string,int>> ans;

	frr(i,cnt)
		ans.pb( mp(var[i],(int)x[i]) );

	sort(all(ans));

	for(auto x : ans)
		cout << x.fst << " " << x.snd << endl;

}

int main(){
	while(	cin >> l >> c){
		solve();
	}
}