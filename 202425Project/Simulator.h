#pragma once

#include "Prototype.h"
#include <string>

class Simulator
{
	std::vector<std::list<std::string>> simulationLog;
public:
	// This makes the game prototype play against itself using the file and first character specified.
	std::list<std::string> run(std::string file, char start, int seed) {
		Prototype game(file);
		game.seed(seed);
		std::list<std::string> cityNameLog;
		while (true) {
			std::string city = game.getCity(start);
			if (city.empty()) break;        
			game.markUsed(city);             
			cityNameLog.push_back(city); 
		}
		return cityNameLog;
	}

	// runs k simulations of game and return a double coutning the time to run the batch in seconds. 
	// Results should be stored internally in a vector list of strings
	double batch(std::string file, int k, int seed) {
		Prototype game(file);
		game.seed(seed);
		return 0; // Placeholder return statement
	}

	//This returns a vector with all simulation results executed so far. Each simulation should be reprensented as a list of strings.
	std::vector<std::list<std::string>> getResults() {
		return simulationLog;
	}
};

