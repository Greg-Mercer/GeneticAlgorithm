//
// Created by Greg on 2018-11-11.
//

#ifndef GENETICALGORITHM_CITY_HPP
#define GENETICALGORITHM_CITY_HPP

#include <string>

using namespace std;

/**
 * A city. Has a unique Id and randomly generated coordinates.
 */
class City {
private:
    unsigned long id; // the unique Id of this city
    double x; // the x coordinate of this city
    double y; // the y coordinate of this city

public:
    static double MAP_BOUNDARY; // the coordinate limit within which cities can generate
    /**
     * Counter for city Id.
     */
    static unsigned long count;

    /**
     * Generates a city with random x and y coordinates in a given boundary.
     */
    City();

    /**
     * Generates a placeholder city with sample values.
     * @param value the value to map to all instance variables
     */
    City(unsigned long value) : id(value), x(value), y(value) {};

    /**
     * Default copy constructor for city.
     * @param other the city to copy
     */
    City(const City& other) = default;

    /**
     * Default destructor for city.
     */
    ~City() = default;

    /**
     * Gets the distance as the crow flies between this city and another.
     * @param other the other city
     * @return the distance between this and the other city
     */
    double get_distance_between_cities(City& other);

    /**
     * Checks if this city and another have identical Ids.
     * @param other the city to compare to
     * @return true if this city and the other have identical Ids
     */
    bool operator == (City& other);

    /**
     * Returns the Id of this city.
     * @return this city's Id
     */
    unsigned long getId() const;
};


#endif //GENETICALGORITHM_CITY_HPP
