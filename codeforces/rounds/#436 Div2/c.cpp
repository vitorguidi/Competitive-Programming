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
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;

ll a,b,f,k;

bool check(int x){

	int fuel = b;

	int solo = k/2;

	for(int i=1;i<=solo;i++){

		if(fuel<f)	return false;		//ida ate f
		fuel-=f;

		if(fuel>=2*abs(a-f))	fuel-=2*abs(a-f);		//de f ate a, de a ate f de novo
		else{
			x--;
			fuel=b;
			fuel-=2*abs(a-f);
			if(fuel<0)	return false;
		}

		if(i<solo || (i==solo && k%2)){		//de f ate a, e ainda devo ter o suficiente pra voltar ate f

			if(fuel>=2*f)	fuel-=f;
			else{
				x--;
				fuel=b;
				fuel-=f;
				if(fuel<0)	return false;
			}

		}

		else{							//de f ate a, no caso que eu paro no a

			if(fuel>=f)	fuel-=f;
			else{
				x--;
				fuel=b;
				fuel-=f;
				if(fuel<0)	return false;
			}

		}

	}

	if(k%2){

		if(fuel<f)	return false;
		fuel-=f;

		if(fuel>=abs(a-f))	fuel-=abs(a-f);
		else{
			x--;
			fuel=b;
			fuel-=abs(a-f);
			if(fuel<0)	return false;
		}


	}

	return x>=0;

}

int main(){
    
	fastio;

	cin >> a >> b >> f >> k;

	int ini=0;
	int end = k;
	int best=INF;

	while(ini<=end){
		int mid = (ini+end)>>1;
		if(check(mid)){
			best=mid;
			end=mid-1;
		}
		else	ini=mid+1;
	}	

	cout << (best==INF ? -1 : best) << endl;

}