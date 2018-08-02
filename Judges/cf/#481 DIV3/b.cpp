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
    
        int n;
    string s;

    cin >> n;
    getchar();
    getline(cin,s);

    int ans=0;
    int cnt=0;

    int i=0;
    while(i<=n){
        if(i==n){
            ans+=max(cnt-2,0);
            break;
        }
        if(s[i]=='x')   cnt++;
        else{
            ans+=max(cnt-2,0);
            cnt=0;
        }
        i++;
    }

    cout << ans << endl;

}

