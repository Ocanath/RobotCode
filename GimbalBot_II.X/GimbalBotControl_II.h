#ifndef GIMBALBOTCONTROL_II_H
#define	GIMBALBOTCONTROL_II_H

void pin_setup();
void move_servos(int * servo_list, int * wheels, int * gimbal, int cycles);
void Keyboard_Control(int * servo_list, int * wheels, int * gimbal);

#endif	/* GIMBALBOTCONTROL_II_H */

