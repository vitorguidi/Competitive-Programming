#include <bits/stdc++.h>
using namespace std;

int main(){
	int T,a,ct,m,i,num;
	float b;
	scanf("%d",&T);
	//printf("AA\n");
	for(;T>0;T--){
		ct=0;
		scanf("%d",&a);
		scanf("%f",&b);
		m=ceil(a*b);
		for(i=0;i<a;i++){
			scanf("%d",&num);
			if (num >=50)
				ct++;
		}
		if (ct>=m) 
			printf("YES\n");
		else
			printf("NO\n");
	}
	return(0);
}