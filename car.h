/*----------------------------------------------------------
*				HTBLA-Leonding / Klasse: <2Dhif>
* ---------------------------------------------------------
* Exercise Number: 0
* Title:			car.h
* Author:			P. Bauer
* Due Date:		January 9, 2015
* ----------------------------------------------------------
* Description:
* Car abstract data type demo.
* ----------------------------------------------------------
*/
#ifndef ___CAR_H
#define ___CAR_H

typedef struct Carimplementation* Car;
enum CarType {AIXAM,FIAT_MULTIPLA,JEEP};
enum Color {RED,GREEN,BLUE,ORANGE,SILVER,BLACK};

Car get_car(enum CarType cartype);

enum CarType get_type(Car car);

enum Color get_color(Car car);

void init();

double get_fill_level(Car car);

double get_acceleration_rate(Car car);

void set_acceleration_rate(Car car, double acceleration);

void accelerate(Car car);

int get_speed(Car car);

#endif
