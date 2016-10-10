#ifndef PWM_CONTROL_H
#define	PWM_CONTROL_H




void pin_setup();
void servoenable(int motornum, int dir);
void IO_pwm(int * times, int * map, int period, int num_motors, int repeat, int offset);
void move_wheels(char dir, int LeftDuty, int RightDuty, int * times, int * map, int num_motors, int num_loops);


#endif	/* PWM_CONTROL_H */

