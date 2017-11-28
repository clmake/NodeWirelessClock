#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <SPI.h>
#include "WundergroundClient.h"
#include "YoutubeApi.h"
#include <WiFiClientSecure.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET LED_BUILTIN  //4
Adafruit_SSD1306 display(OLED_RESET);

//#if (SSD1306_LCDHEIGHT != 64)
//#error("Height incorrect, please fix Adafruit_SSD1306.h!");
//#endif

//counter per altre funzioni
unsigned long counter1 = 0;
unsigned long counter2 = 0;
unsigned long counter3 = 0;

//Impostazioni ora locale
int ore = 23;
int minuti = 59;
int secondi = 0;
unsigned long current_time = 0;
unsigned long last_time = 0;


// Impostazioni Wunderground
WundergroundClient wunderground(true);
String currentweather;
String currenttemp;
String currenthum;
String currentpress;

// Add your wounderground api key here
String apiKey = "INSERT WOUNDERGROUND API KEY"; 
String country = "INSERT COUNTRY FOR WEATHER";
String city = "INSERT CITY FOR WEATHER";
int counter = 0;

//Impostazioni Youtube
// API Key per Youtube
#define API_KEY "INSERT YOUTUBE API KEY"  // your google apps API Token UCQB4RRae63k2nnA1YA39yZg
#define CHANNEL_ID "INSERT YOUR CHANNEL ID" // makes up the url of channel
String youtubesubscriber;
String youtubeview;
String youtubecomments;
String youtubevideo;

//Impostazioni WiFi
WiFiClientSecure client;
YoutubeApi api(API_KEY, client);

//Connessione WiFi
char ssid[] = "INSERT YOUR WIFI SSID";  //  your network SSID (name)
char pass[] = "INSERT YOUR WIFI PASSWORD";       // your network password
unsigned int localPort = 2390;      // local port to listen for UDP packets

/* Don't hardwire the IP address or we won't get the benefits of the pool.
 *  Lookup the IP address for the host name instead */
//IPAddress timeServer(129, 6, 15, 28); // time.nist.gov NTP server
IPAddress timeServerIP; // time.nist.gov NTP server address
const char* ntpServerName = "pool.ntp.org";

const int NTP_PACKET_SIZE = 48; // NTP time stamp is in the first 48 bytes of the message

byte packetBuffer[ NTP_PACKET_SIZE]; //buffer to hold incoming and outgoing packets

// A UDP instance to let us send and receive packets over UDP
WiFiUDP udp;

void setup()
{

  // Oled Setup
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  // Clear the buffer.
  display.clearDisplay();
  display.display();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("CL Make");
  display.println("visita il mio sito");
  display.println("http://www.clmake.it/");
  display.display();
    
  delay(3000);
  Serial.begin(115200);
  Serial.println();
  Serial.println();

  // We start by connecting to a WiFi network
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);

  
  WiFi.status();
  delay(10000);
  WiFi.status();
  //while (WiFi.status() != WL_CONNECTED) {
  //  delay(500);
  //  Serial.print(".");
  //}
  if (WiFi.status() == WL_CONNECTED){
    Serial.println("");
    
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
  
    
  
    //wetaher righe
    wunderground.updateConditions(apiKey, country, city);
    //wunderground.updateForecast(apiKey, country, city);
  }
    Serial.println("Starting UDP");
    udp.begin(localPort);
    Serial.print("Local port: ");
    Serial.println(udp.localPort());
    current_time = millis();

    
}



void add_hour(){
  ore = ore + 1;
  if (ore > 23){
    ore = 0;
  }
}

void add_minute(){
  minuti = minuti + 1;
  if (minuti > 59){
    minuti = 0;
    add_hour();
  }
}

void add_second(){
  secondi = secondi + 1;
  if (secondi > 59){
    secondi = 0;
    add_minute();
  }
}


void loop()
{
  counter1=millis();
  //display ora
  last_time = millis();
  //Serial.println(last_time);
  //Serial.println(current_time);
  if (last_time - current_time >1000){
    //Serial.print("è passato un secondo");
    current_time = last_time;
    add_second();
  }
  
  if (last_time == 4294967296){
    current_time = 0;
  }
  if (counter1 == 4294967296){
    counter2 = 0;
  }

  //Orario
  showtime();

  //altre funzioni

   if (counter1-counter2>60000){ 
    counter2=counter1;
    
    if (WiFi.status() == WL_CONNECTED){ 
        if (counter3 == 0){
        weatherwunderground();
        showweather();
        delay(5000);
        youtube();
        showyoutube();
        delay(5000);
        timenode();
        }else if (counter1-counter3>360000){
        weatherwunderground();
        showweather();
        delay(5000);
        youtube();
        showyoutube();
        delay(5000);
        counter3=counter1;
        timenode();
        
        }
      }else{
      showweather();
      delay(5000);
      add_second();
      add_second();
      add_second();
      add_second();
      add_second();
      add_second();
      showyoutube();
      delay(5000);
      add_second();
      add_second();
      add_second();
      add_second();
      add_second();
      add_second();
    }
  }
  
}


