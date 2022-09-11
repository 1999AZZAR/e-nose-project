//------------------------------------HEATER------------------------------------ - //

void kontrolheater() {

  if (DHT.temperature <= 35)
  {
    lcd2.setCursor(0, 0);
    lcd2.print(" T chamber ");
    lcd2.print(DHT.temperature);
    lcd2.setCursor(0, 1);  lcd2.print("    HEATER ON   "); //heater on
    
    digitalWrite(heater, HIGH);
    
    delay(1000);
    
    for (c = 0; c <= 5 ; c += 1) {
      updatesensor();
      lcd2.setCursor(0, 0);  lcd2.print("   T chamber   ");
      lcd2.print(DHT.temperature);
      
      if (c == 3) {
        c = 0;
        
      }
      if (DHT.temperature >= 35) {
        c = 6;
      }
    }
  }
}

//---------------------------------------------------------------------------------------//
