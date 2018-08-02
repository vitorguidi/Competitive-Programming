#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define pq priority_queue
#define grtp greater<pair<int,int>>()
#define fr(i,n)	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

typedef pair<int,int> pii;
typedef vector<int,int> vi;
typedef long long int ll;

ll v[100100],acum[100100];

ll solve(ll x){

	ll cnt=0;
	ll atual=x;

	while(atual!=1){

		if(atual==1)	break;
				

		if(atual%2==0){
			atual=atual/2;
			cnt++;
			continue;
		}

		else{
			atual--;
			cnt++;
		}

	}

	return cnt;

}

int main(){

	int t,n,q;
	ll aux;

	scanf("%d",&t);

	for(int i=0;i<t;i++){

		cin >> n >> q;

		for(int j=1;j<=n;j++){
			scanf("%I64d",&aux);
			v[j]=solve(aux);
		}

		for(int j=1;j<=n;j++){
			acum[j]=acum[j-1]+v[j];
		}

		for(int j=0;j<q;j++){
			int x,y;
			scanf("%d %d",&x,&y);
			ll ans = acum[y]-acum[x-1];
			printf("%I64d\n",ans);
		}

	}

}