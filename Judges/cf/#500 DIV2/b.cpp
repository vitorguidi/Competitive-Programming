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

typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int n,x;
vi normal;
vi altered;
map<int,int> cnt,cnt2;

int main(){
    
	cin >> n >> x;

	fr(i,n){

		int aux; cin >> aux;
		
		normal.pb( aux );
		altered.pb( aux&x );
		
		cnt[aux]++;
		cnt2[(aux&x)]++;
	
	}

	fr(i,n){
	
		int num = normal[i];
	
		if( cnt[num] > 1){
			cout << 0 << endl;
			return 0;
		}

	}

	fr(i,n){

		int num = normal[i];

		if(cnt2[num]==0)
			continue;

		if(cnt2[num]==1 && (num&x)==num)
			continue;

		if(cnt2[num]==1 && (num&x)!=num){
			cout << 1 << endl;
			return 0;
		}

		if(cnt2[num]>1){
			cout << 1 << endl;
			return 0;
		}
	
	}

	fr(i,n){

		if(cnt2[altered[i]]>1){
			cout << 2 << endl;
			return 0;
		}
	}

	cout << -1 << endl;

}

