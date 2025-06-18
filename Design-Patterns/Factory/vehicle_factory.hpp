#ifndef vehicle_factory
#define vehicle_factory

#include<iostream>
#include "car.hpp"
#include "bike.hpp"
using namespace std;

class VehicleFactory {
    public:
        static Vehicle* getVehicle(string vehicleType);
};

#endif