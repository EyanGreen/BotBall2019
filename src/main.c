#include <kipr/botball.h>
void movestraight (int);
void leftturn (int);
void rightturn (int);
int main()
{
    int claw_port = 1;
    int arm_port = 0;
    int claw_open = 1600; 
    int claw_close = 105;
    int arm_up = 1050;
    int arm_down = 1900;
        
   //While Away From Cube It Keeps Driving. 
    while (analog(0)< 1400)
        { 
            movestraight (80);
            msleep(500);
        }
    ao();
    enable_servos ();
    moveservo (claw_port,claw_open); //Claw will open after it stops moving.
    msleep(500);
    moveservo (arm_port,arm_down);
    msleep(500);
    moveservo (claw_port,claw_close);
    msleep(500);
    moveservo (arm_port,arm_up);
    msleep(500);
    disable_servos ();
    return 0;
}
void movestraight (int power)
{
    motor(0,power); //moves left motor at 80 percent of its maximum speed
    motor(3,power);//moves right motor at 80 percent of its maximum speed

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

void moveservo (int port, int distance)
{
    set_servo_position (port,distance); 
}