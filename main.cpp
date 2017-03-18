#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <string.h>
#include <conio.h>
#include "cows.h"
#include "definicion.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//VARIABLES GLOBALES
cows vacas[ANCHO];
int opcOrden=0;

void imprimir_lista(int a);
void motodo_ordenamiento(int j, int c);
void ordenOpcional(int pos, int cont);
void ordenarPorNombre(int c);

int main(int argc, char *argv[]) {

	int opc=0,cont=0,pos=0,rep=0;
	string nombre,raza1;
	float peso,lts_leche;
	int raza=1;
	int contOrden=1;
	int bandera=0;
			
	do{	
		cout<<"\tElija una Opcion"<<endl<<endl;
		cout<<"1- Agregar Vaca"<<endl;
		cout<<"2- Mostrar Lista de Vacas"<<endl;
		cout<<"3- Salir"<<endl<<endl;
		cout<<"Opcion: ";
		cin>>opc;
		system("cls");
	
		switch (opc){
		
			case 1:
				cout<<"\tIngrese los Datos de la Vaca"<<endl<<endl;
				int v,a,i;
				do{
					a=0;
					do{
						cout<<"Nombre: ";
						cin>>nombre;
						v=nombre.size();
						if (v>14){
							cout<<"\nEl nombre el muy largo"<<endl;
							cout<<"(NO DEBE PASAR DE 14 CARACTERES)\n"<<endl;
							system("pause");
							system("cls");
							cout<<"\tIngrese los Datos de la Vaca"<<endl<<endl;
						}
						
					}while(v>14);
					v=0;
				
					if (cont>0){
						do{
							if (nombre == vacas[v].getNombre()){
								cout<<"El nombre ya existe"<<endl;
								a=1;
								system("pause");
								system("cls");
								cout<<"\tIngrese los Datos de la Vaca"<<endl<<endl;
							}
							v++;
						}while(v<cont);
					}
					
					if(isalpha(nombre[0])){}
					else{
						cout<<"\nEl nombre no debe iniciar con numero\n"<<endl;
						a=1;
						system("pause");
					system("cls");
					cout<<"\tIngrese los Datos de la Vaca"<<endl<<endl;
					}
					
				}while(a==1);
				vacas[cont].setNombre(nombre);
			
				cout<<"\nRaza: "<<endl<<endl;
				cout<<"   1- Guernsey"<<endl;
				cout<<"   2- Jersey"<<endl;
				cout<<"   3- Pasiega"<<endl;
				cout<<"   4- Simmental"<<endl;
				cin>>raza;
				vacas[cont].setRaza(raza);
			
				cout<<"\nPeso (Kg): ";
				cin>>peso;
				vacas[cont].setPeso(peso);
			
				cout<<"\nLitros de leche: ";
				cin>>lts_leche;
				vacas[cont].setLitroLeche(lts_leche);
			
				cont++;
				system("cls");
				cout<<"\n\n\tREGISTRO EXITOSO"<<endl<<endl;
				system("PAUSE");
				system("cls");
			break;
			
			case 2:
				
				cout<<"\tSeleccione el Orden Deseado"<<endl<<endl;
				cout<<"1- Por Nombre"<<endl;
				cout<<"2- Por Raza"<<endl;
				cout<<"3- Por Peso"<<endl;
				cout<<"4- Por Litros de Leche"<<endl<<endl;
				cout<<"Opcion: ";
				cin>>opcOrden;
				system("cls");
				switch (opcOrden){
					case 1:
						cout<<"\t\t\tOrden por Nombre"<<endl<<endl<<endl;
						ordenarPorNombre(cont);
						imprimir_lista(cont);
						opc=0;
						system("pause");
						system("cls");						
					break;					
					
					case 2:
						contOrden=1;
						cout<<"\t\t\tOrden por Raza"<<endl<<endl<<endl;
						for(int i=0; i<cont; i++ ){
							for(int j=0; j<=cont-2; j++){
								if(vacas[j].getRaza() > vacas[j+1].getRaza()) {
									motodo_ordenamiento(j, cont);									
								}
							}								
						}
						for (int i=0;i<cont;i++){
							
							if(vacas[i].getRaza() == vacas[i+1].getRaza()){
								contOrden++;
							}
							
							if ((contOrden > 1) && (vacas[i+1].getRaza()!=rep)){
								if (bandera==0){
									pos=i;
									bandera=1;
								}
								rep=vacas[i].getRaza();
								if (vacas[i].getRaza() != vacas[i+1].getRaza()){
									ordenOpcional(pos, contOrden);
									contOrden=1;
									bandera=0;
								}	
							}
						}
						imprimir_lista(cont);
						opc=0;
						system("pause");
						system("cls");
						
					break;
					
					case 3:
						//Ordenar por peso
						contOrden=1;
						cout<<"\t\t\tOrden por Peso"<<endl<<endl<<endl;
							
						for(int i=0; i<cont; i++ ){
							for(int j=0; j<=cont-2; j++){
								if(vacas[j].getPeso() > vacas[j+1].getPeso()) {
									motodo_ordenamiento(j, cont);
								}
							}							
						}
						for (int i=0;i<cont;i++){
							
							if(vacas[i].getPeso() == vacas[i+1].getPeso()){
								contOrden++;
							}
							
							if ((contOrden > 1) && (vacas[i+1].getPeso()!=rep)){
								if (bandera==0){
									pos=i;
									bandera=1;
								}
								rep=vacas[i].getPeso();
								if (vacas[i].getPeso() != vacas[i+1].getPeso()){
									ordenOpcional(pos, contOrden);
									contOrden=1;
									bandera=0;
								}	
							}
						}
						imprimir_lista(cont);
						opc=0;
						system("pause");
						system("cls");								
					break;
					
					case 4:
						contOrden=1;
						cout<<"\t\tOrden por Litros de Leches Producidos"<<endl<<endl<<endl;
						for(int i=0; i<cont; i++ ){
							int minimo = i;
							for(int j=0; j<=cont-2; j++){
								if(vacas[j].getLitroLeche() > vacas[j+1].getLitroLeche()) {
									motodo_ordenamiento(j, cont);
								}
							}							
						}
						for (int i=0;i<cont;i++){
							
							if(vacas[i].getLitroLeche() == vacas[i+1].getLitroLeche()){
								contOrden++;
							}
							
							if ((contOrden > 1) && (vacas[i+1].getLitroLeche()!=rep)){
								if (bandera==0){
									pos=i;
									bandera=1;
								}
								rep=vacas[i].getLitroLeche();
								if (vacas[i].getLitroLeche() != vacas[i+1].getLitroLeche()){
									ordenOpcional(pos, contOrden);
									contOrden=1;
									bandera=0;
								}	
							}
						}
						imprimir_lista(cont);
						opc=0;
						system("pause");
						system("cls");						
					break;
				}
			break;
			case 3:
				
			break;
		}
	}while(opc!=3);
		
	
	return 0;
}

void imprimir_lista(int a) {
	string raza1;
	int cont=a;
	
	if (opcOrden==1){
		cout<<setw(15)<<left<<"Nombre"<<setw(15)<<left<<"Raza"<<setw(15)<<left<<"Peso"<<setw(15)<<left<<"Leche (Lts)"<<endl<<endl;
	}
	if (opcOrden==2){
		cout<<setw(15)<<left<<"Raza"<<setw(15)<<left<<"Nombre"<<setw(15)<<left<<"Peso"<<setw(15)<<left<<"Leche (Lts)"<<endl<<endl;
	}
	if (opcOrden==3){
		cout<<setw(15)<<left<<"Peso"<<setw(15)<<left<<"Nombre"<<setw(15)<<left<<"Raza"<<setw(15)<<left<<"Leche (Lts)"<<endl<<endl;
	}
	if (opcOrden==4){
		cout<<setw(15)<<left<<"Leche (Lts)"<<setw(15)<<left<<"Nombre"<<setw(15)<<left<<"Raza"<<setw(15)<<left<<"Peso"<<endl<<endl;
	}	
			
	for (int x=0;x<cont;x++){
		
		if (vacas[x].getRaza()==1){
			raza1="Guernsey";
		}
		else if(vacas[x].getRaza()==2){
			raza1="Jersey";
		}
		else if(vacas[x].getRaza()==3){
			raza1="Pasiega";
		}
		else if(vacas[x].getRaza()==4){
			raza1="Simmental";
		}
		
		if (opcOrden==1){
			cout<<setw(15)<<left<<vacas[x].getNombre()<<setw(15)<<left<<raza1<<setw(15)<<left<<vacas[x].getPeso()<<setw(19)<<left<<vacas[x].getLitroLeche()<<endl;
		}
		if (opcOrden==2){
			cout<<setw(15)<<left<<raza1<<setw(15)<<left<<vacas[x].getNombre()<<setw(15)<<left<<vacas[x].getPeso()<<setw(19)<<left<<vacas[x].getLitroLeche()<<endl;
		}
		if (opcOrden==3){
			cout<<setw(15)<<left<<vacas[x].getPeso()<<setw(15)<<left<<vacas[x].getNombre()<<setw(15)<<left<<raza1<<setw(19)<<left<<vacas[x].getLitroLeche()<<endl;
		}
		if (opcOrden==4){
			cout<<setw(15)<<left<<vacas[x].getLitroLeche()<<setw(15)<<left<<vacas[x].getNombre()<<setw(15)<<left<<raza1<<setw(15)<<left<<vacas[x].getPeso()<<endl;
		}		
	}
}

void motodo_ordenamiento(int j, int c){
	string auxNom;
	float aux;
	int auxI;	
	aux = vacas[j].getPeso();
	vacas[j].setPeso(vacas[j+1].getPeso());
	vacas[j+1].setPeso(aux);
									
	auxNom = vacas[j].getNombre();
	vacas[j].setNombre(vacas[j+1].getNombre());
	vacas[j+1].setNombre(auxNom);
									
	aux = vacas[j].getLitroLeche();
	vacas[j].setLitroLeche(vacas[j+1].getLitroLeche());
	vacas[j+1].setLitroLeche(aux);
									
	auxI = vacas[j].getRaza();
	vacas[j].setRaza(vacas[j+1].getRaza());
	vacas[j+1].setRaza(auxI);
}

void ordenOpcional(int pos, int cont){
	string nombre1,nombre2;
	char nom[14], nom2[14];		
	int v;
	for(int i=pos; i<pos+cont; i++ ){
		for(int j=pos; j<=(pos+cont)-2; j++){
			nombre1=vacas[j].getNombre();
			nombre2=vacas[j+1].getNombre();
			v=nombre1.size();
			for (int x=0; x<v; x++){
				nom[x]=nombre1[x];
			}
			v=nombre2.size();
			for (int y=0; y<v; y++){
				nom2[y]=nombre2[y];
			}
								
			if(strcmp (nom , nom2) > 0) {
				motodo_ordenamiento(j, cont);
			}						
								
		}							
	}
}

void ordenarPorNombre(int c){
	string nombre1,nombre2;
	char nom[14], nom2[14];		
	int v;
	int cont=c;
	
	for(int i=0; i<cont; i++ ){
		for(int j=0; j<=cont-2; j++){
			nombre1=vacas[j].getNombre();
			nombre2=vacas[j+1].getNombre();
			v=nombre1.size();
			for (int x=0; x<v; x++){
				nom[x]=nombre1[x];
			}
			v=nombre2.size();
			for (int y=0; y<v; y++){
				nom2[y]=nombre2[y];
			}
								
			if(strcmp (nom , nom2) > 0) {
				motodo_ordenamiento(j, cont);
			}						
								
		}							
	}
}	
