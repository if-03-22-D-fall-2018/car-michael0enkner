#include "car.h"

struct CarData
{
enum CarType type;
int max_speed;
double fill_level;
double accelerate;
double speed;
double lowest_accelerate;
double highest_accelerate;
};

struct CarImplementation
{
enum Color color;
struct CarData car_data;
bool is_available;
};

struct CarData aixam = { AIXAM, 45, 16.0, 0.0, 0, -8.0, 1.0 };
struct CarData fiat_multipla = { FIAT_MULTIPLA, 170, 65.0, 0.0, 0, -8.0, 2.26 };
struct CarData jeep = { JEEP, 196, 80.0, 0.0, 0, -8.0, 3.14 };

struct CarImplementation aixam1 = { RED, aixam, false };
struct CarImplementation fiat_multipla1 = { GREEN, fiat_multipla, false };
struct CarImplementation fiat_multipla2 = { BLUE, fiat_multipla, false };
struct CarImplementation fiat_multipla3 = { ORANGE,fiat_multipla, false };
struct CarImplementation jeep1 = { SILVER, jeep, false };
struct CarImplementation jeep2 = { BLACK, jeep, false };

static Car car_park[MAX_CARS] = {&aixam1,&fiat_multipla1,&fiat_multipla2,&fiat_multipla3,&jeep1, &jeep2};

void init()
{
for (int i = 0; i < MAX_CARS; i++)
{
car_park[i]->is_available = false;
car_park[i]->car_data.speed = 0;
car_park[i]->car_data.accelerate = 0;
}
}

Car get_car(enum CarType type)
{
for (int i = 0; i < MAX_CARS; i++)
{
if (car_park[i]->car_data.type == type && !car_park[i]->is_available)
{
car_park[i]->is_available = true;
return car_park[i];
}
}
return 0;
}

int get_speed(Car car)
{
if (car->car_data.speed - (int)car->car_data.speed >= 0.5) {
return (int)car->car_data.speed + 1;
}
return (int)car->car_data.speed;
}
CarType get_type(Car car)
{
return car->car_data.type;
}
Color get_color(Car car)
{
return car->color;
}

double get_fill_level(Car car)
{
return car->car_data.fill_level;
}

double get_acceleration_rate(Car car)
{
return car->car_data.accelerate;
}

void set_acceleration_rate(Car car, double rate)
{
if (rate >= car->car_data.lowest_accelerate && rate <= car->car_data.highest_accelerate)
{
car->car_data.accelerate = rate;
}
else if (rate < car->car_data.lowest_accelerate)
{
car->car_data.accelerate = car->car_data.lowest_accelerate;
}
else
{
car->car_data.accelerate = car->car_data.highest_accelerate;
}
}

void accelerate(Car car)
{
double speed = car->car_data.accelerate * 3.6;

if (speed + car->car_data.speed < car->car_data.max_speed)
{
car->car_data.speed+=speed;
}
else if (car->car_data.speed < car->car_data.max_speed)
{
speed = car->car_data.max_speed - car->car_data.speed;
car->car_data.speed += speed;
}
}
