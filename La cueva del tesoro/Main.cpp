#include<bits/stdc++.h>
using namespace std;
struct arbol{
	int izq,der;
};
arbol ruta[5002];
int pasos[5002];
int n,padres,tesoro;
int i=0;
void lectura(){
	int nodo;
	cin>>n>>padres>>tesoro;
	for(int i=1;i<=padres;i++){
		cin>>nodo;
		cin>>ruta[nodo].izq>>ruta[nodo].der;
	}
}

bool busqueda(int pos){
	if(pos<=0 or pos>n) return false;
	if(pos==tesoro){
		pasos[++i]=pos;
		return true;
	}
	if(busqueda(ruta[pos].izq)){
		pasos[++i]=pos;
		return true;
	}
	if(busqueda(ruta[pos].der)){
		pasos[++i]=pos;
		return true;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	lectura();
	busqueda(1);
	cout<<i<<'\n';
	for(;i>=1;i--){
		cout<<pasos[i]<<'\n';
	}
}
