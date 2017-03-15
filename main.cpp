#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "cows.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	cows vacas[10];
	int opc=0,cont=0;
	string nombre;
	float peso,lts_leche;
	int raza=1;
		
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
						
					
					case 2:
						cout<<"\t\t\tOrden por Raza"<<endl<<endl<<endl;
						
						
					break;
					
					case 3:
						//Ordenar por peso
						cout<<"\t\t\tOrden por Peso"<<endl<<endl<<endl;
							
					break;
					
					case 4:
						cout<<"\t\tOrden por Litros de Leches Producidos"<<endl<<endl<<endl;
						
					break;
					
				}
			break;
			case 3:
				return 0;
			break;
		}
	}while(opc!=3);
	
	
	return 0;
}
