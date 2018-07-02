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

int v[100100];

int bins(int x,int ini, int end){
	if(ini>end || v[end]<x || v[ini]>x)
		return -1;
	int mid=(ini+end)/2;
	if(v[mid]<x)
		return bins(x,mid+1,end);
	else if(v[mid]>x)
		return bins(x,ini,mid-1);
	else
		return mid;
}

int main(){ 

	int n,s;
	cin >> n;
	fr(i,n)
		cin >> v[i];
	cin >> s;
	fr(i,n){
		int ans=bins(s-v[i],0,n-1);
		if(ans!=-1){
			cout << v[i] << ' ' << v[ans] << endl;
			return 0;
		}
	}

}
