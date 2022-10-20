#pragma once

#include <vector>
#include <fstream>
#include "Vehicle.h"

using namespace std;

namespace bs
{
	struct
	{
		const char* file_path = "base.info";

		unsigned int people = 0U;
		vector<vhcl::Vehicle*> vehicles;
		double petrol = 0;
		double goods = 0;

		void arrive(vhcl::Vehicle*& _vehicles)
		{
			_vehicles->arrive(people, petrol, goods);
			vehicles.push_back(_vehicles);
		}

		vhcl::Vehicle* leave(unsigned int _index)
		{
			if (vehicles[_index]->leave(people, petrol, goods))
			{
				vhcl::Vehicle* temp = vehicles[_index];
				vehicles.erase(vehicles.begin() + _index);
				return temp;
			}
			else return nullptr;
		}
	} Base;
}