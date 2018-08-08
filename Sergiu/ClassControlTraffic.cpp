#include "ClassControlTraffic.h"

//ControlTraffic* ControlTraffic :: InstanceControl= nullptr;

ControlTraffic ::  ControlTraffic (

  uint8_t ConfigFrecventaNormala,
  uint8_t ConfigDuratieNormala,
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
  uint8_t ConfigGreenPinEst
)
{
  FrecventaNormala  =  ConfigFrecventaNormala ;
  DuratieNormala  = ConfigDuratieNormala ;
  VolumNormal  = ConfigVolumNormal ;


  FrecventaAlerta  = ConfigFrecventaAlerta ;
  DuratieAlerta  = ConfigDuratieAlerta ;
  VolumAlerta  =  ConfigVolumAlerta ;
  //----------------------------------------------------------------------------------------------------------------

  //parametri control timp
  TimpVerdeNord = ConfigTimpVerdeNord ;
  TimpGalbenNord = ConfigTimpGalbenNord ;

  TimpVerdeSud =  ConfigTimpVerdeSud;
  TimpGalbenSud = ConfigTimpGalbenSud ;

  TimpVerdeVest = ConfigTimpVerdeVest ;
  TimpGalbenVest =  ConfigTimpGalbenVest;

  TimpVerdeEst = ConfigTimpVerdeEst ;
  TimpGalbenEst =  ConfigTimpGalbenEst;

  TimpVerdePietoni = ConfigTimpVerdePietoni ;
  TimpGalbenIntermitent = ConfigTimpGalbenIntermitent;
  TimpUrgenta = ConfigTimpUrgenta;
  //------------------------------------------------------------------------------

  // pini leduri semafor masini
  PinVerdeNord = ConfigPinVerdeNord ;
  PinRosuNord =  ConfigPinRosuNord;
  PinGalbenNord =  ConfigPinGalbenNord;

  PinVerdeSud = ConfigPinVerdeSud ;
  PinRosuSud =  ConfigPinRosuSud;
  PinGalbenSud = ConfigPinGalbenSud ;

  PinVerdeVest = ConfigPinVerdeVest ;
  PinRosuVest =  ConfigPinRosuVest;
  PinGalbenVest = ConfigPinGalbenVest ;

  PinVerdeEst = ConfigPinVerdeEst ;
  PinRosuEst =  ConfigPinRosuEst;
  PinGalbenEst = ConfigPinGalbenEst ;

  //-------------------------------------------------------------------------------

  //pini semafoare pietoni
  RedPinNord = ConfigRedPinNord ;
  GreenPinNord = ConfigGreenPinNord ;

  RedPinSud = ConfigRedPinSud ;
  GreenPinSud = ConfigGreenPinSud ;

  RedPinVest = ConfigRedPinVest ;
  GreenPinVest = ConfigGreenPinVest ;

  RedPinEst = ConfigRedPinEst ;
  GreenPinEst = ConfigGreenPinEst ;

}

/*ControlTraffic* ControlTraffic :: getInstanceControl(

  uint8_t ConfigFrecventaNormala,
  uint8_t ConfigDuratieNormala,
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
  uint8_t ConfigGreenPinEst)
{
  if (InstanceControl == nullptr ) {
    InstanceControl = new ControlTraffic(
      ConfigFrecventaNormala,
      ConfigDuratieNormala,
      ConfigVolumNormal,


      ConfigFrecventaAlerta,
      ConfigDuratieAlerta,
      ConfigVolumAlerta,
      //----------------------------------------------------------------------------------------------------------------

      //parametri control timp
      ConfigTimpVerdeNord,
      ConfigTimpGalbenNord,

      ConfigTimpVerdeSud,
      ConfigTimpGalbenSud,

      ConfigTimpVerdeVest,
      ConfigTimpGalbenVest,

      ConfigTimpVerdeEst,
      ConfigTimpGalbenEst,

      ConfigTimpVerdePietoni,
      ConfigTimpGalbenIntermitent,
      ConfigTimpUrgenta,
      //------------------------------------------------------------------------------

      // pini leduri semafor masini
      ConfigPinVerdeNord,
      ConfigPinRosuNord,
      ConfigPinGalbenNord,

      ConfigPinVerdeSud,
      ConfigPinRosuSud,
      ConfigPinGalbenSud,

      ConfigPinVerdeVest,
      ConfigPinRosuVest,
      ConfigPinGalbenVest,

      ConfigPinVerdeEst,
      ConfigPinRosuEst,
      ConfigPinGalbenEst,

      //-------------------------------------------------------------------------------

      //pini semafoare pietoni
      ConfigRedPinNord,
      ConfigGreenPinNord,

      ConfigRedPinSud,
      ConfigGreenPinSud,

      ConfigRedPinVest,
      ConfigGreenPinVest,

      ConfigRedPinEst,
      ConfigGreenPinEst);
  }

}*/
void ControlTraffic :: InitializareIntersectie() {

  Nord  =  SemaforMasina(PinVerdeNord, PinRosuNord, PinGalbenNord);
  Sud   =   SemaforMasina(PinVerdeSud, PinRosuSud, PinGalbenSud);
  Vest  =  SemaforMasina(PinVerdeVest, PinRosuVest, PinGalbenVest);
  Est   =   SemaforMasina(PinVerdeEst, PinRosuEst, PinGalbenEst);

  SunetTrecere = BuzzerTraffic :: getInstance (
                   ConfigFrecventaNormala,
                   ConfigDuratieNormala,
                   ConfigVolumNormal,

                   ConfigFrecventaAlerta,
                   ConfigDuratieAlerta,
                   ConfigVolumAlerta
                 );

  PietonNord = SemaforPieton(RedPinNord, GreenPinNord);
  PietonSud = SemaforPieton(RedPinSud, GreenPinSud);
  PietonVest = SemaforPieton(RedPinVest, GreenPinVest);
  PietonEst = SemaforPieton(RedPinEst, GreenPinEst);

  PietonNord.initSemaforPieton();
  PietonSud.initSemaforPieton();
  PietonVest.initSemaforPieton();
  PietonEst.initSemaforPieton();

}
void ControlTraffic :: PietoniRosu() {
  PietonNord.rosu();
  PietonSud.rosu();
  PietonVest.rosu();
  PietonEst.rosu();
}

void ControlTraffic :: GalbenIntermitent() {

  Nord.GalbenOn();
  Sud.GalbenOn();
  Vest.GalbenOn();
  Est.GalbenOn();

  delay(TimpGalbenIntermitent);

  Nord.GalbenOff();
  Sud.GalbenOff();
  Vest.GalbenOff();
  Est.GalbenOff();

  delay(TimpGalbenIntermitent);

}

void ControlTraffic :: StateMachineDumb(uint8_t Comanda) {

  switch (Comanda) {
    case 0 :
      {
        Nord.RosuOn();
        Sud.RosuOn();
        Vest.RosuOn();
        Est.RosuOn();

        elapsedMillis timeElapsed;
        while (timeElapsed < TimpVerdePietoni) {
           delay(500);
          (*SunetTrecere).RingBuzzerNormal();
          PietonNord.verde();
          PietonSud.verde();
          PietonVest.verde();
          PietonEst.verde();
          
        }
      }
      break;
    case 1 :
      {

        elapsedMillis timeElapsed;
        while (timeElapsed < TimpGalbenNord) {
          Nord.GalbenOn();
          PietoniRosu();
        }
        if (timeElapsed = !0) {
          timeElapsed = 0;
        }

        while (timeElapsed < TimpVerdeNord) {
          Nord.VerdeOn();
          PietoniRosu();
        }

        if (timeElapsed = !0) {
          timeElapsed = 0;
        }

        while (timeElapsed < TimpGalbenNord) {
          Nord.GalbenOn();
          PietoniRosu();
        }

        Nord.RosuOn();
        PietoniRosu();
      }

      break;

    case 2 :
      {
        elapsedMillis timeElapsed;
        while (timeElapsed < TimpGalbenSud) {
          Sud.GalbenOn();
          PietoniRosu();
        }

        if (timeElapsed = !0) {
          timeElapsed = 0;
        }

        while (timeElapsed < TimpVerdeSud) {
          Sud.VerdeOn();
          PietoniRosu();
        }
        if (timeElapsed = !0) {
          timeElapsed = 0;
        }

        while (timeElapsed < TimpGalbenSud) {
          Sud.GalbenOn();
          PietoniRosu();
        }


        Sud.RosuOn();
        PietoniRosu();

      }
      break;
    case 3 :
      {
        elapsedMillis timeElapsed;

        while (timeElapsed < TimpGalbenVest) {
          Vest.GalbenOn();
          PietoniRosu();
        }


        if (timeElapsed = !0) {
          timeElapsed = 0;
        }

        while (timeElapsed < TimpVerdeVest) {
          Est.VerdeOn();
          PietoniRosu();
        }

        if (timeElapsed = !0) {
          timeElapsed = 0;
        }

        while (timeElapsed < TimpGalbenVest) {
          Vest.GalbenOn();
          PietoniRosu();
        }

        Vest.RosuOn();
        PietoniRosu();
      }

      break;

    case 4 :
      {
        elapsedMillis timeElapsed;

        while (timeElapsed < TimpGalbenEst) {
          Est.GalbenOn();
          PietoniRosu();
        }


        if (timeElapsed = !0) {
          timeElapsed = 0;
        }

        while (timeElapsed < TimpVerdeEst) {
          Est.VerdeOn();
          PietoniRosu();
        }

        if (timeElapsed = !0) {
          timeElapsed = 0;
        }

        while (timeElapsed < TimpGalbenEst) {
          Est.GalbenOn();
          PietoniRosu();
        }

        Est.RosuOn();
        PietoniRosu();

      }
  }
}

void ControlTraffic :: StateMachineUrgenta(uint8_t Comanda) {

  switch (Comanda) {
    case 1 :
      {
        PietoniRosu();
        Sud.RosuOn();
        Vest.RosuOn();
        Est.RosuOn();

        elapsedMillis timeElapsed;
        while (timeElapsed < TimpUrgenta) {
          Nord.VerdeOn();
        }
        Nord.RosuOn();
      }
      break;
    case 2 : {
        PietoniRosu();
        Vest.RosuOn();
        Est.RosuOn();
        Nord.RosuOn();

        elapsedMillis timeElapsed;
        while (timeElapsed < TimpUrgenta) {
          Sud.VerdeOn();
        }
        Sud.RosuOn();
      }
      break;
    case 3: {
        PietoniRosu();
        Sud.RosuOn();
        Est.RosuOn();
        Nord.RosuOn();

        elapsedMillis timeElapsed;
        while (timeElapsed < TimpUrgenta) {
          Vest.VerdeOn();
        }
        Vest.RosuOn();
      }
      break;
    case 4 : {
        PietoniRosu();
        Sud.RosuOn();
        Nord.RosuOn();
        Vest.RosuOn();

        elapsedMillis timeElapsed;
        while (timeElapsed < TimpUrgenta) {
          Est.VerdeOn();
        }
        Est.RosuOn();
      }
      break ;
  }
}
void ControlTraffic :: TaskLoop() {

  /*for (uint8_t index  = 0; index < 3 ; index ++) {
    StateMachineDumb(index);
  }*/
      //GalbenIntermitent();
  uint8_t comanda = 1;

    if (comanda !=0) {
    StateMachineUrgenta(comanda);
    for (uint8_t index  = comanda + 1; index < 3 ; index ++) {
      StateMachineDumb(index);
      Serial.print('-');
    }
    } else {
    for (uint8_t index  = 0; index < 3 ; index ++) {
      StateMachineDumb(index);
      Serial.print('+');
    }
    }
}

