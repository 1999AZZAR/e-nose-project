//------------------------------rata rata cres Ro----------------------------------------//

void cresro() { // 24 data untuk 2 menit
  
  lcd.setCursor(0, 1);   lcd.print("   GET Ro DATA  ");
  lcd2.setCursor(0, 0);  lcd2.print("    PROGRESS    ");
  
  for (c =  0;  c  <=  48;  c  +=  1)
  { //2.5  detik*48  =  120  detik  (2menit)
    updatesensor();
    cres();

    r1ro = r1ro + r1;
    r1ro = r1ro / 2;

    r2ro = r2ro + r2;
    r2ro = r2ro / 2;

    r3ro = r3ro + r3;
    r3ro = r3ro / 2;

    r4ro = r4ro + r4;
    r4ro = r4ro / 2;

    r5ro = r5ro + r5;
    r5ro = r5ro / 2;
    /*
        lcd.setCursor(0, 0);
        lcd.print(r1ro); lcd.print("  ");
        lcd.setCursor(9, 1);
        lcd.print(r2ro); lcd.print("  ");
        lcd.setCursor(0, 1);
        lcd.print(r3ro); lcd.print("  ");
        lcd2.setCursor(0, 0);
        lcd2.print(r4ro); lcd2.print("  ");
        lcd2.setCursor(0, 1);
        lcd2.print(r5ro); lcd2.print("  ");
    */
    a =  c * 100 / 48;

    lcd2.setCursor(0, 1);
    lcd2.print("   "); 
    lcd2.print(a);
    lcd2.print(" %    ");
    
    delay(2500);
  };
  Serial.print(r1ro); Serial.print(" "); 
  Serial.print(r2ro); Serial.print(" ");
  Serial.print(r3ro); Serial.print(" "); 
  Serial.print(r4ro); Serial.print(" ");
  Serial.print(r5ro); Serial.print(" ");
  
  lcd.setCursor(0, 1);  lcd.print("Ro DATA COMPLETE");
  
  lcd2.noBacklight();
  lcd2.setCursor(0, 0);  lcd2.print("    ");
  lcd2.setCursor(0, 1);  lcd2.print("    ");
  
  a = 0;
  
}

//---------------------------------------------------------------------------------------//
