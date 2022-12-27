#include "ComissariObject.h"
#include "simulator.h"
#include "simulationobject.h"
#include "simulationevent.h"
#include <string>

using namespace std;

CComissariObject::CComissariObject(CSimulator* simulator,string nom,CSimulationObject* predecessor,CSimulationObject* successor):CResourceHandling(simulator,nom)
{
    //Atenció els que tingueu més d'un predecessor i un successor
    m_predecessor=predecessor;
    m_successor=successor;
}

//Métode que el simulador us invocarà per a recollir els estadístics (print per consola)
void CComissariObject::showStatistics()  {
    cout << m_nom <<  " No tinc estadístics, això penalitzarà";
};
    
//Processar un esdeveniment de simulació, funció pura que us toca implementar
void CComissariObject::processEvent (CSimulationEvent* event)  {
    //Sols pot rebre dos events i sols té un estat
    if (event->getEventType()==eORDRE){
        /********
         * de tipus eORDRE, que tindrà una missió i per tant he de demanar al predecessor que m'envii l'event de eSTART
         * atenció!!!, recordeu que els esdeveniments no poden ser constants ni immediats, apliqueu alguna distribució
         * *****/
        m_predecessor->sendMeEvent(new CSimulationEvent(10,m_predecessor,this,event->getMission(),eSTART));
    }
    if (event->getEventType()==eSTART){
        /*********
         * de tipus eSTART en aquest cas podria programar el seu primer event dins del procediment d'actuació que tingui 
         * (fixeu-vos que aquest element no es mou, els vostres si que hauran de fer-ho), però aquest objecte és FAKE així
         * que no farà res i considera que pot transmetre l'ordre d'START al seu successor.
         * Pareu ull, que cal propagar l'ordre, de forma que la missió aniria passant per diferents objectes de simulació
         * ********/
        CSimulationEvent* unEvent=new CSimulationEvent(20,this,m_successor,event->getMission(),eSTART);
        m_Simulator->scheduleEvent(unEvent);
    }
}

//Métode que el simulador invocarà a l'inici de la simulació, abans de que hi hagi cap esdeveniment a la llista d'esdeveniments
void CComissariObject::simulationStart(){
    //Invoquem al pare pq ens crearà les missions de tot el dia, però no les veurem pq estaran com esdeveniments de simulació
    CResourceHandling::simulationStart();
    setState(sLLIURE);
}
//Métode que el simulador us pot invocar a la finalització de l'estudi
void CComissariObject::simulationEnd()  {
    showStatistics();
}