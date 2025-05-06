#include <iostream>
#include <string>
using namespace std;

struct Movie {
    string title;
    string director;
    int yearReleased;
    int lengthMinutes;
    double ratingOutOf10;
    string genre;
};

int main() {
    const int numberMovies = 3;
    Movie movies[numberMovies];
    double ratingTotal = 0.0;
    int longestMovie = 0;
    int filterYear;
    bool found = false;

    cout << "--- Movie Collection Manager ---\n";
    for (int i = 0; i < numberMovies; ++i) { // Only up to 3 movies
        cout << "Enter details for movie #" << (i + 1) << ":\n";

        cout << "Title: ";
        getline(cin, movies[i].title); // Gets title

        cout << "Director: ";
        getline(cin, movies[i].director); // Gets director

        cout << "Year Released: ";
        cin >> movies[i].yearReleased; // Gets released year

        cout << "Duration (in minutes): "; // Gets the length
        cin >> movies[i].lengthMinutes;

        cout << "Rating (out of 10): "; // Gets rating
        cin >> movies[i].ratingOutOf10;
        cin.ignore(); // Removes the leftover newline

        cout << "Genre: "; // Gets genre
        getline(cin, movies[i].genre);

        cout << endl;
    }

    cout << "\n--- Your Movie Collection ---\n";
    for (int i = 0; i < numberMovies; ++i) {
        cout << "Movie #" << (i + 1) << ":\n";
        cout << "Title: " << movies[i].title << endl;
        cout << "Director: " << movies[i].director << endl;
        cout << "Year Released: " << movies[i].yearReleased << endl;
        cout << "Duration: " << movies[i].lengthMinutes << " minutes\n";
        cout << "Rating: " << movies[i].ratingOutOf10 << "/10\n";
        cout << "Genre: " << movies[i].genre << "\n\n";
    }

    for (int i = 0; i < numberMovies; ++i) { // Should check every movie
        ratingTotal += movies[i].ratingOutOf10;

        if (movies[i].lengthMinutes > movies[longestMovie].lengthMinutes) { // Checks movies to see if theyre longer than the current longest movie
            longestMovie = i;
        }
    }

    double averageRating = ratingTotal / numberMovies;

    cout << "Average Rating: " << averageRating << "/10\n";
    cout << "Longest Movie: " << movies[longestMovie].title << " (" << movies[longestMovie].lengthMinutes << " minutes)\n";

    cout << "\nEnter a year to filter movies released after that year: ";
    cin >> filterYear;
    
    cout << "Movies released after " << filterYear << ":\n";
    
    for (int i = 0; i < numberMovies; ++i) {
        if (movies[i].yearReleased > filterYear) {
            cout << "- " << movies[i].title << " (" << movies[i].yearReleased << ")\n";
            found = true;
        }
    }
    
    if (!found) { // Only if there arent any movies made past that year
        cout << "No movies found released after " << filterYear << ".\n";
    }
    
    return 0;
}
