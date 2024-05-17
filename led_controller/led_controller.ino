#include <IRremote.h>
#include <FastLED.h>

#define NUM_LEDS 300 //LEDの個数
#define controlPin 5 //RGB制御出力ピン

int receiverPin = 9; //IR受診品
int ledPin = 12; //リレー接続ピン
int cds = 0; //フォトレジスタアナログ０番ピン

CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(receiverPin, true); 
  pinMode(ledPin, OUTPUT);

  FastLED.addLeds<WS2812B, controlPin, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(64);
}

void loop() {
  cds = analogRead(0);
  int val = cds / 4;

  if (IrReceiver.decode() && val < 254) {
    digitalWrite(ledPin, HIGH);
    delay(100);

    IrReceiver.printIRResultShort(&Serial);

    if (IrReceiver.decodedIRData.decodedRawData == 0xF609FF00) {
      int x = 0;
      IrReceiver.resume();

      //カラフルモード（イルミ）
      while(x < 1) {
        if(analogRead(0) / 4 < 253){
          for (int i = 0; i < NUM_LEDS; i += 6) {
            leds[i] = CRGB::Red;
            leds[i + 1] = CRGB::Green;
            leds[i + 2] = CRGB::LightGoldenrodYellow;;
            leds[i + 3] = CRGB::Blue;
            leds[i + 4] = CRGB::LightGoldenrodYellow;;
            i -= 1;
          }
          FastLED.show();
          delay(100);

          if (IrReceiver.decode()) {
            if (IrReceiver.decodedIRData.decodedRawData != 0xF609FF00) {
              x ++;
            }
          }

          for (int i = 0; i < NUM_LEDS; i += 6) {
            leds[i] = CRGB::Green;
            leds[i + 1] = CRGB::Fuchsia;
            leds[i + 2] = CRGB::Blue;
            leds[i + 3] = CRGB::LightGoldenrodYellow;
            leds[i + 4] = CRGB::Fuchsia;
            i -= 1;
          }
          FastLED.show();
          delay(100);

          if (IrReceiver.decode()) {
            if (IrReceiver.decodedIRData.decodedRawData != 0xF609FF00) {
              x ++;
            }
          }

          for (int i = 0; i < NUM_LEDS; i += 6) {
            leds[i] = CRGB::Blue;
            leds[i + 1] = CRGB::MediumSpringGreen;
            leds[i + 2] = CRGB::Red;
            leds[i + 3] = CRGB::MediumSpringGreen;
            leds[i + 4] = CRGB::Green;
            i -= 1;
          }
          FastLED.show();
          delay(50);

          IrReceiver.resume();
          delay(50);
          if (IrReceiver.decode()) {
            if (IrReceiver.decodedIRData.decodedRawData != 0xF609FF00) {
              x ++;
            }
          }
        }else if(analogRead(0) / 4 > 253){
          for (int i = 0; i <= NUM_LEDS; i ++) {
            leds[i] = CRGB::Black;
          }
          FastLED.show();
          delay(100); 
        }
      }


    }else if(IrReceiver.decodedIRData.decodedRawData == 0xEA15FF00) {
      IrReceiver.resume();
      int x = 0;
      //カラフルモード（パターンなし）
      while(x < 1){
        if (analogRead(0) /4 < 253){
          for (int i = 0; i < NUM_LEDS; i += 6) {
            leds[i] = CRGB::Red;
            leds[i + 1] = CRGB::Green;
            leds[i + 2] = CRGB::LightGoldenrodYellow;
            leds[i + 3] = CRGB::Blue;
            leds[i + 4] = CRGB::LightGoldenrodYellow;
            i -= 1;
          }
          FastLED.show();
          delay(100);
          if (IrReceiver.decode() && IrReceiver.decodedIRData.decodedRawData != 0xEA15FF00){
            x ++;
          }

        }else{
          for (int i = 0; i <= NUM_LEDS; i ++){
            leds[i] = CRGB::Black;
          }
          FastLED.show();
          delay(100);
          if (IrReceiver.decode() && IrReceiver.decodedIRData.decodedRawData != 0xEA15FF00){
            x ++;
          }
        }
        IrReceiver.resume();
      }


    }else if(IrReceiver.decodedIRData.decodedRawData == 0xE916FF00) {
      IrReceiver.resume();
      int x = 0;
      //単色（ホワイト）
      while(x < 1){
        if (analogRead(0) /4 < 253){
          for (int i = 0; i < NUM_LEDS; i ++) {
            leds[i] = CRGB::Beige;
          }
          FastLED.show();
          delay(100);
          if (IrReceiver.decode() && IrReceiver.decodedIRData.decodedRawData != 0xE916FF00){
            x ++;
          }

        }else{
          for (int i = 0; i <= NUM_LEDS; i ++){
            leds[i] = CRGB::Black;
          }
          FastLED.show();
          delay(100);
          if (IrReceiver.decode() && IrReceiver.decodedIRData.decodedRawData != 0xE916FF00){
            x ++;
          }
        }
        IrReceiver.resume();
      }


    }else if(IrReceiver.decodedIRData.decodedRawData == 0xBA45FF00){
      //消灯
      digitalWrite(ledPin, LOW);
      delay(100);


    }else if(IrReceiver.decodedIRData.decodedRawData == 0xF30CFF00) {
      IrReceiver.resume();
      int x = 0;
      //単色（ブルー）
      while(x < 1){
        if (analogRead(0) /4 < 253){
          for (int i = 0; i < NUM_LEDS; i ++) {
            leds[i] = CRGB::Blue;
          }
          FastLED.show();
          delay(100);
          if (IrReceiver.decode() && IrReceiver.decodedIRData.decodedRawData != 0xF30CFF00){
            x ++;
          }

        }else{
          for (int i = 0; i <= NUM_LEDS; i ++){
            leds[i] = CRGB::Black;
          }
          FastLED.show();
          delay(100);
          if (IrReceiver.decode() && IrReceiver.decodedIRData.decodedRawData != 0xF30CFF00){
            x ++;
          }
        }
        IrReceiver.resume();
      }


    }else if(IrReceiver.decodedIRData.decodedRawData == 0xE718FF00) {
      IrReceiver.resume();
      int x = 0;
      //単色（ブラウン）
      while(x < 1){
        if (analogRead(0) /4 < 253){
          for (int i = 0; i < NUM_LEDS; i ++) {
            leds[i] = CRGB::Brown;
          }
          FastLED.show();
          delay(100);
          if (IrReceiver.decode() && IrReceiver.decodedIRData.decodedRawData != 0xE718FF00){
            x ++;
          }

        }else{
          for (int i = 0; i <= NUM_LEDS; i ++){
            leds[i] = CRGB::Black;
          }
          FastLED.show();
          delay(100);
          if (IrReceiver.decode() && IrReceiver.decodedIRData.decodedRawData != 0xE718FF00){
            x ++;
          }
        }
        IrReceiver.resume();
      }


    }

  }else if (IrReceiver.decode() && val > 253){
    //消灯
    if(IrReceiver.decodedIRData.decodedRawData == 0xBA45FF00){
      digitalWrite(ledPin, LOW);
      delay(100);
    }
  }

  IrReceiver.resume();
}
