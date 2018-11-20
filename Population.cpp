//
// Created by Greg on 2018-11-12.
//

#include "Population.hpp"


void Population::start() {

    generate_population();

    unsigned long i = 0;
    while(best_distance / base_distance < improvement_factor || i < ITERATIONS) {
        sga();
        report();
        i++;
    }

}

void Population::generate_population() {

}


void Population::select_elites() {

}

void Population::sga() {

    select_elites();

    crossover();
}

vector<Tour> Population::select_parents() {

    for(unsigned long i = 0; i < number_of_elites; i++) {
        population.at(i).mutate();
    }

}

Tour Population::crossover() {

    select_parents();

}

void Population::report() {

}

