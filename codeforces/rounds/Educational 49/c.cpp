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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int v[10100];

double calc(int a, int b){
	double x = (double)a;
	double y = (double)b;
	return pow(x+y,2)/(x*y);
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--){

    	int x; cin >> x;
    	ms(v,0);

    	vi aux; int cnt=0;

    	fr(i,x){
    		int val; cin >> val;
    		v[val]++;
    		if(v[val]==2){
    			aux.pb(val);
    			v[val]=0;
    			cnt++;
    		}

    	}

    	sort(all(aux));

    	double dist = 1e20;
    	int a,b;

    	int len = aux.size();
    	
    	for(int i=0;i<len-1;i++){
    	
    		double aux2 = calc(aux[i],aux[i+1]);

    		if(aux2<dist){
    			a=aux[i];
    			b=aux[i+1];
    			dist=aux2;
    		}
    	}

    	cout << a << " " << a << " " << b << " " << b << endl;
    }

}

