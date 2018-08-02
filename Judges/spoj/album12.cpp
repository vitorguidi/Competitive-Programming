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

	int x,y;
	int l1,h1,l2,h2;
	cin >> x >> y >> l1 >> h1 >> l2 >> h2;

	if(max(l1,l2)<=x && h1+h2<=y)
		cout << 'S' << endl;
	else if(max(l1,l2)<=y && h1+h2<=x)
		cout << 'S' << endl;
	else if(max(l1,h2)<=x && l2+h1<=y)
		cout << 'S' << endl;
	else if(max(l1,h2)<=y && l2+h1<=x)
		cout << 'S' << endl;
	else if(max(l2,h1)<=y && l1+h2<=x)
		cout << 'S' << endl;
	else if(max(l2,h1)<=x && l1+h2<=y)
		cout << 'S' << endl;
	else if(max(h1,h2)<=x && l1+l2<=y)
		cout << 'S' << endl;
	else if(max(h1,h2)<=y && l1+l2<=x)
		cout << 'S' << endl;

	else if(l1+l2<=x && max(h1,h2)<=y)
		cout << 'S' << endl;
	else if(l1+l2<=y && max(h1,h2)<=x)
		cout << "S" << endl;
	else if(h1+l2<=x && max(l1,h2)<=y)
		cout << "S" << endl;
	else if(h1+l2<=y && max(l1,h2)<=x)
		cout << 'S' << endl;
	else if(h2+l1<=x && max(l2,h1)<=y)
		cout << 'S' << endl;
	else if(h2+l1<=y && max(l2,h1)<=x)
		cout << 'S' << endl;
	else if(h1+h2<=x && max(l1,l2)<=y)
		cout << 'S' << endl;
	else if(h1+h2<=y && max(l1,l2)<=x)
		cout << 'S' << endl; 

	else
		cout << 'N' << endl;
	
}

