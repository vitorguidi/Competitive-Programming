#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define INF 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define fi first
#define dbg(x) cout << #x << " = " << x << endl
#define se second
#define fst first
#define snd second
#define fastcin ios_base::sync_with_stdio(false);
#define ll long long
#define endl "\n"
#define MAX

int grundy[100][100];
int clk=1;

void solve(){

	int k,n; cin >> n >> k;
	cout << "Case " << clk++ << ": " << (grundy[n][k]==0 ? "Losing" : "Winning") << endl;

}

int main()
{	
	fastcin;

	for(int k=1;k<=50;k++){			//para cada k possivel

	
		for(int i = 0;i<k;i++)		//inicializo o grundy das jogadas invalidas pra zero
			grundy[i][k]=0;

		for(int i=k;i<=50;i++){		//i = grundy q qro calcular

			set<int> mex;

			for(int j=0;j<=i-k;j++){
				//cout << j << " - " << i-k-j << endl;
				int aux = grundy[j][k]^grundy[i-k-j][k];
				mex.insert(aux);
			}

			for(int j=0;j<100;j++){
				if(mex.find(j)==mex.end()){
					grundy[i][k]=j;
					break;
				}
			}


		}


	}

	// for(int i=0;i<=5;i++)
	// 	cout << i << " - " << (grundy[i][2]) << endl;

	int t; cin >> t;
	while(t--)	solve();

}