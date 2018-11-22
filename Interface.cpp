//
// Created by Greg on 2018-11-22.
//

#include "Interface.hpp"
#include <iostream>
#include <limits>

using namespace std;

Interface::Interface() {
    menu();
}

void Interface::menu() {

    cout << "C++ assignment 2: Genetic algorithm for travelling salesman problem" << endl;
    bool finished = false;
    while(!finished) {
        cout << endl;
        cout << "1 - Start genetic algorithm" << endl;
        cout << "2 - City settings" << endl;
        cout << "3 - Tour settings" << endl;
        cout << "4 - Population settings" << endl;
        cout << "5 - Exit" << endl;

        int input;
        cin >> input;

        switch(input) {
            case 1: {
                Population pop;
                pop.start();
                finished = true;
                break;
            }
            case 2:
                city_menu();
                break;
            case 3:
                tour_menu();
                break;
            case 4:
                pop_menu();
                break;
            case 5:
                finished = true;
                break;
            default:
                cout << "Invalid input. Please try again." << endl;
                break;
        }
    }

}

void Interface::city_menu() {
    cout << "Enter a value for city map boundary (default = 1000)" << endl;
    double boundary;
    cin >> boundary;
    City::MAP_BOUNDARY = boundary;
    cout << "Map boundary set to " << boundary << "." << endl << endl;
}

void Interface::tour_menu() {
    cout << "Enter the number of cities in a tour (default = 32)" << endl;
    unsigned long cit;
    cin >> cit;
    Tour::CITIES_IN_TOUR = cit;
    cout << "Cities in tour set to " << cit << "." << endl << endl;

    cout << "Enter the mutation rate (default = 0.15)" << endl;
    double mr;
    cin >> mr;
    Tour::MUTATION_RATE = mr;
    cout << "Mutation rate set to " << mr << "." << endl << endl;
}

void Interface::pop_menu() {
    cout << "Enter the desired improvement factor (default = 1.75)" << endl;
    double imp;
    cin >> imp;
    Population::IMPROVEMENT_FACTOR = imp;
    cout << "Desired improvement factor set to " << imp << "." << endl << endl;

    cout << "Enter the population size (default = 32)" << endl;
    unsigned long ps;
    cin >> ps;
    Population::POPULATION_SIZE = ps;
    cout << "Population size set to " << ps << "." << endl << endl;

    cout << "Enter the number of iterations (default = 1000)" << endl;
    unsigned long i;
    cin >> i;
    Population::ITERATIONS = i;
    cout << "Iterations set to " << i << "." << endl << endl;

    cout << "Enter the number of elites (default = 1)" << endl;
    unsigned long e;
    cin >> e;
    Population::NUMBER_OF_ELITES = e;
    cout << "Number of elites set to " << e << "." << endl << endl;

    cout << "Enter the number of parents (default = 2)" << endl;
    unsigned long np;
    cin >> np;
    Population::NUMBER_OF_PARENTS = np;
    cout << "Number of parents set to " << np << "." << endl << endl;

    cout << "Enter the parent pool size (default = 5)" << endl;
    unsigned long pps;
    cin >> pps;
    Population::PARENT_POOL_SIZE = pps;
    cout << "Parent pool size set to " << pps << "." << endl << endl;
}