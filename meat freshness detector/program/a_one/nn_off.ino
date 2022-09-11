//------------------------------------DATA NN OFFLINE------------------------------------ - //

void NNoff() {
  lcd.setCursor(0, 0);  lcd.print("   UJI DAGING  ");
  lcd.setCursor(0, 1);  lcd.print(" TIDAK LANGSUNG");
  lcd.setCursor(0, 1);
  
  for (a = 0; a <= 16; a += 1)
  {
    lcd.print("#");
    delay(200);
  }

  lcd.setCursor(0, 0);  lcd.print(" Load data Input");
  lcd.setCursor(0, 1);  lcd.print("                ");
  char val;

  for (c = 1; c <= 22; c += 1)
  {
    d = 1;
    val = c;
    
    if (val == 1)
    {
      sensi[0] = 0.995;
      sensi[1] = 1.081;
      sensi[2] = 1.003;
      sensi[3] = 1.001;
      sensi[4] = 1.005;
    }
    
    else if (val == 2)
    {
      sensi[0] = 0.99;
      sensi[1] = 1.12;
      sensi[2] = 1.01;
      sensi[3] = 0.97;
      sensi[4] = 1.01;
    }
    
    else if (val == 3)
    {
      sensi[0] = 0.961;
      sensi[1] = 1.067;
      sensi[2] = 0.976;
      sensi[3] = 0.99;
      sensi[4] = 0.964;
    }
    
    else if (val == 4)
    {
      sensi[0] = 0.997;
      sensi[1] = 1.119;
      sensi[2] = 1.009;
      sensi[3] = 1.025;
      sensi[4] = 1.021;
    }
    
    else if (val == 5)
    {
      sensi[0] = 0.989;
      sensi[1] = 1.092;
      sensi[2] = 0.995;
      sensi[3] = 0.96;
      sensi[4] = 1.005;
    }
    
    else if (val == 6)
    {
      sensi[0] = 0.992;
      sensi[1] = 1.085;
      sensi[2] = 0.995;
      sensi[3] = 0.999;
      sensi[4] = 1.001;
    }
    
    else if (val == 7)
    {
      sensi[0] = 0.997;
      sensi[1] = 1.086;
      sensi[2] = 0.996;
      sensi[3] = 1.013;
      sensi[4] = 1.025;
    }
    
    else if (val == 8)
    {
      sensi[0] = 1.001;
      sensi[1] = 1.088;
      sensi[2] = 1.004;
      sensi[3] = 1.017;
      sensi[4] = 1.022;
    }
    
    else if (val == 9)
    {
      sensi[0] = 1.001;
      sensi[1] = 1.089;
      sensi[2] = 1.013;
      sensi[3] = 0.991;
      sensi[4] = 0.998;
    }
    
    else if (val == 10) { //a 10
      sensi[0] = 1.006;
      sensi[1] = 1.034;
      sensi[2] = 1.025;
      sensi[3] = 1.01;
      sensi[4] = 0.999;
    }
    
    else if (val == 11) { //b 11
      sensi[0] = 1.012;
      sensi[1] = 1.068;
      sensi[2] = 1.015;
      sensi[3] = 1.008;
      sensi[4] = 1.012;
    }
    
    else if (val == 12) { //c 12
      sensi[0] = 2.92;
      sensi[1] = 1.15;
      sensi[2] = 2.83;
      sensi[3] = 2.46;
      sensi[4] = 3.70;
    }
    
    else if (val == 13) { //d 13
      sensi[0] = 1.108;
      sensi[1] = 1.114;
      sensi[2] = 1.12;
      sensi[3] = 0.999;
      sensi[4] = 1.117;
    }
    
    else if (val == 14) { //e 14
      sensi[0] = 1.374;
      sensi[1] = 0.996;
      sensi[2] = 1.266;
      sensi[3] = 1.228;
      sensi[4] = 1.417;
    }
    
    else if (val == 15) { //f 15
      sensi[0] = 2.143;
      sensi[1] = 0.9;
      sensi[2] = 1.940;
      sensi[3] = 1.760;
      sensi[4] = 2.510;
    }
    
    else if (val == 16) { //g 16
      sensi[0] = 2.279;
      sensi[1] = 1.298;
      sensi[2] = 2.294;
      sensi[3] = 2.24;
      sensi[4] = 2.639;
    }
    
    else if (val == 17) { //h 17
      sensi[0] = 3.589;
      sensi[1] = 1.109;
      sensi[2] = 3.419;
      sensi[3] = 2.922;
      sensi[4] = 5.091;
    }
    
    else if (val == 18) { //i 18
      sensi[0] = 4.198;
      sensi[1] = 1.152;
      sensi[2] = 4.102;
      sensi[3] = 3.336;
      sensi[4] = 5.625;
    }
    
    else if (val == 19) { //j 19
      sensi[0] = 3.031;
      sensi[1] = 1.161;
      sensi[2] = 2.978;
      sensi[3] = 2.597;
      sensi[4] = 3.788;
    }
    
    else if (val == 20) { //k 20
      sensi[0] = 3.48;
      sensi[1] = 1.07;
      sensi[2] = 3.43;
      sensi[3] = 2.86;
      sensi[4] = 4.31;
    }
    
    else if (val == 21) { //l 21
      sensi[0] = 2.26;
      sensi[1] = 1.51;
      sensi[2] = 2.207;
      sensi[3] = 2.135;
      sensi[4] = 2.789;
    }
    
    else if (val == 22) { //m 22
      sensi[0] = 3.93;
      sensi[1] = 1.14;
      sensi[2] = 3.90;
      sensi[3] = 3.11;
      sensi[4] = 5.14;
    }
    
    // -------------------------------------------data uji segar-----------------------------------------//
    else if (val == 23) { //m
      sensi[0] = 0.702839407;
      sensi[1] = 0.88890896;
      sensi[2] = 0.959802318;
      sensi[3] = 0.899047367;
      sensi[4] = 0.987455068;
    }
    
    else if (val == 24) { //n
      sensi[0] = 1.145625678;
      sensi[1] = 1.119375457;
      sensi[2] = 1.002090354;
      sensi[3] = 1.140697643;
      sensi[4] = 1.01452403;
    }
    
    else if (val == 254) { //o
      sensi[0] = 1.019807489;
      sensi[1] = 1.108160731;
      sensi[2] = 0.996963351;
      sensi[3] = 1.121426149;
      sensi[4] = 1.005300521;
    }
    
    // --------------------------------------------data uji tidak segar------------------------------------ - //
    else if (val == 26) { //p
      sensi[0] = 1.137050283;
      sensi[1] = 1.03709916;
      sensi[2] = 1.006642131;
      sensi[3] = 1.058695014;
      sensi[4] = 1.025453744;
    }
    
    else if (val == 27) { //q
      sensi[0] = 1.217713189;
      sensi[1] = 1.576189945;
      sensi[2] = 1.606527094;
      sensi[3] = 1.642779849;
      sensi[4] = 1.311457964;
    }
    
    else if (val == 28) { //r
      sensi[0] = 1.202653492;
      sensi[1] = 1.62285434;
      sensi[2] = 1.778264882;
      sensi[3] = 1.631823461;
      sensi[4] = 1.277608188;
    };

    NN();

    lcd.setCursor(0, 1);    lcd.print ("    DATA KE     ");
    lcd.print (c);
    
    updatepb();
    
    if (buttonState == HIGH)
      ia++;
      
    if (buttonState2 == HIGH)
      ja++;
      
    if (ja == 2) {
      lcd2.setCursor(0, 0); lcd2.print(" cancel by user ");
      lcd2.setCursor(0, 1); lcd2.print("                ");
      
      delay(2000);
      
      homescreen();
      ja = 0;
      ia = 0;
      c = 22;
    }
    delay(1500);
  }
}

//---------------------------------------------------------------------------------------//
