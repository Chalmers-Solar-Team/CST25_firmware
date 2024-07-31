#include <Arduino.h>

int value = 0;
// ABCDEFG,dp
const int numeral[10] = {
    B11111100, // 0
    B01100000, // 1
    B11011010, // 2
    B11110010, // 3
    B01100110, // 4
    B10110110, // 5
    B00111110, // 6
    B11100000, // 7
    B11111110, // 8
    B11100110, // 9
};

// pins for decimal point and each segment
// dp, G, F, E, D, C, B, A
// 1-4, 2-5,3-6,4-7,6-28,7-29,8-30,9-31
// 19-8, 18-9, 17-10, 16-11, 15-24, 14-25, 13-26, 12-27
// the first number is the pin on the 7seg display, the second number is the pin on the arduino
// 1 goes to d, 2 goes to dp, 3 goes to e, 4 goes to c, 5 goes to gnd, 6 goes to d, 7 goes to dp, 8 goes to e
// 9 goes to c, 10 goes to gnd, 11 goes to b, 12 goes to a, 13 goes to f, 14 goes to g, 15 goes to gnd
// 16 goes to b, 17 goes to a, 18 goes to f, 19 goes to g

// 7seg pin 17, 16, 4, 1 , 3, 18, 19, 2 goes to digit 1 and 2
// 7seg pin 12, 11, 9, 6, 8, 13, 14, 7 goes to digit 3 and 4

const int segmentPins12[] = {4, 8, 9, 6, 5, 7, 11, 10};

const int segmentPins34[] = {29, 24, 25, 30, 28, 31, 27, 26};

const int numberofDigits = 4;

const int digitPins[numberofDigits] = {0, 1, 2, 3}; // digits 1, 2, 3, 4

void setup()
{
  // begin serial communication
  Serial.begin(9600);

  for (int i = 0; i < 8; i++)
    pinMode(segmentPins12[i], OUTPUT); // set segment and DP pins to output

  for (int i = 0; i < 8; i++)
    pinMode(segmentPins34[i], OUTPUT); // set segment and DP pins to output

  // sets the digit pins as outputs
  for (int i = 0; i < numberofDigits; i++)
    pinMode(digitPins[i], OUTPUT);

  // set all digit pins to HIGH, except for digit 4
  digitalWrite(digitPins[0], HIGH);
  digitalWrite(digitPins[1], LOW);
  digitalWrite(digitPins[2], HIGH);
  digitalWrite(digitPins[3], LOW);
  digitalWrite(segmentPins12[3], HIGH);
  digitalWrite(segmentPins34[3], HIGH);

  // pinMode(39, INPUT);
  pinMode(40, INPUT);
}

void displayDigit(int number)
{
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(segmentPins12[i], (numeral[number] >> i) & 1);
    digitalWrite(segmentPins34[i], (numeral[number] >> i) & 1);
  }
}

void displayNumber(int number, int t = 5)
{
  int digit0 = number / 10000;
  int digit1 = (number % 10000) / 1000;
  int digit2 = (number % 1000) / 100;
  int digit3 = (number % 100) / 10;
  int digit4 = number % 10;

  digitalWrite(digitPins[0], LOW);
  digitalWrite(digitPins[1], HIGH);
  digitalWrite(digitPins[2], HIGH);
  digitalWrite(digitPins[3], HIGH);
  displayDigit(digit1);
  delay(t);

  digitalWrite(digitPins[0], HIGH);
  digitalWrite(digitPins[1], LOW);
  digitalWrite(digitPins[2], HIGH);
  digitalWrite(digitPins[3], HIGH);
  displayDigit(digit2);
  delay(t);

  digitalWrite(digitPins[0], HIGH);
  digitalWrite(digitPins[1], HIGH);
  digitalWrite(digitPins[2], LOW);
  digitalWrite(digitPins[3], HIGH);
  displayDigit(digit3);
  delay(t);

  digitalWrite(digitPins[0], HIGH);
  digitalWrite(digitPins[1], HIGH);
  digitalWrite(digitPins[2], HIGH);
  digitalWrite(digitPins[3], LOW);
  displayDigit(digit4);
  delay(t);
}

void loop()
{
  analogReadResolution(10);
  int value = analogRead(40);

  displayNumber(value);
  Serial.println(value);
}