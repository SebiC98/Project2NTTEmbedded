#ifndef BuzzerTraffic_h
#define BuzzerTraffic_h

#include <toneAC.h>
#include <stddef.h>

// CONNECTION:
//   Pins  9 & 10 - ATmega328, ATmega128, ATmega640, ATmega8, Uno, Leonardo, etc.
//   Pins 11 & 12 - ATmega2560/2561, ATmega1280/1281, Mega
//   Pins 12 & 13 - ATmega1284P, ATmega644
//   Pins 14 & 15 - Teensy 2.0
//   Pins 25 & 26 - Teensy++ 2.0

class BuzzerTraffic
{

  private :

    //Parametri pentru functia toneAC pentru cazul in care
    //semaforul la pietoni este verde si este suficient timp
    //pentru pietoni sa treaca
    
    uint8_t FrecventaNormala;
    uint8_t DuratieNormala;
    uint8_t VolumNormal;

    //Parametri pentru functia toneAC folositi a avertiza
    //pietoni ca timpul pentru culoarea verde se
    //apropie de sfarsit

    uint8_t FrecventaAlerta;
    uint8_t DuratieAlerta;
    uint8_t VolumAlerta;

    static BuzzerTraffic* Instance = nullptr;

    //constructor cu parametri
    BuzzerTraffic(
      uint8_t,
      uint8_t,
      uint8_t,
      uint8_t,
      uint8_t,
      uint8_t);

  public :
    BuzzerTraffic* getInstance(
      uint8_t ConfigFrecventaNormala,
      uint8_t ConfigDuratieNormalat,
      uint8_t ConfigVolumNormala,
      
      uint8_t ConfigFrecventaAlerta,
      uint8_t ConfigDuratieAlerta,
      uint8_t ConfigVolumAlerta
    );

    //Metode
    void RingBuzzerNormal();//metoda ce genereza pentru sunet pentru operare normala
    void RingBuzzerAlerta();//metoda ce genereaza sunet pentru avertizare terminare timp
    void StopBuzzer();//metoda ce opreste sunetul generat de buzzer
};
#endif

