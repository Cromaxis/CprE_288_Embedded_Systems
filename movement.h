/*
 * movement.h
 *
 *  Created on: Sep 4, 2018
 *      Author: kenneth1
 */

#include <stdio.h>
#include "open_interface.h"
#include "lcd.h"
#include "timer.h"

#ifndef MOVEMENT_H_
#define MOVEMENT_H_
oi_t *sensor_data;

//Initialize sensor data and lcd screen
void movement_init();

//Move a distance given in mm and when bumped back up turn and try moving again
void move_by_distance(int mm);

//Stop the wheels
void stop();

//Have both wheels go at the same speed
void go_same(int speed);

//Have the wheels go at different speeds
void go_diff(int speed_left, int speed_right);

//when bumped move to the right or left based on where the bump was detected
void bumped_left();
void bumped_right();

//Move backwards a given distance in mm
void back_up(int mm);

//turn 90 degrees cw or ccw
void turn_90_cw();

void turn_90_ccw();

//frees up sensors
void movement_clear();

#endif /* MOVEMENT_H_ */
