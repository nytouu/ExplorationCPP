#include <iostream>
#include "Location.cpp"

using namespace std;


// Variables
int stamina = 100;
Location *visited[] = {};


// Functions
Location *locationChoice(Location *first, Location *second);


// Declaration
int
main()
{

    Location *place1 = new Location("Entrance", "the entrance", 10);
    Location *place2 = new Location("Hall", "the hall", 20);
    Location *place3 = new Location("Kitchen", "the kitchen", 30);

    visited[0] = place1;

    Location *result = locationChoice(place2, place3);

    if (result == 0)
        return 1;
    else
        return 0;
}

Location
*locationChoice(Location *first, Location *second)
{
    string choice;

    cout << "Choisissez un chemin: \"" << first->getName() <<  "\" ou \"" << second->getName() << "\" :" << endl;
    cin >> choice;

    if (choice == first->getName())
    {
        stamina -= first->getDifficulty();
        visited[1] = first;
        return first;
    }
    else if (choice == second->getName())
    {
        stamina -= second->getDifficulty();
        visited[1] = second;
        return second;
    }
    else
        return 0;
}
