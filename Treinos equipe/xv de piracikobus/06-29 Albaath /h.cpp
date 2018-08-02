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

map<int,int> posid; 
map<int,int> posir;



int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	int t,n,d,r,ok,pd,pr,tempo; 
	cin>>t; 
	while(t--){
		cin>>n>>d>>r; 
		posid.clear(); 
		posir.clear(); 
		pd=pr=tempo=ok=0; 
		while(!ok){ 
			tempo++;
			pd= (pd+d)%n; 
			pr= (pr+r)%n; 
			
			posid[pd]=1; 
			posir[pr]=1;


			if(posir[pd]) 
				ok=1; 
					
			if(posid[pr]) 
				ok=1;
		} 
		cout<<tempo<<endl;
	}	

}