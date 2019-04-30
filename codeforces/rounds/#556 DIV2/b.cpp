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

int n;
int grid[55][55];

bool valid_cell(int x, int y){
    return x>0 && x<=n && y>0 && y<=n && grid[x][y]==0;
}

bool valid_pos(int x, int y){

    if (!valid_cell(x,y)) return false;
    if (!valid_cell(x+1,y))   return false;
    if (!valid_cell(x+2,y)) return false;
    if(!valid_cell(x+1,y-1))    return false;
    if(!valid_cell(x+1,y+1))    return false;
    return true;

}

void pinta(int x, int y){

    grid[x][y]=1;
    grid[x+1][y]=1;
    grid[x+2][y]=1;
    grid[x+1][y-1]=1;
    grid[x+1][y+1]=1;

}

int main(){

	fastio;

    cin >> n;

    string s; getline(cin,s);

    frr(i,n){
        getline(cin,s);
        frr(j,n)
            grid[i][j] = (s[j-1] == '#' ? 1 : 0);
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(valid_pos(i,j))  pinta(i,j);
        }
    }

    frr(i,n){
        frr(j,n){
            if(!grid[i][j]){
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;

}