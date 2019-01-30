#include "bits/stdc++.h"
using namespace std;

int v[2020];

int main(){

	int t; cin >> t;
	while(t--){
	
		int n; cin >> n;
		
		for(int i=0;i<2*n;i++){
			cin >> v[i];
		}
		
		int ans= 0;
		
		for(int i=0;i<2*n;i++){
			ans=max(ans,v[i]+v[2*n-1-i]);
		}
		
		cout << ans << endl;
		
	}

}