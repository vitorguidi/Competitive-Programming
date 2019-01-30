#include "bits/stdc++.h"
using namespace std;

int main(){

	int t; cin >> t;
	while(t--){
		int x,n; cin >> x >> n;
		int amt = x%n;
		int resto = x - amt;
		
		if(x<n){
			cout << -1 << endl;
			continue;
		}
		
		for(int i=0;i<n-amt;i++)
			cout << x/n << " ";
		for(int i=0;i<amt;i++)
			cout << x/n + 1 << " ";
		cout << endl;
	}

}