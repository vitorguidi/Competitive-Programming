#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define pq priority_queue
#define grtp greater< pair<int,int> >

#define gnl cout << endl
#define olar cout << "olar" << endl

typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int fatorial(int k){
    int i,fat=1; 
    for(i=1;i<=k;i++) 
        fat *= i;
    return(fat);
}

int main(){
    int t,n,freq[27],i,impar,soma; 
    char str[21]; 

    cin>>t; 
    while(t--){  
        for(i=0;i<27;i++) 
            freq[i]=0; 
        impar=0; 
        soma=0;

        scanf("%d",&n); 
        scanf(" %s",str); 
        for(i=0;i<n;i++) 
            freq[str[i]-'a']++; 

        for(i=0;i<27;i++) 
            if(freq[i]%2!=0) 
                impar++; 
        
        if(impar<2){
            for(i=0;i<27;i++){ 
                freq[i]/=2;
                soma+=freq[i];
            }     
            soma=fatorial(soma); 
            for(i=0;i<27;i++) 
                soma/=fatorial(freq[i]); 
            cout<<soma<<endl;
        }    
        else{
            cout<<"0"<<endl;
        }

    } 
    return 0;
	
}
