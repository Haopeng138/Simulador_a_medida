#include "postObject.h"
#include "simulator.h"
#include "simulationobject.h"
#include "simulationevent.h"
#include <string>

using namespace std;

CPostObject::CPostObject(CSimulator* simulator,string nom):CSimulationObject(simulator,nom)
{
}


//Métode que el simulador us invocarà per a recollir els estadístics (print per consola)
void CPostObject::showStatistics()  {
    cout << m_nom <<  " No tinc estadístics";
};


//Processar un esdeveniment de simulació, funció pura que us toca implementar
void CPostObject::processEvent (CSimulationEvent* event)  {
   
}

//Métode que el simulador invocarà a l'inici de la simulació, abans de que hi hagi cap esdeveniment a la llista d'esdeveniments
void CPostObject::simulationStart()  {
    setState(sLLIURE);    
}
//Métode que el simulador us pot invocar a la finalització de l'estudi
void CPostObject::simulationEnd()  {
}