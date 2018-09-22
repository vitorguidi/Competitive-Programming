#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		cout<<min((m/2)*((n+2)/2)+((n+1)/2)*((m+1)/2),((m+2)/2)*(n/2)+((n+1)/2)*((m+1)/2))<<endl;		
	}

}