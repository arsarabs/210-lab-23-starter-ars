// COMSC-210 | Lab 23 | Anthony R. Sarabia
// IDE used: Visual Studio

#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;
    
const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();



int main() {

    //Variables all in one place
    srand(time(0));
    bool again = true; // initliaze to something
    string names[SZ_NAMES];
    string colors[SZ_COLORS];
    int i = 0;
    ifstream fin("names.txt");
    ifstream fin1("colors.txt");
    list<Goat> trip; // List to store Goats for the trip

    // read & populate arrays for both names and colors arrays
    if (!fin) {
        cout << "ERROR! Couldn't open file." << endl;
        return 1;
    }
    while (i < SZ_NAMES && fin >> names[i++]); // populating name array
    fin.close();

    i = 0;

    if (!fin1) {
        cout << "ERROR! Couldn't open file." << endl;
        return 1;
    }
    while (i < SZ_COLORS && fin1 >> colors[i++]); // populating color array
    fin1.close();

    //MAIN MENU
    while (again) {
        int userChoice = main_menu();
        switch (choice) {
        case 1:
            //add a goat to trip
            break;
        case 2:
            //delete a goat from the trip
            break;
        case 3:
            //display all goats
            break;
        case 4:
            //Exit program
            break;
        default:
            //Invalid choice
        }
    }
    return 0;
}

int select_goat(list<Goat> trip) {
    dispaly_trip(trip);
    
    
    bool valid = false; // input validiation flag
    int userChoice; // user's choice

    //until valid loop
    while (!valid) {
        cout << "Number of goat to delete: " << endl;
        cin >> userChoice;

        // Check for input failure or invalid range
        if (cin.fail() || userChoice < 1 || userChoice > trip.size()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "enter a number between 1 - " << trip.size() << endl;
        }
        else {
            valid = true; // Valid input received
        }
    }
    

    return userChoice; //return user's choice
}
void delete_goat(list<Goat>& trip) {

}
void add_goat(list<Goat>& trip, string[], string[]) {

}
void display_trip(list<Goat> trip) {

}
int main_menu() {

}



