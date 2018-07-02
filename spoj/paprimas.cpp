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
 
int main(){
 
	string s;
	while(getline(cin,s)){
		int sum=0;
		fr(i,s.size()){
			if(s[i]>='a' && s[i]<='z')
				sum+=1+s[i]-'a';
			else
				sum+=27+s[i]-'A';
		}
		int flag=0;
		for(int i=2;i*i<=sum;i++){
			if(sum%i==0){
				cout << "It is not a prime word." << endl;
				flag=1;
				break;
			}
		}
		if(flag!=1){
			cout << "It is a prime word." << endl;
		}
 
	}
}