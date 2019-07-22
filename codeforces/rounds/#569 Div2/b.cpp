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


ll v[100100];

ll troca(ll x){
    return -x-1ll;
}

int main(){

	fastio;

    int n;
    cin >> n;

    frr(i,n)
        cin >> v[i];

    frr(i,n)
        if(v[i]>=0)
            v[i]=troca(v[i]);

    if(n%2==0){
        frr(i,n)
            cout << v[i] << " ";
        gnl;
        return 0;
    }

    int mn = INF;
    int ind = -1;

    frr(i,n)
        if(v[i]<mn){
            mn=v[i];
            ind=i;
        }

    v[ind]=troca(v[ind]);

    frr(i,n)
        cout << v[i] << " ";
    gnl;

}