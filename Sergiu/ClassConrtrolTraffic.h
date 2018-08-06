#ifndef ControlTraffic_h
#define ControlTraffic_h

#include <Arduino.h>
#include <BuzzerClassTraffic.h>
#include <ConfigFileTraffic.h>
#include <ClassSemaforMasina.h>

class ControlTraffic
{
  private :

    uint8_t FrecventaNormala ;
    uint8_t DuratieNormalat ;
    uint8_t VolumNormala =;


    uint8_t FrecventaAlerta ;
    uint8_t DuratieAlerta ;
    uint8_t VolumAlerta ;
    //----------------------------------------------------------------------------------------------------------------

    //parametri control timp
    uint8_t TimpVerdeNord;
    uint8_t TimpRosuNord;
    uint8_t TimpGalbenNord;

    uint8_t TimpVerdeSud;
    uint8_t TimpRosuNordSud;
    uint8_t TimpGalbenNordSud;

    uint8_t TimpVerdeVest;
    uint8_t TimpRosuNordVest;
    uint8_t TimpGalbenNordVest;

    uint8_t TimpVerdeEst;
    uint8_t TimpRosuEst;
    uint8_t TimpGalbenEst;

    uint8_t TimpVerdePietoni;

    //------------------------------------------------------------------------------

    // pini leduri semafor masini
    uint8_t PinVerdeNord;
    uint8_t PinRosuNord;
    uint8_t PinGalbenNord;

    uint8_t PinVerdeSud;
    uint8_t PinRosuSud;
    uint8_t PinGalbenSud;

    uint8_t PinVerdeVest;
    uint8_t PinRosuVest;
    uint8_t PinGalbenVest;

    uint8_t PinVerdeEst;
    uint8_t PinRosuEst;
    uint8_t PinGalbenEst;

    //-------------------------------------------------------------------------------

    //pini semafoare pietoni
    uint8_t RedPinNord;
    uint8_t GreenPinNord;

    uint8_t RedPinSud;
    uint8_t GreenPinSud;

    uint8_t RedPinVest;
    uint8_t GreenPinVest;

    uint8_t RedPinEst;
    uint8_t GreenPinEst;

  public :
       Buzzer *Traffic;
       SemaforMasina Nord;
       SemaforMasina Sud;
       SemaforMasina Vest;
       SemaforMasina Est;

       void InitializareSemafoare();
       void TaskLoop();
       void StateMachine(uint8_t Comanda);
       uint8_t UrgentaControl();

}

#endif
