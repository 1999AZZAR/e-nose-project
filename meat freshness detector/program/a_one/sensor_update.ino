//------------------------------updatesensor---------------------------------------------//

void updatesensor() {
  analogReference(EXTERNAL);
  vbat =    analogRead(battre);
  vbat =    vbat / 1024 * 5;

  sensorValue1 = analogRead(analogInPin1);
  sensorValue2 = analogRead(analogInPin3);
  sensorValue3 = analogRead(analogInPin4);
  sensorValue4 = analogRead(analogInPin5);
  sensorValue5 = analogRead(analogInPin6);
  sensorValue9 = analogRead(analogInPin9);

  sensorValue1 = 1024 - sensorValue1;
  sensorValue2 = 1024 - sensorValue2;
  sensorValue3 = 1024 - sensorValue3;
  sensorValue4 = 1024 - sensorValue4;
  sensorValue5 = 1024 - sensorValue5;

  //

  Serial.print(sensorValue1);
  Serial.print("   ");
  Serial.print(sensorValue2);
  Serial.print("   ");
  Serial.print(sensorValue3);
  Serial.print(" ");
  Serial.print(sensorValue4);
  Serial.print("   ");
  Serial.print(sensorValue5);
  Serial.print(" ");
  Serial.println();
  int chk = DHT.read(DHT11_PIN);
  /*
      switch (chk)
      {
        case DHTLIB_OK:
        Serial.print("OK,\t");
        break;
        case DHTLIB_ERROR_CHECKSUM:
        Serial.print("Checksum error,\t");
        break;
        case DHTLIB_ERROR_TIMEOUT:

        Serial.println("Time out error,\t");
        break;
        case DHTLIB_ERROR_CONNECT:
        Serial.print("Connect error,\t");
        break;
        case DHTLIB_ERROR_ACK_L:
        Serial.print("Ack Low error,\t");
        break;
        case DHTLIB_ERROR_ACK_H:
        Serial.print("Ack High error,\t");
        break;
        default:
        Serial.println("Unknown error,\t");
        break;
      }
  */
}

//---------------------------------------------------------------------------------------//
