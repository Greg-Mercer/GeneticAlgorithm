//
// Created by Greg on 2018-11-11.
//

#include <random>
#include "City.hpp"



unsigned long City::count = 1;

City::City() {
    mt19937 rng;
    default_random_engine re;
    rng.seed(random_device()());
    uniform_real_distribution<double> dist(0.00, MAP_BOUNDARY);

    this->x = dist(re);
    this->y = dist(re);
    this->id = count;
    count++;
}

double City::get_distance_between_cities(City &other) {
    return ((this->x - other.x) + (this->y - other.y));
}

bool City::operator==(City &other) {
    return this->id == other.id;
}
