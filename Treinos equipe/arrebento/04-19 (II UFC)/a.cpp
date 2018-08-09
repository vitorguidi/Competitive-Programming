	#include <bits/stdc++.h>
	using namespace std;	

	long long int mdc(long long int a, long long int b){
		if(b==0)	return a;
		return mdc(b,a%b);
	}

	int main(){

	int t;
	long long int a,b,c;

	cin >> t;	

	for(int i=0;i<t;i++){
		cin >> a >> b;
		if(mdc(a,b)!=1)		cout << "Sim" << endl;
		else				cout << "Nao" << endl;
	}

	return 0;
}
