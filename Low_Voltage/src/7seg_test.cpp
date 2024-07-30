#include <Arduino.h>
/*
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
const int segmentPins12[] = {21, 7, 8, 22, 20, 23, 10, 29};

const int numberofDigits = 4;

const int digitPins[numberofDigits] = {36, 33, 35, 34}; // digits 1, 2, 3, 4

void setup()
{
  for (int i = 0; i < 8; i++)
    pinMode(segmentPins12[i], OUTPUT); // set segment and DP pins to output

  // sets the digit pins as outputs
  for (int i = 0; i < numberofDigits; i++)
    pinMode(digitPins[i], OUTPUT);

  // set all digit pins to HIGH, except for digit 4
  digitalWrite(36, HIGH);
  digitalWrite(35, HIGH);
  digitalWrite(34, LOW);
  digitalWrite(33, HIGH);
}

void showDigit(int number, int digit)
{
  digitalWrite(digitPins[digit], HIGH);
  for (int segment = 1; segment < 8; segment++)
  {
    boolean isBitSet = bitRead(numeral[number], segment);

    digitalWrite(segmentPins12[segment], isBitSet);
  }
  delay(50);
  digitalWrite(digitPins[digit], LOW);
}

void showNumber(int number)
{
  if (number == 0)
    showDigit(0, numberofDigits - 1); // display 0 in the rightmost digit
  else
  {
    for (int digit = numberofDigits - 1; digit >= 0; digit--)
    {
      if (number > 0)
      {
        showDigit(number % 10, digit);
        number = number / 10;
      }
    }
  }
}

void loop()
{
  showNumber(value);
  value++;
  if (value == 10000)
    value = 0;
}
*/

void setup()
{
  pinMode(29, OUTPUT);
}
void loop()
{
  digitalWrite(29, HIGH);
  delay(1000);
  digitalWrite(29, LOW);
  delay(1000);
}