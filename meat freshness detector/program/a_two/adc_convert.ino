//--------------------------convert adc ke satuan hambatan-------------------------------//
void cres() {
  updatesensor();
  adc1 = sensorValue1 * 0.0048828125;
  r1 = adc1 * vr1;
  r1 = 215000 - r1;
  r1 = r1 / adc1;

  adc2 = sensorValue2 * 0.0048828125;
  r2 = adc2 * vr2;
  r2 = 215000 - r2;
  r2 = r2 / adc2;

  adc3 = sensorValue3 * 0.0048828125;
  r3 = adc3 * vr3;
  r3 = 215000 - r3;
  r3 = r3 / adc3;

  adc4 = sensorValue4 * 0.0048828125;
  r4 = adc4 * vr4;
  r4 = 215000 - r4;
  r4 = r4 / adc4;

  adc5 = sensorValue5 * 0.0048828125;
  r5 = adc5 * vr5;
  r5 = 215000 - r5;
  r5 = r5 / adc5;
  
  /*
    lcd.setCursor(0, 0);  lcd.print(r1); lcd.print("   ");
    lcd.setCursor(9, 1);  lcd.print(r2); lcd.print("   ");
    lcd.setCursor(0, 1);  lcd.print(r3); lcd.print("   ");
    lcd2.setCursor(0, 0);  lcd2.print(r4); lcd2.print("   ");
    lcd2.setCursor(0, 1);  lcd2.print(r5); lcd2.print("   ");
  */
}
//---------------------------------------------------------------------------------------//
