#include "arduino-mock/IRremote.h"

// Taken from IRremoteInt.h
#define ERR 0
#define DECODED 1

static IRrecvMock* gIRrecvMock = nullptr;
IRrecvMock* irrecvMockInstance() {
  if(!gIRrecvMock) {
    gIRrecvMock = new IRrecvMock();
  }
  return gIRrecvMock;
}

void releaseIRrecvMock() {
  if(gIRrecvMock) {
    delete gIRrecvMock;
    gIRrecvMock = nullptr;
  }
}

IRrecvMock::IRrecvMock() {
  irValue = 0;
}

decode_results::decode_results() {
  decode_type = 0;
  panasonicAddress = 0;
  value = 0;
  bits = 0;
  rawbuf = NULL;
  rawlen = 0;
}

IRrecv_::IRrecv_(int16_t recvpin) {
  recvPin = recvpin;
}

int16_t IRrecv_::decode(decode_results *results) {
  assert (gIRrecvMock != nullptr);
  gIRrecvMock->decode(results);
  assert (results != nullptr);
  results->value = gIRrecvMock->getIRValue();
  return DECODED;
}

void IRrecv_::enableIRIn() {
  assert (gIRrecvMock != nullptr);
  gIRrecvMock->enableIRIn();
}

void IRrecv_::resume() {
  assert (gIRrecvMock != nullptr);
  gIRrecvMock->resume();
}

//// Preinstantiate Objects
//IRrecv_ IRrecv;
