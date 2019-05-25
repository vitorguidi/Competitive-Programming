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

map<int,int> id;
vii events;
int n,k;

int seg[1200100];
int lazy[1200100];

void unlazy(int node, int l, int r){

    seg[node]+=lazy[node];
    if(l!=r){
        lazy[2*node]+=lazy[node];
        lazy[2*node+1]+=lazy[node];
    }
    lazy[node]=0;

}

int query(int node, int l, int r, int a, int b){
    unlazy(node,l,r);
    if(l>b || r<a)  return 0;
    if(a<=l && r<=b)    return seg[node];
    int mid = (l+r)>>1;
    return max(query(2*node,l,mid,a,b), query(2*node+1,mid+1,r,a,b));

}

void update(int node, int l, int r, int a, int b){

    unlazy(node,l,r);
    if(l>b || r<a)  return;
    if(a<=l && r<=b){
        lazy[node]++;
        unlazy(node,l,r);
        return;
    }
    int mid = (l+r)>>1;
    update(2*node,l,mid,a,b);
    update(2*node+1,mid+1,r,a,b);
    seg[node]=max(seg[2*node],seg[2*node+1]);
}

int main(){

    fastio;


    cin >> n >> k;  

    set<int> comprime;
    for(int i=0;i<n;i++){
        int ini, end;
        cin >> ini >> end;
        comprime.insert(ini);
        comprime.insert(end);
        comprime.insert(end-1);
        events.pb({end-1,ini});  //talvez desempate de inicio seja importante -> nop
    }

    sort(all(events));

    int cnt = 0;

    for(auto x : comprime)
        id[x]=++cnt;


    fr(i,n){
        events[i].fst = id[events[i].fst];
        events[i].snd = id[events[i].snd];
    }

    int ans = 0;

    for(auto x : events){

        int ini = x.snd;
        int end = x.fst;

        int frente = query(1,1,3*n,ini,end);

        if(frente<k){
            ans++;
            update(1,1,3*n,ini,end);
        }

    }

    cout << ans << endl;

}