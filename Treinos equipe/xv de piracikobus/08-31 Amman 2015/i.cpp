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
#define olar cout << "pira" << endl

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int val[255];
int aux[255];

int main(){
	    
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	

	int t; cin >> t;
	string s;
	getline(cin,s);

	while(t--){

		getline(cin,s);
		
		int len = s.size();
		int ans=1;

		for(int k=2;k<=len;k++){	//bruta os k n triviais

			fr(d,10){

				fr(i,len)				//reseta vetor
					val[i]=s[i]-'0';

				ms(aux,0);

				int soma=0;

				fr(i,len-k+1){			//itera em todas as posicoes iniciais
					
					soma+=aux[i];
					val[i]+=soma;
					if(val[i]<0)
						val[i]+=10;
					val[i]%=10;
					
					int amt=10+d-val[i];	// faz oq precisar pra setar ela pra d
					val[i]+=amt;
					val[i]%=10;
					
					aux[i+1]+=amt;		//lazy update
					aux[i+k]-=amt;

				}

				for(int i=len-k+1;i<len;i++){
					soma+=aux[i];
					val[i]+=soma;
					if(val[i]<0)
						val[i]+=10;
					val[i]%=10;
				}
				

				// fr(i,len)
				// 	cout << val[i] << ' ';
				// gnl;

				int cnt=0;
				fr(i,len)
					if(val[i]==d)
						cnt++;

				if(cnt==len)
					ans=k;

			}

		}

		cout << ans << endl;

	}

}