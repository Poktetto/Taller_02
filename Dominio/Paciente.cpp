#include "Paciente.h"

using namespace std;
Paciente::Paciente(string ID, string nombre, int edad,  double temp,int pArterial, int dolor, string tDolor, bool trauma, bool sintNeuro, bool cirugia, int dias ){
    this->ID = ID;
    this->nombre = nombre;
    this->edad = edad;
    this->temp = temp;
    this->dolor =dolor;
    this->tDolor =tDolor;
    this->trauma = trauma;
    this->sintNeuro = sintNeuro;
    this->pArterial = pArterial;
    this->cirugia = cirugia;
    this->dias=dias;
}
Paciente::~Paciente(){
}