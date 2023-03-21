#include <iostream>
#include "Location.cpp"

using namespace std;


// Variables
int stamina = 25;
Location *visited[] = {};


// Functions
Location *locationChoice(Location *first, Location *second);
int goCamping(Location *where);
void restStamina();


// Declaration
int
main()
{
    Location *place1 = new Location("Entrance", "the entrance", 10);
    Location *place2 = new Location("Hall", "the hall", 20);
    Location *place3 = new Location("Kitchen", "the kitchen", 30);

    visited[0] = place1;
    place2->setRestingLocation(true);

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

    cout << "Where ?: \"" << first->getName() <<  "\" or \"" << second->getName() << "\" :" << endl;
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

        cout << "Would you like to camp in the " << selected->getName() << " : y/n" << endl;
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

    if (selected->isRestLocation())
    {
        char rest;

        cout << "Would you like to rest in the " << selected->getName() << "?" << endl;
        cin >> rest;

        switch (rest)
        {
            case 'y':
                restStamina();
            case 'n':
                cout << "okay okay" << endl;
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
    cout << "You camped in the " << where->getName() << ", you feel rested." << endl;
    return where->getDifficulty() / 2;
}

void
restStamina()
{
    stamina += 50;

    if (stamina > 100)
        stamina = 100;

    cout << "+50 Stamina, now at : " << stamina << endl;
}
