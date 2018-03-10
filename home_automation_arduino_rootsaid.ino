   //SIMPLE AND CHEAP HOME AUTOMATION SYSTEM USING NODEMCU AND ARDUINO BY ROOTSAID
   //Simple Arduino Code for building a home automation system that can control electrical appliances 
   //such as lights, fans, gates etc suing our mobile phone from anywhere around the world. 
   //All you need is a Node MCU board, some relays and an android phone. 
   //Credits - Krishna S
   //Complete Project Tutorial on - : http://rootsaid.com/arduino-home-automation/


    #include <ESP8266WiFi.h>
    #include <WiFiUdp.h>

    const char* ssid = "rootsaid";
    const char* password = "testpassword";

    WiFiUDP Udp;
    unsigned int port = 5514;
    char packet[255];

    void setup()
    {
    Serial.begin(9600);
    Serial.println();
    pinMode(D0, OUTPUT);
    pinMode(D1, OUTPUT);
    pinMode(D2, OUTPUT);
    pinMode(D3, OUTPUT);

    Serial.printf("Connecting to %s ", ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
    delay(500);
    Serial.print(".");
    }
    Serial.println("Connection Successful");
    Udp.begin(port);
    Serial.printf("Listener started at IP %s, at port %d \n", WiFi.localIP().toString().c_str(), port);
    }

     

    void loop()
    {
    int packetSize = Udp.parsePacket();
    if (packetSize)
    {
    Serial.printf("Received %d bytes from %s, port %d\n", packetSize, Udp.remoteIP().toString().c_str(), Udp.remotePort());
    int len = Udp.read(packet, 255);
    if (len > 0)
    {
    packet[len] = 0;
    }
    Serial.printf("UDP packet contents: %s\n", packet);
    if(packet=="device1on")
    {
       digitalWrite(D0, HIGH); 
    }
    else if(packet=="device1off")
    {
       digitalWrite(D0, LOW); 
    }
    else if(packet=="device2on")
    {
       digitalWrite(D1, HIGH); 
    }
    else if(packet=="device2off")
    {
       digitalWrite(D1, LOW); 
    }
    else if(packet=="device3on")
    {
       digitalWrite(D2, HIGH); 
    }
    else if(packet=="device3off")
    {
       digitalWrite(D2, LOW); 
    }
    else if(packet=="device3on")
    {
       digitalWrite(D3, HIGH); 
    }
    else if(packet=="device3off")
    {
       digitalWrite(D3, LOW); 
    }
    else
    {
     Serial.printf("Invalid"); 
    }
    }
    }
    
