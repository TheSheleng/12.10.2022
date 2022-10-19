#pragma once

#include <fstream>

using namespace std;

namespace bs
{
	class
	{
		const char* file_path = "base.info";

		unsigned int people;
		unsigned int vehicles;
		double petrol;
		double goods;

	public:
		void save() 
		{
			fstream file(file_path, ios::out | ios::trunc | ios::binary);
			
			if (file.is_open())
			{
				file.write((char*)&people, sizeof(people));
				file.write((char*)&vehicles, sizeof(vehicles));
				file.write((char*)&petrol, sizeof(petrol));
				file.write((char*)&goods, sizeof(goods));
				file.close();
			}
		}

		void load() 
		{
			fstream file(file_path, ios::in | ios::binary);

			if (file.is_open())
			{
				file.read((char*)&people, sizeof(people));
				file.read((char*)&vehicles, sizeof(vehicles));
				file.read((char*)&petrol, sizeof(petrol));
				file.read((char*)&goods, sizeof(goods));
				file.close();
			}
		}
	} Base;
}