/*
   dht11    pin 48 -->
   batt     pin A9 -->
   LM35     pin A7
   mq5      pin A6
   tgs813   pin A5 -->
   tgs2602  pin A4 -->
   tgs2620  pin A3 -->
   tgs2600  pin A2 -->
   mq137    pin A1
   mq135    pin A0 -->
   MOSI - pin 11
   MISO - pin 12
   CLK - pin 13
   CS - pin 4
   BTN1 - 46
   BTN2 - 47
   REL - 49
*/
#include <SPI.h>
#include <SD.h>
const int chipSelect = 4;
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <math.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
LiquidCrystal_I2C lcd2(0x26, 16, 2);
#include <dht11.h>
dht11 DHT;
#define DHT11_PIN 48

const int analogInPin1 = A0, analogInPin3 = A2, analogInPin4 = A3, analogInPin5 = A4;
const int analogInPin6 = A5, analogInPin9 = A8;
int sensorValue1, sensorValue2, sensorValue3, sensorValue4, sensorValue5, sensorValue6, sensorValue7, sensorValue8, sensorValue9;
double outputValue = 0;
double battre = A9;
double vbat = 0;
double vbat2;
const int buttonPin = 46;
const int button2 = 47;
const int heater =  49;
int waktudelay = 2000;
int buttonState = 0;
int buttonState2 = 0;
int ia = 0, ja = 0, ka = 0, la = 0;
int a = 0, b = 0, c = 0, d = 0;
double adc1, adc2, adc3, adc4, adc5;
double r1, r2, r3, r4, r5;
double r1ro, r2ro, r3ro, r4ro, r5ro;
double r1rg, r2rg, r3rg, r4rg, r5rg;
int vr1 = 43000;
int vr2 = 10000;
int vr3 = 10000;
int vr4 = 10000;
int vr5 = 10000;
int z;
int menit = 120; //2 menit
const int InputNodes = 5;
const int HiddenNodes = 8;
const int OutputNodes = 2;
const float maxi = 6;
//double sensitivitas=0;
File dataFile = SD.open("log.txt", FILE_WRITE);

float sensi[InputNodes];    // 5 input nilai Sensitivitas

const float BobotInHid[InputNodes][HiddenNodes] = {   // Bobot Input ke Hidden layer (5, 8)
  { 30.70241165 , -3.713850021 , 8.947570801 , -2.377589941  , 3.426021576  , 22.2597847  , -5.18145752 , -1.013198495 },
  { 27.04392242 , -4.444502354 , 6.228762627 , -3.49154377 , 3.074835062  , 20.07707787 , -6.841657639  , -0.678613126 },
  { 28.58146095 , -4.381884575 , 8.939346313 , -2.092128754 , 2.756980181  , 20.48993301 , -4.794213772  , -1.270322084 },
  { 2.867153883 , -0.877912819 , 1.399313092 , 0.270878077 , 0.9207201  , 1.737950087 , 0.633344233 , 0.022247078 },
  { 28.57825851 , -2.519629478  , 9.453680992 , -2.096366882  , 2.394304514  , 21.44807434 , -4.127983093  , -1.405970693 }
};

const float
BobotHidOut[HiddenNodes][OutputNodes] = {  // Bobot  Hidden layer ke Ouput(8, 2)

  { -15.82777119 , 16.31928825 },
  { 2.900993109 , -3.837117672 },
  { -4.701883793 , 4.159037113 },
  { 2.423502207 , -2.96257925 },
  { 2.023983955 , -3.747912169 },
  { -11.7565937 , 11.3633604 },
  { 4.446260452 , -4.158718586 },
  { 1.702514768 , -1.408094049 }
};

const float Bias[HiddenNodes + OutputNodes] = { //(1,10)
  -21.48898888  , 2.772899151 , -6.767085075  , 1.16192627  , 1.690261841 , -15.76756477  , 4.04007864  , -1.39218843 , 10.9704628  , -9.764332771
};

float Masukan[InputNodes];
float Hidden[HiddenNodes];
float Keluaran[OutputNodes];

int i, j, k;  //layer
float sum2;
//float activasi;

void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd2.init();
  //  if (!SD.begin(chipSelect)) {
  //  lcd2.println("Card failed");
  //    return;
  //  }
  //  Serial.println("card ok");
  lcd.noBacklight();
  lcd2.noBacklight();
  delay(100);
  pinMode(heater, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  delay(200);
  lcd.backlight();
  lcd2.backlight();
  menit = menit * 2;
  homescreen();
}

void loop() {

  updatesensor();
  updatepb();
  if (buttonState == HIGH)   ia++;  if (buttonState2 == HIGH)
    ja++;
  if (ja == 1) {
    if (buttonState2 == HIGH ) {
      lcd.setCursor(0, 0);  lcd.print("UJI TDK LANGSUNG");
      lcd.setCursor(0, 1);  lcd.print("   Yes     No   ");
      lcd2.noBacklight();
      lcd2.setCursor(0, 0);  lcd2.print("                ");
      lcd2.setCursor(0, 1);  lcd2.print("                ");
    }
    if (ia == 1) {
      lcd2.backlight();
      NNoff();    ia = 0;
    }
  }
  //------------------------
  if (ja == 2) {
    if (buttonState2 == HIGH) {
      lcd.setCursor(0, 0);  lcd.print(" UJI LANGSUNG?  ");
      lcd.setCursor(0, 1);  lcd.print("   Yes     No   ");
      lcd2.noBacklight();
      lcd2.setCursor(0, 0);  lcd2.print("                ");
      lcd2.setCursor(0, 1);  lcd2.print("                ");
    }
    if (ia == 1) {
      lcd2.backlight();
      NNon();    ia = 0;
    }
    delay(50);
  }
  //------------------------
  if (ja == 3) {
    if (buttonState2 == HIGH) {
      lcd.setCursor(0, 0);  lcd.print("    THANKS TO   ");
      lcd.setCursor(0, 1);  lcd.print("   YES     NO   ");
      lcd2.noBacklight();
      lcd2.setCursor(0, 0);  lcd2.print("                ");
      lcd2.setCursor(0, 1);  lcd2.print("                ");
    }
    if (ia == 1) {
      about();
      homescreen(); ja = 0; ia = 0;
    }
  }

  if (ja == 4) {
    homescreen();
    //  thanks to
    ja = 0;
  }
  ia = 0;
}
//---------------------------------------------------------------------//
