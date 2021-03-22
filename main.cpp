/*
    Program: Selects random restuarant to eat
    Options: (b)reakast, (f)astfood, (s)it-down, (n)ice, (d)rinks, (h)elp, default prints all randoms
    Date: 3/21/2021
    By: Ernest Duckworth IV
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

//struct for the arguments
struct Args{
    bool all = true, brek = false, fast = false, sit = false, nice = false, drinks = false, print = false, fries = false;
};

//struct for color arguements
struct Colors{
    string green = "\033[1;32m", red = "\033[0;31m", bred = "\033[1;31m",  pink = "\033[0;35m", upink = "\033[4;35m", yellow = "\033[0;33m", none = "\033[0m";
};

//prototypes so main is at top:)
bool getOptions(int &, char *[], Args &);
bool readFile(Args &, vector<vector<string>> &);
void addp(int &, string &, vector<string> &i, Args &);
void printvv(const vector<vector<string>> &);
void printRandos(const vector<vector<string>> &);

//Executes whole program
int main(int argc, char *argv[]) {
    Args options;
    if(!getOptions(argc, argv, options)) return 1; //store vectors, stops if fails
    vector<vector<string>> places;
    if(!readFile(options, places)) return 1; //stores vectors based on option selection
    if(options.print) printvv(places);
    printRandos(places); //prints the random selection
    return 0;
}

//Stores options, fails if there is unreconized option
bool getOptions(int &i, char *a[], Args &options){
    Colors c;
    int opt;
    while((opt = getopt(i, a, "abfsndhpF")) != -1){
        switch(opt){
            case 'b': //brekfast
                options.brek = true;
                options.all = false;
                break;
            case 'f': //fast food
                options.fast = true;
                options.all = false;
                break;
            case 's': //sit down
                options.sit = true;
                options.all = false;
                break;
            case 'n': //nice
                options.nice = true;
                options.all = false;
                break;
            case 'd': //drinks
                options.drinks = true;
                options.all = false;
                break;
            case 'p': //prints all places
                options.print = true;
                break;
            case 'F': //fries
                options.fries = true;
                options.all = false;
                break;
            case 'h': //help
                cout << c.yellow;
                cout << "Options are: \n"
                     << " -b = brekfast\n"
                     << " -f = fast food\n"
                     << " -s = sit down\n"
                     << " -d = drinks\n"
                     << " -a = all(default no input)\n" << c.none;
                return false;
                break;
            case '?': //no matching arguements
                cerr << c.bred;
                cerr << "Options are: \n" << c.red
                     << " -b = brekfast\n"
                     << " -f = fast food\n"
                     << " -s = sit down\n"
                     << " -d = drinks\n"
                     << " -a = all(default no input)\n" << c.none;
                return false;
                break;
        }
    }
    return true;
}

//Opens file and attempts to store every line
bool readFile(Args &options, vector<vector<string>> &ps){
    string file = "restaurants.txt";
    ifstream in(file);
    //returns if there is no file
    if(!in){
        cerr << "Cannot find file restaurants.txt\n";
        return false;
    }
    string place = "";
    vector<string> places;
    //i iterator keeps track of what section we are in(i.e brekfast)
    for(int i = 0; getline(in, place); ){
        //new lines in file start with '~'
        if(place.find('~') != string::npos){
            if(places.size() > 1) ps.push_back(places);
            places.clear();
            i++;
            continue;
        }
        addp(i, place, places, options); //only adds if we are in correct section
    }
    return true;
}

//adds depending on what section and if options says to add
void addp(int &i, string &place, vector<string> &places, Args &options){
    //i represents which bracket we are in i.e brekfast
    switch(i){
        case 0:
            if(options.brek || options.all)
                places.push_back(place);
            break;
        case 1:
            if(options.fast || options.all)
                places.push_back(place);
            break;
        case 2:
            if(options.sit || options.all)
                places.push_back(place);
            break;
        case 3:
            if(options.nice || options.all)
                places.push_back(place);
            break;
        case 4:
            if(options.drinks || options.all)
                places.push_back(place);
            break;
        case 5:
            if(options.fries || options.all)
                places.push_back(place);
            break;
    }
}

//prints all options for each section
void printvv(const vector<vector<string>> &s){
    Colors c;
    for(size_t i = 0; i < s.size(); i++){
        for(size_t j = 0; j < s[i].size(); j++){
            if(j == 0) cout << c.upink;
            else cout << c.pink << j << ". " << c.yellow;
            cout << s[i][j] << c.none << '\n';
        }
        cout << '\n';
    }
}

//prints the random selection
void printRandos(const vector<vector<string>> &v){
    Colors c;
    srand((unsigned int)time(0)); //clean cast :
    for(size_t i = 0; i < v.size(); i++){
        cout << c.pink << "Random " << v[i][0] << '\n'
             << "-> " << c.green << v[i][(rand()%(v[i].size()-1))+1] << c.pink << " <-" << c.none << '\n';
    }
}
