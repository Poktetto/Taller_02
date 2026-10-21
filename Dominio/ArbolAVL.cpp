#include "ArbolAVL.h" 
#include <string>
using namespace std; 

ArbolAVL::ArbolAVL(string tipo){
    this->tipo = tipo;
    this->raiz = nullptr;
    this->siguiente = nullptr;

}