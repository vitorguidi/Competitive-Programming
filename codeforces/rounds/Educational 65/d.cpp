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

int color[200200];

int main(){

	fastio;

	int n; cin >> n;
    string s; cin >> s;

    stack<char> q;

    int dpt=0;

    int prof = 0;
    for(auto x : s){
        if(x=='('){
            prof++;
            q.push(x);
            dpt=max(dpt,prof);
        }
        else{
            prof--;
            q.pop();
        }
    }

    int optimal = (dpt+1)/2;

    prof=0;

    for(int i=0;i<n;i++){
        char x = s[i];
        if(x=='('){
            prof++;
            if(prof>optimal){
                color[i]=1;
            }
            q.push(x);
        }
        else{
            if(prof>optimal){
                color[i]=1;
            }
            q.pop();
            prof--;
        }
    }    

    fr(i,n)
        cout << color[i];
    gnl;

}