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

int mdc(int a, int b){
	return a%b==0 ? b : mdc(b,a%b);
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	

	int n,t, v[1000100];
	cin >> t;
	while(t--){
		cin >> n;
		int sum=0;
		fr(i,n){
			cin >> v[i];
			sum+=v[i];
		}
		if(n==1){
			cout << v[0] << " " << 1 << endl;
			continue;
		}
		int x=mdc(v[0],v[1]);
		for(int i=2;i<n;i++){
			x=mdc(v[i],x);
		}
		cout << x << " " << sum/x << endl;
	}

	return (0);

}