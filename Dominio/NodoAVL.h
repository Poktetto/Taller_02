#pragma once
#include "Paciente.h" 
#include <string>

using namespace std; 


class NodoAVL{// nodo para el Arbol balanciado
private:
    Paciente paciente;
    NodoAVL* hijoDer;
    NodoAVL* hijoIzq;
    int altura;
public:
    NodoAVL(Paciente paciente);
    Paciente getPaciente(){
        return paciente;
    } 
    int getAltura(NodoAVL* nodo){
        if (nodo==nullptr){
            return 0;
        } else {
            return nodo->altura;
        }
    }
    int factorBalance(){
        return getAltura(hijoIzq)- getAltura(hijoDer);
    }
    NodoAVL* rotarIzq(){
        NodoAVL* raiz =hijoDer;
        hijoDer = raiz->hijoIzq;
        raiz->hijoIzq =this;
        actualizarAltura();
        raiz->actualizarAltura(); 
        return raiz;
    }
    NodoAVL* rotarDer(){
        NodoAVL* raiz =hijoIzq;
        hijoIzq = raiz->hijoDer;
        raiz->hijoDer =this;
        actualizarAltura();
        raiz->actualizarAltura();
        return raiz;
    }


    NodoAVL* balancear(){
        actualizarAltura();
        //caso que este desbalanceado a la izquierda
        if (factorBalance()>1){
            if (hijoIzq->factorBalance()<0){ // en caso que el hijoIzq tenga un hijo en la derecha, por lo tanto mayor a el hijoIzq
                hijoIzq = hijoIzq->rotarIzq(); 
            }
            return rotarDer();
        }
        //caso que este desbalanceado a la derecha
        if (factorBalance()<-1){
            if (hijoDer->factorBalance()>0){ // en caso el hijoDer temga un hijo menor, por lo tanto al ordenar el menor debe ir antes 
                hijoDer = hijoDer->rotarDer();
            }
            return rotarIzq();
        }
        //caso que este balanciado 
        return this;
    }

    void actualizarAltura(){ //actualiza la altura correspondiendo de lo que es
        int alturaIzq = getAltura(hijoIzq);
        int alturaDer = getAltura(hijoDer);

        if (alturaIzq>alturaDer){
            altura = 1 + alturaIzq;
        } else {
            altura = 1 + alturaDer;
        }
    }

    //aclaracion IMPORTANTE, se usa el del Arbol para añadir al arbol, no este
    NodoAVL* aniadirHijo(NodoAVL* hijo){ //guarda el hijo si este es mayor se va a la Derecha
        //IMPORTANTE ID es string, aun así deberia funcionar por el orden que esta en ascii 
        
        //Derecha
        if (paciente.getID()<hijo->getPaciente().getID()){
            if (hijoDer==nullptr){
                hijoDer=hijo;
            } else {
                hijoDer = hijoDer->aniadirHijo(hijo);
            }
        //Izquierda
        } else if (paciente.getID()>hijo->getPaciente().getID()){
            if (hijoIzq==nullptr){
                hijoIzq=hijo;
            } else {
                hijoIzq = hijoIzq->aniadirHijo(hijo);
            }
        //En caso que no pase ninguno, significa que es igual
        } else {
            return this;
        }
        return balancear();
    }

    NodoAVL* buscarIDNombre(string idNombre) { //para buscar el paciente
    
    if (paciente.getID() == idNombre || paciente.getNombre()== idNombre) {
        return this;
    }
     
    //aqui busca por hijo derecho e izquierdo

    if (idNombre< paciente.getID()){
         if (hijoIzq != nullptr) { 
        NodoAVL* pacienteIzq= hijoIzq-> buscarIDNombre(idNombre);
        if (pacienteIzq != nullptr){
            return pacienteIzq;
            }
         }

    }else{
        if (hijoDer != nullptr) { 
        NodoAVL* pacienteDer= hijoDer-> buscarIDNombre(idNombre);
        if (pacienteDer != nullptr){
            return pacienteDer;
        }
    }

    }
    // aqui busca por nombre
    if (idNombre< paciente.getID()&& hijoIzq!=nullptr){
        
        NodoAVL* pacienteIzq= hijoIzq-> buscarIDNombre(idNombre);
        if (pacienteIzq != nullptr){
            return pacienteIzq;
            }
         
        }
    
        if (idNombre< paciente.getID()&& hijoDer != nullptr) { 
        NodoAVL* pacienteDer= hijoDer-> buscarIDNombre(idNombre);
        if (pacienteDer != nullptr){
            return pacienteDer;
        }
    }

    
    
         return nullptr;
    }
   
 

    ~NodoAVL();
};
