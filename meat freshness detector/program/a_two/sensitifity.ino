//-----------------------tampil ke serial monitor----------------------------------------//

void sensitivitas() {

  lcd.setCursor(0, 0);  lcd.print("  SENSITIVITAS ");
  lcd.setCursor(0, 1);  lcd.print("               ");

  sensi[0] = r1rg / r1ro;
  sensi[1] = r2rg / r2ro;
  sensi[2] = r3rg / r3ro;
  sensi[3] = r4rg / r4ro;
  sensi[4] = r5rg / r5ro;


  Serial.print(sensi[0]); Serial.print(" ");
  Serial.print(sensi[1]); Serial.print(" ");
  Serial.print(sensi[2]); Serial.print(" ");
  Serial.print(sensi[3]); Serial.print(" ");
  Serial.print(sensi[4]); Serial.print(" ");
}
//---------------------------------------------------------------------------------------//
//-----------------------tampil ke serial monitor----------------------------------------//

void serial() {

  lcd.setCursor(0, 0);  lcd.print(sensorValue1); lcd.print("  ");
  lcd.setCursor(8, 0);  lcd.print(sensorValue2); lcd.print("   ");
  lcd.setCursor(0, 1);  lcd.print(sensorValue3); lcd.print("   ");
  lcd.setCursor(6, 1);  lcd.print(sensorValue4); lcd.print("    ");
  lcd.setCursor(12, 1);  lcd.print(sensorValue5); lcd.print("   ");

  lcd2.setCursor(12, 0);  lcd2.print(vbat);  lcd2.print("V ");
  lcd2.setCursor(0, 1);  lcd2.print("H ");
  lcd2.print(DHT.humidity, 1);
  lcd2.setCursor(7, 1);  lcd2.print("T ");
  lcd2.print(DHT.temperature, 1);  lcd2.print(" ");  lcd2.print(ia);

  lcd2.print(ja);
  lcd2.setCursor(0, 0);
  lcd2.print(ka);
  lcd2.print(" ");
  lcd2.print(la);
  lcd2.print(" ");
  lcd2.print(menit);
  lcd2.print("  ");

}

//---------------------------------------------------------------------------------------//
