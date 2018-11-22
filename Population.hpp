//
// Created by Greg on 2018-11-12.
//

#ifndef GENETICALGORITHM_POPULATION_HPP
#define GENETICALGORITHM_POPULATION_HPP
#define POPULATION_SIZE 32
#define ITERATIONS 1000
#define NUMBER_OF_ELITES 1
#define NUMBER_OF_PARENTS 2
#define PARENT_POOL_SIZE 5

#include <vector>
#include "Tour.hpp"

/**
 * A collection of tours. Has methods to execute a genetic algorithm to improve tours.
 */
class Population {
private:
    vector<Tour> population; // a population of tours
    double base_distance; // the distance of the first elite tour
    double best_distance; // the distance of the current elite tour
    double improvement_factor; // the rate of improvement we want the algorithm to achieve

public:
    /**
     * Constructs a population with randomly generated tours.
     */
    Population();

    /**
     * Starts the genetic algorithm.
     */
    void start();

    /**
     * Selects elites from this population.
     */
    void select_elites();

    /**
     * Runs a simple genetic algorithm.
     */
    void sga();

    /**
     * Selects fittest parent tours from a pool of tours in the population.
     * @return the fittest tours from randomly selected pools
     */
    vector<Tour> select_parents();

    /**
     * Performs crossover on all non-elite tours in the population.
     */
    void crossover();

    /**
     * Prints information about the algorithm's progress to the screen.
     */
    void report();
};


#endif //GENETICALGORITHM_POPULATION_HPP
