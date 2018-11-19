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
const ll llINF = 0x3f3f3f3f3f3f3f;

char v[11][11];

bool check(){


	bool ans = false;

	frr(i,10){		//checagem linhas
		frr(j,6){

			bool flag=true;

			for(int k=0;k<5;k++)
				if(v[i][j+k]!='X')
					flag=false;

			ans|=flag;

		}
	}


	frr(i,10){		//checagem colunas
		frr(j,6){

			bool flag=true;

			for(int k=0;k<5;k++)
				if(v[j+k][i]!='X')
					flag=false;

			ans|=flag;

		}
	}


	frr(i,6){		//chegagem diagonal <--
		frr(j,6){

			bool flag=true;

			for(int k=0;k<5;k++)
				if(v[i+k][j+k]!='X')
					flag=false;

			ans|=flag;

		}
	}

	for(int i=5;i<=10;i++){			//checagem diagonal -->
		for(int j=1;j<=6;j++){

			bool flag = true;

			for(int k=0;k<5;k++)
				if(v[i-k][j+k]!='X')
					flag=false;

			ans|=flag;

		}
	}

	return ans;

}

int main(){
    
	fastio;

	frr(i,10)
		frr(j,10)
			cin >> v[i][j];

	bool flag = false;

	frr(i,10){
		frr(j,10){
			
			if(v[i][j]!='.')	continue;

			v[i][j]='X';
			flag|=check();
			v[i][j]='.';

		}
	}

	cout << (flag ? "YES" : "NO") << endl;

}

