//-----------------------------isi data ke SDCARD data online----------------------------//

void savesdon() {

  File dataFile = SD.open("DataOnLine.txt",  FILE_WRITE);
  dataFile.println("");
  dataFile.print(sensi[0]);             dataFile.print(" ,  ");
  dataFile.print(sensorValue2);         dataFile.print(" ,  ");
  dataFile.print(sensorValue3);         dataFile.print(" ,  ");
  dataFile.print(sensorValue4);         dataFile.print(" ,  ");
  dataFile.print(sensorValue5);         dataFile.print(" ,  ");
  dataFile.print(DHT.humidity, 1);      dataFile.print(" ,  ");
  dataFile.print(DHT.temperature, 1);   dataFile.print(" ,  ");
  dataFile.print(vbat);
  dataFile.close();

}

//---------------------------------------------------------------------------------------//
