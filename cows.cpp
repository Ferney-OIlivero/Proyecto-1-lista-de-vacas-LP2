#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "cows.h"
using namespace std;

void cows::setNombre(string v){
	this->nombre=v;
}

void cows::setPeso(float v){
	this->peso=v;
}

void cows::setLitroLeche(float v){
	this->litroLeche=v;
}

void cows::setRaza(int v){
	this->raza=v;
}

string cows::getNombre(){
	return this->nombre;
}

int cows::getRaza(){
	return this->raza;
}

float cows::getPeso(){
	return this->peso;
}

float cows::getLitroLeche(){
	return this->litroLeche;
}
// class constructor
cows::cows()
{
	// insert your code here
}

// class destructor
cows::~cows()
{
	// insert your code here
}

