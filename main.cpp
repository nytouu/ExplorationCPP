#include <iostream>

using namespace std;

string choix_lieu();

int
main()
{
    string result = choix_lieu();

    if (result == "Error")
        return 1;
    else
        return 0;
}

string
choix_lieu()
{
    string choix;

    cout << "Choisissez un chemin: \"Gauche\" ou \"Droite\": " << endl;
    cin >> choix;

    switch (tolower(choix[0]))
    {
        case 'g':
            cout << "Vous avez choisi le passage à gauche !" << endl;
            return "gauche";
        case 'd':
            cout << "Vous avez choisi le passage à droite !" << endl;
            return "droite";
        default:
            cout << "Choix invalide" << endl;
            return "Erreur";
    }

}
