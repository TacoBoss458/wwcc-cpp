#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <limits>
#include <cctype>
using namespace std;

// Isaiah Rusch
// This midterm covers project 7. I want this program to simulate a menu style program that
// sorts the menu between a movie adder, a movie searcher, year filter, a statistic display, 
// a watchlist area, and finally an exit prompt. It needs to allow the user to enter as many movies
// as they want. This means that each of the menu prompts needs to be infinite until the user 
// prompts to extt.

struct Movie { // Movie struct
    string title;
    string director;
    int yearReleased;
    int lengthMinutes;
    double ratingOutOf10;
    string genre;
};

void displayMovie(const Movie& movie) { // User defined function to display a movie
    cout << "Title: " << movie.title << endl;
    cout << "Director: " << movie.director << endl;
    cout << "Year Released: " << movie.yearReleased << endl;
    cout << "Duration: " << movie.lengthMinutes << " minutes\n";
    cout << "Rating: " << movie.ratingOutOf10 << "/10\n";
    cout << "Genre: " << movie.genre << "\n\n";
}

Movie createMovie() { // User defined function to create a movie
    Movie m;
    cout << "Enter movie title: ";
    getline(cin, m.title);
    cout << "Enter director: ";
    getline(cin, m.director);
    cout << "Enter year released: ";
    cin >> m.yearReleased;
    cout << "Enter duration (minutes): ";
    cin >> m.lengthMinutes;
    cout << "Enter rating (out of 10): ";
    cin >> m.ratingOutOf10;
    cin.ignore();
    cout << "Enter genre: ";
    getline(cin, m.genre);
    return m;
}


int main() {
    vector<Movie> movies;
    vector<Movie> watchlist;
    int choice;

    do {
        cout << "\n--- Movie Collection Manager ---\n"; // Menu
        cout << "1. Add a Movie\n";
        cout << "2. Search Movies\n";
        cout << "3. Display Statistics\n";
        cout << "4. Manage Watchlist\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) { // This clears that weird spamming issue 
            cin.clear(); // clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        cin.ignore();
        
        if (choice == 1) { // Movie adder
            Movie m = createMovie(); // Calls create movie 
            movies.push_back(m); // Adds to movie vector
            cout << "Movie added!\n";

        } else if (choice == 2) {
            int searchChoice; // Search menu
            cout << "\n--- Search Movies ---\n";
            cout << "1. Search by Title\n";
            cout << "2. Search by Director\n";
            cout << "3. Search by Genre\n";
            cout << "4. Filter by Year\n";
            cout << "5. Filter by Rating\n";
            cout << "Enter your choice: ";
        
            if (!(cin >> searchChoice)) { // Spammy issue
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Returning to main menu.\n";
                continue;
            }
            cin.ignore();
        
            bool found = false;
        
            switch (searchChoice) {
                case 1: {
                    string title; // Search by title
                    cout << "Enter title to search: ";
                    getline(cin, title);
                    for (const auto& m : movies) { 
                        if (m.title.find(title) != string::npos) { // Checks for parts of strings
                            displayMovie(m);
                            found = true;
                        }
                    }
                    break;
                }
                case 2: {
                    string director; // Search by director
                    cout << "Enter director to search: ";
                    getline(cin, director);
                    for (const auto& m : movies) {
                        if (m.director == director) {
                            displayMovie(m);
                            found = true;
                        }
                    }
                    break;
                }
                case 3: {
                    string genre; // Search by genre
                    cout << "Enter genre to search: ";
                    getline(cin, genre);
                    for (const auto& m : movies) {
                        if (m.genre == genre) {
                            displayMovie(m);
                            found = true;
                        }
                    }
                    break;
                }
                case 4: {
                    int year; // Search by year
                    cout << "Enter year to filter movies released after: ";
                    cin >> year;
                    for (const auto& m : movies) {
                        if (m.yearReleased > year) {
                            displayMovie(m);
                            found = true;
                        }
                    }
                    break;
                }
                case 5: {
                    double minRating; // Search by rating
                    cout << "Enter minimum rating to filter: ";
                    cin >> minRating;
                    for (const auto& m : movies) {
                        if (m.ratingOutOf10 >= minRating) {
                            displayMovie(m);
                            found = true;
                        }
                    }
                    break;
                }
                default:
                    cout << "Invalid search option.\n";
            }
        
            if (!found && searchChoice >= 1 && searchChoice <= 5) { // No movies found. When found is set to true nothing happens
                cout << "No matching movies found.\n";
            }
        } else if (choice == 3) {
            if (movies.empty()) {
                cout << "No movies in collection.\n";
            } else {
                double totalRating = 0;
                map<string, int> genreCount;
                int decadeCounts[10] = {0}; // For decades from 1950s to 2040s
        
                for (const auto& movie : movies) {
                    totalRating += movie.ratingOutOf10;
                    genreCount[movie.genre]++;
        
                    // Count movies by decade
                    if (movie.yearReleased >= 1950 && movie.yearReleased < 2050) {
                        int index = (movie.yearReleased - 1950) / 10;
                        decadeCounts[index]++;
                    }
                }
        
                // Operation 1: Display average rating
                cout << "Average Rating: " << totalRating / movies.size() << "/10\n";
        
                // Operation 2: Display genre counts
                cout << "\nMovies by Genre:\n";
                for (const auto& entry : genreCount) {
                    cout << "- " << entry.first << ": " << entry.second << " movie(s)\n";
                }
            }
        } else if (choice == 4) {
            int subChoice;
            cout << "\n--- Watchlist Menu ---\n";
            cout << "1. Add to Watchlist\n";
            cout << "2. View Watchlist\n";
            cout << "Enter your choice: ";

            if (!(cin >> subChoice)) { // Deals with anything that isnt 1 or 2
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Returning to main menu.\n";
                continue;
            }
            cin.ignore();

            if (subChoice == 1) { // Add movies to watchlist
                string title;
                cout << "Enter title to add to watchlist: ";
                getline(cin, title);
                bool found = false;
                for (const auto& m : movies) {
                    if (m.title == title) {
                        watchlist.push_back(m);
                        cout << "Added to watchlist.\n";
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Movie not found in collection.\n"; // Deals with nonexistant movies
            } else if (subChoice == 2) {
                if (watchlist.empty()) {
                    cout << "Watchlist is empty.\n";
                } else {
                    cout << "\n--- Your Watchlist ---\n"; // Displays all movies in watchlist
                    for (const auto& m : watchlist) {
                        displayMovie(m);
                    }
                }
            }

        } else if (choice == 5) {
            cout << "Exiting program. Goodbye!\n";
        } else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}

// ---Project Requirments Y/N---
// Store movies with title, director, year, rating, and genre: Y
// Search funtion by title, director, or genre: Y
// Filter movies by rating or year range: Y
// Display statistics: Y

// ---Rubric Requirments Y/N---
// Basic structure: Y
// uses cin and getline(): Y
// Uses at least 3 variable types: Y
// Uses if, else if, else, switch statement: Y
// uses for and while loops with breaks and continues: Y
// Uses at least 2 user defined functions: Y
// Demonstrates the manipulation of strings: Y
// uses one or more arrays that perform at least two opperations: 
// Define two structs with two or more members and use them in a function: Y