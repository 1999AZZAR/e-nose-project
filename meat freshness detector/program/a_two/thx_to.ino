//--------------------------------------- thanks to -------------------------------------//

void about() {

  lcd.setCursor(0, 0);  lcd.print("                ");
  lcd.setCursor(0, 1);  lcd.print("                ");

  for (c = 16; c >= 0; c -= 1) {

    lcd.setCursor(c, 0);  lcd.print("ALLAH SUBHANAHU ");
    lcd.setCursor(c, 1);  lcd.print("    WA TAALA    ");

    delay(200);
  }

  delay(2000);

  for (c = 16; c >= 0; c -= 1) {

    lcd.setCursor(c, 0);
    lcd.print("AYAH DAN ALM IBU");
    lcd.setCursor(c, 1);  lcd.print("                ");

    delay(200);

  }

  delay(2000);

  lcd2.backlight();

  for (c = 16; c >= 0; c -= 1) {

    lcd.setCursor(c, 0);  lcd.print("  BUDI GUNAWAN  ");
    lcd.setCursor(c, 1);  lcd.print("   ST.,MT.    ");
    lcd2.setCursor(c, 0);  lcd2.print(" ARIEF SUDARMAJI");
    lcd2.setCursor(c, 1);  lcd2.print("  ST.,MT.,PhD.  ");

    delay(200);

  }

  delay(2000);

  for (c = 16; c >= 0; c -= 1) {

    lcd.setCursor(c, 0);   lcd.print("    SOLEKHAN    ");
    lcd.setCursor(c, 1);   lcd.print("     ST.,MT.    ");
    lcd2.setCursor(c, 0);  lcd2.print("       DAN      ");
    lcd2.setCursor(c, 1);  lcd2.print("    DOSEN UMK   ");

    delay(200);

  }

  delay(2000);

  for (c = 16; c >= 0; c -= 1) {

    lcd.setCursor(c, 0);  lcd.print("   TEMAN TEMAN  ");
    lcd.setCursor(c, 1);  lcd.print("   UMK & UNSOED ");

    lcd2.noBacklight();
    lcd2.setCursor(c, 0);  lcd2.print("                ");
    lcd2.setCursor(c, 1);  lcd2.print("                ");

    delay(200);

  }

  delay(2000);

}
//---------------------------------------------------------------------------------------//
