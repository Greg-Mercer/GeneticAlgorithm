//
// Created by Greg on 2018-11-11.
//

#include "Tour.hpp"
#include <algorithm>
#include <random>

using namespace std;

vector<City> Tour::cities = Tour::generate_cities();

Tour::Tour() {

    vector<City> temp = cities;

    auto rng = default_random_engine{random_device()()};
    shuffle(begin(temp), end(temp), rng);
    tour = temp;

    fitness = determine_fitness();
}

void Tour::shuffle_cities() {

}

double Tour::get_tour_distance() {

    // sum distances between cities in tour
    double distance = 0;
    for(unsigned long i = 1; i < CITIES_IN_TOUR; i++) {
        distance += tour.at(i).get_distance_between_cities(tour.at(i - 1));
    }

    // add distance back to original city
    distance += tour.at(0).get_distance_between_cities(tour.at(CITIES_IN_TOUR - 1));

    return distance;
}

double Tour::determine_fitness() {
    double distance = get_tour_distance();
    return (1 / distance) * FITNESS_SCALAR;
}

void Tour::mutate() {

    fitness = determine_fitness();
}

bool Tour::contains_city(City &city) {
    for(City c : tour) {
        if(city == c)
            return true;
    }
    return false;
}

vector<City> Tour::generate_cities() {
    vector<City> temp;
    for(int i = 0; i < CITIES_IN_TOUR; i++) {
        temp.emplace_back(City{});
    }
    return temp;
}

bool Tour::operator<(Tour &other) {
    return this->fitness < other.fitness;
}
