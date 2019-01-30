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
#define pira cout << "pira" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int row[40][40];
int col[40][40];
int v[40][40];
int n; 

void solve(){
    
    string s;
    getline(cin,s);
    ms(col,0);
    ms(row,0);
    ms(v,0);


    fr(i,n){
    	
    	getline(cin,s);

    	fr(j,n){
    	
    		int letra;

    		if(s[j]>='0' && s[j]<='9')
    			letra=s[j]-'0';
    		else
    			letra=s[j]-'A'+10;

    		v[i][j]=letra;

    		row[i][letra]++;
    		col[j][letra]++;

    	}
   
    }


    fr(i,n){
    	fr(j,n){
    		if(col[i][j]!=1 || row[i][j]!=1) {
    			cout << "No" << endl;
    			return;
    		}
    	}
    }



    fr(i,n-1){

    	if( v[0][i] > v[0][i+1] ){
    		cout << "Not Reduced" << endl;
    		return;
    	}

    	if( v[i][0] > v[i+1][0] ){
    		cout << "Not Reduced" << endl;
    		return;	
    	}

    }

    cout << "Reduced" << endl;

}

int main(){

	while(cin >> n){
		solve();
	}

}

