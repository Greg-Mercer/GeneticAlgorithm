//
// Created by Greg on 2018-11-11.
//

#ifndef GENETICALGORITHM_TOUR_HPP
#define GENETICALGORITHM_TOUR_HPP

#include <vector>
#include "City.hpp"

using namespace std;

class Tour {
private:
    vector<City> cities;
    double fitness;

public:
    Tour();
    Tour(Tour& tour) = default;
    ~Tour() = default;
};


#endif //GENETICALGORITHM_TOUR_HPP
