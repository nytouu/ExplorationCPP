#include <iostream>
#include <fstream>
#include "Location.cpp"

using namespace std;


// Variables
int turn = 0;
int stamina = 25;
Location *visited[] = {};


// Functions
Location *locationChoice(Location *first, Location *second);
int goCamping(Location *where);
void restStamina();
void saveData(string filename);


// Declaration
int
main()
{
    Location *place1 = new Location("Entrance", "the entrance", 10);
    Location *place2 = new Location("Hall", "the hall", 20);
    Location *place3 = new Location("Kitchen", "the kitchen", 30);

    visited[turn] = place1;
    turn++;

    place2->setRestingLocation(true);

    cout << "Stamina : " << stamina << endl;

    Location *result = locationChoice(place2, place3);

    cout << "Stamina : " << stamina << endl;

    if (result == 0)
        return 1;
    else
    {
        saveData("save_file.txt");
        return 0;
    }
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
                break;
            case 'n':
                cout << "okay okay" << endl;
                break;
            default:
                return 0;
        }

    }

    if (!selected->isRestLocation())
        stamina -= selected->getDifficulty() - restValue;

    visited[turn] = selected;

    turn++;
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

void
saveData(string filename)
{
    ofstream saveFile(filename);

    int visitLength = sizeof(*visited) / sizeof(visited[0]);
    cout << visitLength << endl;

    saveFile << ":begin:\n";
    for (int i=0; i <= visitLength; i++)
    {
        saveFile << visited[i]->getName() << endl;
    }
    saveFile << ":end:\0" << endl;

    saveFile.close();

}
