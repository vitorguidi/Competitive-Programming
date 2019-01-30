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
    vi va,vb;

    fr(i,n){
    	int aux; cin >> aux;
    	va.pb(aux);
    }
    fr(i,n){
    	int aux;cin >> aux;
    	vb.pb(aux);
    }

    sort(all(va));
    sort(all(vb));

    ll sa=0;
    ll sb=0;
    int sza=n;
    int szb=n;

    int turn=0;

    while(sza+szb){

   
   		int topa;
   		if(sza)
   			topa=va[sza-1];
   		int topb;
   		if(szb)
   			topb=vb[szb-1];

    	if(turn==0){
    		if(sza==0)
    			szb--;
    		else if(szb==0){
    			sza--;
    			sa+=topa;
    		}
    		else{ //tem coisa em ambos
    			if(topa>=topb){
    				sza--;
    				sa+=topa;
    			}
    			else
    				szb--;
    		}
    	}
    	else{
    		if(sza==0){
    			szb--;
    			sb+=topb;
    		}
    		else if(szb==0)
    			sza--;
    		else{ //tem coisa em ambos
    			if(topa>=topb)
    				sza--;
    			else{
    				szb--;
    				sb+=topb;
    			}
    		}
    	}
    	turn=(turn+1)%2;
    }

    cout << sa - sb << endl;

}

