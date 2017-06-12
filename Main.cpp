//I affirm that all code given below was written solely by me, JD Jamieson, and that any help I
//received adhered to the rules stated for this exam.
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;
namespace Exam1 // NAMESPACE
{
	class Wheel
	{
	private:
		int _radius;
	public:
		Wheel(int radius) { _radius = radius; }
	};
	// STEP 1: Complete the implementation of the Vehicle base class
	// as described in the UML diagram
	class Vehicle
	{
	protected:
		string _color;
		int _topspeed;
		vector<Wheel> wheels;
	public:
		Vehicle(string color) {
			_color = color;
		}
		virtual void Description() = 0;
	};
	// STEP 2: Define the RaceCar, Sedan, and Pickup classes as described
	// in the UML diagram. For this test, you do not need to separate
	// the class implementation into a cpp file.
	class RaceCar : public Vehicle {
	public:
		RaceCar(string _color) :Vehicle(_color) 
		{
			_topspeed = 250; //Top speed: 250mph
			Wheel carwheels(305); //Wheel radius: 305mm
			for (int i = 0; i < 4; i++)
				wheels.push_back(carwheels); //Race cars have 4 wheels
		}
		void Description()
		{
			cout << "I am a " << _color << " race car and I can go " << _topspeed << " mph." << endl;
		}
		
		
	};
	class Sedan : public Vehicle {
	private:
		int number_of_seats;
	public:
		Sedan(string _color, int seats) :Vehicle(_color)
		{
			_topspeed = 95;//Top speed: 95mph
			number_of_seats = seats;
			Wheel carWheels(381);//Wheel radius: 381mm
			for (int i = 0; i < 4; i++)
				wheels.push_back(carWheels); //Sedans have 4 wheels
		}
		void Description()
		{
			cout << "I am a " << _color << " sedan that can carry " << number_of_seats <<
				" people at " << _topspeed << " mph." << endl;
		}
		
	};
	class Pickup : public Vehicle {
	private:
		int hauling_capacity;
	public:
		Pickup(string _color, int capacity) :Vehicle(_color)
		{
			_topspeed = 85;//Top speed: 85mph
			hauling_capacity = capacity;
			Wheel truckWheels(432);//Wheel radius: 432mm
			for (int i = 0; i < 4; i++)
				wheels.push_back(truckWheels); //Pickups have 4 wheels
		}
		void Description()
		{
			cout << "I am a " << _color << " pickup truck that can haul " << hauling_capacity <<
				" sq. feet at " << _topspeed << " mph." << endl;
		}
	};
}

int main()
{
	Exam1::Vehicle * Garage[3];
	// STEP 3: Assign ONE RaceCar, ONE Sedan, AND ONE Pickup object to each of the elements
	// in the Garage array. Remember the classes are defined in the namespace Exam1.
	Garage[0] = new Exam1::RaceCar("cherry red");
	Garage[1] = new Exam1::Sedan("silver",5);
	Garage[2] = new Exam1::Pickup("navy blue", 600);
	for (int i = 0; i < 3; ++i)
	{
		// The method Description() should display an output like
		// "I am a red sedan (or racecar/pickup) and I can go 95 (or 250 or 85) mph"
		Garage[i]->Description();
	}

	return 0;
}
