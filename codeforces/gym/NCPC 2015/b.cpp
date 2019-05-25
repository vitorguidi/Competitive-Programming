#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

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

string insere(string x, int pos){


    string ans;

    int ini=0;
    for(int i=0;i<=x.size();i++){
        if(i==pos)
            ans.pb(x.size()+1+'0');
        else
            ans.pb( x[ini++]);
    }

    return ans;

}

vector<string> solve(int n){
   
    if(n==1)    return {"1"};

    vector<string> ans = solve(n-1);

    vector<string> aux;

    int cnt = 1;
    for(auto x : ans){
        if(!cnt){
            fr(i,n){
                string lol = insere(x, i);
                aux.pb(lol);
            }
        }
        else{
            for(int i=n-1;i>=0;i--){
                string lol = insere(x,i);
                aux.pb(lol);
            }
        }
        cnt=!cnt;
    }

    ans.clear();
    return aux;

}

int main(){

    fastio;

    int n; cin >> n;
    vector<string> ans = solve(n);

    for(auto x : ans){
        for(auto y : x){
            cout << y << " ";
        }
        gnl;
    }
}