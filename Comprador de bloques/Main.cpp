#include<bits/stdc++.h>
using namespace std;
int n,ancho;
long long int altura;
long long int torre[100002];
int optimo=INT_MAX;

bool lectura(){
	int rango=0;
	bool encontrado=false;
	cin>>n>>altura>>ancho;
	for(int i=1;i<=n;i++){
		cin>>torre[i];
		if(torre[i]>=altura) rango++;
		else rango=0;
		if(rango>=ancho) encontrado=true;
		if(torre[i]>=altura and torre[i]<=optimo) optimo=torre[i];
	}
	return encontrado;
}

unsigned long long int compra(){
	unsigned long long int costo=0;
	if(optimo==INT_MAX) optimo=altura;
	for(int i=1;i<=n;i++){
		if(torre[i]<optimo){
			costo+=((optimo-torre[i])*i);
		}
	}
	return costo;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	if(lectura()) cout<<'0'<<'\n';
	else cout<<compra()<<'\n';
}
