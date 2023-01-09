#pragma once 
#include "resourceHandling.h"
#include "simulator.h"
#include "simulationobject.h"

class UnitatSuportArrencada:public CResourceHandling
{
private:
    /* data */
    float potencia;
    float potencia_subministrat;
    int numero_coneccion;
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

