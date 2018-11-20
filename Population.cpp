//
// Created by Greg on 2018-11-12.
//

#include "Population.hpp"

Population::Population() {
    for(int i = 0; i < POPULATION_SIZE; i++) {
        population.emplace_back(Tour{});
    }
}

void Population::start() {

    unsigned long i = 0;
    while(best_distance / base_distance < improvement_factor || i < ITERATIONS) {
        sga();
        report();
        i++;
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
        population.insert(population.begin() + i, elite);
        population.insert(population.begin() + elite_index, temp);
    }
}

void Population::sga() {

    select_elites();

    crossover();
}

vector<Tour> Population::select_parents() {

    for(unsigned long i = NUMBER_OF_ELITES; i < POPULATION_SIZE; i++) {
        population.at(i).mutate();
    }

}

Tour Population::crossover() {

    select_parents();

}

void Population::report() {

}
