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

	int T,ct1,ct2;
	char ma[200][200];
	cin >> T;
	while(T--){
		int m,n,I;
		cin >> n;
		cin >> m;
		cin >> I;
		fr(i,n){
			fr(j,m)
				ma[i][j] = '.';
		}
		fr(i,I){
			char au;
			int a,b,c,d;
			cin >> a >> b >> c >> d;
			a--;b--;c--;d--;
			//cin >> au;
			cin >> au;
			for (ct1=a;ct1<=c;ct1++){
				for (ct2 = b;ct2 <= d;ct2++){
					ma[ct1][ct2] = au;
				}
			}
		}
		fr(i,n){
			fr(j,m)
				cout << ma[i][j];
			cout << endl;
		}
	}

}