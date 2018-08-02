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

int n,shop[110],pinc[110],memo[110][110];

int log2(int x){
	int mx=-1;
	int pwr=1;
	while(x%pwr==0){
		mx++;
		pwr=pwr*2;
	}
	return mx;
}

int pd(int ind, int last){

	if(ind==n)
		return 0;

	int &pdm=memo[ind][last];
	
	if(pdm!=-1)
		return pdm;

	if(shop[last]<shop[ind])
		pdm=max(pinc[ind]+pd(ind+1,ind),pd(ind+1,last));
	else
		pdm=pd(ind+1,last);
	return pdm;

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	

	int t;
	cin >> t;
	while(t--){
		cin >> n;
		fr(i,n){
			cin >> shop[i];
			pinc[i]=log2(shop[i]);
		}
		ms(memo,-1);
		pinc[105]=0;
		cout << pd(0,105) << endl;
	}

}