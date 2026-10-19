#include "Servicios.h"

using namespace std;

Servicios::Servicios(string nombre, NodoP* cabezera){
    this->nombre = nombre;
    this->cabezera = cabezera;
}
Servicios::~Servicios(){
}