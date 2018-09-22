#include<bits/stdc++.h>

using namespace std;

int maxi;
int cr[1123456];
int v[112345];


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>v[i];
			maxi=max(maxi,v[i]);
		}
		sort(v,v+n);
		for(int i=0;i<n;i++){
			if(cr[v[i]]!=0)v[i]=cr[v[i]];
			else{
				for(int j=v[i];j<maxi+1;j+=v[i]){
					if(cr[j]==0)cr[j]=v[i];
				}
			}
		}
		long long num=0;
		for(int i=0;i<n;i++)num+=v[i];
		cout<<num<<endl;
		for(int i=0;i<=maxi;i++)cr[i]=0;
		maxi=0;
	
	}

}