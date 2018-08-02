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

int dist[110];
vector<vi> nodes;

string num_to_str(int x){
	string ans;
	if(x==0)
		return "0";
	while(x!=0){
		ans.pb('0'+x%10);
		x=x/10;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

vector<string> tokenize(string s){

	vector<string> ans;

	int ini=0;
	string aux;

	while(ini<s.size()){

		if(s[ini]!=',' && s[ini]!=' ' && s[ini]!='.'){
			aux.pb(s[ini]);
			ini++;
		}

		else{
			if(aux!="")
				ans.pb(aux);
			aux.clear();
			ini++;
		}
	}

	return ans;

}

void bfs(int v){

	dist[v]=0;
	queue<int> fila;
	fila.push(v);

	while( !fila.empty() ){

		int pai=fila.front();
		fila.pop();

		for(auto filho : nodes[pai]){

			if(dist[filho]>1+dist[pai]){
				dist[filho] = 1+dist[pai];
				fila.push(filho);
			}

		}

	}

}

int main(){

	int a=1;

	int caso = 0;

	while(cin >> a){

		if(!a)
			break;

		caso++;

		nodes.clear();
		nodes.resize(110);

		string s;
		getline(cin,s);

		map < pair<string,string> , int> lista;
		map < int , pair<string,string> > lista2;

		lista[{"P","Erdos"}]=1;
		lista2[1]={"P","Erdos"};
	
		int cnt=2;
		int flag=0;

		fr(i,a){

			getline(cin,s);
			
			int ini=0;

			vector<string> aux = tokenize(s);
			vector< pair<string,string> > conectados;

			while(ini<aux.size()){

				pair<string,string> temporario = mp( aux[ini] , aux[ini+1] );

				if(lista[temporario]==0){
					lista[temporario]=cnt;
					lista2[cnt]=temporario;
					cnt++;
				}

				ini+=2;
				conectados.pb(temporario);
			}


			fr(i,conectados.size()){
				for(int j=i+1;j<conectados.size();j++){
					int x = lista[conectados[i]];
					int y = lista[conectados[j]];
					nodes[x].pb(y);
					nodes[y].pb(x);
				}
			}			

		}

		
		ms(dist,INF);
		dist[1]=0;
		bfs(1);

		set <   pair< pair<string,string>  , int > > ans;

		frr(i,cnt-1){
			if(i==1)
				continue;
			int d = dist[i];
			
			pair <string,string> nome = lista2[i];

			pair <string,string> nome_final = mp (nome.snd,nome.fst);

			ans.insert( mp(  nome_final , d )  );
		}

		vector<string> printassabosta;

		for(auto z : ans){

			string tmp = "";

			tmp+=z.fst.snd;
			tmp+=". ";
			
			tmp+=z.fst.fst;
			tmp+=": ";
			
			if(z.snd==INF)
				tmp+="infinito";
			else
				tmp+=num_to_str(z.snd);
			printassabosta.pb(tmp);
		}

		cout << "Teste " << caso <<  endl;
		for(auto z : printassabosta)
			cout << z << endl;
		gnl;

	}

}
