#include<bits/stdc++.h>
using namespace std;
int reloj[9];
int a,b,c,d,e,f,g,h,i;
void lectura(){
	for(int i=0;i<9;i++){
		cin>>reloj[i];
		reloj[i]%=12;
	}
}

bool revisar(){ 
	if(reloj[0]==0 and reloj[1]==0 and reloj[2]==0 and reloj[3]==0 and
	reloj[4]==0 and reloj[5]==0 and reloj[6]==0 and reloj[7]==0 and
	reloj[8]==0) return true;
	else return false;
}

void calculo(){
	for(a=0;a<4;a++){
		for(b=0;b<4;b++){
			for(c=0;c<4;c++){
				for(d=0;d<4;d++){
					for(e=0;e<4;e++){
						for(f=0;f<4;f++){
							for(g=0;g<4;g++){
								for(h=0;h<4;h++){
									for(i=0;i<4;i++){
										if(revisar()) return;
										reloj[0]=(reloj[0]+3)%12;
										reloj[1]=(reloj[1]+3)%12;
										reloj[3]=(reloj[3]+3)%12;
										reloj[4]=(reloj[4]+3)%12;
									}
									reloj[0]=(reloj[0]+3)%12;
									reloj[1]=(reloj[1]+3)%12;
									reloj[2]=(reloj[2]+3)%12;
								}
								reloj[1]=(reloj[1]+3)%12;
								reloj[2]=(reloj[2]+3)%12;
								reloj[4]=(reloj[4]+3)%12;
								reloj[5]=(reloj[5]+3)%12;
							}
							reloj[0]=(reloj[0]+3)%12;
							reloj[3]=(reloj[3]+3)%12;
							reloj[6]=(reloj[6]+3)%12;
						}
						reloj[1]=(reloj[1]+3)%12;
						reloj[3]=(reloj[3]+3)%12;
						reloj[4]=(reloj[4]+3)%12;
						reloj[5]=(reloj[5]+3)%12;
						reloj[7]=(reloj[7]+3)%12;
					}
					reloj[2]=(reloj[2]+3)%12;
					reloj[5]=(reloj[5]+3)%12;
					reloj[8]=(reloj[8]+3)%12;
				}
				reloj[3]=(reloj[3]+3)%12;
				reloj[4]=(reloj[4]+3)%12;
				reloj[6]=(reloj[6]+3)%12;
				reloj[7]=(reloj[7]+3)%12;
			}
			reloj[6]=(reloj[6]+3)%12;
			reloj[7]=(reloj[7]+3)%12;
			reloj[8]=(reloj[8]+3)%12;
		}
		reloj[4]=(reloj[4]+3)%12;
		reloj[5]=(reloj[5]+3)%12;
		reloj[7]=(reloj[7]+3)%12;
		reloj[8]=(reloj[8]+3)%12;
	}
}

void mostrar(int par,int imp){
	for(int lim=1;lim<=par;lim++) cout<<imp<<' ';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	lectura();
	calculo();
	mostrar(a,9); mostrar(b,8); mostrar(c,7); mostrar(d,6); mostrar(e,5);
	mostrar(f,4); mostrar(g,3); mostrar(h,2); mostrar(i,1);
	cout<<'\n';
	
	return 0;
}
