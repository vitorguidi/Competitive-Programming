#include "bits/stdc++.h"
using namespace std;

int main(){

	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		cout << __builtin_popcount(n^(n-1)) << endl;
	}


}