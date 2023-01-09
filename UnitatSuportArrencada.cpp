#include "UnitatSuportArrencada.h"
#include "simulator.h"
#include "simulationobject.h"
#include "simulationevent.h"
#include <string> 

using namespace std;

UnitatSuportArrencada::UnitatSuportArrencada(CSimulator *simulator,string nom, int potencia, CSimulationObject *post):CResourceHandling(simulator,nom)
{
    this->potencia =float(potencia);
}

void UnitatSuportArrencada::showStatistics()
{
    std::cout << "--------------Statisticas de Unidad de Apoyo---------------" << endl;
    std::cout << "Numero de conecciones realizadas: " << numero_coneccion << " conecciones " << endl;
    std::cout << "Tiempo de carga total : " << tiempo_de_carga << " s " << endl;
    std::cout << "Potencia subministrado al avión total : " << potencia_subministrat << "(W)Vatios" << endl;
    std::cout << "--------------Statisticas de Unidad de Apoyo---------------" << endl;
}

void UnitatSuportArrencada::processEvent(CSimulationEvent *event)
{
    if (event->getEventType()==e_UNITAT_SUPORT_CARREGA && getState()==sDESCONECTAT){
        std::cout << "Conectado y cargando" << endl ;
        numero_coneccion++;
        tiempo_inicial = event->getTime();
        setState(sCONECTAT);
       
    }else if (event->getEventType()==e_UNITAT_SUPORT_CARREGA && getState()==sCONECTAT){
        std::cout << "Estas intentando conectar algo que ya está conectado" << endl;
    }

    if (event->getEventType()==e_UNITAT_SUPORT_FI_CARREGA && getState()==sCONECTAT){
        float tmp = (event->getTime()-tiempo_inicial);
        tiempo_de_carga += tmp;     
        float perdida_potencia = 1.0F-float(rand()%10)/float(100);
        potencia_subministrat += (potencia*perdida_potencia)*tmp;

        setState(sDESCONECTAT);
    }else if (event->getEventType()==e_UNITAT_SUPORT_FI_CARREGA && getState()==sDESCONECTAT){
        std::cout << "Estas intentando desconectar algo que ya no está conectado" << endl;
    }

    
   
}

void UnitatSuportArrencada::simulationStart()
{
    CResourceHandling::simulationStart();
    setState(sDESCONECTAT);
    std::cout << "Inicializando la unidad de apoyo al arranque" << endl;
    tiempo_de_carga = 0;
    potencia_subministrat = 0;
    numero_coneccion = 0;
}

void UnitatSuportArrencada::simulationEnd()
{
    if(getState()==sCONECTAT){
        std::cout << "No se ha desconectado del avion.\n Haga una revisión." << endl;
        setState(sDESCONECTAT);
        std::cout << "Se mostrará las estatisticas obtenida hasta ahora" << endl;
    }else{
        showStatistics();
    }
    
    
}
