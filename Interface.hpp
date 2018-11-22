//
// Created by Greg on 2018-11-22.
//

#ifndef GENETICALGORITHM_INTERFACE_HPP
#define GENETICALGORITHM_INTERFACE_HPP


#include "Population.hpp"

/**
 * A user interface. Allows user to run algorithm and edit algorithm criteria.
 * Does not handle errors/validate input.
 */
class Interface {
public:
    /**
     * Constructs an interface.
     */
    Interface();

    /**
     * Destroys an interface.
     */
    ~Interface() = default;

    /**
     * Renders a menu for the user to run or edit genetic algorithm.
     */
    void menu();

    /**
     * Allows user to edit city settings.
     */
    void city_menu();

    /**
     * Allows user to edit tour settings.
     */
    void tour_menu();

    /**
     * Allows user to edit population settings.
     */
    void pop_menu();
};


#endif //GENETICALGORITHM_INTERFACE_HPP
