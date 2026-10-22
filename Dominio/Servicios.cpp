#include "Servicios.h"

using namespace std;

Servicios::Servicios(string nombre, NodoP* cabezera, ArbolAVL* arbolAVLPacientes){
    this->nombre = nombre;
    this->cabezera = cabezera;
    this->arbolAVLPacientes = arbolAVLPacientes;
    
}
Servicios::~Servicios(){
}