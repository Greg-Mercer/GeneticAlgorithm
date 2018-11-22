#include <utility>

//
// Created by Greg on 2018-11-11.
//

#ifndef GENETICALGORITHM_TOUR_HPP
#define GENETICALGORITHM_TOUR_HPP
#define CITIES_IN_TOUR 32
#define FITNESS_SCALAR 100000
#define MUTATION_RATE 0.15
#define PLACEHOLDER_CITY -1

#include <vector>
#include "City.hpp"

using namespace std;

/**
 * A tour as an ordered list of cities. Has methods to evaluate and manipulate tours as part of a genetic
 * algorithm.
 */
class Tour {
private:
    vector<City> tour; // a tour of cities as an ordered list
    double fitness; // the fitness of this tour

public:
    /**
     * The cities for all tours.
     */
    static vector<City> cities;

    /**
     * Statically generates the cities for all tours.
     * @return the cities for all tours
     */
    static vector<City> generate_cities();

    /**
     * Constructs a Tour with a randomized tour path.
     */
    Tour();

    /**
     * Constructs a Tour with a given tour path.
     * @param start the tour to set
     */
    Tour(vector<City> start) : tour(std::move(start)) {};

    /**
     * Standard copy constructor for Tour.
     * @param other the Tour to copy
     */
    Tour(const Tour& other) = default;

    /**
     * Standard destructor for Tour.
     */
    ~Tour() = default;

    /**
     * Calculates and returns the total distance of this tour.
     * @return this tour's distance
     */
    double get_tour_distance();

    /**
     * Calculates and returns the fitness of this tour.
     * @return this tour's fitness
     */
    double determine_fitness();

    /**
     * Randomly mutates a selection of cities in the tour by
     * swapping their positions.
     */
    void mutate();

    /**
     * Checks if this tour contains a given city
     * @param city the city to check
     * @return true if this tour contains the city
     */
    bool contains_city(City& city);

    /**
     * Compares the fitness of this tour with another.
     * @param other the tour to compare with
     * @return true if this tour has a worse fitness than the other
     */
    bool operator < (Tour& other);

    /**
     * Performs crossover on this tour's cities with a set of parents.
     * @param parents the parents to crossover
     */
    void crossover (vector<Tour> parents);
};


#endif //GENETICALGORITHM_TOUR_HPP
