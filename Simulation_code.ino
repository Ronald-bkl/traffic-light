enum street_lights {
  GREEN,
  RED,
  YELLOW
};

street_lights LIGHT = GREEN;

const int greenP = 4;
const int redP = 2;
const int yellowP = 3;

int t3 = 3000;
int t2 = 2000;
int t1 = 1000;

bool afterGreen = true; 

void setup() {
  pinMode(greenP, OUTPUT);
  pinMode(redP, OUTPUT);
  pinMode(yellowP, OUTPUT);
}

void loop() {
  switch (LIGHT) {
    case GREEN:
      digitalWrite(greenP, HIGH);
      digitalWrite(redP, LOW);
      digitalWrite(yellowP, LOW);
      delay(t3);
    LIGHT=YELLOW;
    break;

    case YELLOW:
        digitalWrite(yellowP, HIGH);
        digitalWrite(greenP, LOW);
        digitalWrite(redP, LOW);
        delay(t1);
    if(afterGreen)
    {
    LIGHT=RED;
    }
    else
    {
      LIGHT=GREEN;
    }
    
    afterGreen=!afterGreen;
    break;

    case RED:
      digitalWrite(redP, HIGH);
      digitalWrite(greenP, LOW);
      digitalWrite(yellowP, LOW);
      delay(t2);
      LIGHT = YELLOW;
      
      break;
  }
}