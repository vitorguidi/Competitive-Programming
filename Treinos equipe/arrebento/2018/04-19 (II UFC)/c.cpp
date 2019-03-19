#include <bits/stdc++.h>
using namespace std;

int main(){
	int x,y,high,low,play;
	int rl,rj;
	cin >> x >> y;
	while(x>=0 && y>=0){
	    if(x==0 && y==0)    break;
	    high=max(x,y);
	    low=min(x,y);
	    play=high-low;
	    if(x>=y){      
	        x-=play;
	        cout << 1 << " " << play  << endl;
	    }
	    else{ 
	       y-=play;
	       cout << 2 << " " << play << endl;
	    }
	    cout.flush();
	    
	   // cout << "pilha 1= " << x << " pilha2 = " << y << endl;
	    
	   
	    if(x!=0 && y!=0){
	        cin >> rl >> rj;
	        if(rl==1)   x-=rj;
	        else        y-=rj;
	    }	
	    
	   // cout << "pilha 1= " << x << " pilha2 = " << y << endl;   
	    
    }	     
	
}
