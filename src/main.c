#include <kipr/botball.h>
//Prototypes

void movestraight (int,int);
void leftturn (int);
void rightturn (int);
void movebackward (int,int);
void moveservo (int,int);
//Variables
int main()
{
    int claw_port = 3;
    int arm_port = 0;
    int claw_open = 1600; 
    int claw_close = 845;
    int arm_up = 1050;
    int arm_down = 1600;
    
    enable_servos();
    moveservo(arm_port,arm_down);
    msleep(500);
    moveservo(claw_port,claw_open); 
    msleep(500);
    movestraight(850,90);
    leftturn(2000);
    movebackward(3050,90);  
    rightturn(2000);
    movestraight(300,90);
    leftturn(2000);
    movestraight(1250,90);
    movebackward(4050,90);  
    moveservo(arm_port,arm_up);
    moveservo(claw_port,claw_close);
    disable_servos();

    return 0;
}    
//Moves the robot forward.
//Moves the robot forward or backward.
void movestraight (int distance, int speed)
{
    motor (0, speed);
    motor (3,speed);
    msleep (distance);
}  

void movebackward (int distance, int speed)
{
    motor (0, -speed);
    motor (3,-speed);
    msleep (distance);
}  
//Does a left turn.
void leftturn (int time)
{
    motor(0,80); //moves left motor at 80 percent of its maximum speed
    motor(3,20);//moves right motor at 20 percent of its maximum speed
    msleep (time);//makes robot stop for 2 seconds   
}
//Does a right turn.
void rightturn (int time)
{
    motor(0,20); //moves left motor at 80 percent of its maximum speed
    motor(3,80);//moves right motor at 20 percent of its maximum speed
    msleep (time);//makes robot stop for 2 seconds   
}
//Moves any servo.
void moveservo (int port, int distance)
{
    set_servo_position (port,distance); 
}

