

#include <SPI.h>
#include <Ethernet.h>


byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(192, 168, 1, 177);
IPAddress myDns(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 0, 0);



EthernetServer server(23);

EthernetClient clients[4];

void setup() {
 
  Ethernet.begin(mac, ip, myDns, gateway, subnet);
 
  server.begin();

  Serial.begin(9600);
  while (!Serial) {
    ; 
  }


  Serial.print("Chat server address:");
  Serial.println(Ethernet.localIP());
}

void loop() {
 
  EthernetClient client = server.available();

  
  if (client) {

    boolean newClient = true;
    for (byte i = 0; i < 4; i++) {
      
      if (clients[i] == client) {
        newClient = false;
        break;
      }
    }

    if (newClient) {
      
      for (byte i = 0; i < 4; i++) {
        if (!clients[i] && clients[i] != client) {
          clients[i] = client;
        
          client.flush();
          Serial.println("We have a new client");
          client.print("Hello, client number: ");
          client.print(i);
          client.println();
          break;
        }
      }
    }

    if (client.available() > 0) {
  
      char thisChar = client.read();
      
      for (byte i = 0; i < 4; i++) {
        if (clients[i] && (clients[i] != client)) {
          clients[i].write(thisChar);
        }
      }
  
      Serial.write(thisChar);
    }
  }
  for (byte i = 0; i < 4; i++) {
    if (!(clients[i].connected())) {
      
      clients[i].stop();
    }
  }
}
