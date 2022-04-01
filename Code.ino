#include "FastLED.h"
#define DATA_PIN 3
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS 6
#define BRIGHTNESS 255
#define BRIGHTLOW 3
#define BRIGHTHIGH 255
#define INTERFADE 100
#define MAGNECTIC_SWITCH 5
volatile byte state = 0;
// byte state = LOW;

CRGB leds[NUM_LEDS];

void setup() {
delay(1500); // initial delay of a few seconds is recommended
pinMode(DATA_PIN, OUTPUT);
pinMode(LED_BUILTIN, OUTPUT);
pinMode(MAGNECTIC_SWITCH, INPUT);
FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip); // initializes LED strip
FastLED.setBrightness(BRIGHTNESS);// global brightness
showProgramCleanUp(2500); // clean up
// digitalWrite(LED_BUILTIN, HIGH);
}

/*If the magnetic switch is near the magnet, it will return true, */
/*otherwise it will return false */
boolean isNearMagnet()
{
int sensorValue = digitalRead(MAGNECTIC_SWITCH);
if(sensorValue == HIGH)//if the sensor value is HIGH?
{
digitalWrite(LED_BUILTIN,HIGH);
CleanUp();
return true;//yes,return true
}
else
{
digitalWrite(LED_BUILTIN,LOW);
return false;//no,return false
}
}

// switches off all LEDs for "delaytime" time
void showProgramCleanUp(long delayTime) {
for (int i = 0; i < NUM_LEDS; ++i) {
leds[i] = CRGB::Black;
}
FastLED.show();
delay(delayTime);
}

// switches off all LEDs for reset
void CleanUp() {
for (int i = 0; i < NUM_LEDS; ++i) {
leds[i] = CRGB::Black;
}
FastLED.show();
}

void showProgramAllWhite(long delayTime) {
for (int i = 0; i < NUM_LEDS; ++i) {
// leds[i] = CRGB::White;
// CRGB newPixel = CHSV(120, 120, 120);
leds[i].setRGB(125, 255, 255);
}
FastLED.show();
delay(delayTime);
}

void showProgramAllRed(long delayTime) {
for (int i = 0; i < NUM_LEDS; ++i) {
// leds[i] = CRGB::White;
// CRGB newPixel = CHSV(120, 120, 120);
leds[i].setRGB(255, 0, 0);
}
FastLED.show();
delay(delayTime);
}

void showProgramAllBlue(long delayTime) {
for (int i = 0; i < NUM_LEDS; ++i) {
// leds[i] = CRGB::White;
// CRGB newPixel = CHSV(120, 120, 120);
leds[i].setRGB(0, 0, 255);
}
FastLED.show();
delay(delayTime);
}


// main program
void loop() {
// Départ blanc - fadeout
for (int i = BRIGHTHIGH; i > BRIGHTLOW; i = --i) {
if (!isNearMagnet()) {
if (i == BRIGHTHIGH){
showProgramAllWhite(500);
}
else {
showProgramAllWhite(3);
}
FastLED.setBrightness(i);
delay(INTERFADE);
} else {
return;
}
}
// fadein vers le Bleue
for (int i = BRIGHTLOW; i < BRIGHTHIGH; i = ++i) {
if (!isNearMagnet()) {
showProgramAllBlue(3);
FastLED.setBrightness(i);
delay(INTERFADE);
}
else {
return;
}
}
// Fadeout du bleue
for (int i = BRIGHTHIGH; i > BRIGHTLOW; i = --i) {
if (!isNearMagnet()) {
if (i == BRIGHTHIGH){
showProgramAllBlue(500);
}
else {
showProgramAllBlue(3);
}
FastLED.setBrightness(i);
delay(INTERFADE);
} else {
return;
}
}
// FadeIN vers le blanc
for (int i = BRIGHTLOW; i < BRIGHTHIGH; i = ++i) {
if (!isNearMagnet()) {
showProgramAllWhite(3);
FastLED.setBrightness(i);
delay(INTERFADE);
} else {
return;
}
}
// Fadeout du blanc
for (int i = BRIGHTHIGH; i > BRIGHTLOW; i = --i) {
if (!isNearMagnet()) {
if (i == BRIGHTHIGH){
showProgramAllWhite(500);
}
else {
showProgramAllWhite(3);
}
FastLED.setBrightness(i);
delay(INTERFADE);
} else {
return;
}
}
// FadeIN vers le Rouge
for (int i = BRIGHTLOW; i < BRIGHTHIGH; i = ++i) {
if (!isNearMagnet()) {
showProgramAllRed(3);
FastLED.setBrightness(i);
delay(INTERFADE);
} else {
return;
}
}
// Fadeout du rouge
for (int i = BRIGHTHIGH; i > BRIGHTLOW; i = --i) {
if (!isNearMagnet()) {
if (i == BRIGHTHIGH){
showProgramAllRed(500);
}
else {
showProgramAllRed(3);
}
FastLED.setBrightness(i);
delay(INTERFADE);
} else {
return;
}
}
// fadein vers le Blanc
for (int i = BRIGHTLOW; i < BRIGHTHIGH; i = ++i) {
if (!isNearMagnet()) {
showProgramAllWhite(3);
FastLED.setBrightness(i);
delay(INTERFADE);
} else {
return;
}
}
}
