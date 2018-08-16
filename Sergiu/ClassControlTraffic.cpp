#include "ClassControlTraffic.h"

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
  uint8_t ConfigGreenPinEst,

  uint8_t ConfigMOSI ,
  uint8_t CinfigMISO ,
  uint8_t ConfigSCK ,
  uint8_t ConfigSS
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

  //--------------------------------------------------------------------------------
  //Pini SPI

  MOSI = ConfigMOSI;
  MISO = ConfigMISO;
  SCK  = ConfigSCK;
  SS = ConfigSS;

}

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
  uint8_t VerdeOn = 1;
  uint8_t VerdeOff = 0;

  switch (Comanda) {
    case 0 :
      {
        uint8_t CurrentState = 0;
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
          if (ControlIntersectie(VerdeOn , CurrentState) == 1) {
            StateMachineDumb('B');
          }
        }
        break;
      }

    case 1 :
      {
        uint8_t CurrentState = 1;
        elapsedMillis timeElapsed;
        while (timeElapsed < TimpGalbenNord) {
          Nord.GalbenOn();
          PietoniRosu();
          if ( ControlIntersectie(VerdeOff,  CurrentState) == 1 ) {
            StateMachineDumb('B');
          }
        }

        if (timeElapsed = !0) {
          timeElapsed = 0;
        }

        while (timeElapsed < TimpVerdeNord) {
          Nord.VerdeOn();
          PietoniRosu();
          if (ControlIntersectie(VerdeOn, CurrentState) == 1) {
            StateMachineDumb('B');
          }
        }


        if (timeElapsed = !0) {
          timeElapsed = 0;
        }


        while (timeElapsed < TimpGalbenNord) {
          Nord.GalbenOn();
          PietoniRosu();
          if (ControlIntersectie(VerdeOff, CurrentState) == 1) {
            StateMachineDumb('B');
          }
        }

        Nord.RosuOn();
        break;
      }


    case 2 :
      {
        uint8_t CurrentState = 2;
        elapsedMillis timeElapsed;
        while (timeElapsed < TimpGalbenSud) {
          Sud.GalbenOn();
          PietoniRosu();
          if (ControlIntersectie(VerdeOff, CurrentState) == 1) {
            StateMachineDumb('B');
          }
        }

        if (timeElapsed = !0) {
          timeElapsed = 0;
        }

        while (timeElapsed < TimpVerdeSud) {
          Sud.VerdeOn();
          PietoniRosu();
          if (ControlIntersectie(VerdeOn , CurrentState) == 1) {
            StateMachineDumb('B');
          }
        }

        if (timeElapsed = !0) {
          timeElapsed = 0;
        }

        while (timeElapsed < TimpGalbenSud) {
          Sud.GalbenOn();
          PietoniRosu();
          if (ControlIntersectie(VerdeOff, CurrentState) == 1) {
            StateMachineDumb('B');
          }
        }
        Sud.RosuOn();
        break;
      }

    case 3 :
      {

        uint8_t CurrentState = 3;
        elapsedMillis timeElapsed;
        while (timeElapsed < TimpGalbenVest) {
          Vest.GalbenOn();
          PietoniRosu();
          if (ControlIntersectie(VerdeOff, CurrentState) == 1) {
            StateMachineDumb('B');
          }
        }

        if (timeElapsed = !0) {
          timeElapsed = 0;
        }


        while (timeElapsed < TimpVerdeVest) {
          Vest.VerdeOn();
          PietoniRosu();
          if (ControlIntersectie(VerdeOn, CurrentState) == 1) {
            StateMachineDumb('B');
          }
        }

        if (timeElapsed = !0) {
          timeElapsed = 0;
        }

        while (timeElapsed < TimpGalbenVest) {
          Vest.GalbenOn();
          PietoniRosu();
          if (ControlIntersectie(VerdeOff, CurrentState) == 1) {
            StateMachineDumb('B');
          }
        }

        Vest.RosuOn();
        break;
      }


    case 4 :
      {
        uint8_t CurrentState = 4;
        elapsedMillis timeElapsed;
        while (timeElapsed < TimpGalbenEst) {
          Est.GalbenOn();
          PietoniRosu();
          if (ControlIntersectie(VerdeOff, CurrentState) == 1) {
            StateMachineDumb('B');
          }
        }

        if (timeElapsed = ! 0) {
          timeElapsed = 0;
        }


        while (timeElapsed < TimpVerdeEst) {
          Est.VerdeOn();
          PietoniRosu();
          if (ControlIntersectie(VerdeOn, CurrentState) == 1) {
            StateMachineDumb('B');
          }
        }

        if (timeElapsed = !0) {
          timeElapsed = 0;
        }



        while (timeElapsed < TimpGalbenEst) {
          Est.GalbenOn();
          PietoniRosu();
          if (ControlIntersectie(VerdeOff, CurrentState) == 1) {
            StateMachineDumb('B');
          }
        }

        Est.RosuOn();
        break;
      }

    case 'B' : {
        break;
      }
      break;
  }
}

void  ControlTraffic :: ControlTranzitie(uint8_t IfVerde, uint8_t stare, uint8_t comanda) {

  if (IfVerde == 0 ) {
    StateMachineUrgenta(comanda);
  }

  else {
    if (stare == 0)
    {
      elapsedMillis timeElapsed;
      while (timeElapsed <  1000 ) {
        (*SunetTrecere).RingBuzzerNormal();
        delay(500);
        PietonNord.verde();
        PietonSud.verde();
        PietonVest.verde();
        PietonEst.verde();
      }
      StateMachineUrgenta(comanda);

    }
    else  if (stare == 1) {

      elapsedMillis timeElapsed;
      while (timeElapsed < TimpGalbenNord) {
        Nord.GalbenOn();
        PietoniRosu();
      }

      Nord.RosuOn();
      StateMachineUrgenta(comanda);
    }

    else if (stare == 2) {
      elapsedMillis timeElapsed;
      while (timeElapsed < TimpGalbenSud) {
        Sud.GalbenOn();
        PietoniRosu();
      }


      Sud.RosuOn();
      StateMachineUrgenta(comanda);
    }
    else if (stare == 3) {
      elapsedMillis timeElapsed;
      while (timeElapsed < TimpGalbenVest) {
        Vest.GalbenOn();
        PietoniRosu();
      }

      Vest.RosuOn();
      StateMachineUrgenta(comanda);

    }
    else if (stare == 4) {
      elapsedMillis timeElapsed;
      while (timeElapsed < TimpGalbenEst) {
        Est.GalbenOn();
        PietoniRosu();
      }

      Est.RosuOn();
      StateMachineUrgenta(comanda);
    }
  }
}

uint8_t ControlTraffic :: ControlIntersectie(uint8_t IfVerde, uint8_t stare) {
  uint8_t comanda;
  uint8_t Urgenta = 0;

  comanda = ComandaControl();
  Serial.print(comanda);
  Serial.println();

  switch (comanda) {

    case 78 : {
        Urgenta = 1;
        ControlTranzitie(IfVerde, stare, comanda);
        return Urgenta;

      }
      break;
      
    case 83 : {
        Urgenta = 1;
        ControlTranzitie(IfVerde, stare, comanda);
        return Urgenta;
      }
      break;
      
    case 69: {
        Urgenta = 1;
        ControlTranzitie(IfVerde, stare, comanda);
        return Urgenta;
      }
      break;
      
    case 86 : {
        Urgenta = 1;
        ControlTranzitie(IfVerde, stare, comanda);
        return Urgenta;
      }
      break;
  }
}


void ControlTraffic :: StateMachineUrgenta(uint8_t Comanda) {

  switch (Comanda) {
    case 'N' :
      {
        PietoniRosu();
        Sud.RosuOn();
        Vest.RosuOn();
        Est.RosuOn();


        elapsedMillis timeElapsed;
        while (timeElapsed < TimpUrgenta) {
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
        for (index  = 2; index < 5 ; index ++) {
          StateMachineDumb(index);
        }
        break;
      }


    case 'S' : {

        PietoniRosu();
        Vest.RosuOn();
        Est.RosuOn();
        Nord.RosuOn();

        elapsedMillis timeElapsed;
        while (timeElapsed < TimpUrgenta) {
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
        for (index  = 3; index < 5 ; index ++) {
          StateMachineDumb(index);
        }
        break;
      }

    case 'V': {

        PietoniRosu();
        Sud.RosuOn();
        Est.RosuOn();
        Nord.RosuOn();

        elapsedMillis timeElapsed;
        while (timeElapsed < TimpUrgenta) {
          Vest.VerdeOn();
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
        index = 4;
        StateMachineDumb(index);

        break;
      }

    case 'E' : {

        PietoniRosu();
        Sud.RosuOn();
        Nord.RosuOn();
        Vest.RosuOn();

        elapsedMillis timeElapsed;
        while (timeElapsed < TimpUrgenta) {
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
        for (index  = 0; index < 5 ; index ++) {
          StateMachineDumb(index);
        }
        break ;
      }

  }
}

uint8_t ControlTraffic :: ComandaControl() {
  uint8_t confirmare = 'Q';
  uint8_t directie;

  pinMode(MISO, OUTPUT);
  SPCR |= _BV(SPE);

  if ((SPSR & (1 << SPIF)) != 0)
  {
    directie = SPDR;
    Serial.print(directie);
  }
  return directie;
}


void ControlTraffic :: TaskLoop() {
  for (index  = 0; index < 5 ; index ++) {
    StateMachineDumb(index);
  }
  //GalbenIntermitent();
}


