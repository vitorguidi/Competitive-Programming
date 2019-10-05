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

#define endl "\n" 
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 
 
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;
 
const int INF = 0x3f3f3f3f;

bool eval[30];

int main(){

    //olar;

    int n; cin >> n;

    fr(i,n){
        char x; cin >> x;
        eval[i]= (x=='F' ? false : true);
    }
    stack<char> ops;
	//oi Guidi
    char x;
    while(cin >> x){
        //dbg(x);
        if(x=='*' || x=='+'){
            char c1 = ops.top();ops.pop();
            char c2 = ops.top();ops.pop();


            bool val1 = (c1 == 'T' ? true : false);
            bool val2 = (c2 == 'T' ? true : false);
            bool result = false;
            if(x=='*')  result = val1&val2;
            else        result = val1|val2;
            
            // dbg(x);
            // dbg(val1);
            // dbg(val2);
            // dbg(result);
            // cout << "###" << endl;

            ops.push( (result ? 'T' : 'F') );
        }
        else if(x=='-'){
            char c1 = ops.top();ops.pop();
            bool val = (c1 == 'T' ? true : false);
            val = !val;
            // dbg(x);
            // dbg(c1);
            // dbg(val);
            //cout << "###" << endl;
            ops.push( (val ? 'T' : 'F') );
        }
        else{
            bool val = eval[x-'A'];
            ops.push( (val ? 'T' : 'F') );
            //cout << "inserting" << x << endl;
        }
    }

    char ans = ops.top();
    cout << ans << endl;
 
}