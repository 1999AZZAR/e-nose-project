//------------------------------rata rata cres Rg----------------------------------------//

void cresrg() { // 24 data untuk 2 menit

  lcd.setCursor(0, 0);
  lcd.print("   GET Rg DATA");
  lcd.setCursor(0, 1);
  lcd.print("           ");
  lcd2.backlight();
  lcd2.setCursor(0, 0);
  lcd2.print("    PROGRESS    ");


  for (c = 0; c <= 48; c += 1) {  //2.5 detik*48 = 120 detik (2menit)

    updatesensor();
    cres();

    r1rg = r1rg + r1;
    r1rg = r1rg / 2;

    r2rg = r2rg + r2;
    r2rg = r2rg / 2;

    r3rg = r3rg + r3;
    r3rg = r3rg / 2;

    r4rg = r4rg + r4;
    r4rg = r4rg / 2;

    r5rg = r5rg + r5;
    r5rg = r5rg / 2;

    a =  c * 100 / 48;

    lcd2.setCursor(0, 1);
    lcd2.print("       ");
    lcd2.print(a);
    lcd2.print("% ");

    delay(2500);

  }

  Serial.print(r1rg);
  Serial.print(" ");
  Serial.print(r2rg);
  Serial.print(" ");
  Serial.print(r3rg);
  Serial.print(" ");
  Serial.print(r4rg);
  Serial.print(" ");
  Serial.print(r5rg);
  Serial.print(" ");

  lcd.setCursor(0, 1);
  lcd.print("Rg DATA COMPLETE");
  lcd2.noBacklight();
  lcd2.setCursor(0, 0);
  lcd2.print(" ");
  lcd2.setCursor(0, 1);
  lcd2.print(" ");

  a = 0;

}

//---------------------------------------------------------------------------------------//
