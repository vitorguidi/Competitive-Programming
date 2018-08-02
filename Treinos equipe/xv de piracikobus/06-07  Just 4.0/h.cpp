#include <bits/stdc++.h>
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

int t,n,m,mat[55][55];
int total,borda;

int main(){

    cin >> t;

    while(t--){

        cin >> n >> m;
        
        getchar();
        total=borda=0;

        fr(i,n){
            string s;
            getline(cin,s);
            fr(j,s.size()){
                mat[i][j]=s[j]-'0';
                if(mat[i][j]==1)  total++;
            }
        }

        fr(i,m) borda+=mat[0][i];
        fr(i,m) borda+=mat[n-1][i];
        fr(i,n) borda+=mat[i][0];
        fr(i,n) borda+=mat[i][m-1];


        if(mat[0][0])       borda--;
        if(mat[0][m-1])     borda--;
        if(mat[n-1][0])     borda--;
        if(mat[n-1][m-1])   borda--;

        if(total<2*m+2*n-4){
            cout << -1 << endl;
            continue;
        }

        cout << 2*m+2*n-4 -borda << endl;   

    }        
}
