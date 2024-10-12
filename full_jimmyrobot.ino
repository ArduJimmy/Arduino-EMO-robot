sen#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <MPU6050.h>
#include <LMotorController.h>

MPU6050 mpu;

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define OLED_ADDR 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int buzzerPin = 9;
bool isLifted = false;

void setup() {
    Serial.begin(115200);
    Wire.begin();
    mpu.initialize();
    
    pinMode(buzzerPin, OUTPUT);

    if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
      Serial.println(F("SSD1306 allocation failed"));
      for (;;)
        ;
    }
    display.clearDisplay();
    display.display();

  }

  void loop() {

  int16_t ax, ay, az;
  mpu.getAcceleration(&ax, &ay, &az);
    // Check if the robot is being lifted (e.g., sudden change in acceleration)
    if (abs(ax) > 12000 || abs(ay) > 12000 || abs(az) < 1000) {
        if (!isLifted) {
            isLifted = true;
            display.clearDisplay();      
            feelingConfused();
            }
          } 
        else {
            isLifted = false;
            display.clearDisplay(); 
            stopBeeping();
            feelingSleepy();
          }

    delay(300);


    // Assume you have already read the MPU6050 sensor values into ax, ay, az
    //Serial.print("ax: ");
    //Serial.println(abs(ax));  // Print the absolute value of ax
    //Serial.print("ay: ");
    //Serial.println(abs(ay));  // Print the absolute value of ay
    //Serial.print("az: ");
    //Serial.println(abs(az));  // Print the absolute value of az
    //delay(500);  // Delay to make the output readable
              
  }

  void stopBeeping(){
        noTone(buzzerPin); // Turn off the buzzer
  }
  void drawRoundRectangleEyes(int x, int y, int w, int h) {
    display.clearDisplay();
    display.fillRoundRect(x, y, w, h, 5, SSD1306_WHITE); // Draw a round rectangle for the eyes
    display.fillRoundRect(x + 60, y, w, h, 5, SSD1306_WHITE);
    display.display();
  }

  void commonBlink() {
    // Common blink with a small soft line
    display.clearDisplay();
    drawRoundRectangleEyes(15, 20, 40, 30); // Draw normal eyes
    delay(500);
    // Blink effect
    display.clearDisplay();
    display.fillRoundRect(10, 50, 40, 1, 13, SSD1306_BLACK); // Left eye blink line
    display.fillRoundRect(88, 50, 40, 1, 13, SSD1306_BLACK); // Right eye blink line
    display.display();
    delay(200); // Blink duration
    // Back to normal eyes
    drawRoundRectangleEyes(15, 20, 40, 30); // Draw normal eyes
    delay(500);
  }

  void feelingHappy() {
    // Eyes like crescent moon
    display.clearDisplay();
    // Left Eye (crescent shape)
    display.fillCircle(32, 40, 15, SSD1306_WHITE);   // Full circle
    display.fillCircle(32, 45, 15, SSD1306_BLACK);   // Overlapping circle to create crescent
    // Right Eye (crescent shape)
    display.fillCircle(96, 40, 15, SSD1306_WHITE);   // Full circle
    display.fillCircle(96, 45, 15, SSD1306_BLACK);   // Overlapping circle to create crescent
    display.display();
  }
  void feelingAnnoyed() {
    // Eyes like crescent moon
    display.clearDisplay();
    drawRoundRectangleEyes(15, 32, 40, 5);
    display.display();
  }

  void feelingSuspecious() {
    // Eyes like crescent moon
    display.clearDisplay();
    drawRoundRectangleEyes(15, 20, 40, 20);
    display.display();
  }

  void feelingAngry() {
    display.clearDisplay();
    drawRoundRectangleEyes(15, 20, 40, 30); // Draw normal eyes
    // Animate the eyes shrinking and shaking randomly
    for (int i = 0; i < 20; i++) {
      display.clearDisplay();

      int offsetX = random(-1, 1); // Random offset between -1 and 1

      // Left Eye (Wider triangle shape for more angry expression)
      //display.fillTriangle(20, 25, 60, 45, 20, 45, SSD1306_WHITE); // Left angry eye
      display.fillTriangle(20, 25 + offsetX, 60, 45 + offsetX, 20, 45, SSD1306_WHITE); // Left angry eye

      // Right Eye (shifted 10 pixels right)
      //display.fillTriangle(108, 25, 68, 45, 108, 45, SSD1306_WHITE); // Right angry eye
      display.fillTriangle(108, 25 + offsetX, 68, 45 + offsetX, 108, 45, SSD1306_WHITE); // Right angry eye

      display.display();
      delay(100);
    }
}


void feelingConfused() {
    display.clearDisplay();
    drawRoundRectangleEyes(15, 20, 40, 30); // Draw normal eyes
    // Animate the eyes shrinking and shaking randomly
    for (int i = 0; i < 20; i++) {
      display.clearDisplay();

      int offsetX = random(-35, 35); // Random offset between -1 and 1
      int offsetY = random(-35, 35);    

      // Draw smaller, "shaking" eyes
      drawRoundRectangleEyes(15 + offsetX, 20 + offsetY, 40, 30);
      display.display();

      commonBlink();
      
      delay(100);
    }
  }

void feelingBrutalExplosion() {
    display.clearDisplay();

    for (int i = 0; i < 15; i++) {
      // Explosion effect: expanding circles
      display.drawCircle(64, 32, i, SSD1306_WHITE); // Centered at (64,32), expand radius from 0 to 14
      display.display();
      delay(50);  // Adjust delay for explosion speed
      display.clearDisplay();  // Clear screen for next frame
    }

    for (int i = 0; i < 10; i++) {
      // Draw small random pixels to mimic explosion debris
      int x = random(0, 128);
      int y = random(0, 128);
      display.drawPixel(x, y, SSD1306_WHITE);
      display.display();
      delay(50);
    }

    // Clear after the explosion
    display.clearDisplay();
    display.display();
  }

  void feelingSleepy() {
    display.clearDisplay();

    // Draw sleepy eyes
    drawRoundRectangleEyes(20, 60, 30, 1);
    display.display();
    delay(500);

    // Draw three "Z" characters, blinking in order
    for (int i = 0; i < 3; i++) {
      display.clearDisplay();

      // Redraw sleepy eyes
      drawRoundRectangleEyes(20, 60, 30, 1);

      // Draw the "Z" characters of different sizes
      display.setTextColor(SSD1306_WHITE);

      // Small "z"
      display.setTextSize(3);
      display.setCursor(90, 10);
      display.print("z");

      // Medium "z"
      display.setTextSize(2);
      display.setCursor(80, 20);
      display.print("z");

      // Large "z"
      display.setTextSize(1);
      display.setCursor(70, 30);
      display.print("z");

      display.display();
      delay(300);  // Delay to control the blinking animation

      // Clear the "Z" characters for blinking effect
      display.clearDisplay();
      drawRoundRectangleEyes(20, 60, 30, 1);
      display.display();
      delay(300);
    }
  }



  void Totheleft() {
    display.clearDisplay();
    drawRoundRectangleEyes(1, 20, 40, 30); // Draw normal eyes
    display.display();
  }

  void Totheright() {
    display.clearDisplay();
    drawRoundRectangleEyes(25, 20, 40, 30); // Draw normal eyes
    display.display();
  }

  void TotheTop() {
    display.clearDisplay();
    drawRoundRectangleEyes(15, 1, 40, 30); // Draw normal eyes
    display.display();
  }

  void TotheBottom() {
    display.clearDisplay();
    drawRoundRectangleEyes(15, 40, 40, 30); // Draw normal eyes
    display.display();
  }

  void isengVoice() {
    for (int i = 0; i < 10; i++) {
      tone(buzzerPin, 150, 100);
      delay(100);
      tone(buzzerPin, 200, 100);
      delay(100);
    }
  }

  void emergencyVoice() {
    // Generate the sound pattern for "help" using the buzzer
    tone(buzzerPin, 800, 200);  // H sound
    delay(300);
    tone(buzzerPin, 1000, 150); // E sound
    delay(100);
    tone(buzzerPin, 900, 200);  // L sound
    delay(200);
    tone(buzzerPin, 900, 200);  // P sound
    delay(400);
    tone(buzzerPin, 800, 200);  // H sound
    delay(300);
    tone(buzzerPin, 1000, 150); // E sound
    delay(100);
    tone(buzzerPin, 900, 200);  // L sound
    delay(200);
    tone(buzzerPin, 900, 200);  // P sound
    delay(500);
  }

  void policeVoice(int duration) {
    unsigned long endTime = millis() + duration; // Run the siren for the specified duration
    while (millis() < endTime) {
      tone(9, 700); // High tone
      delay(300);
      tone(9, 400); // Low tone
      delay(300);
    }
    noTone(9); // Turn off the buzzer
  }

  void iseng_2_Voice() {
    tone(buzzerPin, 800, 400);
    delay(2000);
    noTone(9); // Turn off the buzzer
  }
