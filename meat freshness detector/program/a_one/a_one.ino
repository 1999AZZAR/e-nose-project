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
   MOSI     pin 11
   MISO     pin 12
   CLK      pin 13
   CS       pin 4
   BTN1     46
   BTN2     47
   REL      49
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
  { 0.643  , -0.653 , 1.174  , -0.408  , -0.028 , 1.083  , 1.944  , 0.721  },
  { 11.173 , 6.882  , 12.772 , -13.634 , -3.265 , 5.558  , -5.518 , -6.935 },
  { 1.177  , 0.605  , 0.43   , 0.788   , -1.74  , -0.871 , -0.207 , 1.123  },
  { 1.578  , 2.274  , -1.363 , 1.493   , -1.833 , 2.552  , -2.024 , 0.503  },
  { -0.501 , 0.998  , 0.012  , -0.034  , 0.972  , -0.567 , -0.144 , 1.348  }
};

const float BobotHidOut[HiddenNodes][OutputNodes] = {  // Bobot Ouput ke Hidden layer (8, 2)
  { -0.915 , 0.946  },
  { -0.622 , 0.334  },
  { 0.173  , 0.35   },
  { -0.278 , 0.241  },
  { 0.622  , -0.961 },
  { -0.832 , 0.95   },
  { 0.303  , -0.538 },
  { -0.193 , -0.756 }
};

const float Bias[HiddenNodes + OutputNodes] = { //(1,10)
  -24.56  ,
  -13.571 , 
  -18.971 , 
  13.561  , 
  8.687   , 
  -9.304  , 
  10.246  , 
  3.591   , 
  -0.463  , 
  -0.484
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
  if (buttonState == HIGH)   ia++;  if (buttonState2 == HIGH)  ja++;
  if (ja == 1) {
    if (buttonState2 == HIGH ) {
      lcd.setCursor(0, 0);   lcd.print("UJI TDK LANGSUNG");
      lcd.setCursor(0, 1);   lcd.print("   Yes     No   ");
      lcd2.noBacklight();
      lcd2.setCursor(0, 0);  lcd2.print("              ");
      lcd2.setCursor(0, 1);  lcd2.print("              ");
    }
    if (ia == 1) {
      lcd2.backlight();
      NNoff();    ia = 0;
    }
  }
  //------------------------
  if (ja == 2) {
    if (buttonState2 == HIGH) {
      lcd.setCursor(0, 0);   lcd.print(" UJI LANGSUNG?  ");
      lcd.setCursor(0, 1);   lcd.print("   Yes     No   ");
      lcd2.noBacklight();
      lcd2.setCursor(0, 0);  lcd2.print("              ");
      lcd2.setCursor(0, 1);  lcd2.print("              ");
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
      lcd.setCursor(0, 1);  lcd.print("   Yes     No   ");
      lcd2.noBacklight();
      lcd2.setCursor(0, 0);  lcd2.print("    ");
      lcd2.setCursor(0, 1);  lcd2.print("    ");
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
//---------------------------------------------------------------------------------------//
