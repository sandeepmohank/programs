#include "mbed.h"

DigitalIn mypin1(D7); // change this to the button on your board
DigitalIn mypin2(D4);
DigitalOut myled1(LED1);
DigitalOut myled2(LED4);
DigitalOut mypin3(D8);  //A4 L1
DigitalOut mypin4(D9);  //A3 L2
DigitalOut mypin5(D10); //A1 R1
DigitalOut mypin6(D11); //A2 R2
PwmOut enable2(D2);
PwmOut enable1(D14);
int s1, s2;
static void left_turn();
static void right_turn();
static void straight1();
static void stop();

static void straight1()
{
  printf(" Move forward\n");
  mypin3 = 0;
  mypin4 = 1;
  mypin5 = 0;
  mypin6 = 1;
}

int main()
{

  enable1.period(0.01f); // 4 second period
  enable2.period(0.01f);
  enable1.write(0.2f);
  enable2.write(0.2f);
  /*
while(2) {

         printf("mypin1-- %d,mypin2-- %d\n\r", mypin1.read(), mypin2.read());
         ThisThread::sleep_for(100);
        
}*/

  while (1)
  {
    ThisThread::sleep_for(200);
    s2 = mypin2;
    s1 = mypin1;
    printf("mypin1 has value : %d \n\r", s1);
    printf("mypin2 has the value : %d \n\r", s2);

    if ((s1 == 0) && (s2 == 0))
    {
      printf("hello world..\n");

      straight1();
      printf("go straight..\n");
    }
    else if (s1 == 0 && s2 == 1)
    {

      
      right_turn();
      printf("right turn..\n");
      ThisThread::sleep_for(500);
      
    }
    else if (s1 == 1 && s2 == 0)
    {

      
      left_turn();
      printf("left turn..\n");
      ThisThread::sleep_for(500);
      
    }
    else if (s1 == 1 && s2 == 1)
    {
      //stop();
      enable1.write(0.0f);
      enable2.write(0.0f);
      printf("stop..\n");
      ThisThread::sleep_for(3000);
      //printf("stop..");
    }
  }
}
static void left_turn()
{ 
  enable1.write(0.3f);
  enable2.write(0.4f);
  mypin3 = 0;
  mypin4 = 1;
  mypin5 = 1;
  mypin6 = 0;
  //enable1.write(0.3f);
  //enable2.write(0.3f);
}
static void right_turn()
{ 
  enable1.write(0.4f);
  enable2.write(0.3f);
  mypin3 = 1;
  mypin4 = 0;
  mypin5 = 0;
  mypin6 = 1;
 // enable1.write(0.3f);
  //enable2.write(0.3f);
}

static void stop()
{

  mypin3 = 1;
  mypin4 = 0;
  mypin5 = 1;
  mypin6 = 0;
  ThisThread::sleep_for(1000);
  }
