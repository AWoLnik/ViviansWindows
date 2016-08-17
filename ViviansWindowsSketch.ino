// Vivian's Windows by Adam Wolnikowski,
// developed for Penn Air & Hydraulics
// as part of a charitable project in 
// cooperation with V-LINC.
// Description ~~~~~~~~~~~~~~~~~~~~~~~~~
//              Small arduino program 
//              for controlling the 
//              window acutation system
//              built and installed for
//              Vivian Paff.
// Changelog ~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  Version 1.0 - Core Functionality

#include <SimpleTimer.h>

// define motor controller pins
#define dir1 2
#define pwm1 3
#define dir2 4
#define pwm2 5
#define dir3 7
#define pwm3 6
#define dir4 8
#define pwm4 9
#define dir5 10
#define pwm5 11

// define button pins
#define button1up 14
#define button2up 16
#define button3up 18
#define button4up 13
#define button5up 1
#define button1down 15
#define button2down 17
#define button3down 19
#define button4down 12
#define button5down 0

// instantiate timers
SimpleTimer timer;
int lastTimeout;
int delayTime = 5000;

// booleans for tracking state of each motor
boolean running1 = false;
boolean running2 = false;
boolean running3 = false;
boolean running4 = false;
boolean running5 = false;

void setup() {
  Serial.begin(9600);
  
  // setup motor controller pins
  pinMode(dir1,OUTPUT);
  pinMode(pwm1,OUTPUT);
  pinMode(dir2,OUTPUT);
  pinMode(pwm2,OUTPUT);
  pinMode(dir3,OUTPUT);
  pinMode(pwm3,OUTPUT);
  pinMode(dir4,OUTPUT);
  pinMode(pwm4,OUTPUT);
  pinMode(dir5,OUTPUT);
  pinMode(pwm5,OUTPUT);

  // setup button pins
  pinMode(button1up,INPUT);
  pinMode(button2up,INPUT);
  pinMode(button3up,INPUT);
  pinMode(button4up,INPUT);
  pinMode(button5up,INPUT);
  pinMode(button1down,INPUT);
  pinMode(button2down,INPUT);
  pinMode(button3down,INPUT);
  pinMode(button4down,INPUT);
  pinMode(button5down,INPUT);

  // set internal pull-up resistors for buttons
  digitalWrite(button1up,HIGH);
  digitalWrite(button2up,HIGH);
  digitalWrite(button3up,HIGH);
  digitalWrite(button4up,HIGH);
  digitalWrite(button5up,HIGH);
  digitalWrite(button1down,HIGH);
  digitalWrite(button2down,HIGH);
  digitalWrite(button3down,HIGH);
  digitalWrite(button4down,HIGH);
  digitalWrite(button5down,HIGH);
}

void loop() {
  timer.run();
  
  if(digitalRead(button1up)==LOW) {
    timer.deleteTimer(lastTimeout);
    digitalWrite(dir1,LOW);
    if(!running1) {
      setMotor1();
      lastTimeout = timer.setTimeout(40000,killMotor1);
    } else {
      killMotor1();
    }
  }

  if(digitalRead(button1down)==LOW) {
    timer.deleteTimer(lastTimeout);
    digitalWrite(dir1,HIGH);
    if(!running1) {
      setMotor1();
      lastTimeout = timer.setTimeout(40000,killMotor1);
    } else {
      killMotor1();
    }
  }

  if(digitalRead(button2up)==LOW) {
    timer.deleteTimer(lastTimeout);
    digitalWrite(dir2,LOW);
    if(!running2) {
      setMotor2();
      lastTimeout = timer.setTimeout(40000,killMotor2);
    } else {
      killMotor2();
    }
  }

  if(digitalRead(button2down)==LOW) {
    timer.deleteTimer(lastTimeout);
    digitalWrite(dir2,HIGH);
    if(!running2) {
      setMotor2();
      lastTimeout = timer.setTimeout(40000,killMotor2);
    } else {
      killMotor2();
    }
  }

  if(digitalRead(button3up)==LOW) {
    timer.deleteTimer(lastTimeout);
    digitalWrite(dir3,LOW);
    if(!running3) {
      setMotor3();
      lastTimeout = timer.setTimeout(40000,killMotor3);
    } else {
      killMotor3();
    }
  }

  if(digitalRead(button3down)==LOW) {
    timer.deleteTimer(lastTimeout);
    digitalWrite(dir3,HIGH);
    if(!running3) {
      setMotor3();
      lastTimeout = timer.setTimeout(40000,killMotor3);
    } else {
      killMotor3();
    }
  }

  if(digitalRead(button4up)==LOW) {
    timer.deleteTimer(lastTimeout);
    digitalWrite(dir4,LOW);
    if(!running4) {
      setMotor4();
      lastTimeout = timer.setTimeout(40000,killMotor4);
    } else {
      killMotor4();
    }
  }

  if(digitalRead(button4down)==LOW) {
    timer.deleteTimer(lastTimeout);
    digitalWrite(dir4,HIGH);
    if(!running4) {
      setMotor4();
      lastTimeout = timer.setTimeout(40000,killMotor4);
    } else {
      killMotor4();
    }
  }

  if(digitalRead(button5up)==LOW) {
    timer.deleteTimer(lastTimeout);
    digitalWrite(dir5,LOW);
    if(!running5) {
      setMotor5();
      lastTimeout = timer.setTimeout(40000,killMotor5);
    } else {
      killMotor5();
    }
  }

  if(digitalRead(button5down)==LOW) {
    timer.deleteTimer(lastTimeout);
    digitalWrite(dir5,HIGH);
    if(!running5) {
      setMotor5();
      lastTimeout = timer.setTimeout(40000,killMotor5);
    } else {
      killMotor5;
    }
  }

  delay(1000);
}

void setMotor1() {
  analogWrite(pwm1,222);
  running1 = true;
}

void setMotor2() {
  analogWrite(pwm2,222);
  running2 = true;
}

void setMotor3() {
  analogWrite(pwm3,222);
  running3 = true;
}

void setMotor4() {
  analogWrite(pwm4,222);
  running4 = true;
}

void setMotor5() {
  analogWrite(pwm5,222);
  running5 = true;
}

void killMotor1() {
  analogWrite(pwm1,0);
  running1 = false;
}

void killMotor2() {
  analogWrite(pwm2,0);
  running2 = false;
}

void killMotor3() {
  analogWrite(pwm3,0);
  running3 = false;
}

void killMotor4() {
  analogWrite(pwm4,0);
  running4 = false;
}

void killMotor5() {
  analogWrite(pwm5,0);
  running5 = false;
}
