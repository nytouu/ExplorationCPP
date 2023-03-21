#ifndef LOCATION_CPP
#define LOCATION_CPP

#include "Location.h"
#include <string>

Location::Location(std::string newName, std::string newDescription, int newDifficulty)
{
	name = newName;
	description = newDescription;
	difficulty = newDifficulty;
}

void
Location::setDescription(std::string newDescription)
{
	description = newDescription;
}

void
Location::setDifficulty(int newDifficulty)
{
	if (newDifficulty < 1)
		newDifficulty = 1;
	if (newDifficulty > 19)
		newDifficulty = 19;
	difficulty = newDifficulty;
}

void
Location::setRestingLocation(bool newValue)
{
	restLocation = newValue;
}

std::string
Location::getName()
{
	return name;
}

int
Location::getDifficulty()
{
	return difficulty;
}

bool
Location::getCamping()
{
	return camping;
}

bool
Location::isRestLocation()
{
	return restLocation;
}

#endif
