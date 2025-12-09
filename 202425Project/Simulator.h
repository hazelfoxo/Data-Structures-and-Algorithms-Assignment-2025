#pragma once

#include "Prototype.h"
#include <string>

class Simulator
{
public:
	// This makes the game prototype play against itself using the file and first character specified.
	std::list<std::string> run(std::string file, char start, int seed) {
		std::list < std::string> results;
		return results;
	}

	// runs k simulations of game and return a double coutning the time to run the batch in seconds. 
	// Results should be stored internally in a vector list of strings
	double batch(std::string file, int k, int seed) {
		return 0;
	}

	//This returns a vector with all simulation results executed so far. Each simulation should be reprensented as a list of strings.
	std::vector<std::list<std::string>> getResults() {
		std::vector<std::list<std::string>> results;
		return results;
	}
};

