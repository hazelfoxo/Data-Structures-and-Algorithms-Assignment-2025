#pragma once
#include <fstream>
#include <string>
#include <vector>

//#define ASSIGNMENT_2		//Uncomment to switch to feedback mode for assignment 2

/*
*	
*	INSERT TIME COMPLEXITIES HERE:
* 
*	Constructor:		______
*	getCity:			______
*	checkCity:			______
*	markUsed:			______
*	restart:			______
* 
*/

class Prototype {
	//insert data structures here:
	std::vector<std::string> cityNames;
	std::vector<std::string> usedCityNames;
public:
	//insert methods here:

	// Constructor
	// Accepts name of file as string, reads file and populates interal data structures.
	Prototype(std::string fileName) {
		cityNames = readFile(fileName);
	}

	static std::vector<std::string> readFile(std::string &fileName) {
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
	std::string getCity(char letter){
		return "city name";
	}
	
	// Accepts a city as a string and return true if a valid, only unused city is passed.
	bool checkCity(std::string cityName) {
		return false;
	}

	// Accepts a city as a string and marks it as used. checkcity no longer accepts as valid.
	void markUsed(std::string cityName) {
		if (checkCity(cityName)) {
			usedCityNames.push_back(cityName);
		}
	}

	// Restarts the game.
	void restart() {

	}
};

