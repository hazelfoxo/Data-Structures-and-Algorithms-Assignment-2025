#pragma once

#include "Prototype.h"
#include <string>
#include <iostream>

class Simulator
{
	std::vector<std::list<std::string>> simulationLog;
public:
	// This makes the game prototype play against itself using the file and first character specified.
	std::list<std::string> run(std::string file, char start, int seed) {
		Prototype game(file);
		game.seed(seed);
		std::list<std::string> currentSimulation;
		while (true) {
			std::string cityName = game.getCity(start);
			if (!cityName.empty()) {
				game.markUsed(cityName);
				start = (char) cityName.back();
				currentSimulation.push_back(cityName);
			}
			else {
				break;
			}
		}

		simulationLog.push_back(currentSimulation);
		return currentSimulation;
	}

	// runs k simulations of game and return a double counting the time to run the batch in seconds. 
	// Results should be stored internally in a vector list of strings
	double batch(std::string file, int k, int seed) {
		Prototype game(file);
		game.seed(seed);
		std::list<std::string> currentSimulation;


		simulationLog.push_back(currentSimulation);
		return 0; // Placeholder return statement
	}

	//This returns a vector with all simulation results executed so far. Each simulation should be reprensented as a list of strings.
	std::vector<std::list<std::string>> getResults() {
		return simulationLog;
	}
};

