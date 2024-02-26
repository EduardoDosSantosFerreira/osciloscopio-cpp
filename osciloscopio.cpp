#include <LiquidCrystal.h>

#define INPUT_PIN A0
#define MAX_REPETITION 19
#define LCD_REFRESH_DELAY 1000
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const byte LEVELS[] = {' ', 0, '_', 1, 2, 3, 4, 5, 6, 255, '*'};


#if MAX_REPETITION < 10
void inline print_rep(int unsigned repeation_count) {
    lcd.print(repeation_count);
}

#elif MAX_REPETITION < 20
void print_rep(int unsigned repeation_count) {
    if (repeation_count < 10) {
      lcd.print(repeation_count);
    } else {
      lcd.write(LEVELS[(repeation_count - 9)]);
    }
}

#else
void print_rep(int unsigned repeation_count) {
    if (repeation_count < 10) {
      lcd.print(repeation_count);
    } else if (repeation_count < 99) {
      lcd.write(LEVELS[(repeation_count / 10)]);
    } else {
       lcd.write(LEVELS[10]);        
    }
}
#endif

void setup() {
    lcd.begin(16, 2);
    
    byte bar[] = {0, 0, 0, 0, 0, 0, 0, 21};
    lcd.createChar(0, bar);
    bar[7] = 31;
    for (int i=1; i < 7; i++) {
        bar[7 - i] = 31;
        lcd.createChar(i, bar);
    }
    delay(100);
    lcd.clear();
}

int inline readInput() {
    return (analogRead(INPUT_PIN) / 103.0);
}

void loop() {
    int unsigned repetition;
    byte unsigned last_value;
    byte unsigned value;

    byte unsigned levels[20];
    byte unsigned repetitions[20];

    byte i = 0;
    
    value = last_value = readInput();
    for (i = 0; i < 20; i++) {
       repetition = 0;
       while (value == last_value) {
           value = readInput();
           if (++repetition == MAX_REPETITION) break; 
        }
        levels[i] = LEVELS[last_value];
        repetitions[i] = repetition;
        last_value = value;
    }
    long int unsigned best_value = 0;
    byte best_index;
    for (i=1; i < 5; i++) {
      if (best_value < (repetitions[i] + levels[i] * 10)) {
          best_value = repetitions[i] + levels[i] * 10;
          best_index = i;
      }
    }
    lcd.home();
    lcd.noDisplay();
    for (i = 0; i < 16; i++) {
        lcd.write(levels[i + best_index]);
    }
    lcd.setCursor(0, 1);
    for (i = 0; i < 16; i++) {
        print_rep(repetitions[i + best_index]);
    }
    lcd.display();
    delay(LCD_REFRESH_DELAY);
}
