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
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

long double mmm(long double a, long double b){
	if(a<b)
		return a; 
	return b;

}

int main(){
	
	cout<<setprecision(2)<<fixed;
	fastio;
	int n;
	long double l,h,ans; 
	
	while(cin>>n>>l>>h){
		
		ans=2*max(l,h); 

		long double b1,b2,a2,y1,y2,x2;//pontos
		
		long double m,k,c,aux; //reta;

		cin>>b1>>a2>>b2;

		frr(i,n){
			
			if(i==n){
				if(i%2)
					ans=mmm(ans,fabs(l-a2)); 
				else
					ans=mmm(ans,fabs(a2)); 
			}
			
			else{
				cin>>y1>>x2>>y2;

				if(i%2){
					ans=mmm(ans,fabs(l-a2)); //parede
					m=y2-y1; //reta
					k=l-x2; 
					c=m*x2+k*y2; 
					c*=-1; 
					
					aux=fabs(a2*m+b2*k+c); 
					aux/=hypot(m,k);

					ans=mmm(ans,aux);

				}
				else{
					ans=mmm(ans,fabs(a2));
					m=y1-y2; 
					k=x2; 
					c=-y1*x2;
					
					aux=fabs(a2*m+b2*k+c); 
					aux/=hypot(m,k);

					ans=mmm(ans,aux);
				}
				//dbg(aux);
				a2=x2; b1=y1; b2=y2;
			}

		}

		cout<<ans<<endl;		
	}

}
