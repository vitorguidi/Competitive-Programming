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
#define pq priority_queue
#define grtp greater< pair<int,int> >

#define gnl cout << endl
#define olar cout << "olar" << endl
#define gottagofast ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

bool mysort(pii a, pii b){
	if(a.fst!=b.fst)
		return a.fst>b.fst;
	return a.snd<b.snd;
}

int main(){ 

    int n,taken[10100];
   	pii cows[10100];
    cin >> n;

    fr(i,n){
        int x,y;
        cin >> x >> y;
        cows[i]=mp(x,y);
    }

    sort(cows,cows+n,mysort);
    ms(taken,0);
    int sum=0;
    fr(i,n){
    	int d=cows[i].snd;
    	while(d){
    		if(taken[d]==0){
    			taken[d]++;
    			sum+=cows[i].fst;
    			break;
    		}
    		else
    			d--;
    	}
    }

    cout << sum << endl;

}
