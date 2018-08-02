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

int d[110][110][16];
int gabarito;
char m[110][110];

map<char,int> ids;

struct coord{
    int x, y;
};

int r,c;

int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};

vector<coord> saida;

void bfs(coord v){

	queue< pair<coord,int> > fila;					//carrego as coordenadas do vertice (i,j) e a bitmask(chaves que esstou carregando)

	d[v.x][v.y][0]=0;

	fila.push(mp(v,0));

	while(!fila.empty()){

		coord pai = fila.front().fst;
		int maskpai = fila.front().snd;

		fila.pop();

		fr(i,4){

			coord filho=pai;

			filho.x+=dx[i];
			filho.y+=dy[i];

			int mask_filho=maskpai;

			if(filho.x<0 || filho.x>=r)
				continue;
			if(filho.y<0 || filho.y>=c)
				continue;

			char mf = m[filho.x][filho.y];
			
			if(mf=='#')
				continue;

			if(mf=='X'){
				d[filho.x][filho.y][maskpai]=1+d[pai.x][pai.y][maskpai];
				return;
			}

			if(mf=='b' || mf=='y' || mf=='r' || mf=='g'){		//lidar com achar as chaves
				int porta=ids[mf];
				mask_filho=mask_filho|(1<<porta);
			}

			if( (mf=='B' || mf=='Y' || mf=='R'  || mf=='G') && !( (1<<ids[mf])&(mask_filho) ))	//se nao tnho a chave nao atualizo
				continue;

			else{
				if(d[filho.x][filho.y][mask_filho]>1+d[pai.x][pai.y][maskpai]){
					d[filho.x][filho.y][mask_filho]=1+d[pai.x][pai.y][maskpai];
					fila.push(mp(filho,mask_filho));
				}

			}//

		}
	}

}



int main(){

	ids['B']=ids['b']=0;
	ids['Y']=ids['y']=1;
	ids['R']=ids['r']=2;
	ids['G']=ids['g']=3;

	gottagofast;
    
    while(cin>>r){
    
        if(!r)
            break;
        
        cin >> c;
        string s;
        getline(cin,s);
  
        coord ini;

        saida.clear();

        fr(i,r){
            
            getline(cin,s);
            
            fr(j,c){
            	m[i][j]=s[j];
            	coord aux;
	            aux.x=i;
	            aux.y=j;

	            if(s[j]=='*')
	                ini=aux;
	            
	            if(s[j]=='X')
	                saida.pb(aux);
        	}              
        }

        fr(i,r)
        	fr(j,c)
        		fr(k,16)
        			d[i][j][k]=INF;

        bfs(ini);
        
        int ans=INF;

        fr(i,saida.size()){
        	fr(k,16)
        		if(d[saida[i].x][saida[i].y][k]<ans)
        			ans=d[saida[i].x][saida[i].y][k];
        }

        if(ans==INF)
        	cout <<"The poor student is trapped!" << endl;
        else
        	cout << "Escape possible in " << ans << " steps." << endl;
        
	}	
}