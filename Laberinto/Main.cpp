#include <bits/stdc++.h>
using namespace std;
struct nodo{
    int f,c,p;
    bool activas[10];
    void inicializar(){
        for(int i=1;i<=9;i++){
            activas[i]=0;
        }
    }
};
int movs[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
queue<nodo>cola;
int f,c,k,x;
bool visitados[102][102][2][2][2][2][2][2][2][2][2];
char mapa[102][102];

void lectura(){
    nodo inicial;
    cin>>f>>c>>k>>x;
    for(int i=1;i<=f;i++){
        for(int j=1;j<=c;j++){
            cin>>mapa[i][j];
            if(mapa[i][j]=='I'){
                inicial.f=i;
                inicial.c=j;
                inicial.p=k;
            }
        }
    }
    visitados[inicial.f][inicial.c][0][0][0][0][0][0][0][0][0]=1;
    inicial.inicializar();
    cola.push(inicial);
}

bool valido(nodo &r){
    if(r.f>=1 and r.f<=f and r.c>=1 and r.c<=c and mapa[r.f][r.c]!='#' and !visitados[r.f][r.c][r.activas[1]][r.activas[2]][r.activas[3]][r.activas[4]]
       [r.activas[5]][r.activas[6]][r.activas[7]][r.activas[8]][r.activas[9]]){
        visitados[r.f][r.c][r.activas[1]][r.activas[2]][r.activas[3]][r.activas[4]]
        [r.activas[5]][r.activas[6]][r.activas[7]][r.activas[8]][r.activas[9]]=1;
        return true;
    }
    return false;
}

nodo puntos(nodo &r){
    if(mapa[r.f][r.c]>='1' and mapa[r.f][r.c]<='9'){
        int aux=mapa[r.f][r.c]-48;
        if(! r.activas[aux]){
            visitados[r.f][r.c][r.activas[1]][r.activas[2]][r.activas[3]][r.activas[4]]
            [r.activas[5]][r.activas[6]][r.activas[7]][r.activas[8]][r.activas[9]]=1;
            r.p+=(aux*x);
            r.activas[aux]=1;
        }
    }
}

void busqueda(){
    nodo actual,copia;
    bool si=false;
    int max_puntos=-1;
    while(!cola.empty()){
        actual=cola.front(); cola.pop();
        if(mapa[actual.f][actual.c]=='S' and actual.p>max_puntos){
            max_puntos=actual.p;
            si=true;
        }
        if(actual.p>=0){
            actual.p--;
            for(int i=0;i<4;i++){
                copia=actual;
                copia.f+=movs[i][0];
                copia.c+=movs[i][1];
                puntos(copia);
                if(valido(copia)){
                    cola.push(copia);
                }
            }
        }
    }
    if(! si){
        cout<<"NOPE"<<'\n';
    }else{
        cout<<max_puntos<<'\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    lectura();
    busqueda();

    return 0;
}
