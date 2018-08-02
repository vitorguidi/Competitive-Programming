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

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	

	int t;
	cin >> t;
	while(t--){
		int h,w,d;
		cin >> h >> w >> d;
		int k,q;
		k = (h-1)%(w-1);
		q = (h-1)/(w-1);

		if(w>=h){
			if(d==h)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
			continue;
		}

		if(q%2==0 && k+1==d)
			cout << "Yes" << endl;
		else if(q%2==1 && w-k==d)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;

	}

	return (0);

}