#include <iostream>
#include <clocale> //para los tildes
#include <fstream> //para recibir texto
#include <sstream> //para separar el texto
//hay que incluir el h y compilar con el cpp... 
#include "..\Dominio\Paciente.h" // para compilar hay que poner las clases "g++ Logica\main.cpp -Include Dominio\NodoP.cpp Dominio\Paciente.cpp Dominio\Servicios.cpp Dominio\ArbolAVL.cpp Dominio\NodoAVL.cpp -o main.exe"".\main.exe "
#include "..\Dominio\Servicios.h" //es exponencial, ahora hay que poner este en el compilar
#include "..\Dominio\NodoP.h"
#include "..\Dominio\ArbolAVL.h" 
#include "..\Dominio\NodoAVL.h"
using namespace std;

NodoP* pacientesHead=nullptr; //Cabezera de los pacientes a atender
Servicios* serviciosHead=nullptr; //cabezera de los servicios




void limpiarLista(NodoP* nodoAct){
    NodoP* nodoTemp = nodoAct;
    while (nodoTemp!=nullptr){
        NodoP* nodoTemp2 = nodoTemp;
        nodoTemp = nodoTemp->getNext();
        delete nodoTemp2;
    }
    nodoAct = nullptr;
    
}
void limpiarServicio(Servicios* serviciosAct){
    Servicios* servicioTemp = serviciosAct;
     while (servicioTemp!=nullptr){
        Servicios* serviciosTemp2 = servicioTemp;
        servicioTemp = servicioTemp->getNext();
        delete serviciosTemp2;
    }
    serviciosAct = nullptr;
}

void calcularRuta(Paciente pacienteActual){//calcular la ruta, usado en "Atender Pacientes"
    while (true){ //para detenerse una vez llegado al deseado 
        cout<< "ruta: ";
        if (pacienteActual.getCirugia()){
            cout<< "Cirugía == 1 "<< endl; 
            break;
        }
        cout<< "Cirugía == 0 -> ";
        if(pacienteActual.getDolor()>7|| pacienteActual.getTemp()>39.0){
            cout<< "Dolor > 7 o Temperatura > 39° "<<endl;
            break;
        }
        cout<< "Dolor < 7 o Temperatura < 39° -> ";
        if (pacienteActual.getEdad()<16){
            cout<< "Edad < 16 años "<<endl;
            break; 
        }
        cout<< "Edad > 16 años -> ";
        if (pacienteActual.getNeuro()){
            cout<< "Sintomas Neurologicos == 1 "<< endl;
            break;
        }
        cout<< "Sintomas Neurologicos == 0 ->";
        if (pacienteActual.getTrauma()){
            cout<< "Trauma == 1 "<< endl;
            break;
        }
        cout<< "Trauma == 0 ->";
        if (pacienteActual.getPArterial()>120 && pacienteActual.getTDolor()=="pecho"){
            cout<< "Presion Arterial > 120 y Tipo de dolor == pecho"<<endl;
            break;
        }
        cout << "Presion Arterial < 120 y Tipo de dolor != pecho ->";
        if (pacienteActual.getDias()>1){
            cout<< "Dias esperados en hospitalización > 1 "<<endl;
            break;
        }
        cout<< "Dias esperados en hospitalización < 1 "<<endl;
        break;
    };
 
}
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
        int temporal =0;
        
        cout<< "=== ATENDIENDO PACIENTES ==="<<endl;
        cout<< "ID: "<<pacienteActual->getPaciente().getID()<<endl;
        cout<< "Nombre: " <<pacienteActual->getPaciente().getNombre()<<endl;
        cout<< "Edad: "<<pacienteActual->getPaciente().getEdad()<<endl;
        cout<< "Temperatura: "<<pacienteActual->getPaciente().getTemp()<<endl;
        cout<< "Presion Arterial: "<<pacienteActual->getPaciente().getPArterial()<<endl;
        cout<< "Tipo de Dolor: "<<pacienteActual->getPaciente().getDolor()<<endl;
        if (pacienteActual->getPaciente().getTrauma()){temporal=1;}else {temporal=0;};
        cout<< "Trauma: "<<temporal<<endl; 
        if (pacienteActual->getPaciente().getNeuro()){temporal=1;}else {temporal=0;};
        cout<< "Sintomas Neurologicos: "<<temporal<<endl; 
        if (pacienteActual->getPaciente().getCirugia()){temporal=1;}else {temporal=0;};
        cout<< "Cirugia: "<<temporal<<endl;
        cout<< "Cantidad de dias estimados: " << pacienteActual->getPaciente().getDias()<<endl;
        cout<<endl;
       
        pacientesHead = pacientesHead->getNext();
        pacienteActual->setNext(nullptr); 
       

        //Posicionar paciente actual en el servicio, luego borrar de la lista de pacientes en espera (pacientesHead)
        Servicios* servicioActual = serviciosHead; 
        while (servicioActual!=nullptr){

            if (pacienteActual->getPaciente().getServicio()==servicioActual->getNombre()){
                //se cumple cuando coinciden los nombres de los Servicios
                
                //funcion que imprime la ruta que tomo el paciente
                calcularRuta(pacienteActual->getPaciente());
                cout<<endl;
                //print
                cout<<"Paciente enviado a "<<pacienteActual->getPaciente().getServicio()<<endl;
                Paciente paciente = pacienteActual->getPaciente();
        
       
                servicioActual->getArbolP()->aniadirNodo(new NodoAVL(paciente));
                cout<<"Paciente insertado en el AVL de "<<paciente.getServicio()<<endl;
                
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

    //hay que recorrer el AVL para esto? deberia ser, no especifica
    cout << "=== ESTADO DE LOS DEPARTAMENTOS ===" << endl;
    Servicios* servicioActual = serviciosHead; 
    NodoP* pacienteActual = nullptr;


    servicioActual = serviciosHead;// esto permite que se reinicie en cada opcion para que no se pierda las demas listas
    cout<<endl;
    cout<<"ESTADO URGENCIAS: "<<endl;
    if (servicioActual->getSizeNodoP()==0){
        cout<<"Sin pacientes"<< endl;
    } else {
         cout<<"pacientes en el departamento de urgencias: "<<servicioActual->getSizeNodoP()<<endl;
    }
   

    pacienteActual= servicioActual->getNodoP();
    while (pacienteActual!=nullptr){
        cout <<  pacienteActual->getPaciente().getNombre() << " ("<< pacienteActual->getPaciente().getEdad()<<") "<< endl;
        pacienteActual= pacienteActual-> getNext();
    }


    servicioActual = serviciosHead;
    servicioActual = servicioActual->getNext();
    cout<<endl;
    cout<<"ESTADO MEDICINA GENERAL: "<<endl;
       if (servicioActual->getSizeNodoP()==0){
        cout<<"Sin pacientes"<< endl;
    } else {
    cout<<"pacientes en el departamento de medicina general: "<<servicioActual->getSizeNodoP()<<endl;
    }   
    pacienteActual= servicioActual->getNodoP();
    while (pacienteActual!=nullptr){
        cout <<  pacienteActual->getPaciente().getNombre() << " ("<< pacienteActual->getPaciente().getEdad()<<") "<< endl;
        pacienteActual= pacienteActual-> getNext();
    }


    servicioActual = serviciosHead;
    servicioActual = servicioActual->getNext()->getNext();
    cout<<endl;
    cout<<"ESTADO CARDIOLOGÍA: "<<endl;
       if (servicioActual->getSizeNodoP()==0){
        cout<<"Sin pacientes"<< endl;
    } else {
    cout<<"pacientes en el departamento de cardiología: "<<servicioActual->getSizeNodoP()<<endl;
    }     

    pacienteActual= servicioActual->getNodoP();
    while (pacienteActual!=nullptr){
        cout <<  pacienteActual->getPaciente().getNombre() << " ("<< pacienteActual->getPaciente().getEdad()<<") "<< endl;
        pacienteActual= pacienteActual-> getNext();
    }


    servicioActual = serviciosHead;
    servicioActual = servicioActual->getNext()->getNext()->getNext();
    cout<<endl;
    cout<<"ESTADO NEUROLOGÍA: "<<endl;
       if (servicioActual->getSizeNodoP()==0){
        cout<<"Sin pacientes"<< endl;
    } else {
    cout<<"pacientes en el departamento de neurología: "<<servicioActual->getSizeNodoP()<<endl;
    }

    pacienteActual= servicioActual->getNodoP();
    while (pacienteActual!=nullptr){
        cout <<  pacienteActual->getPaciente().getNombre() << " ("<< pacienteActual->getPaciente().getEdad()<<") "<< endl;
        pacienteActual= pacienteActual-> getNext();
    }


    servicioActual = serviciosHead;
    servicioActual = servicioActual->getNext()->getNext()->getNext()->getNext();
    cout<<endl;
    cout<<"ESTADO TRAUMATOLOGÍA: "<<endl;
       if (servicioActual->getSizeNodoP()==0){
        cout<<"Sin pacientes"<< endl;
    } else {
    cout<<"pacientes en el departamento de traumatología: "<<servicioActual->getSizeNodoP()<<endl;
    }      

    pacienteActual= servicioActual->getNodoP();
    while (pacienteActual!=nullptr){
        cout <<  pacienteActual->getPaciente().getNombre() << " ("<< pacienteActual->getPaciente().getEdad()<<") "<< endl;
        pacienteActual= pacienteActual-> getNext();
    }


    servicioActual = serviciosHead;
    servicioActual = servicioActual->getNext()->getNext()->getNext()->getNext()->getNext();
    cout<<endl;
    cout<<"ESTADO CIRUGÍA: "<<endl;
       if (servicioActual->getSizeNodoP()==0){
        cout<<"Sin pacientes"<< endl;
    } else {
    cout<<"pacientes en el departamento de cirugía: "<<servicioActual->getSizeNodoP()<<endl;
    }      

    pacienteActual= servicioActual->getNodoP();
    while (pacienteActual!=nullptr){
        cout <<  pacienteActual->getPaciente().getNombre() << " ("<< pacienteActual->getPaciente().getEdad()<<") "<< endl;
        pacienteActual= pacienteActual-> getNext();
    }


    servicioActual = serviciosHead;
    servicioActual = servicioActual->getNext()->getNext()->getNext()->getNext()->getNext()->getNext();
    cout<<endl;
    cout<<"ESTADO PEDIATRÍA: "<<endl;
       if (servicioActual->getSizeNodoP()==0){
        cout<<"Sin pacientes"<< endl;
    } else {
    cout<<"pacientes en el departamento de pediatría: "<<servicioActual->getSizeNodoP()<<endl;
    }

    pacienteActual= servicioActual->getNodoP();
    while (pacienteActual!=nullptr){
        cout <<  pacienteActual->getPaciente().getNombre() << " ("<< pacienteActual->getPaciente().getEdad()<<") "<< endl;
        pacienteActual= pacienteActual-> getNext();
    }

    servicioActual = serviciosHead;
    servicioActual = servicioActual->getNext()->getNext()->getNext()->getNext()->getNext()->getNext()->getNext();
    cout<<endl;
    cout<<"ESTADO HOSPITALIZACIÓN: "<<endl;
       if (servicioActual->getSizeNodoP()==0){
        cout<<"Sin pacientes"<< endl;
    } else {
    cout<<"pacientes en el departamento de hospitalización: "<<servicioActual->getSizeNodoP()<<endl;
    }       

    pacienteActual= servicioActual->getNodoP();
    while (pacienteActual!=nullptr){
        cout <<  pacienteActual->getPaciente().getNombre() << " ("<< pacienteActual->getPaciente().getID()<<") "<< endl;
        pacienteActual= pacienteActual-> getNext();
    }
 
}



void buscarPaciente(){// metodo para buscar paciente
     cout << "=== BUSCAR PACIENTE ===" << endl;
     string opcion;
     cout << "Indique el ID o Nombre del paciente: ";
        cin >>opcion;


    
     cout << "Buscando en AVL..."<< endl;
    
    NodoAVL* pacienteB = serviciosHead->buscarPacienteS(opcion);

    if (pacienteB!= nullptr){
        
         cout << "Paciente encontrado:"<<endl;
         cout<< "ID: "<<pacienteB->getPaciente().getID()<<endl;
        cout<< "Nombre: " <<pacienteB->getPaciente().getNombre()<<endl;
        cout<< "Edad: "<<pacienteB->getPaciente().getEdad()<<endl;
        cout<< "Departamento: "<<pacienteB->getPaciente().getServicio()<<endl;
        cout<< "T: "<<pacienteB->getPaciente().getTemp()<<"° ";
        cout<< "| P A: "<<pacienteB->getPaciente().getPArterial() ;
        cout<< " | Tipo de Dolor: "<<pacienteB->getPaciente().getDolor();
        cout<< " | T: "; 
        if (pacienteB->getPaciente().getTrauma()){cout<< " Si";}else {cout<< " No";};
        cout<< " | SN: "; 
        if (pacienteB->getPaciente().getNeuro()){cout<< " Si";}else {cout<< " No";};
         cout<< " | RC: ";
        if (pacienteB->getPaciente().getCirugia()){cout<< " Si";}else {cout<< " No";};
       
        cout<< " | DH:" << pacienteB->getPaciente().getDias()<<endl; // nose a que se refiere ninguno
        cout<<endl;

    }else{
        cout << "Paciente no encontrado:";
    }

  
}


int main(){

    //para tildes
    setlocale(LC_ALL, "es_ES.UTF-8");



    ifstream arch("pacientes.txt");
    string linea;

    
    NodoP* pacientesLast=nullptr;
    
    //creacion de pacientes
    while (getline(arch,linea)){
        //Separacion del texto
        stringstream ss(linea);
        string ID, nombre, edad, temp, pArterial,dolor,tDolor,trauma,sintNeuro,cirugia,dias;
        getline(ss, ID ,';'); //para almacenar las partes
        getline(ss, nombre, ';');
        getline(ss, edad, ';'); int intEdad = stoi(edad);
        getline(ss, temp, ';'); double doubleTemp = stod(temp);
        getline(ss, pArterial, ';'); int intArterial = stoi(pArterial);
        getline(ss, dolor, ';'); int intDolor = stoi(dolor);
        getline(ss, tDolor, ';'); 
        getline(ss, trauma, ';'); int intTrauma = stoi(trauma);
        getline(ss, sintNeuro, ';'); int intNeuro = stoi(sintNeuro);
        getline(ss, cirugia, ';'); int intCirugia = stoi(cirugia);
        getline(ss, dias, ';'); int intDias = stoi(dias);
        //separa y transforma a lo que necesitamos para el paciente
        

        Paciente cliente(ID,nombre,intEdad,doubleTemp,intArterial,intDolor,tDolor,intTrauma==1,intNeuro==1,intCirugia==1,intDias); //crea el paciente 
        //cout << cliente.getNombre() << endl; //print para revisar si se crea la lista

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
 
    NodoP* urgencias(nullptr);
    serviciosHead =new Servicios("Urgencias", urgencias, new ArbolAVL());

    NodoP* medicinaGeneral(nullptr);
    Servicios* servicioMedGen=new Servicios("Medicina General", medicinaGeneral, new ArbolAVL());
    serviciosHead->setNext(servicioMedGen); 

    NodoP* cardiologia(nullptr);
    Servicios* servicioCardio=new Servicios("Cardiologia", cardiologia, new ArbolAVL());
    servicioMedGen->setNext(servicioCardio);

    NodoP* neulogia(nullptr);
    Servicios* servicioNeuro=new Servicios("Neurologia", neulogia, new ArbolAVL());
    servicioCardio->setNext(servicioNeuro);

    NodoP* traumatologia(nullptr);
    Servicios* servicioTrauma=new Servicios("Traumatologia", traumatologia, new ArbolAVL());
    servicioNeuro->setNext(servicioTrauma);

    NodoP* cirugia(nullptr);
    Servicios* servicioCirugia=new Servicios("Cirugia", cirugia, new ArbolAVL());
    servicioTrauma->setNext(servicioCirugia);

    NodoP* pediatria(nullptr);
    Servicios* servicioPed=new Servicios("Pediatria", pediatria, new ArbolAVL());
    servicioCirugia->setNext(servicioPed);

    NodoP* hospital(nullptr);
    Servicios* servicioHospital=new Servicios("Hospitalizacion", hospital, new ArbolAVL());
    servicioPed->setNext(servicioHospital); 

   


    //menu
    int opcion = 0;
    while (opcion!= 4)
    {
        cout << "=== HOSPITAL MARMAJA ===" << endl;// texto menu
        cout << "1. Atender pacientes" << endl;
        cout << "2. Ver departamentos" << endl;
        cout << "3. Buscar Paciente" << endl;
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
            buscarPaciente();
            break;

        case 4:
            limpiarLista(pacientesHead);
       
            limpiarServicio(serviciosHead);
            break;
            
            
        default:
            cout <<   "opcion no valida"<< endl;
            break;
        }

    }
    
    
    
    return 0;
}

