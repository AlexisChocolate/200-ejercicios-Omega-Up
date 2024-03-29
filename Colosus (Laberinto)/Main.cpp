#include <bits/stdc++.h>

using namespace std;

int visitados [1002][1002];
int pasos[1002][1002];
struct nodo {
    int a,b;
};
nodo actual, nuevo, fin, inicio;
int movimientos[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

queue <nodo> COLA;

char MAPA[1002][1002];
int M, N, T;


int main()
{
    cin>> M >> N >> T;
    for(int i=1; i<=M; i++){
        for(int j=1; j<=N; j++){
            cin >> MAPA[i][j];
            if(MAPA[i][j]=='C'){
                inicio.a = i;
                inicio.b = j;
            }
        }
    }
    fin.a = -1;
    fin.b = -1;
    visitados[inicio.a][inicio.b] = 1;
    pasos[inicio.a][inicio.b] = 0;
    COLA.push(inicio);
    while(!COLA.empty()){
        actual = COLA.front(); COLA.pop();
        if(MAPA[actual.a][actual.b] == 'O'){
            fin = actual;
            break;
        }
        for(int j= 0; j<=3 ; j++){
            nuevo.a = actual.a + movimientos[j][0];
            nuevo.b = actual.b + movimientos[j][1];
            if(visitados[nuevo.a][nuevo.b] == 0){
                /// coordenada valida
                if(nuevo.a >= 1 and nuevo.a <= M and
                    nuevo.b >= 1 and nuevo.b <= N){
                    if(MAPA[nuevo.a][nuevo.b]== 'L' or
                        MAPA[nuevo.a][nuevo.b] =='O'){
                        visitados[nuevo.a][nuevo.b] = 1;
                        pasos[nuevo.a][nuevo.b] = pasos[actual.a][actual.b] + 1;
                        COLA.push(nuevo);
                    }

                }
            }
        }
    }
    if(fin.a == -1 and fin.b == -1){
        cout << -1;
    } else if(pasos[fin.a][fin.b] <= T){
        cout << pasos[fin.a][fin.b];
    } else {
        cout << -1;
    }

    return 0;
}
