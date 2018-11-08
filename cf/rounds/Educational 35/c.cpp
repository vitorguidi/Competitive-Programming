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
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int main(){
    
    int a,b,c;
    cin >> a >> b >> c;

    vi x = {a,b,c};

    sort(all(x));

    if(x[0]==1)
    	puts("YES");

    else if(x[0]==2)
    	cout << (x[1]==2 || (x[1]==4 && x[2]==4) ? "YES" : "NO") << endl;
    
    else if(x[0]==3)
    	if(x[1]==3 && x[2]==3)
    		puts("YES");
    	else
    		puts("NO");
    

    else
    	puts("NO");

}

