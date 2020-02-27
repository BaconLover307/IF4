// Vehicle.hpp

#ifndef __VEHICLE__HPP__
#define __VEHICLE__HPP__

#include <iostream>

class Vehicle {
  protected:
    float fuel;  // bensin kendaraan

  public:
	Vehicle();
	void addFuel(float fuel);
	virtual void drive();
	virtual int getNumOfWheels() = 0;
};

class MotorCycle : public Vehicle {
  public:
  	MotorCycle();
  	void drive();
}

class Car : public Vehicle {
  public:
  	Car();
  	void openDoor();
  	void drive();
}

#endif
