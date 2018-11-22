//
// Created by Greg on 2018-11-12.
//

#include "Population.hpp"
#include <random>
#include <iostream>

using namespace std;

Population::Population() {
    for(int i = 0; i < POPULATION_SIZE; i++) {
        population.emplace_back(Tour{});
    }
}

void Population::start() {

    select_elites();
    base_distance = best_distance;

    unsigned long i = 0;
    improvement_factor = 1.8;
    double current_improvement = 1;

    while(current_improvement < improvement_factor && i < ITERATIONS) {
        sga();
        report();
        i++;
        current_improvement = base_distance / best_distance;
        cout << i << ", improvement=" << current_improvement << endl;
    }

}

void Population::select_elites() {
    for(unsigned long i = 0; i < NUMBER_OF_ELITES; i++) {
        Tour& elite = population.at(i);
        unsigned long elite_index = i;
        for(unsigned long j = 0; j < POPULATION_SIZE; j++) {
            if(elite < population.at(j)) {
                elite = population.at(j);
                elite_index = j;
            }
        }
        Tour& temp = population.at(i);
        population.at(i) = elite;
        population.at(elite_index) = temp;
    }
    best_distance = population.at(0).get_tour_distance();
}

void Population::sga() {

    crossover();

    for(unsigned long i = NUMBER_OF_ELITES; i < POPULATION_SIZE; i++) {
        population.at(i).mutate();
    }

    select_elites();

}

vector<Tour> Population::select_parents() {

    vector<Tour> parents;

    for(int i = 0; i < NUMBER_OF_PARENTS; i++) {
        vector<Tour> pool;

        // add random tours to pool. not necessarily distinct.
        for(int j = 0; j < PARENT_POOL_SIZE; j++) {
            default_random_engine re;
            re.seed(random_device()());
            uniform_int_distribution<unsigned long> dist(NUMBER_OF_ELITES, POPULATION_SIZE - 1);
            pool.emplace_back(population.at(dist(re)));
        }

        // extract fittest tours from pool and add to parent list
        Tour& fittest = pool.at(0);
        for(Tour t : pool) {
            if(fittest < t) {
                fittest = t;
            }
        }
        parents.emplace_back(fittest);
    }
    return parents;
}

void Population::crossover() {

    for(unsigned long i = NUMBER_OF_ELITES; i < POPULATION_SIZE; i++) {
        vector<Tour> parents = select_parents();
        population.at(i).crossover(parents);
    }

}

void Population::report() {

    cout << "Best distance so far: " << best_distance << endl;

}
