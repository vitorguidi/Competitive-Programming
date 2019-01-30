#include <bits/stdc++.h>
using namespace std;

char field[100][100];
int okv[100][100],okh[100][100], sum[100][100];

int main(){

	int n,k,s;

	cin >> n >> s;

	for (int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> field[i][j];
		}
		getchar();
	}
 
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			
			int cnt=0;		//verifica se da pra posicionar na horizontal com o rabo do navio na casa atual
			
			for(int k=0;k<s;k++){
				if(j+k>=n || field[i][j+k]=='#')	break;
				else	cnt++;
			}
			if(cnt==s){
				for(int k=0;k<s;k++){
					okh[i][j+k]+=1;
				}
			}	
					
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){

			int cnt=0;		//verifica se da pra posicionar na vertical com o rabo do navio na casa atual		
		
			for(int k=0;k<s;k++){
				if(j+k>=n || field[j+k][i]=='#')	break;
				else	cnt++;
			}
			if(cnt==s){
				for(int k=0;k<s;k++){
					okv[j+k][i]+=1;
				}
			}

		}
	}

	int x=1, y=1;
	int mn=0;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			sum[i][j]=okv[i][j]+okh[i][j];
			if(sum[i][j]>mn){	
				mn=sum[i][j];
				x=i+1;
				y=j+1;
			}
		}
	}


	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < n; ++j)
	// 	{
	// 		cout << field[i][j];
	// 	}
	// 	cout << endl;
	// }

	// cout << endl;

	// for (int i = 0; i < n; ++i)
	// {
	// 	for (int j = 0; j < n; ++j)
	// 	{
	// 		cout << okv[i][j];
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;


	// for (int i = 0; i < n; ++i)
	// {
	// 	for (int j = 0; j < n; ++j)
	// 	{
	// 		cout << okh[i][j];
	// 	}
	// 	cout << endl;
	// }

	// cout << endl;
	cout << x << " " << y << endl;

}