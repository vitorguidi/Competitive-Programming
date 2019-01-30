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
#define all(x)	x.begin(),x.end()

#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int v[100100];
int here[30];

int main(){
	
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    
    int k;
    cin >> k;
    
    string s;
    cin >>s;
    
    int len = s.size();
    
    fr(i,len)
		v[i]=s[i]-'a';
	
	int end=0;
    int sum = 0;
  
    int mx = 0;
    pii ans = mp(-1,-1);
    
    fr(i,len){
		
		while(sum<k && end<len){	
			
			int letra = v[end];
			
			if(!here[letra])
				sum++;
				
			here[letra]++;
			end++;
		}
		
		while(here[ v[end] ] != 0 && end<len && sum==k){
			here[ v[end] ]++;
			end++;
		}
		if(sum<=k){
		
			if(mx<end-i){
				mx=end-i;
				ans=mp(i+1,end);
			}
			
		}
		
		here[ v[i] ]--;
		
		if(!here[ v[i] ])
			sum--;
		
				
	}

	cout << ans.fst << " " << ans.snd << endl;


}