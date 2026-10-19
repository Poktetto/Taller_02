#include "NodoP.h"
#include "Paciente.h"

using namespace std;

NodoP::NodoP(Paciente paciente): paciente(paciente){
    this->paciente= paciente;
    this->next =nullptr;
}
Paciente NodoP ::getPaciente(){return this->paciente;}
NodoP* NodoP::getNext(){return this ->next;}
void NodoP::setNext(NodoP* next){
    this->next =next;
}
void NodoP::setPaciente(Paciente paciente){
    this-> paciente =paciente;
}


NodoP::~NodoP(){}

