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


int main(){
    
    int n; cin >> n;

    if(n==1 || n==2){
    	cout << "No" << endl;
    	return 0;
    }

    cout << "Yes" << endl;

    if(n%2==0){

    	cout << "2 1 " << n << endl;
    	cout << n-2 << " ";
    	for(int i=2;i<n;i++)
    		cout << i << " ";
    	gnl; 

    }

    else{

    	cout << "1 " << (n+1)/2 << endl;
    	cout << n-1 << " ";
    	for(int i=1;i<=n;i++){
    		if(i==(n+1)/2)
    			continue;
    		cout << i << " ";
    	}
    	gnl;


    }

}