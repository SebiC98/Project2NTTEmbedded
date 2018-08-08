#ifndef ConfigFile
#define ConfigFile

//parametri buzzer
const uint8_t ConfigFrecventaNormala = 200;
const uint8_t ConfigDuratieNormala = 20;
const uint8_t ConfigVolumNormal = 10;


const uint8_t ConfigFrecventaAlerta = 155;
const uint8_t ConfigDuratieAlerta = 5;
const uint8_t ConfigVolumAlerta = 15;
//----------------------------------------------------------------------------------------------------------------

//parametri control timp
const uint16_t ConfigTimpVerdeNord=5000;
const uint16_t ConfigTimpGalbenNord=1000;

const uint16_t ConfigTimpVerdeSud=5000;
const uint16_t ConfigTimpGalbenSud=1000;

const uint16_t ConfigTimpVerdeVest=5000;
const uint16_t ConfigTimpGalbenVest=1000;

const uint16_t ConfigTimpVerdeEst=5000;
const uint16_t ConfigTimpGalbenEst=1000;

const uint16_t ConfigTimpVerdePietoni=8000;
const uint16_t ConfigTimpUrgenta = 8000;

//------------------------------------------------------------------------------

// pini leduri semafor masini
const uint8_t ConfigPinVerdeNord=8;
const uint8_t ConfigPinRosuNord=10;
const uint8_t ConfigPinGalbenNord=13;

const uint8_t ConfigPinVerdeSud=5;
const uint8_t ConfigPinRosuSud=6;
const uint8_t ConfigPinGalbenSud=7;

const uint8_t ConfigPinVerdeVest;
const uint8_t ConfigPinRosuVest;
const uint8_t ConfigPinGalbenVest;

const uint8_t ConfigPinVerdeEst;
const uint8_t ConfigPinRosuEst;
const uint8_t ConfigPinGalbenEst;

//-------------------------------------------------------------------------------

//pini semafoare pietoni 
const uint8_t ConfigRedPinNord=11;
const uint8_t ConfigGreenPinNord=9;

const uint8_t ConfigRedPinSud=2;
const uint8_t ConfigGreenPinSud=3;

const uint8_t ConfigRedPinVest;
const uint8_t ConfigGreenPinVest;

const uint8_t ConfigRedPinEst;
const uint8_t ConfigGreenPinEst;

#endif
