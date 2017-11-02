
// #define diy_pwm A2
#define pwm 3
#define dir 2
#define STEERING_FEEDBACK_PIN A0
// #define pot A1


void setup() {
  // put your setup code here, to run once:

   pinMode(pwm,OUTPUT);
   pinMode(dir,OUTPUT);
   // pinMode(diy_pwm,OUTPUT);
   // pinMode(pot,INPUT);

   // pinMode(13, OUTPUT);

   Serial.begin(9600);
}

int pwm_value = 255;

const int STEER_MIN = 380;
const int STEER_CTR = 512;
const int STEER_MAX = 700;
const int STEER_INC = 20;

int steerTarget=STEER_CTR;

void loop() {

    // ----------------------------------------------------------------------
    // Determine target position:
    // ----------------------------------------------------------------------
    if (Serial.available()) {
        char value = Serial.read();
        // Serial.write(value);

        if (value == 'l') { // More Left
            steerTarget -= STEER_INC;
            if (steerTarget < STEER_MIN) steerTarget = STEER_MIN;
        }
        else if (value == ';') { // More right
            steerTarget += STEER_INC;
            if (steerTarget > STEER_MAX) steerTarget = STEER_MAX;
        }
        else if (value == 'p') { // Centre
            steerTarget=STEER_CTR;
        }

        if (value != '\n') {
            Serial.println(steerTarget);
        }
    }

            // digitalWrite(pwm, pwm_value);                               //increase PWM in every 0.1 sec
            // delay(100);
            // digitalWrite(pwm, 0);                               //increase PWM in every 0.1 sec
    // ----------------------------------------------------------------------
    // Make target and actual line up:
    // ----------------------------------------------------------------------
    // int steerFeedback = analogRead(STEERING_FEEDBACK_PIN);
    // Serial.println(steerFeedback);
    // delay(500);

    // 0 - 1023. Active range observed is: 390 to 656
    // 2 to 3 ohms. is 4 to 6 / 10
    // Center is 512 but may be a little higher.

}


