#include "ClassSemaforMasina.h"

SemaforMasina :: SemaforMasina(uint8_t ConfigIndex,uint8_t ConfigPinVerde,uint8_t ConfigPinRosu,uint8_t ConfigPinGalben){
    
    index=ConfigIndex;
    PinVerde=ConfigPinVerde;
    PinRosu=ConfigPinRosu;
    PinGalben=ConfigPinGalben;
}

void SemaforMasina :: VerdeOn(){
  digitalWrite(PinVerde,HIGH);
  digitalWrite(PinRosu,LOW);
  digitalWrite(PinGalben,LOW);
}

void SemaforMasina :: RosuOn(){
  digitalWrite(PinRosu,HIGH);
  digitalWrite(PinGalben,LOW);
  digitalWrite(PinVerde,LOW);
}

void SemaforMasina :: GalbenOn(){
  digitalWrite(PinGalben,HIGH);
  digitalWrite(PinRosu,LOW);
  digitalWrite(PinVerde,LOW);
}

