#include <iostream>
using namespace std;
 
int main(){
 
	int n,size;
	int i,j;
 
	cin >> n;
 
	for (i=0;i<n;i++){
		cin >> size;
 
		if(size%2==1){
			cout << -1 << endl;
			continue;
		}
 
		for(j=1;j<=size/2;j++){
			cout << (2*j) << " " << (2*j)-1;
			if(j!=size/2)	cout << " ";
		}
 
		cout << endl;
	}
 
	return 0;
 
}	