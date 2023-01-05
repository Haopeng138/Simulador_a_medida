#pragma once
#include "simulationobject.h"
#include <string>



class CMission;

//Afegiu els enumerats que considereu necessaris...
enum enumEventType {
    eORDRE,eMOURE,eAPARCAR,eSTART,
    /*Propias*/
    e_UNITAT_SUPORT_CARREGA,e_UNITAT_SUPORT_FI_CARREGA};
/*
* eORDRE --> el recurs rep una missió
* eMOURE --> el recurs es mou
* eAPARCAR --> el recurs aparca
* eSTART --> el recurs pot arrancar les seves operacions
* e_UNITAT_SUPORT_CARREGA --> La bateria envia energia cap l'avio
*/

class CSimulationEvent{
    public:
        CSimulationEvent(){};
        CSimulationEvent(float time,CSimulationObject* provider,CSimulationObject* consumer,CMission* mission,enumEventType eventType);
        ~CSimulationEvent(){};
        float getTime(){return m_eventTime;};
        CSimulationObject* getProvider(){return m_provider;};
        CSimulationObject* getConsumer(){return m_consumer;};
        CMission* getMission(){return m_mission;};
        enumEventType getEventType(){return m_eventType;};
        void executed();
        std::string trace();
    protected:
        CSimulationObject* m_provider;
        CSimulationObject* m_consumer;
        CMission* m_mission;
        enumEventType m_eventType;
        float m_eventTime;
};


