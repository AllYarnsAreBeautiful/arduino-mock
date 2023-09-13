/** Implementation of EEPROM mock **/

#include "arduino-mock/EEPROM.h"

static EEPROMMock* p_EEPROMMock = nullptr;
EEPROMMock* EEPROMMockInstance() {
  if (!p_EEPROMMock) {
    p_EEPROMMock = new EEPROMMock();
  }
  return p_EEPROMMock;
}

void releaseEEPROMMock() {
  assert (p_EEPROMMock != nullptr);
  if (p_EEPROMMock) {
    delete p_EEPROMMock;
    p_EEPROMMock = NULL;
  }
}

uint8_t EEPROM_::read(int a) {
  assert (p_EEPROMMock != nullptr);
  return p_EEPROMMock->read(a);
}

void EEPROM_::write(int a, uint8_t b) {
  assert (p_EEPROMMock != nullptr);
  p_EEPROMMock->write(a, b);
}

// Preinstantiate Objects
EEPROM_ EEPROM;
