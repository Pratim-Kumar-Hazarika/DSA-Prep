#ifndef vehicle_hpp
#define vehicle_hpp

class Vehicle {
    public:
        Vehicle();
      virtual ~Vehicle();

        virtual void createVehicle() = 0;
};
#endif