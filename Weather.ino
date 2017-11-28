void weatherwunderground(){
  counter = counter+1;
  if(counter==180){
    wunderground.updateConditions(apiKey, country, city);
    counter=0;
  }

  if(wunderground.getWeatherText() == NULL){
    wunderground.updateConditions(apiKey, country, city);
    
  }
  
  Serial.print("Weather of: ");
  Serial.print(country);
  Serial.print(" ");
  Serial.println(city);
  
  currentweather = wunderground.getWeatherText();
  Serial.print("current weather: ");
  Serial.println(currentweather);

  currenttemp = wunderground.getCurrentTemp();
  Serial.print("current temp: ");
  Serial.println(currenttemp);

  currenthum = wunderground.getHumidity();
  Serial.print("current humidity: ");
  Serial.println(currenthum);

  currentpress = wunderground.getPressure();
  Serial.print("current pressure: ");
  Serial.println(currentpress);
 
}


