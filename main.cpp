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

    if (trip.empty()) { // Check again if the trip is empty
        return -1;
    }
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
    if (trip.empty()) { // Check if the trip has any Goats to delete
        cout << "The trip has no goats to delete." << endl;
        return;
    }

    int choice = select_goat(trip); // Get the user's choice of Goat to delete
    if (choice == -1) { // Check if selection was invalid
        return;
    }
    //iterator to Goat to be deleted & moves iterator to ssaid Goat
    auto it = trip.begin();
    advance(it, choice - 1);
    cout << "Deleting goat: " << it->get_description() << endl;
    trip.erase(it); // Remove the Goat from the trip list
}
void add_goat(list<Goat>& trip, string names[], string colors[]) {
    //the strucutre of this function shouldn't be too bad (SEE BELOW)
    
    //1. Randomly select name from names array & color from the colors array
     string selected_name = names[rand() % SZ_NAMES];
     string selected_color = colors[rand() % SZ_COLORS];


    //2. generate an age of 0-MAX_AGE
     int selected_age = rand() % (MAX_AGE + 1); // using random formula

    //3.  Create a new Goat object with the selected attributes
    Goat new_goat(selected_name, selected_age, selected_color);

    //4. Add the new Goat to the trip list (using push back)
    trip.push_back(new_goat);

    //5. Output (with format)
    cout << fixed << setprecision(0); // Ensure age is displayed without decimal places
    cout << "Goat added: " << new_goat.get_description() << endl;
}
//This function displays all the details 
void display_trip(list<Goat> trip) {
    int index = 1; // Counter for numbering Goats
    set<string> unique_colors; // Set to store unique colors

    if (trip.empty()) { // Check if the trip has any Goats
        cout << "The trip has no goats." << endl;
        return;
    }

    cout << "current trip goats" << endl;
    cout << "#" << "Name " << "Age " << "Color " << endl;

    // Iterate through the trip list and display each Goat's details
    for (const auto& goat : trip) {
        cout << index++ << goat.get_name() << goat.get_age() << goat.get_color() << endl;

        unique_colors.insert(goat.get_color()); // Insert color into the set
    }

    // Display the unique colors present in the trip
    cout << "\nUnique Colors in Trip:" << endl;
    for (const auto& color : unique_colors) {
        cout << "- " << color << endl;
    }
}
int main_menu() {
    int userChoice;
    bool valid = false;

    while (!valid) {
        // menu options
        cout << "*** GOAT MANAGER 3001 ***" << endl;
        cout << "[1] Add a goat" << endl;
        cout << "[2] Delete a goat" << endl;
        cout << "[3] List goats" << endl;
        cout << "[4] Quit" << endl;
        cout << "Choice --> ";

        cin >> choice; 

        // Check for input failure or invalid range
        if (cin.fail() || choice < 1 || choice > 4) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
        else {
            valid = true; // Valid input received
        }
    }

    return choice; // Return the validated choice
    }

}



