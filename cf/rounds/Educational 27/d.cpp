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

int main(){
    
	fastio;

	int n; cin >> n;

	int cost=0;
	int over=0;
	int speed= 0;
	int speed_lim=INF;
	stack<int> lim;

	frr(i,n){

		int t; cin >> t;
	
		if(t==1){

			cin >> speed;

			while(speed>speed_lim){
				cost++;
				lim.pop();
				if(lim.empty())	speed_lim=INF;
				else			speed_lim=lim.top();
			}

		}

		if(t==2){
			cost+=over;
			over=0;
		}

		if(t==3){

			cin >>speed_lim;
			lim.push(speed_lim);

			while(speed>speed_lim){
				
				cost++;
				lim.pop();
				speed_lim= (!lim.empty() ? lim.top() : INF );

			}

		}

		if(t==4)
			over=0;
		
		if(t==5){
			while(!lim.empty())	lim.pop();
			speed_lim=INF;
		}
		

		if(t==6)
			over++;

	}

	cout << cost << endl;

}

