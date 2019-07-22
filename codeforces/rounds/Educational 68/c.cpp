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

string s,t,p;
int memo[110][110];

int pd(int l, int r){

    if(l==s.size() || r  == t.size())
        return 0;

    int &pdm = memo[l][r];
    if(pdm!=-1)
        return pdm;

    pdm=0;

    if(s[l]==t[r]){
        pdm=pd(l+1,r+1)+1;
    }

    pdm=max({pdm,pd(l+1,r),pd(l,r+1)});

    return pdm;

}

void go(){

    cin >> s >> t >> p;

    ms(memo,-1);

    int aux = pd(0,0);
    if(aux!=s.size()){
        cout << "NO" << endl;
        return;
    }

    int cnts[26],cntt[26];
    ms(cnts,0);
    ms(cntt,0);

    for(auto x : s)
        cnts[x-'a']++;
    for(auto x : p)
        cnts[x-'a']++;
    for(auto x : t)
        cntt[x-'a']++;

    bool flag=true;

    fr(i,26)
        if(cnts[i]<cntt[i])
            flag=false;

    cout << (flag ? "YES" : "NO" ) << endl;

}

int main(){

	fastio;

	int q;cin >> q;
    while(q--)
        go();

}