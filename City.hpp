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
    unsigned long id;
    double x;
    double y;

public:
    static unsigned long count;
    City();
    City(int marker) : id(-1), x(-1), y(-1) {};
    City(const City& other) = default;
    ~City() = default;
    double get_distance_between_cities(City& other);
    bool operator == (City& other);
    unsigned long getId() const;
};


#endif //GENETICALGORITHM_CITY_HPP
