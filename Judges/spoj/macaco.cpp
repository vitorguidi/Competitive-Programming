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

int main(){

	int n,cnt=0;

	while(true){
		cin >> n;
		if(!n)
			break;
		cnt++;
		cout << "Teste " << cnt << endl;
		int x1=-INF,y1=INF,x2=INF,y2=-INF;
		int flag=0;
		
		fr(i,n){
			int a,b,c,d;
			cin >> a >> b >> c >> d;
			if(x1>=c || y1<=d || x2<=a || y2>=b){
				flag=1;
			}
			x1=max(x1,a);
			x2=min(x2,c);
			y1=min(b,y1);
			y2=max(y2,d);

		}

		if(flag || !n)
			cout << "nenhum" << endl << endl;
		else
			cout << x1 << " " <<  y1 << " " << x2 << " " << y2 << endl << endl;
	}
}
	


