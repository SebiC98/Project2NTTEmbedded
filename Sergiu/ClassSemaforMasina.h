#ifndef SemaforMasina_h
#define SemaforMasina_h

#include <Arduino.h>
class SemaforMasina
{
  private:
    
    uint8_t PinVerde;
    uint8_t PinRosu;
    uint8_t PinGalben;

  public :
    SemaforMasina();
    SemaforMasina(uint8_t ConfigPinVerde,uint8_t ConfigPinRosu,uint8_t ConfigPinGalben);
    
    //Metode
    void VerdeOn();
    void RosuOn();
    void GalbenOn();  
    void GalbenOff();
};
#endif

