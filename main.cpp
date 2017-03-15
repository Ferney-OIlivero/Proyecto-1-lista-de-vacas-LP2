#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char *argv[]) {
	

	int opc=0;

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
