#include <iostream>
#include <fstream> //para recibir texto
#include <sstream> //para separar el texto

#include "Paciente.h" // para compilar hay que poner las clases "g++ main.cpp Paciente.cpp -o main.exe" / "g++ *.cpp -o main, .\main.exe"
#include "Servicios.h" //es exponencial, ahora hay que poner este en el compilar
#include "NodoP.h"
using namespace std;

NodoP* pacientesHead=nullptr; //Cabezera de los pacientes a atender
Servicios* serviciosHead=nullptr; //cabezera de los servicios
NodoP* historialHead=nullptr;//  cabecera del historial

void atenderPacientes(){ //metodo para atender pacientes
    cout << endl;
    int cantidad=0;
    NodoP* pacienteActual = pacientesHead; //para indicar el paciente actual / el paciente actual es temporal? /si, el unico que no es es el Head
    
    int iteracion =0; //para los numeros de pacientes;

    while (pacienteActual!=nullptr){
        iteracion += 1;
        //       |
        //print \ / 
        cout << iteracion <<". "<<pacienteActual->getPaciente().getID()<<" - "<<pacienteActual->getPaciente().getNombre()<<endl;
        pacienteActual=pacienteActual->getNext(); //posicionar el siguiente en la lista

    }
    cout << "Indique cantidad de pacientes: ";
    cin>>cantidad;
    cout << endl;
    //reset el leer la lista
    for (int i=0; i<cantidad;i++){
        if (pacientesHead == nullptr) {
            cout << "No quedan mas pacientes en la lista de espera." << endl;
            break;
        }
        pacienteActual = pacientesHead; // esto tiene que ir aqui  para que no imprima los pacientes ya atendidos
        cout<< "=== ATENDIENDO PACIENTES ==="<<endl;
        cout<< "ID: "<<pacienteActual->getPaciente().getID()<<endl;
        cout<< "Nombre: " <<pacienteActual->getPaciente().getNombre()<<endl;
        cout<< "Edad: "<<pacienteActual->getPaciente().getEdad()<<endl;
        cout<< "Servicio: " <<pacienteActual->getPaciente().getServicio()<<endl;
        cout<<endl;
        
       
        pacientesHead = pacientesHead->getNext();
        pacienteActual->setNext(nullptr); 
        NodoP* historialTemporal=new NodoP(pacienteActual->getPaciente());// se crea de esta forma evita que que colapse el programa
        historialTemporal->setNext(historialHead);//hace el guardado en formato LIFO 
        historialHead= historialTemporal;//la cabecera va abajo y el temporal arriba

        //Posicionar paciente actual en el servicio, luego borrar de la lista de pacientes en espera (pacientesHead)
        Servicios* servicioActual = serviciosHead; 
        while (servicioActual!=nullptr){

            if (pacienteActual->getPaciente().getServicio()==servicioActual->getNombre()){
                //se cumple cuando coinciden los nombres de los Servicios

                //print
                cout<<"Paciente enviado a "<<pacienteActual->getPaciente().getServicio()<<endl;
                if (servicioActual->getNodoP()==nullptr){
                    servicioActual->setNodoP(pacienteActual);  
                } else {
                    NodoP* ultimoServicio = servicioActual->getNodoP();
                    while (ultimoServicio->getNext() != nullptr) {
                        ultimoServicio = ultimoServicio->getNext();
                    }
                    ultimoServicio->setNext(pacienteActual);

                } break; //permite "eliminarlo" de la lista sin tener que borrarlo de la memoria para utilizar en los servicios
                
           
              
            }
            servicioActual = servicioActual->getNext();
        }
  
        cout<<endl;
    }
     
}
void verDepartamento(){//metodo para ver los departamentos/servicio
    int opcion = 0;
     cout << "=== DEPARTAMENTOS/SERVICIOS ===" << endl;// texto menu
        cout << "1. Urgencias" << endl;
        cout << "2. Medicina General" << endl;
        cout << "3. Cardiología" << endl;
        cout << "4. Neurología" << endl;
        cout << "5. Traumatología" << endl;
        cout << "6. Cirugía" << endl;
        cout << "7. Pediatría" << endl;
        cout << "8. Hospitalización" << endl;
        cout << "seleccione opcion: ";
        cin >>opcion;
        
        Servicios* servicioActual = serviciosHead; 
        NodoP* pacienteActual = nullptr;
        switch (opcion){ 
        case 1:
             servicioActual = serviciosHead;// esto permite que se reinicie en cada opcion para que no se pierda las demas listas
            cout<<endl;
            cout<<"=== ESTADO URGENCIAS ==="<<endl;
            cout<<"pacientes en el departamento de urgencias: "<<servicioActual->getSizeNodoP()<<endl;
           
            pacienteActual= servicioActual->getNodoP();
            while (pacienteActual!=nullptr){
                cout <<  pacienteActual->getPaciente().getNombre() << " ("<< pacienteActual->getPaciente().getEdad()<<") "<< endl;
               pacienteActual= pacienteActual-> getNext();
            }
        

           /* while (servicioActual->getNodoP()!=nullptr){
                cout << servicioActual->getNodoP()->getPaciente().getNombre() << " ("<<servicioActual->getNodoP()->getPaciente().getEdad()<<") "<< endl;
                servicioActual->setNodoP(servicioActual->getNodoP()->getNext());
            }*/
            
            break;
        case 2:
            servicioActual = serviciosHead;
            servicioActual = servicioActual->getNext();
            cout<<endl;
            cout<<"=== ESTADO MEDICINA GENERAL ==="<<endl;
            cout<<"pacientes en el departamento de medicina general: "<<servicioActual->getSizeNodoP()<<endl;
           
            pacienteActual= servicioActual->getNodoP();
            while (pacienteActual!=nullptr){
                cout <<  pacienteActual->getPaciente().getNombre() << " ("<< pacienteActual->getPaciente().getEdad()<<") "<< endl;
               pacienteActual= pacienteActual-> getNext();
            }
            
            break;

        case 3:
        //al final lo unico que cambia es el getNext y el texto
            servicioActual = serviciosHead;
            servicioActual = servicioActual->getNext()->getNext();
            cout<<endl;
            cout<<"=== ESTADO CARDIOLOGÍA ==="<<endl;
            cout<<"pacientes en el departamento de cardiología: "<<servicioActual->getSizeNodoP()<<endl;
           

            pacienteActual= servicioActual->getNodoP();
            while (pacienteActual!=nullptr){
                cout <<  pacienteActual->getPaciente().getNombre() << " ("<< pacienteActual->getPaciente().getEdad()<<") "<< endl;
               pacienteActual= pacienteActual-> getNext();
            }
            break;
        case 4:
            servicioActual = serviciosHead;
            servicioActual = servicioActual->getNext()->getNext()->getNext();
            cout<<endl;
            cout<<"=== ESTADO NEUROLOGÍA ==="<<endl;
            cout<<"pacientes en el departamento de neurología: "<<servicioActual->getSizeNodoP()<<endl;
           

            pacienteActual= servicioActual->getNodoP();
            while (pacienteActual!=nullptr){
                cout <<  pacienteActual->getPaciente().getNombre() << " ("<< pacienteActual->getPaciente().getEdad()<<") "<< endl;
               pacienteActual= pacienteActual-> getNext();
            }
            break;
        case 5:
            servicioActual = serviciosHead;
            servicioActual = servicioActual->getNext()->getNext()->getNext()->getNext();
            cout<<endl;
            cout<<"=== ESTADO TRAUMATOLOGÍA ==="<<endl;
            cout<<"pacientes en el departamento de traumatología: "<<servicioActual->getSizeNodoP()<<endl;
           

           pacienteActual= servicioActual->getNodoP();
            while (pacienteActual!=nullptr){
                cout <<  pacienteActual->getPaciente().getNombre() << " ("<< pacienteActual->getPaciente().getEdad()<<") "<< endl;
               pacienteActual= pacienteActual-> getNext();
            }
            break;
        case 6:
            servicioActual = serviciosHead;
            servicioActual = servicioActual->getNext()->getNext()->getNext()->getNext()->getNext();
            cout<<endl;
            cout<<"=== ESTADO CIRUGÍA ==="<<endl;
            cout<<"pacientes en el departamento de cirugía: "<<servicioActual->getSizeNodoP()<<endl;
           

            pacienteActual= servicioActual->getNodoP();
            while (pacienteActual!=nullptr){
                cout <<  pacienteActual->getPaciente().getNombre() << " ("<< pacienteActual->getPaciente().getEdad()<<") "<< endl;
               pacienteActual= pacienteActual-> getNext();
            }
            break;
        case 7:
            servicioActual = serviciosHead;
            servicioActual = servicioActual->getNext()->getNext()->getNext()->getNext()->getNext()->getNext();
            cout<<endl;
            cout<<"=== ESTADO PEDIATRÍA ==="<<endl;
            cout<<"pacientes en el departamento de pediatría: "<<servicioActual->getSizeNodoP()<<endl;
           

            pacienteActual= servicioActual->getNodoP();
            while (pacienteActual!=nullptr){
                cout <<  pacienteActual->getPaciente().getNombre() << " ("<< pacienteActual->getPaciente().getEdad()<<") "<< endl;
               pacienteActual= pacienteActual-> getNext();
            }
            break;
        case 8:
            servicioActual = serviciosHead;
            servicioActual = servicioActual->getNext()->getNext()->getNext()->getNext()->getNext()->getNext()->getNext();
            cout<<endl;
            cout<<"=== ESTADO HOSPITALIZACIÓN ==="<<endl;
            cout<<"pacientes en el departamento de hospitalización: "<<servicioActual->getSizeNodoP()<<endl;
           

            pacienteActual= servicioActual->getNodoP();
            while (pacienteActual!=nullptr){
                cout <<  pacienteActual->getPaciente().getNombre() << " ("<< pacienteActual->getPaciente().getEdad()<<") "<< endl;
               pacienteActual= pacienteActual-> getNext();
            }
            break;
        
        default:
            cout <<   "opcion no valida"<< endl;

            break;
        }
}
void historialAtencion(){// metodo para ver el historial de atencion
     cout << "=== HISTORIAL DE ÚLTIMAS ATENCIONES DEL HOSPITAL ===" << endl;
     if (historialHead==nullptr){
        cout<<"No hay pacientes registrados."<< endl;
        return;
     }

     NodoP* historialActual=historialHead;
     while (historialActual!=nullptr)//imprime la lista
     {
        cout<<"Nombre: "<<historialActual->getPaciente().getNombre()<<" | Edad: "<<historialActual->getPaciente().getEdad()<<" | Departamento: "<<historialActual->getPaciente().getServicio()<<endl;
        historialActual=historialActual->getNext();
     }
     
}


int main(){

    ifstream arch("pacientes.txt");
    string linea;

    
    NodoP* pacientesLast=nullptr;
    
    //creacion de pacientes
    while (getline(arch,linea)){
        //Separacion del texto
        stringstream ss(linea);
        string ID, nombre, edad, servicio;
        getline(ss, ID ,';'); //para almacenar las partes
        getline(ss, nombre, ';');
        getline(ss, edad, ';');
        getline(ss, servicio, ';');

        int intEdad = stoi(edad); //para pasarlo a int
        

        Paciente cliente(ID,nombre,intEdad,servicio); //crea el paciente (Sinceramente desconozco porque lo llame cliente)
        cout << cliente.getNombre() << endl;

        NodoP* pacienteNew = new NodoP(cliente);

        if (pacientesHead == nullptr){
            pacientesHead = pacienteNew; //guardas el primero
            pacientesLast = pacienteNew; //guardas el ultimo que es el primero
        } else {
            pacientesLast->setNext(pacienteNew); //el anterior que era el ultimo almacena el actual en su siguiente
            pacientesLast = pacienteNew; //se pociciona el actual como ultimo
        }
       
    }

    //creacion de departamentos
    //supongo que solo son los 8 departamentos
    NodoP* urgencias(nullptr);
    serviciosHead =new Servicios("Urgencias", urgencias);

    NodoP* medicinaGeneral(nullptr);
    Servicios* servicioMedGen=new Servicios("Medicina General", medicinaGeneral);
    serviciosHead->setNext(servicioMedGen); 

    NodoP* cardiologia(nullptr);
    Servicios* servicioCardio=new Servicios("Cardiologia", cardiologia);
    servicioMedGen->setNext(servicioCardio);

    NodoP* neulogia(nullptr);
    Servicios* servicioNeuro=new Servicios("Neurologia", neulogia);
    servicioCardio->setNext(servicioNeuro);

    NodoP* traumatologia(nullptr);
    Servicios* servicioTrauma=new Servicios("Traumatologia", traumatologia);
    servicioNeuro->setNext(servicioTrauma);

    NodoP* cirugia(nullptr);
    Servicios* servicioCirugia=new Servicios("Cirugia", cirugia);
    servicioTrauma->setNext(servicioCirugia);

    NodoP* pediatria(nullptr);
    Servicios* servicioPed=new Servicios("Pediatria", pediatria);
    servicioCirugia->setNext(servicioPed);

    NodoP* hospital(nullptr);
    Servicios* servicioHospital=new Servicios("Hospitalizacion", hospital);
    servicioPed->setNext(servicioHospital); 

    //siento que debe haber una mejor manera... 
    //esto crea una lista de nodos de servicio?
    //si


    //menu
    int opcion = 0;
    while (opcion!= 4)
    {
        cout << "=== HOSPITAL MARMAJA ===" << endl;// texto menu
        cout << "1. Atender pacientes" << endl;
        cout << "2. Ver departamento" << endl;
        cout << "3. Revisar historial de atención" << endl;
        cout << "4. Salir" << endl;
        cout << "seleccione opcion: ";
        cin >>opcion;
        switch (opcion)
        {
        case 1:
            atenderPacientes();
            break;
        case 2:
            verDepartamento();
            break;
        case 3:
            historialAtencion();
            break;

        case 4:
            break;
            
            
        default:
            cout <<   "opcion no valida"<< endl;
            break;
        }

    }
    
    
    
    return 0;
}

