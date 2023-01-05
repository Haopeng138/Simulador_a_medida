#include "UnitatSuportArrencada.h"
#include "simulator.h"
#include "simulationobject.h"
#include "simulationevent.h"
#include <string> 

using namespace std;

UnitatSuportArrencada::UnitatSuportArrencada(CSimulator *simulator, int potencia, CSimulationObject *post)
{
}

void UnitatSuportArrencada::showStatistics()
{
    std::cout << "Potencia subministrat al avió : " << potencia_subministrat << "(W)Vatios";
}

void UnitatSuportArrencada::processEvent(CSimulationEvent *event)
{
    if (event->getEventType()==e_UNITAT_SUPORT_CARREGA && getState()==sDESCONECTAT){
        tiempo_inicial = event->getTime();
        setState(sCONECTAT);
        std::cout << "Conetado y cargando" ;
    }

    if (event->getEventType()==e_UNITAT_SUPORT_FI_CARREGA && getState()==sCONECTAT){
        potencia_subministrat += potencia*(event->getTime()-tiempo_inicial);
    }
}

void UnitatSuportArrencada::simulationStart()
{
    CResourceHandling::simulationStart();
    setState(sDESCONECTAT);
    potencia_subministrat = 0;
}

void UnitatSuportArrencada::simulationEnd()
{
    showStatistics();
}
