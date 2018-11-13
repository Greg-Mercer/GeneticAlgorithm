//
// Created by Greg on 2018-11-11.
//

#ifndef GENETICALGORITHM_TOUR_HPP
#define GENETICALGORITHM_TOUR_HPP
#define CITIES_IN_TOUR 32

#include <vector>
#include "City.hpp"

using namespace std;

class Tour {
private:
    vector<City> cities;
    double fitness;

public:
    Tour();
    Tour(Tour& other) = default;
    ~Tour() = default;
    void shuffle_cities();
    double get_tour_distance();
    double determine_fitness();
    void mutate();
    bool contains_city(City& city);
};


#endif //GENETICALGORITHM_TOUR_HPP
