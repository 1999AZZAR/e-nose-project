//------------------------------------DATA NN ONLINE------------------------------------ - //

void NNon() {

  lcd.setCursor(0, 0);  lcd.print("   UJI DAGING  ");
  lcd.setCursor(0, 1);  lcd.print("    LANGSUNG   ");
  /*
      heater on, tunggu 2 menit / suhu diatas 30
      read adc -> convert to res
      sensitivitas
      kalkulasi nn
  */
  kontrolheater();
  updatesensor();
  // --------------------- 2

  digitalWrite(heater, HIGH);
  cresro();
  lcd.setCursor(0, 0);  lcd.print("  SUNTIKKAN GAS ");
  lcd.setCursor(0, 1);  lcd.print(" KEDALAM CHAMBER");
  for (c = 0; c <= 52 ; c += 1)
  {
    updatepb();
    if (buttonState2 == HIGH)
    {
      c = 52;
    }
    if (c == 50) {
      c = 0;
    }
    delay(50);
  }
  cresrg();
  lcd2.backlight();
  sensitivitas();
  NN();

  lcd.setCursor(0, 0); lcd.print(" HASIL CALC NN  ");
  if ( Keluaran[0], DEC >= Keluaran[1], DEC) {
    lcd.setCursor(0, 1); lcd.print("  DAGING SEGAR  ");
  }
  else if ( Keluaran[0], DEC <= Keluaran[1], DEC) {
    lcd.setCursor(0, 1); lcd.print("DAGING TDK SEGAR");
  }
  else {
    lcd.setCursor(0, 1); lcd.print("  INVALID DATA  ");
  };
}

//---------------------------------------------------------------------------------------//
