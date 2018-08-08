#include "ClassSemaforMasina.h"

SemaforMasina :: SemaforMasina() {
  PinVerde = 0;
  PinRosu = 0;
  PinGalben = 0;
}

SemaforMasina :: SemaforMasina(uint8_t ConfigPinVerde, uint8_t ConfigPinRosu, uint8_t ConfigPinGalben) {
  PinVerde = ConfigPinVerde;
  PinRosu = ConfigPinRosu;
  PinGalben = ConfigPinGalben;
}

void SemaforMasina :: VerdeOn() {
  pinMode(PinVerde, OUTPUT);
  digitalWrite(PinVerde, HIGH);
  digitalWrite(PinRosu, LOW);
  digitalWrite(PinGalben, LOW);
}

void SemaforMasina :: RosuOn() {
  pinMode(PinRosu, OUTPUT);
  digitalWrite(PinRosu, HIGH);
  digitalWrite(PinGalben, LOW);
  digitalWrite(PinVerde, LOW);
}

void SemaforMasina :: GalbenOn() {
  pinMode(PinGalben, OUTPUT);
  digitalWrite(PinGalben, HIGH);
  digitalWrite(PinRosu, LOW);
  digitalWrite(PinVerde, LOW);
}

void SemaforMasina :: GalbenOff() {
  pinMode(PinVerde, OUTPUT);
  digitalWrite(PinGalben, LOW);
}

