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
#define pira cout << "pira" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

string s;
int len;
int cnt[2];

bool is_pal(int l, int r){

	while(l<=r){
		if(s[l]!=s[r])
			return false;
		l++;r--;
	}

	return true;

}

int main(){
    
	int odd=0;
	int even=0;

	getline(cin,s);

	len=s.size();
	
	fr(i,s.size()){

		for(int j=i;j<s.size();j++){

			if(is_pal(i,j))
				cnt[ (j-i+1)%2 ]++;
			
		}
	}

	if(!cnt[0])
		cout << "Odd." << endl;
	else
		cout << "Or not." <<endl;

}

