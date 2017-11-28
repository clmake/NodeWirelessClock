void showtime(){
  Serial.print("Sono le ore: ");
  if(ore <10){
    Serial.print("0");
  }
  Serial.print(ore);
  Serial.print(":");
  if(minuti <10){
    Serial.print("0");
  }
  Serial.print(minuti);
  Serial.print(":");
  if(secondi <10){
    Serial.print("0");
  }
  Serial.print(secondi);
  Serial.println("");

  
  display.clearDisplay();
  //display.display();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("CL Make");
  //display.println("Sono le ore");
  display.setTextSize(2);
  display.setCursor(11, 11);
  if(ore <10){
    display.print("0");
  }
  display.print(ore);
  display.print(":");
  if(minuti <10){
    display.print("0");
  }
  display.print(minuti);
  display.print(":");
  if(secondi <10){
    display.print("0");
  }
  display.print(secondi);
  display.println("");

  display.display();
}

void showweather(){
  display.clearDisplay();
  //display.display();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print("Meteo di: ");
  display.println(city);
  display.print("Meteo: ");
  display.println(currentweather);
  display.print("Temp: ");
  display.print(currenttemp);
  display.print(" Hum: ");
  display.println(currenthum);
  display.print("Press: ");
  display.print(currentpress);

  display.display();
}

void showyoutube(){
  display.clearDisplay();
  //display.display();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Youtube: CL Make");
  display.print("Iscritti: ");
  display.println(youtubesubscriber);
  display.print("Visite: ");
  display.println(youtubeview);
  display.print("Video: ");
  display.println(youtubevideo);

   display.display();
}


