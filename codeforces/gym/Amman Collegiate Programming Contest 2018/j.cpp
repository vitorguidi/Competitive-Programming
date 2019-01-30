#include<bits/stdc++.h>

using namespace std;

#define int long long
#define endl "\n"


int intersect(int a,int b, int c,int d){
	int com=max(a,c);
	int fim=min(b,d);	
	if(fim<com)return 0;
	return fim-com+1;
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		int a,b,v;
		cin>>a>>b>>v;
		int vold=v;
		int resp=0;
		for(int i=0;i<61;i++){
			if((v>>i)%2){
				v-=(1ll<<i);
				resp=max(resp,intersect(a,b,v,v+((1ll<<i)-1)));
			
			}
		}
		v=vold;
		resp=max(resp,intersect(a,b,0,(1ll<<(63-__builtin_clzll(v)))-1));
		//cout<<"resp eh "<<resp<<endl;
		int sizemax=1;
		int i=0;
		int num=v;
		while(true){
			if((num>>i)%2==0)break;
			else num-=(1ll<<i);
			sizemax*=2;
			i++;
		}
		int vzerado=num;
		//cout<<vzerado<<" "<<sizemax<<endl;
		//achar menor maior ou igual
		for(i=60;i>=0;i--){
			if((num>>i)%2==1 && num-(1ll<<i)>=a)num-=(1ll<<i);
		}
		resp=max(resp,intersect(a,b,num,num+sizemax-1));
		//cout<<"resp eh "<<resp<<endl;
		resp=max(resp,intersect(a,b,(num-1)&vzerado,((num-1)&vzerado)+sizemax-1));
		//cout<<"resp eh "<<resp<<endl;
		cout<<resp<<endl;
	}
}