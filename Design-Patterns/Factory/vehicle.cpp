#include "vehicle.hpp"
#include <iostream>
using namespace std;
Vehicle::Vehicle() {
    cout << "Vehicle base constructor called" << endl;
}

Vehicle::~Vehicle() {
    cout << "Vehicle base destructor called" << endl;
}
