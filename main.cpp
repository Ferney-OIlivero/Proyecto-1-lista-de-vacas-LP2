#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
#include <string.h>
#include <cctype>
#include <sstream>
#include "cows.h"
#include "definicion.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// VAriables Globales
cows vacas[ANCHO];
int opcOrden=0;

	
void imprimir_lista(int a);
void motodo_ordenamiento(int j);
void ordenOpcional(int pos, int cont);
void ordenarPorNombre(int c);
bool validar(string valor);

int main(int argc, char *argv[]) {
	char numero[14];
	char nomb[14];
	string nombre;
	int contador[ANCHO]={0};
	string valortemp;
	float peso,lts_leche;
	int raza=1;
	int i,j; //para ciclo for
	int opc=0,cont=0,pos=0,rep=0;
	int iteracion = 1, bandera=0;
	int contOrden=1;

	do{
		do{
			
			system("cls");
			cout<<"\tElija una Opcion"<<endl<<endl;
			cout<<"1- Agregar Vaca"<<endl;
			cout<<"2- Mostrar Lista de Vacas"<<endl;
			cout<<"3- Salir"<<endl<<endl;
			cout<<"Opcion: ";
			cin>>valortemp;
			if(validar(valortemp)==false){
				cout<<"\n"<<ERROR<<endl<<endl;
				system("pause");
			}else{
				istringstream(valortemp)>>opc;
				if(opc<1 || opc>3){
					cout<<"\n"<<ERROR<<endl<<endl;
					system("pause");
				}
				bandera=1;	
            }   	
		}while(bandera!=1);
		bandera=0;	
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
				
				system("cls");
				cout<<"\tIngrese los Datos de la Vaca"<<endl<<endl;
				do{
					cout<<"Raza: "<<endl<<endl;
					cout<<"   1- Guernsey"<<endl;
					cout<<"   2- Jersey"<<endl;
					cout<<"   3- Pasiega"<<endl;
					cout<<"   4- Simmental"<<endl;
					cin>>valortemp;
					if(validar(valortemp)==false){
						cout<<"\n"<<ERROR<<endl<<endl;
						system("pause");
						system("cls");
						cout<<"\tIngrese los Datos de la Vaca"<<endl<<endl;
					}else{
						istringstream(valortemp)>>raza;
						bandera=1;
						if(raza<1 || raza>4){
							cout<<"\n"<<ERROR<<endl<<endl;
							system("pause");
							system("cls");
							cout<<"\tIngrese los Datos de la Vaca"<<endl<<endl;
							bandera=0;
						}
						vacas[cont].setRaza(raza);
						
                	}
				}while(bandera!=1);
				bandera=0;
				
				system("cls");
				cout<<"\tIngrese los Datos de la Vaca"<<endl<<endl;
				do{
					cout<<"Peso (Kg): ";
					cin>>valortemp;
					if(validar(valortemp)==false){
						cout<<"\n"<<ERROR<<endl<<endl;
						system("pause");
						system("cls");
						cout<<"\tIngrese los Datos de la Vaca"<<endl<<endl;
					}else{
						istringstream(valortemp)>>peso;
						bandera=1;		
						if(peso<1){
							cout<<"\n"<<ERROR<<endl<<endl;
							system("pause");
							system("cls");
							cout<<"\tIngrese los Datos de la Vaca"<<endl<<endl;
							bandera=0;
						}
						vacas[cont].setPeso(peso);
                	}
				}while(bandera!=1);
				bandera=0;
			//	vacas[cont].setPeso(peso);
				system("cls");
				cout<<"\tIngrese los Datos de la Vaca"<<endl<<endl;
				do{
					cout<<"Litros de leche: ";
					cin>>valortemp;
					if(validar(valortemp)==false){
						cout<<"\n"<<ERROR<<endl<<endl;
						system("pause");
						system("cls");
						cout<<"\tIngrese los Datos de la Vaca"<<endl<<endl;
					}else{
						istringstream(valortemp)>>lts_leche;
						bandera=1;
						if(lts_leche<0){
							cout<<"\n"<<ERROR<<endl<<endl;
							system("pause");
							system("cls");
							cout<<"\tIngrese los Datos de la Vaca"<<endl<<endl;
							bandera=0;
						}
						vacas[cont].setLitroLeche(lts_leche);						
                	}
				}while(bandera!=1);
				bandera=0;
					
			
				cont++;
				system("cls");
				cout<<"\n\n\tREGISTRO EXITOSO"<<endl<<endl;
				system("PAUSE");
				system("cls");
			break;
			
			case 2:
				if (cont ==0){
					cout<<"\n\nLA LISTA ESTA VACIA"<<endl;
					system("pause");
					system("cls");
				}else{
					do{
						cout<<"\tSeleccione el Orden Deseado"<<endl<<endl;
						cout<<"1- Por Nombre"<<endl;
						cout<<"2- Por Raza"<<endl;
						cout<<"3- Por Peso"<<endl;
						cout<<"4- Por Litros de Leche"<<endl<<endl;
						cout<<"Opcion: ";
						cin>>valortemp;
						if(validar(valortemp)==false){
							cout<<"\n"<<ERROR<<endl<<endl;
							system("pause");
						}else{
							istringstream(valortemp)>>opcOrden;
							bandera=1;
							if(opcOrden<1 || opcOrden>4){
								cout<<"\n"<<ERROR<<endl<<endl;
								system("pause");
								bandera=0;
							}
								
            			}
            			system("cls");
					}while(bandera!=1);
					bandera=0;	
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
										motodo_ordenamiento(j);
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
					
						case 3: //ORDEN POR PESO
							contOrden=1;
							cout<<"\t\t\tOrden por Peso"<<endl<<endl<<endl;
							
							for(int i=0; i<cont; i++ ){
								for(int j=0; j<=cont-2; j++){
									if(vacas[j].getPeso() > vacas[j+1].getPeso()) {
										motodo_ordenamiento(j);
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
					
						case 4: //ORDENAS POR LITROS DE LECHE
							contOrden=1;							
							cout<<"\t\tOrden por Litros de Leches Producidos"<<endl<<endl<<endl;
							for(int i=0; i<cont; i++ ){
								for(int j=0; j<=cont-2; j++){
									if(vacas[j].getLitroLeche() > vacas[j+1].getLitroLeche()) {
										motodo_ordenamiento(j);
									}
								}							
							}
												//comparar cuantas veces se repite el mismo valor y sumar
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
				}	
			break;
		}
	}while(cont<=1000 && opc!=3);
	
	
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
	cout<<endl;
}

void motodo_ordenamiento(int j){
	cows aux;
	
	aux = vacas[j];
	vacas[j] = vacas[j+1];
	vacas[j+1] = aux;						
}

void ordenarPorNombre(int c){
	string nombre1, nombre2;
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
				motodo_ordenamiento(j);
			}						
								
		}							
	}
}

void ordenOpcional(int pos, int cont){
	string nombre1, nombre2;
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
				motodo_ordenamiento(j);
			}						
								
		}							
	}
}

bool validar(string valor){
    bool valida=true;
    int tam=valor.size();
	for(int i=0;i<tam;i++){
		if((valor[i]<48 || valor[i]>57) && (valor[i]!=46)){
			valida=false;
			break;
		}
	}
	return valida;
}
