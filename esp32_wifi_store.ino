#include "wifi_store.h"

wifi_store ws;

void setup() {
  Serial.begin(115200);

  ws.manage_credentials();
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    int delimiter_pos = command.indexOf(',');
    String ssid = command.substring(0, delimiter_pos);
    String password = command.substring(delimiter_pos + 1);
    Serial.println(ssid);
    Serial.println(password);
    ws.write_credentials(ssid, password);
    ws.connect();
  }
}
