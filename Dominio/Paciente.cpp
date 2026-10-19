#include "Paciente.h"

using namespace std;
Paciente::Paciente(string ID, string nombre, int edad, string servicio){
    this->ID = ID;
    this->nombre = nombre;
    this->edad = edad;
    this->servicio = servicio;
}
Paciente::~Paciente(){
}