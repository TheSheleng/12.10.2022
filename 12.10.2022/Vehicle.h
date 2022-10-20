#pragma once

namespace vhcl
{
	class Vehicle
	{
	protected:
		const int TANK_VOLUME;
		int petrol_amoute;

	public:
		Vehicle(double petrol_amoute, double TANK_VOLUME);
		double getTankVolume();
		double getPetrolAmoute();
		virtual void arrive(unsigned int& _people, double& _petrol, double& _goods);
		virtual bool leave(unsigned int& _people, double& _petrol, double& _goods);
	};

	class Bus : public Vehicle
	{
	protected:
		const int MAX_PEOPLE;
		int peole_count;

	public:
		Bus(int peole_count, int MAX_PEOPLE, double petrol_amoute, double TANK_VOLUME);
		int getPeopleCount();
		int getMaxPeople();
		void arrive(unsigned int& _people, double& _petrol, double& _goods) override;
		bool leave(unsigned int& _people, double& _petrol, double& _goods) override;
	};

	class Truck : public Vehicle
	{
	protected:
		const double MAX_LOAD;
		double load_count;

	public:
		Truck(double load_count, double MAX_LOAD, double petrol_amoute, double TANK_VOLUME);
		double getLoadCount();
		double getMaxLoad();
		void arrive(unsigned int& _people, double& _petrol, double& _goods) override;
		bool leave(unsigned int& _people, double& _petrol, double& _goods) override;
	};
}

