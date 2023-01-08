#include "UnitatSuportArrencada.h"
#include "simulator.h"
#include "simulationobject.h"
#include "simulationevent.h"
#include <string> 

using namespace std;

UnitatSuportArrencada::UnitatSuportArrencada(CSimulator *simulator,string nom, int potencia, CSimulationObject *post):CResourceHandling(simulator,nom)
{
    this->potencia = potencia;
}

void UnitatSuportArrencada::showStatistics()
{
    std::cout << "Temps de carga total : " << tiempo_de_carga << " s " << endl;
    std::cout << "Potencia subministrat al avió total : " << potencia_subministrat << "(W)Vatios" << endl;
}

void UnitatSuportArrencada::processEvent(CSimulationEvent *event)
{
    if (event->getEventType()==e_UNITAT_SUPORT_CARREGA && getState()==sDESCONECTAT){
        std::cout << "Conectado y cargando" << endl ;
        tiempo_inicial = event->getTime();
        setState(sCONECTAT);
       
    }

    if (event->getEventType()==e_UNITAT_SUPORT_FI_CARREGA && getState()==sCONECTAT){
        float tmp = (event->getTime()-tiempo_inicial);
        tiempo_de_carga += tmp; 
        potencia_subministrat += potencia*tmp;
        setState(sDESCONECTAT);
    }

   
}

void UnitatSuportArrencada::simulationStart()
{
    CResourceHandling::simulationStart();
    setState(sDESCONECTAT);
    std::cout << "Inicializando la unidad de apoyo al arranque" << endl;
    tiempo_de_carga = 0;
    potencia_subministrat = 0;
}

void UnitatSuportArrencada::simulationEnd()
{

    showStatistics();
}
