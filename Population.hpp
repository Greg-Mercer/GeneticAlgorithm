//
// Created by Greg on 2018-11-12.
//

#ifndef GENETICALGORITHM_POPULATION_HPP
#define GENETICALGORITHM_POPULATION_HPP

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

public:
    static double IMPROVEMENT_FACTOR; // the rate of improvement we want the algorithm to achieve
    static unsigned long POPULATION_SIZE; // size of this population
    static unsigned long ITERATIONS; // number of iterations for the genetic algorithm
    static unsigned long NUMBER_OF_ELITES; // number of elites for the genetic algorithm
    static unsigned long NUMBER_OF_PARENTS; // number of parents to use for crossover
    static unsigned long PARENT_POOL_SIZE; // the size of the pool of parents

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
