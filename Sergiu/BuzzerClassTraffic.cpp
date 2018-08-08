#include "BuzzerClassTraffic.h"

BuzzerTraffic* BuzzerTraffic::Instance = nullptr ;


BuzzerTraffic* BuzzerTraffic :: getInstance(

  uint8_t ConfigFrecventaNormala,
  uint8_t ConfigDuratieNormala,
  uint8_t ConfigVolumNormal,


  uint8_t ConfigFrecventaAlerta,
  uint8_t ConfigDuratieAlerta,
  uint8_t ConfigVolumAlerta
)
{
  if (Instance == nullptr) {
    Instance = new BuzzerTraffic(

      ConfigFrecventaNormala,
      ConfigDuratieNormala,
      ConfigVolumNormal,


      ConfigFrecventaAlerta,
      ConfigDuratieAlerta,
      ConfigVolumAlerta
    );
  }
  return Instance;
}

BuzzerTraffic :: BuzzerTraffic(
  uint8_t ConfigFrecventaNormala,
  uint8_t ConfigDuratieNormala,
  uint8_t ConfigVolumNormal,
  uint8_t ConfigFrecventaAlerta,
  uint8_t ConfigDuratieAlerta,
  uint8_t ConfigVolumAlerta
)

{
  FrecventaNormala = ConfigFrecventaNormala;
  DuratieNormala = ConfigDuratieNormala;
  VolumNormal = ConfigVolumNormal;

  FrecventaAlerta = ConfigFrecventaAlerta;
  DuratieAlerta = ConfigDuratieAlerta;
  VolumAlerta = ConfigVolumAlerta;
}

void BuzzerTraffic :: RingBuzzerNormal() {
  toneAC(FrecventaNormala, VolumNormal, DuratieNormala);
  toneAC(FrecventaNormala, VolumNormal, DuratieNormala);
}

void BuzzerTraffic :: RingBuzzerAlerta() {
  toneAC(FrecventaAlerta, VolumAlerta, DuratieAlerta);
  toneAC(FrecventaAlerta, VolumAlerta, DuratieAlerta);
  toneAC(FrecventaAlerta, VolumAlerta, DuratieAlerta);
  toneAC(FrecventaAlerta, VolumAlerta, DuratieAlerta);
}
void BuzzerTraffic :: StopBuzzer()
{
  noToneAC();
}

