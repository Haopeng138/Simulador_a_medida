#include <iostream>
#include <list>
#include "simulationevent.h"
#include "mission.h"
#include "simulationobject.h"
#include <iostream>
#include <string>

CSimulationEvent::CSimulationEvent(float time,CSimulationObject* provider,CSimulationObject* consumer,CMission* mission,enumEventType eventType)
{//Inicialitzacions
  m_consumer=consumer;
  m_provider=provider;
  m_mission=mission;
  m_eventTime=time;
  m_eventType=eventType;
};

void CSimulationEvent::executed(){
  m_consumer->processEvent(this);
  std::cout << trace();
}

std::string CSimulationEvent::trace(){
  std::string tmp;
  if (m_consumer->getState()==sCONECTAT){
    tmp = "Conectado";
  }else if (m_consumer->getState()==sDESCONECTAT){
    tmp = "Desconectado";
  }else{
    tmp = "Otros estados";
  }
  return std::to_string(m_eventTime)+"[" + m_provider->m_nom+" -> "+m_consumer->m_nom+"] "+ m_consumer->m_nom + " "+ tmp + " \n";
 
}

