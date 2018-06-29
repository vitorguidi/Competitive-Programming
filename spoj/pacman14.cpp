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
#define pq priority_queue
#define grtp greater< pair<int,int> >

#define gnl cout << endl
#define olar cout << "olar" << endl
#define gottagofast ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int main(){

	int n;
	char v[110][110];
	cin >> n;
	int sum=0,mx=0;
	fr(i,n){
		fr(j,n){
			cin >> v[i][j];
		}
	}
	fr(i,n){
		if(i%2==0){
			fr(j,n){
				if(v[i][j]=='o'){
					sum++;
					mx=max(mx,sum);
				}
				if(v[i][j]=='A')
					sum=0;
			}
		}
		else{
			for(int j=n-1;j>=0;j--){
				if(v[i][j]=='o'){
					sum++;
					mx=max(mx,sum);
				}
				if(v[i][j]=='A')
					sum=0;
			}
		}
	}
	cout << mx << endl;
}