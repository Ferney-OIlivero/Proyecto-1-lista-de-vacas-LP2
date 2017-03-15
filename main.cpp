#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <string.h>
#include <conio.h>
#include "cows.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	string auxNom;
	float aux;
	int auxI;
	cows vacas[10];
	int opc=0,cont=0;
	string nombre,raza1;
	float peso,lts_leche;
	int raza=1;
	string nombre1,nombre2;
	char nom[14], nom2[14];	
		
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
				cout<<"Nombre: ";
				cin>>nombre;
				vacas[cont].setNombre(nombre);
			
				cout<<"\nRaza: "<<endl<<endl;
				cout<<"   1- Simmental"<<endl;
				cout<<"   2- Pasiega"<<endl;
				cout<<"   3- Jersey"<<endl;
				cout<<"   4- Guernsey"<<endl;
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
				cin>>opc;
				system("cls");
				switch (opc){
					case 1:
						cout<<"\t\t\tOrden por Nombre"<<endl<<endl<<endl;
						int v;
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
							}							
						}
						// IMPRIMIR
						cout<<setw(15)<<left<<"  Nombre"<<setw(15)<<left<<"  raza"<<setw(15)<<left<<"Peso"<<setw(15)<<left<<"Litro Leche"<<endl<<endl;
						for (int x=0;x<cont;x++){
		
							if (vacas[x].getRaza()==1){
								raza1="Simmental";
							}
							else if(vacas[x].getRaza()==2){
								raza1="Pasiega";
							}
							else if(vacas[x].getRaza()==3){
								raza1="Jersey";
							}
							else if(vacas[x].getRaza()==4){
								raza1="Guernsey";
							}
		
							cout<<setw(15)<<left<<vacas[x].getNombre()<<setw(15)<<left<<raza1<<setw(15)<<left<<vacas[x].getPeso()<<setw(19)<<left<<vacas[x].getLitroLeche()<<endl;
						}
						opc=0;
						system("pause");
						system("cls");						
					break;					
					
					case 2:
						cout<<"\t\t\tOrden por Raza"<<endl<<endl<<endl;
						for(int i=0; i<cont; i++ ){
							for(int j=0; j<=cont-2; j++){
								if(vacas[j].getRaza() > vacas[j+1].getRaza()) {
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
							}								
						}
						// IMPRIMIR
						cout<<setw(15)<<left<<"  Nombre"<<setw(15)<<left<<"  raza"<<setw(15)<<left<<"Peso"<<setw(15)<<left<<"Litro Leche"<<endl<<endl;
						for (int x=0;x<cont;x++){
		
							if (vacas[x].getRaza()==1){
								raza1="Simmental";
							}
							else if(vacas[x].getRaza()==2){
								raza1="Pasiega";
							}
							else if(vacas[x].getRaza()==3){
								raza1="Jersey";
							}
							else if(vacas[x].getRaza()==4){
								raza1="Guernsey";
							}
		
							cout<<setw(15)<<left<<vacas[x].getNombre()<<setw(15)<<left<<raza1<<setw(15)<<left<<vacas[x].getPeso()<<setw(19)<<left<<vacas[x].getLitroLeche()<<endl;
						}
						opc=0;
						system("pause");
						system("cls");
						
					break;
					
					case 3:
						//Ordenar por peso
						cout<<"\t\t\tOrden por Peso"<<endl<<endl<<endl;
							
						for(int i=0; i<cont; i++ ){
							for(int j=0; j<=cont-2; j++){
								if(vacas[j].getPeso() > vacas[j+1].getPeso()) {
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
							}							
						}
						// IMPRIMIR
						cout<<setw(15)<<left<<"  Nombre"<<setw(15)<<left<<"  raza"<<setw(15)<<left<<"Peso"<<setw(15)<<left<<"Litro Leche"<<endl<<endl;
						for (int x=0;x<cont;x++){
		
							if (vacas[x].getRaza()==1){
								raza1="Simmental";
							}
							else if(vacas[x].getRaza()==2){
								raza1="Pasiega";
							}
							else if(vacas[x].getRaza()==3){
								raza1="Jersey";
							}
							else if(vacas[x].getRaza()==4){
								raza1="Guernsey";
							}
		
							cout<<setw(15)<<left<<vacas[x].getNombre()<<setw(15)<<left<<raza1<<setw(15)<<left<<vacas[x].getPeso()<<setw(19)<<left<<vacas[x].getLitroLeche()<<endl;
						}
						opc=0;
						system("pause");
						system("cls");								
					break;
					
					case 4:
						cout<<"\t\tOrden por Litros de Leches Producidos"<<endl<<endl<<endl;
						for(int i=0; i<cont; i++ ){
							int minimo = i;
							for(int j=0; j<=cont-2; j++){
								if(vacas[j].getLitroLeche() > vacas[j+1].getLitroLeche()) {
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
							}							
						}
												// IMPRIMIR
						cout<<setw(15)<<left<<"  Nombre"<<setw(15)<<left<<"  raza"<<setw(15)<<left<<"Peso"<<setw(15)<<left<<"Litro Leche"<<endl<<endl;
						for (int x=0;x<cont;x++){
		
							if (vacas[x].getRaza()==1){
								raza1="Simmental";
							}
							else if(vacas[x].getRaza()==2){
								raza1="Pasiega";
							}
							else if(vacas[x].getRaza()==3){
								raza1="Jersey";
							}
							else if(vacas[x].getRaza()==4){
								raza1="Guernsey";
							}
		
							cout<<setw(15)<<left<<vacas[x].getNombre()<<setw(15)<<left<<raza1<<setw(15)<<left<<vacas[x].getPeso()<<setw(19)<<left<<vacas[x].getLitroLeche()<<endl;
						}
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
