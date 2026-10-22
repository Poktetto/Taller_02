#pragma once
#include "NodoP.h"
#include "NodoAVL.h"
#include "ArbolAVL.h"
# include <string>
using namespace std;

class Servicios{
private:
    string nombre; //despues hay que cambiarlo por el Stack correspondiente
    Servicios* next;
    NodoP* cabezera; 
    ArbolAVL arbolAVLPacientes; //cada servicio tiene su AVL
public:
    Servicios(string nombre, NodoP* cabezera);
    void setNext(Servicios* next){
        this->next = next;
    }
    Servicios* getNext(){
        return next;
    }
    NodoP* getNodoP(){
        return cabezera;
    }
    string getNombre(){
        return nombre;
    }
    void setNodoP(NodoP* cabezera){
        this->cabezera = cabezera;
    }
    int getSizeNodoP(){
        int size =0;
        NodoP* temp;
        temp=cabezera;
        while (temp!=nullptr){
            size+=1;
            temp = temp->getNext();
        }
        
        return size;
    }
    ArbolAVL& getArbolP() { 
        return arbolAVLPacientes;
     } 
    ~Servicios();
};