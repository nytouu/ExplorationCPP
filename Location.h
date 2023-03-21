#ifndef LOCATION_H
#define LOCATION_H

#include <string>

class Location {
	protected:
		std::string name;
		std::string description;
		int difficulty;
		bool camping = false;
	public:
		Location(std::string newName, std::string newDescription, int newDifficulty);
		void setDescription(std::string newDescription);
		void setDifficulty(int newDifficulty);
		void addLocation(Location *newLocation);

		std::string getName();
		int getDifficulty();
		bool getCamping();
};

#endif
