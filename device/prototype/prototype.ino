// MPU-6050 Short Example Sketch
// By Arduino User JohnChi
// August 17, 2014
// Public Domain

#include<Wire.h>

const int MPU_addr=0x68; // I2C address of the MPU-6050
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
uint16_t orientation; // 1..6

struct Acceleration { 
  int16_t x;
  int16_t y;
  int16_t z;
};

Acceleration currentAcceleration = {0,0,0};

uint16_t obtainOrientation(Acceleration acceleration) {
  if (acceleration.x > 13000) return 1;
  if (acceleration.x < -13000) return 6;
  if (acceleration.y < -13000) return 3;
  if (acceleration.y > 13000) return 4;
  if (acceleration.z > 13000) return 2;
  if (acceleration.z < -13000) return 5;
  return 0;
}

void readAccelerometer() {
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B); // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true); // request a total of 14 registers
 
  AcX=Wire.read()<<8|Wire.read(); // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
  AcY=Wire.read()<<8|Wire.read(); // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ=Wire.read()<<8|Wire.read(); // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  Tmp=Wire.read()<<8|Wire.read(); // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  GyX=Wire.read()<<8|Wire.read(); // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  GyY=Wire.read()<<8|Wire.read(); // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  GyZ=Wire.read()<<8|Wire.read(); // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)

  currentAcceleration = {AcX, AcY, AcZ};

  orientation = obtainOrientation(currentAcceleration);

  Serial.println(orientation);
  
  Serial.print("AcX = "); Serial.print(currentAcceleration.x);
  Serial.print(" | AcY = "); Serial.print(currentAcceleration.y);
  Serial.print(" | AcZ = "); Serial.print(currentAcceleration.z);
  Serial.print(" | Tmp = "); Serial.print(Tmp/340.00+36.53); //equation for temperature in degrees C from datasheet
  Serial.print(" | GyX = "); Serial.print(GyX);
  Serial.print(" | GyY = "); Serial.print(GyY);
  Serial.print(" | GyZ = "); Serial.println(GyZ);
}

void setup(){
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B); // PWR_MGMT_1 register
  Wire.write(0); // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  Serial.begin(115200);
}

void loop(){
   readAccelerometer();
   delay(1000);  
}
