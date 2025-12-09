#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#define ASSIGNMENT_2		//Uncomment to switch to feedback mode for assignment 2

/*
*
*	INSERT TIME COMPLEXITIES HERE:
*
*	Constructor:		O(n)
*	getCity:			O(n)
*	checkCity:			O(log n), O(n)
*	markUsed:			O(n)
*	restart:wel			O(n)
*
*/

class Prototype {
	//insert data structures here:
	std::vector<std::string> cityNames;
	std::unordered_set<std::string> usedCityNames;
public:
	//insert methods here:

	// Constructor
	// Accepts name of file as string, reads file and populates internal data structures.

	// Sorts vector so we can use binary search later
	Prototype(std::string fileName) {
		cityNames = readFile(fileName);
		std::sort(cityNames.begin(), cityNames.end());
	}

	static std::vector<std::string> readFile(std::string& fileName) {
		std::ifstream ifs(fileName);
		std::string line;
		std::vector<std::string> lines;
		while (getline(ifs, line)) {
			lines.push_back(line);
		}
		return lines;
	}

	// Accpets a character and returns a city begining with that character.
	// Doesn't return used cities
	// 
	// Linear search on vector
	std::string getCity(char letter) {
		for (std::string& city : cityNames) {
			if (!city.empty() && city[0] == letter && checkCity(city))
			{
				return city;
			}
		}
		return "";
	}

	// Accepts a city as a string and return true if a valid, unused city is passed
	// 
	// Binary search on sorted vector and hash lookup on unordered

	bool checkCity(std::string cityName) {
		if (std::binary_search(cityNames.begin(), cityNames.end(), cityName)) {
			return !usedCityNames.contains(cityName);
		}
		return false;
	}

	// Accepts a city as a string and marks it as used. checkcity no longer accepts as valid.
	//
	// Same complexity as checkCity
	void markUsed(std::string cityName) {
		if (checkCity(cityName)) {
			usedCityNames.insert(cityName);
		}
	}

	// Restarts the game.
	void restart() {
		usedCityNames.clear();
	}

};