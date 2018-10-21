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

int a[100100],b[100100],t[100100];
int n;

void solve(int x){

	t[0]=x;

	for(int i=1;i<n;i++){

		fr(j,4){

			if( a[i-1]==(j|t[i-1]) && b[i-1]==(j&t[i-1]) ){
				t[i]=j;
				break;
			}

		}

	}

}

bool check(){

	for(int i=1;i<n;i++){
		if(a[i-1]!=(t[i]|t[i-1]) || b[i-1]!=(t[i]&t[i-1]) )
			return false;
	}

	return true;

}


int main(){
    
	fastio;

	cin >> n;

	ms(t,-INF);


	fr(i,n-1)
		cin >> a[i];

	fr(i,n-1)
		cin >> b[i];

	bool flag=false;
	fr(i,4){
		solve(i);
		if(check()){
			flag=true;
			break;
		}
	}

	if(!flag){
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;
	for(int i=0;i<n;i++)
		cout << t[i] << " ";
	gnl;



}

