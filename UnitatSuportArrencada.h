#pragma once 
#include "resourceHandling.h"
#include "simulator.h"
#include "simulationobject.h"

class UnitatSuportArrencada:public CResourceHandling
{
private:
    /* data */
    int potencia;
    int potencia_subministrat;
    float tiempo_de_carga;
    float tiempo_inicial;
    CSimulationObject* m_precedecessor;
    CSimulationObject* m_successor;
public:
    UnitatSuportArrencada(CSimulator* simulator,std::string nom,int potencia,CSimulationObject* post);
    ~UnitatSuportArrencada(){};

    void showStatistics();

    void processEvent (CSimulationEvent* event);

    void simulationStart();

    void simulationEnd();

};

