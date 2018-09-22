#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;

ll c[1010];

int main(){
	
	int t; cin >> t;
	
	while(t--){
		
		ll x,n; cin >> x >> n;
		
		for(int i=0;i<n;i++)
			c[i]=0;
			
		if(n==1){
			cout << x << endl;
			continue;
		}
		
		ll f = x/(2*n-2);
		
		for(int i=1;i<n-1;i++)
			c[i]+=f;
			
		for(int i=n-1;i>=0;i--)
			c[i]+=f;
			
		x = x%(2*n-2);
		
		for(int i=0;i<n-1;i++){
			if(x){
				x--;
				c[i]++;
			}
		}
		
		for(int i=n-1;i>=0;i--){
			if(x){
				x--;
				c[i]++;
			}
		}
		
		for(int i=0;i<n;i++)
			cout << c[i] << " ";

		cout << endl;
				
	}

}