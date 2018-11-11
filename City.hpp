//
// Created by Greg on 2018-11-11.
//

#ifndef GENETICALGORITHM_CITY_HPP
#define GENETICALGORITHM_CITY_HPP

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
    City(City& city) = default;
    ~City() = default;
};


#endif //GENETICALGORITHM_CITY_HPP
