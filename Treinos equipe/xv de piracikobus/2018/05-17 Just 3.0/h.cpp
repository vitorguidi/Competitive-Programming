#include<bits/stdc++.h> 
using namespace std; 
long long a,b,c,d,n; 

int main(){
	
	cin>>n; 
	while(n>0){
		cin>>a>>b>>c>>d; 
		if(log(a)*b<log(c)*d) 
			cout<<"<"<<endl; 
		else 
			cout<<">"<<endl;
		n--;
	}
	return 0;
}