#include "resourceHandling.h"
#include "simulator.h"

using namespace std;

void CResourceHandling::simulationStart(){
    /*******
     * Quan tingueu clar els atributs es generarà un arxiu amb diferents missions (arribades o sortides d'aeronaus caracteritzades)
     * De moment sols es creant dos missions, podeu aprofitar per a fer proves canviant atributs de l'objecte missió
     * ******/
    this->m_Simulator->scheduleEvent(new CSimulationEvent(8,this,this,new CMission("una ordre"),e_UNITAT_SUPORT_CARREGA));
    this->m_Simulator->scheduleEvent(new CSimulationEvent(80,this,this,new CMission("una ordre2"),e_UNITAT_SUPORT_FI_CARREGA));
    this->m_Simulator->scheduleEvent(new CSimulationEvent(100,this,this,new CMission("una ordre"),e_UNITAT_SUPORT_CARREGA));
    this->m_Simulator->scheduleEvent(new CSimulationEvent(1700,this,this,new CMission("una ordre2"),e_UNITAT_SUPORT_FI_CARREGA));
    /*********
     * La programació dels esdeveniments temporals s'expressen en aquest cas com les unitats que cal que passin 
     * a partir del temps actual perquè l'esdeveniment es consideri executat.
     * ******/
     
}