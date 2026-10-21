#include "NodoAVL.h"
#include "Paciente.h"

using namespace std;

NodoAVL::NodoAVL(Paciente paciente) : paciente(paciente){
    this->paciente=paciente;
    this->hijoDer=nullptr;
    this->hijoIzq=nullptr;
    this->altura=1;
}
NodoAVL::~NodoAVL(){ 
}