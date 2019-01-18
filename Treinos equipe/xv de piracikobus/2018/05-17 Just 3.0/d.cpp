#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define pq priority_queue
#define grtp greater< pair<int,int> >
#define gnl cout << endl
#define olar cout << "olar" << endl

const int INF = 0x3f3f3f3f;

int memo[7][10010];


int pd(int ind, int sum){

	if(sum==0)	return 0;
	if(sum<0)	return INF;

	int &pdm = memo[ind][sum];

	if(pdm!=-1)	return pdm;

	int ans=INF;

	for(int i=1;i<=6;i++){

		if(i==7-ind || i==ind)	continue;
		ans=min(ans,1+pd(i,sum-i));
	
	}

	return pdm=ans;
}

int main(){
	
	int t,sum;
	cin >> t;

	ms(memo,-1);

	for(int i=0;i<t;i++){
		cin >> sum;
		int ans = pd(1,sum);
		if(ans!=INF)	cout << ans << endl;
		else			cout << -1 << endl;	
	}





}