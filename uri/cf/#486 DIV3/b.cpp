#include "bits/stdc++.h"
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

bool is_sub(string a, string b){
    int x = a.size();
    int y = b.size();
   
   if(x>y){
       return false;
    }

    if(x==y){
        if(a==b)    return true;
        return false;
    }

    int ds = y-x;
    fr(i,ds+1){
        string  aux;
        fr(j,x){
            aux.pb(b[i+j]);
        } 
        if(a==aux)  return true;
        aux="";
    }
    return false;
}

int main(){

    int n;
    vector<string> words; 
    cin>>n;
    words.resize(n);
    getchar();
    
    fr(i,n) getline(cin,words[i]);

    fr(i,words.size()-1){
        for(int j=i+1;j<words.size();j++){
            if(words[i].size()>words[j].size()) swap(words[i],words[j]);
        }
    }

    fr(i,words.size()-1){
        if( !is_sub(words[i],words[i+1]) ){
            cout << "NO" << endl;
            return 0;
        }
    }

    cout <<"YES" << endl;
    fr(i,words.size()){
        cout << words[i] << endl;
    }


}

