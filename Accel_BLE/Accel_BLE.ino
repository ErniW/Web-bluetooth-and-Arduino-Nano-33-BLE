#include <ArduinoBLE.h>
#include <Arduino_LSM9DS1.h>

BLEService accelService("19b10000-e8f2-537e-4f6c-d104768a1214");

BLEFloatCharacteristic xCharacteristic("19b10001-e8f2-537e-4f6c-d104768a1214", BLENotify);
BLEFloatCharacteristic yCharacteristic("19b10002-e8f2-537e-4f6c-d104768a1214", BLENotify);
BLEFloatCharacteristic zCharacteristic("19b10003-e8f2-537e-4f6c-d104768a1214", BLENotify);

BLEBoolCharacteristic ledCharacteristic("19b10004-e8f2-537e-4f6c-d104768a1214", BLERead | BLEWrite);

BLEDevice central;

void setup(){

  Serial.begin(9600);

  pinMode(13,OUTPUT);

  if(!BLE.begin()){
    Serial.println("Starting BLE failed!");
    while (1);
  }

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  BLE.setLocalName("Accelerometer");
  BLE.setAdvertisedService(accelService);

  accelService.addCharacteristic(xCharacteristic);
  accelService.addCharacteristic(yCharacteristic);
  accelService.addCharacteristic(zCharacteristic);
  
  accelService.addCharacteristic(ledCharacteristic);

  BLE.addService(accelService);

  ledCharacteristic.writeValue(0);

  BLE.setEventHandler(BLEConnected, connectHandler);
  BLE.setEventHandler(BLEDisconnected, disconnectHandler);

  BLE.advertise();

  Serial.println("Accel begin");
}

unsigned long prevTime = 0;

void loop(){

  BLE.poll();

  float x, y, z;
  IMU.readAcceleration(x, y, z);

  unsigned long t = millis();

  if(central.connected()){
    if(t - prevTime > 100){
      xCharacteristic.writeValue(x);
      yCharacteristic.writeValue(y);
      zCharacteristic.writeValue(z);
      prevTime = t;
    }
  }
  else{
    if(t - prevTime > 100){
      central = BLE.central();
      Serial.print('\t');
      Serial.print(x);
      Serial.print('\t');
      Serial.print(y);
      Serial.print('\t');
      Serial.println(z);
      prevTime = t;
    }
  }

  if(ledCharacteristic.written()){
    if(ledCharacteristic.value()){
      digitalWrite(13,HIGH);
    }
    else{
      digitalWrite(13,LOW);
    }
  }
}

void connectHandler(BLEDevice central){
  Serial.print("Connected to: ");
  Serial.println(central.address());
}

void disconnectHandler(BLEDevice central){
  Serial.print("Disconnected from: ");
  Serial.println(central.address());
}
