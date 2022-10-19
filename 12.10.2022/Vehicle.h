#pragma once

namespace vhcl
{
	class Vehicle
	{
		const int tank_volume;
		int petrol_amoute;

	public:
		Vehicle(double petrol_amoute, double tank_volume);
		double getTankVolume();
		double getPetrolAmoute();
		virtual void arrive();
		virtual bool leave();
	};

	class Bus : public Vehicle
	{
		const int max_people;
		int peole_count;

	public:
		Bus(int peole_count, int max_people, double petrol_amoute, double tank_volume);
		int getPeopleCount();
		int getMaxPeople();
	};

	class Truck : public Vehicle
	{
		const double max_load;
		double load_count;

	public:
		Truck(double load_count, int max_load, double petrol_amoute, double tank_volume);
		double getLoadCount();
		double getMaxLoad();
	};
}

