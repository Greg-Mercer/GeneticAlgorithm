//
// Created by Greg on 2018-11-11.
//

#include <random>
#include "City.hpp"

unsigned long City::count = 1;

City::City() {
    default_random_engine re;
    re.seed(random_device()());
    uniform_real_distribution<double> dist(0.00, MAP_BOUNDARY);

    this->x = dist(re);
    this->y = dist(re);
    this->id = count;
    count++;
}

double City::get_distance_between_cities(City &other) {
    return sqrt(pow((this->x - other.x), 2) + pow((this->y - other.y), 2));
}

bool City::operator==(City &other) {
    return this->id == other.id;
}

unsigned long City::getId() const {
    return id;
}
