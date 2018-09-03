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
#define pira cout << "pira" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

pii comp(pii a, pii b, pii c){

	pii aux;
	if(!(a.fst==b.fst && b.fst==c.fst) )
		return {-INF,INF};

	aux.fst=a.fst;
	aux.snd=a.snd+b.snd+c.snd;

	return aux;

}

pii comp2(pii a, pii b, pii c){

	if(a.snd!=b.snd)
		return {-INF,INF};

	pii aux;
	aux.snd=a.snd;
	aux.fst=a.fst+b.fst;

	if(aux.fst!=c.fst)
		return {-INF,INF};

	aux.snd=aux.snd+c.snd;

	return aux;

}



int main(){
    
	int x1,y1;
	int x2,y2;
	int x3,y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	vii a,b,c;
	a.pb( mp(x1,y1) );
	a.pb( mp(y1,x1) );

	b.pb( mp(x2,y2) );
	b.pb( mp(y2,x2) );
	
	c.pb( mp(x3,y3) );
	c.pb( mp(y3,x3) );


	fr(i,2){
		fr(j,2){
			fr(k,2){

				vii aux;
				aux.pb(a[i]);
				aux.pb(b[j]);
				aux.pb(c[k]);
				sort(all(aux));
				do{
					pii x=aux[0];
					pii y=aux[1];
					pii z=aux[2];

					pii aux = comp(x,y,z);
					pii aux2= comp2(x,y,z);
				
					if(aux.fst==aux.snd || aux2.fst==aux2.snd){
						cout << "YES" << endl;
						return 0;
					}	
				}while( next_permutation(all(aux)) ); 

			}
		}
	}


   

	cout << "NO" << endl;


}

