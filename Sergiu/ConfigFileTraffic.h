#ifndef ConfigFile
#define ConfigFile

//parametri buzzer
const uint8_t ConfigFrecventaNormala = 50;
const uint8_t ConfigDuratieNormala = 20;
const uint8_t ConfigVolumNormal = 10;


const uint8_t ConfigFrecventaAlerta = 100;
const uint8_t ConfigDuratieAlerta = 5;
const uint8_t ConfigVolumAlerta = 10;
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
const uint16_t ConfigTimpGalbenIntermitent = 1000;
const uint16_t ConfigTimpUrgenta = 8000;

//------------------------------------------------------------------------------

// pini leduri semafor masini
const uint8_t ConfigPinVerdeNord=23;
const uint8_t ConfigPinRosuNord=27;
const uint8_t ConfigPinGalbenNord=25;

const uint8_t ConfigPinVerdeSud=43;
const uint8_t ConfigPinRosuSud=39;
const uint8_t ConfigPinGalbenSud=41;

const uint8_t ConfigPinVerdeVest=51;
const uint8_t ConfigPinRosuVest=47;
const uint8_t ConfigPinGalbenVest=49;

const uint8_t ConfigPinVerdeEst=35;
const uint8_t ConfigPinRosuEst=31;
const uint8_t ConfigPinGalbenEst=33;

//-------------------------------------------------------------------------------

//pini semafoare pietoni 
const uint8_t ConfigRedPinNord=22;
const uint8_t ConfigGreenPinNord=24;

const uint8_t ConfigRedPinSud=28;
const uint8_t ConfigGreenPinSud=30;

const uint8_t ConfigRedPinVest=48;
const uint8_t ConfigGreenPinVest=50;

const uint8_t ConfigRedPinEst=34;
const uint8_t ConfigGreenPinEst=36;

#endif
