#pragma once
#include <string>

class CSimulationObject;
class CSimulationEvent;

class CMission
{
public:
    CMission(){
    }
    //registra de quan l'entitat entra en el sistema
    CMission(std::string definicio){
        m_id=definicio;
    }
    virtual ~CMission(){}
    bool inFinger(){return m_finger;}//Està aparcat a finger ? o en remot (false)
    bool isLanding(){return m_landing;}//És un vol que ha aterrat o vol despegar (false)
    bool isFrozen(){return m_frozen;}//Fa fred ? o una calor de l'òstia (false)
private:
    //Actualitza la traça d'esdeveniments on aquesta entitat s'ha vist implicat
    void traceEvent(CSimulationEvent* event);   
    std::string m_id;
    bool m_landing;
    bool m_finger;
    bool m_frozen;
};

