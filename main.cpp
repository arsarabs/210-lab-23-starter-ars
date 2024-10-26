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

    // read & populate arrays for names and colors
  
    

    int i = 0;
    while (fin >> names[i++]);
    fin.close();

    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    return 0;
}



