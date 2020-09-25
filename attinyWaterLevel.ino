w#include "tinysnore.h"
const int Salida = 0;
const int Sensor1 = 1;
const int Sensor2 = 2;

//variables

bool Sensor1State;
bool Sensor2State;

const long interval1 = 45;//intervalo entre ciclos, en minutos
const long Int1ms  = interval1 * 60 * 1000;

void setup() {
  // put your setup code here, to run once:
  pinMode(Salida, OUTPUT);
  pinMode(Sensor1, INPUT);
  pinMode(Sensor2, INPUT);

  digitalWrite(Salida, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(Salida, LOW);
  //delay(Int1ms);
  Sensor1State = digitalRead(Sensor1);
  Sensor2State = digitalRead(Sensor2);
  if (Sensor1State == LOW && Sensor1State == Sensor2State){
    llenado();
  }
}

void llenado(){
  while (Sensor1State != HIGH){
    digitalWrite(Salida, HIGH);
    Sensor1State = digitalRead(Sensor2);
  }
}
