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

bool comp (char* s, char* ref,int n){
	
	fr(i,n-2){
		if (s[i] == ref[0] && s[i+1] == ref[1] && s[i+2] == ref[2] ){
				return (true);
		}
	}
	return (false);
}

int main(){

	int T,ok;
	char s[2000],ref[5],a[5],b[5],c[5],d[5];
	scanf("%d",&T);
	while (T--){
		ok = 0;
		scanf(" %s",s);
		scanf(" %s",ref);
		//printf("%s %s",s,ref);
		int m,n;
		n = strlen (s);
		fr(i,n-3){
			if (s[i] == ref[0] && s[i+1] == ref[1] && s[i+2] == ref[2] && s[i+3] == ref[3]){
				printf("good\n");
				ok = 1;
				break;
			}
		}
		if (ok) continue;
		fr (i,4){
			if (i!=0)
				a[i-1] = ref[i];
		}
		fr(i,4){
			if (i==0) b[0] = ref[0];
			if(i>1)
				b[i-1] = ref[i];
		}
		fr(i,4){
			if (i<2) c[i] = ref[i];
			if (i>2)
				c[i-1] =ref[i];
		}
		fr(i,3)
			d[i] = ref[i];

		if (comp(s,a,n) || comp(s,b,n) || comp(s,c,n) || comp (s,d,n)){
			printf("almost good\n");
			ok = 1;
		}

		if (!ok)
			printf("none\n");
	}

	return (0);

}