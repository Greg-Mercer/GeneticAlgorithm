//
// Created by Greg on 2018-11-12.
//

#ifndef GENETICALGORITHM_POPULATION_HPP
#define GENETICALGORITHM_POPULATION_HPP
#define POPULATION_SIZE 32
#define ITERATIONS 1000
#define NUMBER_OF_ELITES 1

#include <vector>
#include "Tour.hpp"


class Population {
private:
    vector<Tour> population;
    double base_distance;
    double best_distance;
    double improvement_factor;

public:
    Population();
    void start();
    void select_elites();
    void sga();
    vector<Tour> select_parents();
    Tour crossover();
    void report();
};


#endif //GENETICALGORITHM_POPULATION_HPP
