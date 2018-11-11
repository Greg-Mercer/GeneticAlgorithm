//
// Created by Greg on 2018-11-11.
//

#include <random>
#include "City.hpp"


long City::count = 1;

City::City() {
    mt19937 rng;
    default_random_engine re;
    rng.seed(random_device()());
    uniform_real_distribution<double> dist(0.00,1000.00);

    this->x = dist(re);
    this->y = dist(re);
    count++;
    // todo: generate random city name
}
