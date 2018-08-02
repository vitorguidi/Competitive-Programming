#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define pq priority_queue
#define grtp greater< pair<int,int> >

#define gnl cout << endl
#define olar cout << "olar" << endl

typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int main(){
    
    int k;
    vi seq[200200];
    vector< pair<int,pii> > ans;
    cin>>k;

    frr(i,k){
    
        int n;
        int sum=0;
        cin>>n;
        
        fr(j,n){
            int aux;
            cin >> aux;
            sum+=aux;
            seq[i].pb(aux);
        }

    
        fr(j,n){
            seq[i][j]=sum-seq[i][j];
            pair<int,pii> aux;
            aux.fst=seq[i][j];
            aux.snd=mp(i,j+1);
            ans.pb(aux);
        }
                
    }

    sort(ans.begin(),ans.end());
    
    if(ans.size()==0 || ans.size()==1){
        cout << "NO" << endl;
        return 0;
    }

    fr(i,ans.size()-1){
        if(ans[i].fst==ans[i+1].fst && (ans[i].snd).fst!=(ans[i+1].snd).fst ){
            cout << "YES" << endl;
            cout << (ans[i].snd).fst << " " << (ans[i].snd).snd << endl;
            cout << (ans[i+1].snd).fst << " " << (ans[i+1].snd).snd << endl;
            return 0;
       }
    }

    cout << "NO" << endl;

}

