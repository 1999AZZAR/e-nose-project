//------------------------------------kalkulasi NN-------------------------------------- - //

void NN() {

  lcd.setCursor(0, 0);  lcd.print("    WAIT DATA  ");
  lcd.setCursor(0, 1);
  //masukan
  Serial.println (" Input  ");

  lcd2.setCursor(0, 0);  lcd2.print ("    loading ");
  lcd2.setCursor(0, 1);  lcd2.print ("            ");

  for ( i = 0 ; i < InputNodes ; i++ )
  {
    Masukan[i] = sensi[i] / maxi;
    Serial.print ( sensi[i], DEC);   Serial.print (" ");
    Serial.print ( Masukan[i], DEC); Serial.print (" ");

    dataFile.print(Masukan[i], DEC);
    dataFile.print(", ");

    delay(10);
  }
  Serial.println ();

  /*****************************************************************
    Compute hidden layer activations
  ******************************************************************/
  for (
    j = 0 ; j < HiddenNodes ; j++ ) {
    sum2 = 0;
    for ( i = 0 ; i < HiddenNodes ; i++ ) { //nilai sum
      sum2 += Masukan[i] * BobotInHid[i][j];
      delay(10);
    }
    Hidden[j] = 1.0 / (1.0 + exp(-(sum2 + Bias[j])));//nilai sigmoid
  }

  /*****************************************************************
    Compute output layer
  ******************************************************************/
  for ( k = 0 ; k < OutputNodes ; k++ ) {
    sum2 = 0;
    for ( j = 0 ; j < HiddenNodes ; j++ ) { //nilai sum
      sum2 += Hidden[j] * BobotHidOut[j][k] ;
      delay(10);
    }
    Keluaran[k] = 1.0 / (1.0 + exp(-(sum2 + Bias[k + 8]))); //nilai sigmoid
  }

  //luaran
  lcd2.print("");
  Serial.println ("  Output ");
  lcd2.setCursor(0, 1);  lcd2.print("    "); //clear lcd
  lcd2.setCursor(0, 0);  lcd2.print("    "); //clear lcd
  lcd2.setCursor(0, 0);
  
  for ( i = 0 ; i < OutputNodes ; i++ ) {
    Serial.print (Keluaran[i], DEC);
    Serial.print (" ");

    lcd2.print("  "); lcd2.print(Keluaran[i], DEC);
    lcd2.setCursor(0, 1);
    //  dataFile.print(sensi[i]);    dataFile.print(" , ");
  }

  Serial.println ();
  if (ja == 2) {
    
    if ( Keluaran[0] >= Keluaran[1]) {
      lcd.setCursor(0, 1);
      lcd.print("  DAGING SEGAR  ");
    }
    
    else {
      lcd.setCursor(0, 1);
      lcd.print("DAGING TDK SEGAR");
    }
  }
  /*
    reset input, hidden dan luaran sum2 = 0;
    for ( i = 0 ; i < InputNodes ; i++ ) {
      sensi[i] = 0;
      Masukan[i] = 0;
    }
    for ( j = 0 ; j < HiddenNodes ; j++ ) {
      Hidden[j] = 0;
    }
    for ( k = 0 ; k < OutputNodes ; k++ ) {
      Keluaran[k] = 0;
    }
  */
}

//---------------------------------------------------------------------------------------//
