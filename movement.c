/*
 * movement.c
 *
 *  Created on: Sep 4, 2018
 *      Author: kenneth1
 */

#include "movement.h"

void movement_init()
{
    sensor_data = oi_alloc();
    lcd_init();
    oi_init(sensor_data);
}

void move_by_distance(int mm)
{

    int curr = 0;
    int speed = 250;

    go_same(speed);

    while (curr < mm)
    {
        oi_update(sensor_data);
        if (sensor_data->bumpLeft)
        {
            //to correct bump distance
            curr -= 100;
            stop();
            bumped_left();
            move_by_distance(mm - curr);
            break;
        }
        if (sensor_data->bumpRight)
        {
            //to correct bump distance
            curr -= 100;
            stop();
            bumped_right();
            move_by_distance(mm - curr);
            break;
        }
        curr += sensor_data->distance;
        lcd_printf("Distance: %d", curr);
    }

    stop();

}

void stop()
{
    oi_setWheels(0, 0);
}

void go_same(int speed)
{
    oi_setWheels(speed, speed);
}

void go_diff(int speed_left, int speed_right)
{
    oi_setWheels(speed_right, speed_left);
}

void bumped_left()
{
    back_up(-150);
    stop();
    turn_by_degree_cw();

    move_by_distance(250);
    turn_by_degree_ccw();

}

void bumped_right()
{
    back_up(-150);
    stop();

    turn_by_degree_ccw();

    move_by_distance(250);
    stop();

    turn_by_degree_cw();
}

void back_up(int mm)
{
    go_same(mm);
    timer_waitMillis(1000);
    stop();
}

void turn_90_cw()
{
    int speed = 185;
    go_diff(speed, -speed);
    timer_waitMillis(910);
    stop();

}

void turn_90_ccw()
{
    int speed = 185;
    go_diff(-speed, speed);

    timer_waitMillis(910);

    stop();
}

void movement_clear()
{
    oi_free(sensor_data);
    //lcd_printf("Donezo!");
}
