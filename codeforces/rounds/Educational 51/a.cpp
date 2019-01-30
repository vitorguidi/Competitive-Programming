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
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

string s;
int len;

bool is_lower(char x){
	return x>='a' && x<='z';
}

bool is_upper(char x){
	return x>='A' && x<='Z';
}

bool is_digit(char x){
	return x>='0' && x<='9';
}

bool check(string x){
	int d=0,l=0,u=0;

	fr(i,x.size()){
		if(is_lower(x[i]))
			l++;
		else if (is_upper(x[i]))
			u++;
		else if(is_digit(x[i]))
			d++;
	}


	return d>0 && l>0 && u>0;

}

int main(){
    
	fastio;

	int t; cin >> t;
	getline(cin,s);

	while(t--){
		
		int d=0,l=0,u=0;
		getline(cin,s);
		len = s.size();
	
		if(check(s)){
			cout << s << endl;
			continue;
		}

		fr(i,len){
			if(is_upper(s[i]))
				u++;
			else if(is_lower(s[i]))
				l++;
			else
				d++;
		}

		string ans;
		int cnt=INF;

		fr(i,len){

			string x = s;
			
			fr(j,len){
			
				int cnt2 = j-i+1;
				int d2 = d,l2=l,u2=u;
				
				for(int k=i;k<=j;k++){
					
					if(d2>1){
						if(l2==0){
							d2--;
							l2++;
							x[k]='a';
						}
						else if(u2==0){
							u2++;
							d2--;
							x[k]='A';
						}
					}

					if(l2>1){
						if(u2==0){
							l2--;
							u2++;
							x[k]='A';
						}
						else if(d2==0){
							d2++;
							l2--;
							x[k]='1';
						}
					}

					if(u2>1){
						if(l2==0){
							l2++;
							u2--;
							x[k]='a';
						}
						else if(d2==0){
							d2++;
							u2--;
							x[k]='1';
						}
					}

				}

				if(check(x) && cnt2<cnt){
					cnt=cnt2;
					ans=x;
				}
			}

		}

		cout << ans << endl;


	}

}

