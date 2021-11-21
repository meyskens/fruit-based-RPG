#include <Arduino.h>

String fruitOfTheDay = "orange or banana";

const int FRUIT_ONE=14;
const int FRUIT_TWO=32;

void die() {
  for (int i = 0; i < 100; i++) {
    Serial.println("You dead m8");
    if (i % 2) {
      digitalWrite(LED_BUILTIN, HIGH);
    } else {
      digitalWrite(LED_BUILTIN, LOW);
    }
    delay(500);
  }
  digitalWrite(LED_BUILTIN, LOW);
}

int getOutcome() {
  while (true) {
    int one = touchRead(FRUIT_ONE);
    int two = touchRead(FRUIT_TWO);
    if (one < 10 && one > 1) {
      return 1;
    } else if (two < 10 && two > 1) {
      return 2;
    }
    delay(100); // delaying to not oversample
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  //Serial.println(touchRead(FRUIT_ONE));
  //delay(500);
  //return;
  Serial.println("Welcome to my world of terror");
  delay(1000);
  Serial.println("it was a sunny afternoon in Yellow City, which is rare...");
  delay(1000);
  Serial.println("Suddenly everything turns dark, and you are being sucked into a black hole... ");
  Serial.print("on the other side you see the same place you were before... However you can only do two things.. touching an ");
  Serial.println(fruitOfTheDay);
  delay(1000);

  Serial.println("A mystherious lady appears, she looks a bit like Tinne but enough difference not to get a copyright strike.");
  Serial.println("She says, \"I am the one who can help you, but you must first prove yourself.\"");
  delay(1000);
  Serial.println("You can either touch the " + fruitOfTheDay);

  if (getOutcome() == 1) {
    Serial.println("You are worth continuing this journey. Follow moe");
    delay(5000);
  } else {
    die();
    return;
  }

  Serial.println("This is the castle of big Ward K. he is the ruler of all computer science.");
  Serial.println("His terror spreads over all Yellow like component parcels, slow but terrifying!");
  delay(1000);
  Serial.println("Your mission is to defeat him and free the students from dark days...");
  Serial.println("Chose your weapon whisely...");
  Serial.println("You can either touch the " + fruitOfTheDay);
  if (getOutcome() == 2) {
    Serial.println("Good choice my friend, let's continue!");
  } else {
    Serial.println("The fruit is rotten it explodes in your face...");
    delay(5000);
    die();
    return;
  }



  // TODO: add more chapters

  Serial.println("YOU WON!!!");
  Serial.println("You are now free to go");
  Serial.println("Or not... restarting in 10 seconds");
  delay(10000);
}