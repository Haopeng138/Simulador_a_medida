#pragma once
#include "resourceHandling.h"
#include "simulator.h"
#include "simulationobject.h"

/****************
 * Un exemple de com tot funcionarà, però aquest objecte l'única cosa que demostra és que es 
 * pot enviar un event a ell mateix quan rebi el de pre i enviar un event a post
*************/
class CComissariObject:public CResourceHandling{
    public:
    CComissariObject(CSimulator* simulator,std::string nom,CSimulationObject* pre, CSimulationObject* post);
    ~CComissariObject(){}
    //Métode que el simulador us invocarà per a recollir els estadístics (print per consola)
    void showStatistics();
    //Processar un esdeveniment de simulació, funció pura que us toca implementar
    void processEvent (CSimulationEvent* event);
    //Métode que el simulador invocarà a l'inici de la simulació, abans de que hi hagi cap esdeveniment a la llista d'esdeveniments
    void simulationStart();
    //Métode que el simulador us pot invocar a la finalització de l'estudi
    void simulationEnd();
    private:
    CSimulationObject* m_predecessor;
    CSimulationObject* m_successor;
};