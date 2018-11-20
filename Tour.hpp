//
// Created by Greg on 2018-11-11.
//

#ifndef GENETICALGORITHM_TOUR_HPP
#define GENETICALGORITHM_TOUR_HPP
#define CITIES_IN_TOUR 32
#define FITNESS_SCALAR 10

#include <vector>
#include "City.hpp"

using namespace std;

class Tour {
private:
    vector<City> tour;
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
    static vector<City> cities;
    static void generate_cities();
    bool operator < (Tour& other);
};


#endif //GENETICALGORITHM_TOUR_HPP
