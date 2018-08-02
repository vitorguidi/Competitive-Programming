#include<bits/stdc++.h> 
using namespace std; 
int main(){
	int t,y,x;

	cin >> t;
	
	for(int i=0;i<t;i++){
		cin >> y >> x;
		cout << ( (100*y) / (x+100) ) << endl;
	}

	
}