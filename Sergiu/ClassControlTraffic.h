#ifndef ControlTraffic_h
#define ControlTraffic_h

#include <Arduino.h>
#include <BuzzerClassTraffic.h>
#include <ConfigFileTraffic.h>
#include <ClassSemaforMasina.h>
#include <SemaforPieton.h>
#include <elapsedMillis.h>
#include <SPI.h>

class ControlTraffic
{
  private :

    uint8_t FrecventaNormala ;
    uint8_t DuratieNormala ;
    uint8_t VolumNormal ;


    uint8_t FrecventaAlerta ;
    uint8_t DuratieAlerta ;
    uint8_t VolumAlerta ;
    //----------------------------------------------------------------------------------------------------------------

    //parametri control timp
    uint16_t TimpVerdeNord;
    uint16_t TimpGalbenNord;

    uint16_t TimpVerdeSud;
    uint16_t TimpGalbenSud;

    uint16_t TimpVerdeVest;
    uint16_t TimpGalbenVest;

    uint16_t TimpVerdeEst;
    uint16_t TimpGalbenEst;

    uint16_t TimpVerdePietoni;
    uint16_t TimpGalbenIntermitent;
    uint16_t TimpUrgenta;
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
    uint8_t index;

    //------------------------
    //Pini SPI pentru mega
    uint8_t MOSI ;
    uint8_t MISO ;
    uint8_t SCK ;
    uint8_t SS ;



  public :

    ControlTraffic(

      uint8_t ConfigFrecventaNormala,
      uint8_t ConfigDuratieNormalat,
      uint8_t ConfigVolumNormal,


      uint8_t ConfigFrecventaAlerta,
      uint8_t ConfigDuratieAlerta,
      uint8_t ConfigVolumAlerta,
      //----------------------------------------------------------------------------------------------------------------

      //parametri control timp
      uint16_t ConfigTimpVerdeNord,
      uint16_t ConfigTimpGalbenNord,

      uint16_t ConfigTimpVerdeSud,
      uint16_t ConfigTimpGalbenSud,

      uint16_t ConfigTimpVerdeVest,
      uint16_t ConfigTimpGalbenVest,

      uint16_t ConfigTimpVerdeEst,
      uint16_t ConfigTimpGalbenEst,

      uint16_t ConfigTimpVerdePietoni,
      uint16_t ConfigTimpGalbenIntermitent,
      uint16_t ConfigTimpUrgenta,
      //------------------------------------------------------------------------------

      // pini leduri semafor masini
      uint8_t ConfigPinVerdeNord,
      uint8_t ConfigPinRosuNord,
      uint8_t ConfigPinGalbenNord,

      uint8_t ConfigPinVerdeSud,
      uint8_t ConfigPinRosuSud,
      uint8_t ConfigPinGalbenSud,

      uint8_t ConfigPinVerdeVest,
      uint8_t ConfigPinRosuVest,
      uint8_t ConfigPinGalbenVest,

      uint8_t ConfigPinVerdeEst,
      uint8_t ConfigPinRosuEst,
      uint8_t ConfigPinGalbenEst,

      //-------------------------------------------------------------------------------

      //pini semafoare pietoni
      uint8_t ConfigRedPinNord,
      uint8_t ConfigGreenPinNord,

      uint8_t ConfigRedPinSud,
      uint8_t ConfigGreenPinSud,

      uint8_t ConfigRedPinVest,
      uint8_t ConfigGreenPinVest,

      uint8_t ConfigRedPinEst,
      uint8_t ConfigGreenPinEst,

      uint8_t ConfigMOSI ,
      uint8_t ConfigMISO ,
      uint8_t ConfigSCK ,
      uint8_t ConfigSS 

    );
 

    BuzzerTraffic *SunetTrecere;

    SemaforMasina Nord;
    SemaforMasina Sud;
    SemaforMasina Vest;
    SemaforMasina Est;

    SemaforPieton PietonNord;
    SemaforPieton PietonSud;
    SemaforPieton PietonVest;
    SemaforPieton PietonEst;

    //metode
    void InitializareIntersectie();
    void TaskLoop();
    void StateMachineDumb(uint8_t Comanda);
    void StateMachineUrgenta(uint8_t Comanda);
    uint8_t ControlIntersectie(uint8_t IFVerde, uint8_t stare);
    void PietoniRosu();
    void GalbenIntermitent();
    uint8_t ComandaControl();
    void ControlTranzitie(uint8_t IfVerde, uint8_t stare,uint8_t comanda);

};

#endif
