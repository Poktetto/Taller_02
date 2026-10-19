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
    string servicio;
public:
    Paciente(string ID, string nombre, int edad, string servicio);
    ~Paciente();
    string getNombre(){
        return nombre;
    }
    string getServicio(){
        return servicio;
    }
    string getID(){
        return ID; 
    }
    int getEdad(){
        return edad;
    }
    
    

};