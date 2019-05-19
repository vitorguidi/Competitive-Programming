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

int main(){

	fastio;

    vi repo = {4,8,15,16,23,42};

    cout << "? 1 2" << endl;
    fflush(stdout);
    int r1; cin >> r1;

    cout << "? 1 3" << endl;	
    fflush(stdout);
    int r2; cin >> r2;


    int pos1 = -1;
    int pos2 = -1;
    int pos3 = -1;

    fr(i,6){
        fr(j,6){
            if(i==j)
                continue;
            fr(k,6){
                if(i==k |j==k)
                    continue;
                if(repo[i]*repo[j]==r1 && repo[i]*repo[k]==r2){
                    pos1=repo[i];
                    pos2=repo[j];
                    pos3=repo[k];
                }
            }
        }
    }

    cout << "? 4 5" << endl;
    fflush(stdout);
    cin >> r1;

    cout << "? 4 6" << endl;    
    fflush(stdout);
    cin >> r2;

    int pos4 = -1;
    int pos5 = -1;
    int pos6 = -1;

    fr(i,6){
        fr(j,6){
            if(i==j)
                continue;
            fr(k,6){
                if(i==k |j==k)
                    continue;
                if(repo[i]*repo[j]==r1 && repo[i]*repo[k]==r2){
                    pos4=repo[i];
                    pos5=repo[j];
                    pos6=repo[k];
                }
            }
        }
    }

    cout << "! " << pos1 << " " << pos2 << " " << pos3 << " " << pos4 << " " << pos5 << " " << pos6 << endl;
}