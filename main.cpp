#include <iostream>
#include "Location.cpp"

using namespace std;


// Variables
int stamina = 20;
Location *visited[] = {};


// Functions
Location *locationChoice(Location *first, Location *second);
int goCamping(Location *where);


// Declaration
int
main()
{

    Location *place1 = new Location("Entrance", "the entrance", 10);
    Location *place2 = new Location("Hall", "the hall", 20);
    Location *place3 = new Location("Kitchen", "the kitchen", 30);

    visited[0] = place1;

    cout << "Stamina : " << stamina << endl;

    Location *result = locationChoice(place2, place3);

    cout << "Stamina : " << stamina << endl;

    if (result == 0)
        return 1;
    else
        return 0;
}

Location
*locationChoice(Location *first, Location *second)
{
    string choice;
    bool canCamping = false;
    int restValue = 0;
    Location *selected;

    cout << "Choisissez un chemin: \"" << first->getName() <<  "\" ou \"" << second->getName() << "\" :" << endl;
    cin >> choice;

    if (choice == first->getName())
        selected = first;
    else if (choice == second->getName())
        selected = second;
    else return 0;

    if (!selected->getCamping() && (stamina - first->getDifficulty() <= 0))
        canCamping = true;

    if (canCamping)
    {
        char camp;
        cout << "Would you like to camp in " << selected->getName() << " : y/n" << endl;
        cin >> camp;

        switch (camp)
        {
            case 'y':
                restValue = goCamping(selected);
                break;
            case 'n':
                cout << "ok then" << endl;
                break;
            default:
                return 0;
        }
    }

    stamina -= selected->getDifficulty() - restValue;
    visited[1] = selected;
    return selected;
}

int
goCamping(Location *where)
{
    cout << "You camped in " << where->getName() << ", you feel rested." << endl;
    return where->getDifficulty() / 2;
}
