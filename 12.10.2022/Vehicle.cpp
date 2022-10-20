#include "Vehicle.h"

vhcl::Vehicle::Vehicle(double petrol_amoute, double TANK_VOLUME) 
	: TANK_VOLUME(TANK_VOLUME), petrol_amoute(petrol_amoute) {}

double vhcl::Vehicle::getTankVolume()
{
	return TANK_VOLUME;
}

double vhcl::Vehicle::getPetrolAmoute()
{
	return petrol_amoute;
}

void vhcl::Vehicle::arrive(unsigned int& _people, double& _petrol, double& _goods)
{
	_people += 1;
}

bool vhcl::Vehicle::leave(unsigned int& _people, double& _petrol, double& _goods)
{
	if (_petrol >= TANK_VOLUME - petrol_amoute && _people >= 1)
	{
		_people -= 1;
		_petrol -= TANK_VOLUME - petrol_amoute;
		petrol_amoute = TANK_VOLUME;
		return true;
	}
	else return false;
}

vhcl::Bus::Bus(int peole_count, int MAX_PEOPLE, double petrol_amoute, double TANK_VOLUME) 
	: peole_count(peole_count), MAX_PEOPLE(MAX_PEOPLE), Vehicle(petrol_amoute, TANK_VOLUME) {}

int vhcl::Bus::getPeopleCount()
{
	return peole_count;
}

int vhcl::Bus::getMaxPeople()
{
	return MAX_PEOPLE;
}

void vhcl::Bus::arrive(unsigned int& _people, double& _petrol, double& _goods)
{
	_people += peole_count + 1;
	peole_count = 0;
}

bool vhcl::Bus::leave(unsigned int& _people, double& _petrol, double& _goods)
{
	if (_petrol >= TANK_VOLUME - petrol_amoute && _people >= MAX_PEOPLE + 1)
	{
		_people -= MAX_PEOPLE + 1;
		peole_count = MAX_PEOPLE;
		_petrol -= TANK_VOLUME - petrol_amoute;
		petrol_amoute = TANK_VOLUME;
		return true;
	}
	else return false;
}

vhcl::Truck::Truck(double load_count, double MAX_LOAD, double petrol_amoute, double TANK_VOLUME)
	: load_count(load_count), MAX_LOAD(MAX_LOAD), Vehicle(petrol_amoute, TANK_VOLUME) {}

double vhcl::Truck::getLoadCount()
{
	return load_count;
}

double vhcl::Truck::getMaxLoad()
{
	return MAX_LOAD;
}

void vhcl::Truck::arrive(unsigned int& _people, double& _petrol, double& _goods)
{
	_people += 1;
	_goods += load_count;
	load_count = 0;
}

bool vhcl::Truck::leave(unsigned int& _people, double& _petrol, double& _goods)
{
	if (_petrol >= TANK_VOLUME - petrol_amoute && _people >= 1 && _goods >= MAX_LOAD)
	{
		_people -= 1;
		_petrol -= TANK_VOLUME - petrol_amoute;
		petrol_amoute = TANK_VOLUME;
		_goods -= MAX_LOAD;
		load_count = MAX_LOAD;
		return true;
	}
	else return false;
}
