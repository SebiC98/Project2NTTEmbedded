#include "ClassControlTraffic.h"

ControlTraffic ControlObject
  (
  
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

void setup() {
  // put your setup code here, to run once:
  ControlObject.InitializareIntersectie();
  Serial.begin(9600);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  ControlObject.TaskLoop();
}
