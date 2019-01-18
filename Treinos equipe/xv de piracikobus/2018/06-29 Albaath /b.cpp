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
#define pira cout << "XV de piracikobus" << endl

typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

void minimiza (char* s,char* t,int m,int n){
	fr(i,n){
		if (s[i]<= 'Z')
			s[i] += 'z' - 'Z';
	}
	fr(i,m){
		if (t[i]<= 'Z')
			t[i] += 'z' - 'Z';
	}



}

int igual (char* t,char* s,int i){
	if (t[i] == 'p'  && s[i] == 'b') return (1);
	if (t[i]=='b' && s[i] == 'p') return (1);
	if (t[i] == 'i'  && s[i] == 'e') return (1);
	if (t[i]=='e' && s[i] == 'i') return (1);
	return (0);
}

int main(){
	char t[200],s[200];

	int T,ok;
	scanf("%d",&T);
	while (T--){
		scanf(" %s",t);
		scanf(" %s",s);
		//printf ("%s %s\n",t,s);
		int m;
		int n;
		m=strlen(t);
		n=strlen(s);
		minimiza (t,s,m,n);
		if (m!=n)
			ok=0;
		else{
			ok = 1;
			fr(i,n){
				if (t[i] == s[i]) continue;
				else{
					if (igual(t,s,i)) continue;
					else ok =0;
				}
			}
		}

		if (ok)
			printf ("Yes\n");
		else
			printf ("No\n");
	}	
	 return (0);
}