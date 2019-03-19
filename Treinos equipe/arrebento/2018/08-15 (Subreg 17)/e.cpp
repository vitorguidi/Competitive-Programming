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

int freq[12];
int scales[12][12];
int jumps[8] = {0,2,4,5,7,9,11,12};

void build(){

	fr(i,12){

		fr(j,8){
			int next = (i+jumps[j])%12;
			scales[i][next]=1;
		}

	}

}

int check(int x){

	fr(i,12)
		if(!scales[x][i] && freq[i])
			return false;
	
	return true;

}

int main(){
    
    int n; cin >> n;
    map<int,string> notas = { {0,"do"},{1,"do#"},{2,"re"},{3,"re#"},{4,"mi"},{5,"fa"},{6,"fa#"},{7,"sol"},{8,"sol#"},{9,"la"},{10,"la#"},{11,"si"} };

    fr(i,n){
    	int aux; cin >> aux;
    	aux--;aux=aux%12;
    	freq[aux]++;
    }

    build();

    int ans = -1;

    fr(i,12){
    	if(check(i)){
    		ans=i;
    		break;
    	}
    }

    if(ans==-1)
    	puts("desafinado");
    else
    	cout << notas[ans] << endl;
}

