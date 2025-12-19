#pragma once

#include "Prototype.h"
#include <string>
#include <chrono>
#include <vector>

class Simulator
{
	std::vector<std::list<std::string>> simulationLog;

public:
	// This makes the game prototype play against itself using the file and first character specified.
	std::list<std::string> run(const std::string& file, char start, int seed) {
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
	double batch(const std::string& file, int k, int seed) {
		const int alphabetLength = 26;
		Prototype game(file);
		game.seed(seed);

		std::chrono::steady_clock::time_point t = std::chrono::steady_clock::now();

		for (int i = 0; i < k; i++) {
			char startingChar = static_cast<char>('a' + game.nextInt(0, alphabetLength - 1));
			run(file, startingChar, seed + i);
		}

		std::chrono::steady_clock::duration elapsed = std::chrono::steady_clock::now() - t;

		return static_cast<double> (std::chrono::duration_cast<std::chrono::nanoseconds > (elapsed).count());

	}

	//This returns a vector with all simulation results executed so far. Each simulation should be reprensented as a list of strings.
	std::vector<std::list<std::string>> getResults() {
		return simulationLog;
	}
};

