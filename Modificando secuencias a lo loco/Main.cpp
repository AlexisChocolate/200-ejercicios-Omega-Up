#include<bits/stdc++.h>
using namespace std;
vector<int>datos(102);
int n;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int i,j,a,b;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>datos[i];
	i=1;
	while(datos[i]!=5) i++;
	a=i+1;
	j=1; i--;
	while(j<i){
		swap(datos[i],datos[j]);
		i--;
		j++;
	}
	i=a;
	while(datos[i]!=5) i++;
	b=i-1;
	j=n;
	i++;
	while(i<j){
		swap(datos[i],datos[j]);
		i++;
		j--;
	}
	i=a; j=b;
	while(a<=b){
		if(datos[a]==7){
			datos[a]=0;
			break;
		}
		a++;
	}
	if(a>b) sort(datos.begin()+i,datos.begin()+j+1);
	for(int i=1;i<=n;i++) cout<<datos[i]<<" ";
}

/// xD
/***

***/
