
/*-------defining Inputs------*/
int flame_S = A0;         // flame sensor
int Smoke_S = A3;    //smoke sensor

/*-------defining Outputs------*/
int LM1 = 2;       // left motor
int LM2 = 3;      // left motor
int RM1 = 4;     // right motor
int RM2 = 5;    // right motor
int pump = 6;   // pump
int Buzzer = 7;  // buzzer
int redled = 8;    // fire signal, red led
int yellowled = 9;  // yellow led
int greenled = 10;  // green led
 
void setup()
{
  pinMode(flame_S, INPUT);
  pinMode(Smoke_S, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(pump, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(redled, OUTPUT);
  pinMode(yellowled, OUTPUT);
  pinMode(greenled, OUTPUT);
  Serial.begin(9600); // for terminal, max 9600 bit pass, baud value
}
 
void loop()
{

  int flameval1 = digitalRead (flame_S) ;// read input value
  int smokeval = digitalRead(Smoke_S);
  Serial.print("Flame_Value = "); // show in terminal
  Serial.println(flameval1);
  Serial.print("Smoke_Value = ");
  Serial.println(smokeval);
    
 
    if (flameval1 == LOW and smokeval == LOW) //If Fire OR Smoke not detected 
    {
    Serial.println(" |...SAFE ENVIRONMENT...| ");
    
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
    digitalWrite(Buzzer, LOW);
    digitalWrite(pump, LOW);
    digitalWrite(redled, LOW);
    digitalWrite(yellowled, LOW);
    digitalWrite(greenled, HIGH);
    }
    
    else if (flameval1 == HIGH and smokeval == LOW) //If Fire detected
    {
    Serial.println(" |...FIRE DETECTED : DANGER!...| ");
    
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    digitalWrite(Buzzer, HIGH);
    digitalWrite(pump, HIGH);
    digitalWrite(redled, HIGH);
    delay(200); // red blinking
    digitalWrite(redled, LOW);
    digitalWrite(yellowled, LOW);
    digitalWrite(greenled, LOW);
    
    }
    else if (flameval1 == LOW and smokeval == HIGH) //If SMOKE detected
    {
    Serial.println(" |...SMOKE DETECTED: WARNING!...| ");
    
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
    digitalWrite(Buzzer, HIGH);
    digitalWrite(redled, LOW);
    digitalWrite(yellowled, HIGH);
    digitalWrite(greenled, LOW);

    }
    else if (flameval1 == HIGH and smokeval == HIGH) //If FIRE & SMOKE detected
    {
    Serial.println(" |...FIRE & SMOKE DETECTED: DANGER!...| ");
    
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    digitalWrite(Buzzer, HIGH);
    digitalWrite(pump, HIGH);
    digitalWrite(redled, HIGH);
    digitalWrite(yellowled, HIGH);
    digitalWrite(greenled, LOW);

    }
    
delay(400); // terminal message delay
 

}
