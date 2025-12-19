#pragma once
#include "Prototype.h"

#define Competition_class Competition			//change to Competition once you've implemented your Competition class, defaults to Prototype

class Competition : public Prototype
{
	std::string getCity(char letter) {
		std::vector<std::string> cityNamesSubset;

		for (std::string& city : cityNames) {
			if (!city.empty() && city[0] == letter && checkCity(city))
			{
				cityNamesSubset.push_back(city);
			}
			if (city[0] > letter) break;
		}

		// Pick city starting with that letter
		if (!cityNamesSubset.empty()) {
			int index = nextInt(0, static_cast<int>(cityNamesSubset.size()) - 1);
			return cityNamesSubset[index];
		}
		return "";
	}
};

