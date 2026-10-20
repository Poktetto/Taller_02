#pragma once
# include <string>
using namespace std;
//Paciente, es el obtenido de el txt
class Paciente{
private:
//se almacena la ID como string para que almacene los 0 del inicio
    string ID;
    string nombre;
    int edad;
    double temp;
    int pArterial;
    int dolor;
    string tDolor;
    bool trauma;
    bool sintNeuro;
    bool cirugia;
    int dias;
public:
    Paciente(string ID, string nombre, int edad, double temp,int pArterial, int dolor, string tDolor, bool trauma, bool sintNeuro, bool cirugia, int dias );
    ~Paciente();
    string getNombre(){
        return nombre;
    }
    string getServicio(){
        return "errorTemp";
    }
    string getID(){
        return ID; 
    }
    int getEdad(){
        return edad;
    }
    
    

};