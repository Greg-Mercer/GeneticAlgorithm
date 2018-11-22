//
// Created by Greg on 2018-11-11.
//

#include "Tour.hpp"
#include <algorithm>
#include <random>

using namespace std;

vector<City> Tour::cities = Tour::generate_cities();
unsigned long Tour::CITIES_IN_TOUR = 32;
double Tour::MUTATION_RATE = 0.15;

Tour::Tour() {

    vector<City> temp = cities;

    auto rng = default_random_engine{random_device()()};
    shuffle(begin(temp), end(temp), rng);
    tour = temp;

    fitness = determine_fitness();
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

    default_random_engine re;
    re.seed(random_device()());
    uniform_real_distribution<float> dist(0.00, 1.00);

    for(unsigned long i = 0; i < CITIES_IN_TOUR; i++) {
        float mutation_val = dist(re);
        if(mutation_val < MUTATION_RATE) {
            bool swap_with_prev = (dist(re) > 0.50);
            if(swap_with_prev) {
                if(i != 0) {
                    City temp = tour.at(i);
                    tour.at(i) = tour.at(i - 1);
                    tour.at(i - 1) = temp;
                }
            } else {
                if(i != CITIES_IN_TOUR - 1) {
                    City temp = tour.at(i);
                    tour.at(i) = tour.at(i + 1);
                    tour.at(i + 1) = temp;
                }
            }
        }
    }

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
    for(unsigned long i = 0; i < CITIES_IN_TOUR; i++) {
        temp.emplace_back(City{});
    }
    return temp;
}

bool Tour::operator<(Tour &other) {
    return this->fitness < other.fitness;
}

void Tour::crossover(vector<Tour> parents) {
    // creates placeholder cities to populate child (cities with invalid ids)
    vector<City> placeholder(CITIES_IN_TOUR, PLACEHOLDER_CITY);
    Tour child{placeholder};
    unsigned long index = 0;

    // populate child with parent cities up to index
    for(unsigned long i = 1; i < parents.size(); i++) {
        default_random_engine re;
        re.seed(random_device()());
        uniform_int_distribution<unsigned long> dist(index, CITIES_IN_TOUR);
        index = dist(re);

        for(unsigned long j = 0; j < index; j++) {
            City curr = parents.at(i - 1).tour.at(j);
            if(!child.contains_city(curr)) {
                child.tour.at(j) = curr;
            }
        }
    }

    // remove all placeholder cities
    for(unsigned long i = 0; i < CITIES_IN_TOUR; i++) {
        auto flag = (unsigned long) -1;
        if(child.tour.at(i).getId() == flag) {
            vector<City>::const_iterator first = child.tour.begin();
            vector<City>::const_iterator last = child.tour.begin() + i;
            child = vector<City>(first, last);
            break;
        }
    }

    // add remaining cities
    for(unsigned long i = 0; i < CITIES_IN_TOUR; i++) {
        City curr = parents.at(parents.size() - 1).tour.at(i);
        if(!child.contains_city(curr)) {
            child.tour.emplace_back(curr);
        }
    }

    // save fitness evaluation until after mutation
    this->tour = child.tour;
}
