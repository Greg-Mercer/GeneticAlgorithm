//
// Created by Greg on 2018-11-11.
//

#ifndef GENETICALGORITHM_CITY_HPP
#define GENETICALGORITHM_CITY_HPP
#define MAP_BOUNDARY 1000

#include <string>

using namespace std;

class City {
private:
    string name;
    double x;
    double y;

public:
    static long count;
    City();
    City(City& other) = default;
    ~City() = default;
    double get_distance_between_cities(City& other);
};


#endif //GENETICALGORITHM_CITY_HPP
