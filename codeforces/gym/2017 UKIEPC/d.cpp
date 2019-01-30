#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define INF 1000000000000001018
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fastcin ios_base::sync_with_stdio(false);
#define ll long long
#define MAX 

  
int main()
{	
	fastcin;

	string s,ori; cin >> s;
	
	int n = s.size();

	ori=s;
	sort(s.begin(),s.end());

	for(int i=0;i<n;i++){
		
		if(ori[i]==s[i])	continue;

		for(int j=i+1;j<n;j++){
		
			if(ori[i]==s[j]){

				int l=i;
				int r=j;

				if(s[l]<s[r])
					swap(l,r);

				swap(s[i],s[j]);

				cout << l+1 << " " << r+1 << endl;


				break;
			}

			
		}
	}

	cout << s << endl;
	
}