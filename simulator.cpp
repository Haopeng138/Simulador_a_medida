#include "simulator.h"
#include "simulationevent.h"
#include "eventlist.h"
#include "preObject.h"
#include "postObject.h"
#include "ComissariObject.h"
#include "UnitatSuportArrencada.h"

CSimulator::CSimulator(){
    //Aquest mètode el podeu canviar si ho creieu necessari
    std::cout << "Exemple amb dos elements \n";
    m_predecessor=new CPreObject(this,"PreObjecte");
    m_successor=new CPostObject(this,"PostObjecte");
    // mnty=new CComissariObject(this,"Comissari",m_predecessor,m_successor);
    mnty=new UnitatSuportArrencada(this,60,m_successor);
   
    run();
}
CSimulator::~CSimulator(){
    //Eliminem objectes que formen part del model
    while (m_objectes.size()>0)
    {
        delete m_objectes.front();
        m_objectes.pop_front();
    }
    //Eliminem la llista d'esdeveniments
    m_eventList->reset();
    delete m_eventList;
}
void CSimulator::run(){
    std::cout << "Iniciem el run\n";
    simulationStart();
    while (!simulationFinished())
    {
        CSimulationEvent* event=(CSimulationEvent*)this->m_eventList->remove();
        m_currentTime=event->getTime();
        event->executed();
        delete event;
    }
    std::cout << "Fi de la simulación\n";
    simulationEnd();
    std::cout << "Hem mostrat els estadístics\n";
}

void CSimulator::simulationStart()
{
    m_eventList=new CEventList();
    //Feu allò que creieu necessari en base el que hem explicat a teoria i hem vist dins de Flexsim.
    mnty->simulationStart();
}

void CSimulator::simulationEnd()
{
   mnty->simulationEnd();
}

bool CSimulator::simulationFinished(){
    return this->m_eventList->isEmpty();
}

void CSimulator::scheduleEvent(CSimulationEvent* event){
    m_eventList->insert(event);
}