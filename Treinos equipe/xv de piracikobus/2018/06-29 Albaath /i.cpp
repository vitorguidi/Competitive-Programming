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
#define pira cout << "XV de piracikobus" << endl

typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int n,k,holes[112345];

bool boo (int l){
	int ct = 0;
	int ini=0,end=0;
	while (ini<n && end<n){
		while(holes[end+1]-holes[ini] + 1<=l && end+1<n)
			end++;
		ct++;
		ini=end+1;
		end++;
	}
	if(ct<=k)
		return true;
	return false;

}

int bb (int ini,int fim){
	if (ini>fim)
		return (INF);
	int meio = (ini+fim)/2;
	int best;
	if (boo(meio)){
		//dbg(meio);
		best = min(meio,(bb(ini,meio-1)));
	}
	else
		return(bb(meio+1,fim));
	return (best);
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){

		cin >> n >> k;
		
		fr(i,n){
			cin >> holes[i];
		}

		cout << bb (1,holes[n-1]) << endl;
	}

	return (0);



}