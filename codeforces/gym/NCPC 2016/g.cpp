#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n) for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) x.begin(),x.end()

#define gnl cout << endl
#define olar cout << olar << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;

int up[30];

int main(){

    fastio;
    
    string s; cin >> s;
    
    for(int i=21;i<=25;i++)
        up[i]=2;
    for(int i=16;i<=20;i++)
        up[i]=3;
    for(int i=11;i<=15;i++)
        up[i]=4;
    for(int i=1;i<=10;i++)
        up[i]=5;
        
    int stars=0;
    int rank =25;
    int streak=0;
        
    for(auto x : s){
    
        if(!rank)   break;
        
        if(x=='L'){     
        
            streak=0;   
                
            if(rank>20)
                continue;
                        
            stars-=1;   
                    
            if(stars<0){            
                if(rank==25)
                    stars=0;
                else if(rank<20){
                    rank++;
                    stars+=up[rank];
                }
                else
                    stars=0;    
            }   
                    
        }
    
        else{
            stars++;
            streak++;       
            if(streak>2 && rank>=6 && rank<=25)
                stars++;            
            if(stars>up[rank]){
                stars-=up[rank];
                rank--;
            }
        }   
    }
    
    if(!rank)
        cout << "Legend" << endl;
    else
        cout << rank << endl;
    

}