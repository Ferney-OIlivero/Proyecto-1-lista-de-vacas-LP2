#include <iostream>
#include <cstdlib>
#include <cstdio>

#ifndef COWS_H
#define COWS_H

using namespace std;
class cows{
	
	public:
		void setNombre(string v);
		void setPeso(float v);
		void setLitroLeche(float v);
		void setRaza(int v);
		string getNombre();
		float getPeso();
		float getLitroLeche();
		int getRaza();	
		// class constructor
		cows();
		// class destructor
		~cows();
	private:
		string nombre;
		float peso;
		float litroLeche;
		int raza;
};

#endif // COWS_H

