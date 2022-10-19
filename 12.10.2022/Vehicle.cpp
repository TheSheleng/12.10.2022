#include "Vehicle.h"

vhcl::Vehicle::Vehicle(double petrol_amoute, double tank_volume) 
	: tank_volume(tank_volume), petrol_amoute(petrol_amoute) {}

double vhcl::Vehicle::getTankVolume()
{
	return tank_volume;
}

double vhcl::Vehicle::getPetrolAmoute()
{
	return petrol_amoute;
}

void vhcl::Vehicle::arrive()
{

}

bool vhcl::Vehicle::leave()
{
	return false;
}

vhcl::Bus::Bus(int peole_count, int max_people, double petrol_amoute, double tank_volume) 
	: peole_count(peole_count), max_people(max_people), Vehicle(petrol_amoute, tank_volume) {}

int vhcl::Bus::getPeopleCount()
{
	return peole_count;
}

int vhcl::Bus::getMaxPeople()
{
	return max_people;
}

vhcl::Truck::Truck(double load_count, int max_load, double petrol_amoute, double tank_volume)
	: load_count(load_count), max_load(max_load), Vehicle(petrol_amoute, tank_volume) {}

double vhcl::Truck::getLoadCount()
{
	return load_count;
}

double vhcl::Truck::getMaxLoad()
{
	return max_load;
}
