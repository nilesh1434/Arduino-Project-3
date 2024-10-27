// Nilesh Jain - 653929943
// Lab 3 - Scrolling output
// This code is supposed to show my name and under it my favorite quote which will scroll through the LCD screen.
// Youtube link - https://youtu.be/oZjMqd3BUNg

#include <LiquidCrystal.h>

// LCD points
int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;

// library
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// scrolling quote
char * quote = "I have a dream     ";
// line number to show string
int lineNum = 1;
int temp = 0;


void setup() {
  // start the LCD screen
  lcd.begin(16, 2);
  // set on column 0, row 0
  lcd.setCursor(1, 0);
  // prints name
  lcd.print("Sai");
}

void loop() {
  // function that has the scrolling quote
  quoteLine();
  // delay for 1 second
  delay(1000);
}

void quoteLine() {
  int len = strlen(quote);
  if (temp == (len - 1)) {
    temp = 0;
  }
  lcd.setCursor(0, lineNum);
  if (temp < lineNum - 16) {
    for (int i = temp; i < temp + 16; i++) {
      lcd.print(quote[i]);
    }
  }
  else {
    for (int i = temp; i < (len - 1); i++) {
      lcd.print(quote[i]);
    }
    for (int i = 0; i <= 16 - (len - temp); i++) {
      lcd.print(quote[i]);
    }
  }
  temp++;
}
