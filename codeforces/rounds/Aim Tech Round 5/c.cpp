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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

struct rect{
	int xb,yb,xu,yu;
};

rect v[133000];
rect acuml[133000];
rect acumr[133000];

rect inter(rect a, rect b){

	if(a.xb>b.xb)
		swap(a,b);

	rect aux;

	aux.xb=max(a.xb,b.xb);
	aux.yb=max(a.yb,b.yb);

	aux.xu=min(a.xu,b.xu);
	aux.yu=min(a.yu,b.yu);

	return aux;

}

bool check(rect a){

	if(a.xb>a.xu)
		return false;
	if(a.yb>a.yu)
		return false;
	return true;

}

rect nill(){
	rect aux;
	aux.xb=-INF;
	aux.yb=-INF;
	aux.xu=INF;
	aux.yu=INF;
	return aux;
}

int main(){
    
	int n;
	cin >> n;

	v[0]=nill();
	v[n+1]=nill();
	acuml[0]=nill();
	acumr[n+1]=nill();

	frr(i,n){
		int xb,yb,xu,yu;
		cin >> xb >> yb >> xu >> yu;
		rect aux;
		aux.xb=xb;
		aux.yb=yb;
		aux.xu=xu;
		aux.yu=yu;
		v[i]=aux;
	}

	frr(i,n)
		acuml[i]=inter(acuml[i-1],v[i]);
	for(int i=n;i>0;i--)
		acumr[i]=inter(acumr[i+1],v[i]);

	frr(i,n){
		rect aux=inter(acuml[i-1],acumr[i+1]);
		if(!check(aux))
			continue;
		else{
			cout << aux.xb << " " << aux.yb << endl;
			return 0;
		}

	}

}

