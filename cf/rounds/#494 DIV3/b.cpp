#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define pq priority_queue
#define grtp greater< pair<int,int> >

#define gnl cout << endl
#define olar cout << "olar" << endl
#define gottagofast ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const double pi = 3.141592653589793238462643383279502884L;

int main(){
    
    int a,b,x;
    cin >> a >> b >> x;
    string s;

    //fazer x+1 segmentos distintos
    if(a>=b){
    	s.pb('0');
    	s.pb('1');
    }
    else{
    	s.pb('1');
    	s.pb('0');
    }
    x--;a--;b--;
    int cnt=1;
    while(cnt<=x){
    	char last=s[s.size()-1];
    	if(last=='0'){
    		s.pb('1');
    		b--;
    	}
    	else{
    		s.pb('0');
    		a--;
    	}
    	x--;
    }

    string ans;

    int flag1=0,flag0=0;
    fr(i,s.size()){

    	if(s[i]=='0' && flag0==0){
    		fr(i,a)
    			ans.pb('0');
    		ans.pb(s[i]);
    		flag0=1;
    	}
    	else if(s[i]=='1' && flag1==0){
    		fr(i,b)
    			ans.pb('1');
    		ans.pb(s[i]);
    		flag1=1;
    	}
    	else
    		ans.pb(s[i]);
    }

    cout << ans << endl;

}

