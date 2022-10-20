#include <iostream>
#include "Vehicle.h"
#include "Base.h"
#include "MenuByList.h"
#include "UserInput.h"

using namespace std;

int main()
{
	MenuByList main_m("Please select an event: ", 
		{
			"The car has arrived", 
			"The car has left",
			"Print info"
		});
	enum
	{
		ARRIVE,
		LEAVE,
		PRINT
	};

	MenuByList car_m("Choose a car: ",
		{
			"Vehicle",
			"Truck",
			"Bus",
		});
	enum
	{
		VEHICLE,
		TRUCK,
		BUS
	};

	vhcl::Vehicle* car = nullptr;
	while (true)
		switch (main_m.getChoice())
		{
		case ARRIVE:
			switch (car_m.getChoice())
			{
			case VEHICLE: 
				car = new vhcl::Vehicle(
					UserInput<double>("Enter petrol amoute: "), 
					UserInput<double>("Enter tank volume: ")
				); 
				break;

			case TRUCK: 
				car = new vhcl::Truck(
					UserInput<double>("Enter load count: "), 
					UserInput<double>("Enter max load: "), 
					UserInput<double>("Enter petrol amoute: "),
					UserInput<double>("Enter tank volume: ")
				); 
				break;

			case BUS: 
				car = new vhcl::Bus(
					UserInput<int>("Enter peole count: "), 
					UserInput<int>("Enter max people: "), 
					UserInput<double>("Enter petrol amoute: "),
					UserInput<double>("Enter tank volume: ")
				);
			
				break;
			}
			bs::Base.arrive(car);
			break;

		case LEAVE:
			int index;
			do index = UserInput<int>("Enter car index: ");
			while (index >= 0 && index < bs::Base.vehicles.size());
			delete bs::Base.leave(index);
			break;

		case PRINT: 
			cout << "Information about the base : " << endl;
			cout << "People: " << bs::Base.people << endl;
			cout << "Vehicles: " << bs::Base.vehicles.size() << endl;
			cout << "Petrol: " << bs::Base.petrol << endl;
			cout << "Goods: " << bs::Base.goods << endl;
			MenuByList::enterPause();
			break;
		}
}