#pragma once
#include "NodoAVL.h" 
#include <string>
using namespace std; 


class ArbolAVL{// Guarda la Raiz, e indica los otros servivcios
private:
    NodoAVL* raiz;
    ArbolAVL* siguiente; //el siguiente arbol de servicio
public:
    ArbolAVL();

    void aniadirNodo(NodoAVL* nuevo){//llama a añadirHijo
        if (raiz==nullptr){
            raiz = nuevo;
        } else{
            raiz = raiz->aniadirHijo(nuevo);
        }
    }
    void setNext(ArbolAVL* siguiente){
        this->siguiente=siguiente;
    }
    NodoAVL* getRaiz(){
        return raiz;
    }
    ArbolAVL* getNext(){ //siguiente servicio 
        return siguiente;
    }
    ~ArbolAVL();
};
