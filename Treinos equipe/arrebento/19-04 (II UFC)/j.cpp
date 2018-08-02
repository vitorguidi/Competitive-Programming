#include <bits/stdc++.h>
using namespace std;

int p_x[1001],p_y[1001],p_r[1001];

int main(){

    int n,dist,rad;
 
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> p_x[i] >> p_y[i] >> p_r[i];
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            dist= ( p_x[i]-p_x[j] )*( p_x[i]-p_x[j] ) + ( p_y[i]-p_y[j] )*( p_y[i]-p_y[j] );
            rad= (p_r[i]+p_r[j])*(p_r[i]+p_r[j]);
            if( dist==rad )   cout << i+1 << " " << j+1 << endl;
    
        }
    }
   
    return 0;   
    
}


