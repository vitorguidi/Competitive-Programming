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

int v[500500];
int n; 

int main(){
    
	cin >> n;   

	fr(i,n)
		cin >> v[i];

	sort(v,v+n);

	ll sum=0;

	if(n==1){
		cout << v[0] << endl;
	}
	else if(v[0]>=0){

		frr(i,n-1)
			sum+=v[i];
		sum-=v[0];
		cout << sum << endl;
	}
	else{
		fr(i,n){
			if(v[i]<0 && i!=n-1)
				sum-=v[i];
			else
				sum+=v[i];
		}
		cout << sum << endl;
	}


}

