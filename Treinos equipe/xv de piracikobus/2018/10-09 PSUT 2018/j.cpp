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

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;


const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;

char teucu[2010][2010];
string s;

struct sq{
	int ll;
	int lr;
	int ld;
	int lu;
	int cnt;
};

sq cu[1010][1010];

void gen(int i, int j){

	sq &x = cu[i][j];

	x.ll+= teucu[2*i+1][2*j] == '|';
	
	x.lr+= teucu[2*i+1][2*j+2] == '|';
	
	x.ld+= teucu[2*i+2][2*j+1] == '-';
	
	x.lu+= teucu[2*i][2*j+1] == '-';
	
	x.cnt+=x.ll+x.lr+x.ld+x.lu;

}

int main(){

	fastio;

	int r,c; cin >> r >> c;
	getline(cin,s);

	queue<pii> fila;

	fr(i,2*r-1){
		getline(cin,s);
		fr(j,2*c-1)
			teucu[i][j]=s[j];
	}

	for(int i =0;i<r-1;i++){
		for(int j=0;j<c-1;j++){
			gen(i,j);
			if(cu[i][j].cnt==3)
				fila.push({i,j});
		}
	}

	int cnt = 0;

	while(!fila.empty()){

		pii cara = fila.front();
		fila.pop();
		
		cnt++;
		
		int i = cara.fst;
		int j = cara.snd;

		if(cu[i][j].cnt==4)
			continue;
		
		sq nego = cu[cara.fst][cara.snd];

		if(nego.ll==0){

			if(j-1>=0){
				cu[i][j-1].lr=1;
				cu[i][j-1].cnt++;
				if(cu[i][j-1].cnt==3)
					fila.push({i,j-1});
			}

			nego.ll=1;
			nego.cnt++;
		
		}


		else if(nego.lr==0){
		
			if(j+1<c-1){
				cu[i][j+1].ll=1;
				cu[i][j+1].cnt++;
				if(cu[i][j+1].cnt==3)			
					fila.push({i,j+1});
			}

			nego.lr=1;
			nego.cnt++;
		
		}


		else if(nego.ld==0){
			
			if(i+1<r-1){
				cu[i+1][j].lu=1;
				cu[i+1][j].cnt++;
				if(cu[i+1][j].cnt==3)
					fila.push({i+1,j});
			}

			nego.ld=1;
			nego.cnt++;
		}


		else if(nego.lu==0){

			if(i-1>=0){
				cu[i-1][j].ld=1;
				cu[i-1][j].cnt++;
				if(cu[i-1][j].cnt==3)		
					fila.push({i-1,j});
			}

			nego.lu=1;
			nego.cnt++;
		}


	}
		
	cout << cnt << endl;

}