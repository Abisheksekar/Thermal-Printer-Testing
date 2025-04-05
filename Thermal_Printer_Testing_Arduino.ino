#include "Adafruit_Thermal.h"
#include "adalogo.h"
#include "adaqrcode.h"
#include "SoftwareSerial.h"

SoftwareSerial mySerial(2, 3);
Adafruit_Thermal printer(&mySerial);

void setup() {
  mySerial.begin(9600);
  delay(3000);
  printer.begin();

  printer.setFont('B');
  printer.println("FontB");
  printer.println("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  printer.setFont('A');
  printer.println("FontA (default)");
  printer.println("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

  printer.inverseOn();
  printer.println(F("Inverse ON"));
  printer.inverseOff();

  printer.doubleHeightOn();
  printer.println(F("Double Height ON"));
  printer.doubleHeightOff();

  printer.justify('R');
  printer.println(F("Right justified"));
  printer.justify('C');
  printer.println(F("Center justified"));
  printer.justify('L');
  printer.println(F("Left justified"));

  printer.boldOn();
  printer.println(F("Bold text"));
  printer.boldOff();

  printer.underlineOn();
  printer.println(F("Underlined text"));
  printer.underlineOff();

  printer.setSize('L');
  printer.println(F("Large"));
  printer.setSize('M');
  printer.println(F("Medium"));
  printer.setSize('S');
  printer.println(F("Small"));

  printer.justify('C');
  printer.println(F("normal\nline\nspacing"));
  printer.setLineHeight(50);
  printer.println(F("Taller\nline\nspacing"));
  printer.setLineHeight();
  printer.justify('L');

  printer.printBarcode("ADAFRUT", CODE39);
  printer.setBarcodeHeight(100);
  printer.printBarcode("123456789123", UPC_A);


   printer.printBitmap(adalogo_width, adalogo_height, adalogo_data);

  // Print the 135x135 pixel QR code in adaqrcode.h:
  printer.printBitmap(adaqrcode_width, adaqrcode_height, adaqrcode_data);
  printer.println(F("Adafruit!"));
  printer.feed(5);
  printer.sleep();      // Tell printer to sleep
  delay(3000L);         // Sleep for 3 seconds
  printer.wake();       // MUST wake() before printing again, even if reset
  printer.setDefault(); // Restore printer to defaults
}

void loop() {
}
