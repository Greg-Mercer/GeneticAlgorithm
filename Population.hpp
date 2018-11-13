//
// Created by Greg on 2018-11-12.
//

#ifndef GENETICALGORITHM_POPULATION_HPP
#define GENETICALGORITHM_POPULATION_HPP
#define POPULATION_SIZE 32


#include <queue>
#include "Tour.hpp"

class Population {
private:
    priority_queue<Tour> population;
    double base_distance;
    double best_distance;
    double improvement_factor;

public:
    vector<Tour> select_parents();
    Tour crossover();
};


#endif //GENETICALGORITHM_POPULATION_HPP
