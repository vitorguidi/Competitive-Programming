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
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;

string genome = "ACTG";

int distance(char x, char y){

    int dist1 = 0;
    char aux = x;

    while(aux!=y){
        dist1++;
        aux++;
        if(aux>'Z')
            aux='A';
    }

    aux=x;
    int dist2=0;

    while(aux!=y){
        dist2++;
        aux--;
        if(aux<'A')
            aux='Z';
    }

    return min(dist1, dist2);

}

int main(){

	fastio;

    int n; cin >> n;
    string s; cin >> s;

    int best = INF;

    for(int i=0;i<=n-4;i++){

        int cost = 0;

        fr(j, 4){

            cost+=distance(s[i+j], genome[j]);

        }

        best=min(best, cost);

    }

    cout << best << endl;

}