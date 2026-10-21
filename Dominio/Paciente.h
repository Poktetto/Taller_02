#pragma once
# include <string>
using namespace std;
//Paciente, es el obtenido de el txt
class Paciente{
private:
//se almacena la ID como string para que almacene los 0 del inicio
//Hay chance que el ordenamiento por id creo
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
        if (this->cirugia){
            return "Cirugia";
        }
        if (this->dolor>7 || this->temp>39.0){
              return   "Urgencias";
            }
         if (this->edad<16){
           return "Pediatria";
          } 
        if (this->sintNeuro){
            return "Neurologia";
         }

        if (this->trauma){
            return "Traumatologia";
        }
        if (this->pArterial>120 && this->tDolor==""){
            return "Cardiologia";
        }
        if (this->dias>1){
           
            return "Hospitalizacion";
        }else{
            return "Medicina General";
        }
        // esto es el arbol de decisiones
        
        return "errorTemp";
    }
    string getID(){
        return ID; 
    }
    int getEdad(){
        return edad;
    }
    
    

};