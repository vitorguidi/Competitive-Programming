#include<bits/stdc++.h> 
using namespace std; 

int main(){

	int T,n,a,b,i;
	long long sum;
	map<int,int> m;
	int v[112345];

	scanf("%d",&T);

	for (;T>0;T--){
		m.clear();
		sum = 0;
		scanf("%d",&n);
		for (i=0;i<n;i++){
			scanf("%d",&a);
			scanf ("%d",&b);
			m[a]++;
			v[i]=b;
		}

		for (i=0;i<n;i++){
			sum += m[v[i]];
		}

		printf ("%I64d\n",sum);

	}

	return 0;
}