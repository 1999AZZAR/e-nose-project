//-----------------------tampil ke serial monitor----------------------------------------//

void sensitivitas() {

  lcd.setCursor(0, 0);  lcd.print("  SENSITIVITAS ");
  lcd.setCursor(0, 1);  lcd.print("               ");

  sensi[0] = r1rg / r1ro;
  sensi[1] = r2rg / r2ro;
  sensi[2] = r3rg / r3ro;
  sensi[3] = r4rg / r4ro;
  sensi[4] = r5rg / r5ro;


  Serial.print(sensi[0]);
  Serial.print("     ");
  Serial.print(sensi[1]);
  Serial.print("     ");
  Serial.print(sensi[2]);
  Serial.print("     ");
  Serial.print(sensi[3]);
  Serial.print("     ");
  Serial.print(sensi[4]);
  Serial.print("     ");

}
//---------------------------------------------------------------------------------------//
