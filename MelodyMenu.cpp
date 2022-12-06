#include <iostream>
#include <chrono>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>

#include "Music.h"

using namespace std;
using namespace std::chrono;

void printWelcome();
void printSearchMenu();
void printOutput();
void printTimeTakenHashMap(std::chrono::milliseconds duration);
void printTimeTakenGraph(std::chrono::milliseconds duration);
void printRepeatProgram();
void runSearch(int menuChoice, set<string>& genres);
void loadData(vector<float>& artist_hotness, vector<string>& artist_id, vector<float>& artist_latitude, vector<float>& artist_longitude, 
    vector<string>& artist_name, vector<string>& artist_terms, vector<float>& artist_terms_freq, vector<string>& song_id, 
    vector<float>& song_loudness, vector<int>& song_year, vector<Music>& musicData);

int main()
{
    int menuChoice;
    bool continueProgram = true;

    vector<Music> musicData;
    set<string> genres;
    
    vector<float> artist_hotness;
    vector<string> artist_id;
    vector<float> artist_latitude;
    vector<float> artist_longitude;
    vector<string> artist_name;
    vector<string> artist_terms;
    vector<float> artist_terms_freq;
    vector<string> song_id;
    vector<float> song_loudness;
    vector<int> song_year;

    srand((unsigned)time(NULL));

    loadData(artist_hotness, artist_id, artist_latitude,
        artist_longitude, artist_name, artist_terms, artist_terms_freq,
        song_id, song_loudness, song_year, musicData);

    for (string genre : artist_terms) {
        genres.insert(genre);
    }

    printWelcome();

    while (continueProgram) {
        printSearchMenu();

        cin >> menuChoice;

        if (menuChoice != 0) {
            runSearch(menuChoice, genres);
            printOutput();
            printRepeatProgram();

            cin >> menuChoice;
            if (menuChoice == 0) {
                continueProgram = false;
            }
        }
        else {
            continueProgram = false;
        }
    }

}

void loadData(vector<float>& artist_hotness, vector<string>& artist_id, vector<float>& artist_latitude, vector<float>& artist_longitude,
    vector<string>& artist_name, vector<string>& artist_terms, vector<float>& artist_terms_freq, vector<string>& song_id,
    vector<float>& song_loudness, vector<int>& song_year, vector<Music>& musicData) {

    ifstream dataFile("music.csv");
    string line;
    string token;
    Music music;
    int i = 0;

    if (!dataFile.is_open()) {
        throw runtime_error("File could not be opened");
    }

    if (dataFile.good()) {
        //read through first line of column names
        getline(dataFile, line);

        //get tokens from each column and store in vectors
        while (getline(dataFile, line)) {
            istringstream s(line);

            getline(s, token, ',');
            getline(s, token, ',');
            token = token.substr(1, token.size() - 2);
            artist_hotness.push_back(stof(token));

            getline(s, token, ',');
            token = token.substr(1, token.size() - 2);
            artist_id.push_back(token);

            getline(s, token, ',');
            token = token.substr(1, token.size() - 2);
            artist_latitude.push_back(stof(token));

            getline(s, token, ',');
            getline(s, token, ',');
            token = token.substr(1, token.size() - 2);
            artist_longitude.push_back(stof(token));

            getline(s, token, ',');
            token = token.substr(1, token.size() - 2);
            artist_name.push_back(token);

            getline(s, token, ',');
            getline(s, token, ',');
            token = token.substr(1, token.size() - 2);
            artist_terms.push_back(token);

            getline(s, token, ',');
            token = token.substr(1, token.size() - 2);
            artist_terms_freq.push_back(stof(token));

            getline(s, token, ',');
            getline(s, token, ',');
            getline(s, token, ',');
            getline(s, token, ',');
            getline(s, token, ',');
            getline(s, token, ',');
            getline(s, token, ',');
            getline(s, token, ',');
            getline(s, token, ',');
            getline(s, token, ',');
            getline(s, token, ',');
            getline(s, token, ',');
            token = token.substr(1, token.size() - 2);
            song_id.push_back(token);

            getline(s, token, ',');
            getline(s, token, ',');
            getline(s, token, ',');
            token = token.substr(1, token.size() - 2);
            song_loudness.push_back(stof(token));

            getline(s, token, ',');
            getline(s, token, ',');
            getline(s, token, ',');
            getline(s, token, ',');
            getline(s, token, ',');
            getline(s, token, ',');
            getline(s, token, ',');
            getline(s, token, ',');
            getline(s, token, ',');
            getline(s, token, ',');
            token = token.substr(1, token.size() - 2);
            song_year.push_back(stoi(token));

            musicData.push_back(Music(artist_hotness[i], artist_id[i], artist_latitude[i], artist_longitude[i],
                artist_name[i], artist_terms[i], artist_terms_freq[i], song_id[i], song_loudness[i], song_year[i]));

            i++;
        }
    }
}
void printWelcome() {
    cout << "Welcome to the Melody Menu!!!" << endl;
    cout << endl;
    cout << "Do you love music? Of course you do." << endl;
    cout << endl;
    cout << "Well I'm here to help you find music that fits your tastes." << endl;
    cout << "Just tell me what you want to search for and I'll find you a curated list of music that fits your preferences." << endl;
    cout << endl;
    cout << "If you can't make up your mind, we can go wild and give you a list of curated music by using the CRAZY SEARCH!" << endl;
    cout << endl;
}

void printSearchMenu() {
    cout << "Search for:" << endl;
    cout << "\t1. Artist" << endl;
    cout << "\t2. Genre" << endl;
    cout << "\t3. Tempo" << endl;
    cout << "\t4. Time Signature" << endl;
    cout << "\t5. Duration" << endl;
    cout << "\t6. Year" << endl;
    cout << "\t7. Key" << endl;
    cout << "\t8. Hotness" << endl;
    cout << "\t9. CRAZY SEARCH" << endl;
    cout << endl;
    cout << "\t0. Exit Program" << endl;
}

void printOutput() {
    cout << endl;
    cout << "Here's your results!!!" << endl;
    cout << endl;
}

void printTimeTakenHashMap(std::chrono::milliseconds duration) {
    cout << endl;
    cout << "Time taken for HashMap: " << duration.count() << "ms" << endl;
    cout << endl;
}

void printTimeTakenGraph(std::chrono::milliseconds duration) {
    cout << endl;
    cout << "Time taken for Graph: " << duration.count() << "ms" << endl;
    cout << endl;
}

void printRepeatProgram() {
    cout << "What would you like to do next?" << endl;
    cout << "\t1. Return to Menu" << endl;
    cout << "\t0. Exit" << endl;
    cout << endl;
}

//adjust this function based on data structures when we know how they function
void runSearch(int menuChoice, set<string>& genres) {
    string input;
    bool valid;

    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    switch (menuChoice) {
    case 1:

        cout << "What artist did you want to search for?" << endl;
        cin >> input;

        start = high_resolution_clock::now();
        //insert search function here
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        printTimeTakenHashMap(duration);

        start = high_resolution_clock::now();
        //insert search function here
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        printTimeTakenGraph(duration);

        break;

    case 2:
        valid = false;

        while (!valid) {

            cout << "What genre are you interested in?" << endl;
            cin >> input;

            if (genres.find(input) == genres.end()) {
                cout << "Unfortunately we don't have that genre in our database. Maybe try another?" << endl;
            }
            else {
                valid = true;
            }
        }

        start = high_resolution_clock::now();
        //insert search function here
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        printTimeTakenHashMap(duration);
        
        start = high_resolution_clock::now();
        //insert search function here
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        printTimeTakenGraph(duration);

        break;

    case 3:

        cout << "Got a tempo in mind? What is it?" << endl;
        cin >> input;

        start = high_resolution_clock::now();
        //insert search function here
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        printTimeTakenHashMap(duration);

        start = high_resolution_clock::now();
        //insert search function here
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        printTimeTakenGraph(duration);

        break;

    case 4:

        cout << "What's your favorite time signature?" << endl;
        cin >> input;

        start = high_resolution_clock::now();
        //insert search function here
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        printTimeTakenHashMap(duration);

        start = high_resolution_clock::now();
        //insert search function here
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        printTimeTakenGraph(duration);

        break;

    case 5:

        cout << "How long are you thinking? In seconds please." << endl;
        cin >> input;

        start = high_resolution_clock::now();
        //insert search function here
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        printTimeTakenHashMap(duration);

        start = high_resolution_clock::now();
        //insert search function here
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        printTimeTakenGraph(duration);

        break;

    case 6:
        cout << "Give me a year!" << endl;
        cin >> input;

        start = high_resolution_clock::now();
        //insert search function here
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        printTimeTakenHashMap(duration);

        start = high_resolution_clock::now();
        //insert search function here
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        printTimeTakenGraph(duration);

        break;

    case 7:
        cout << "Want everything in the same key? Enter 0-11:" << endl;
        cin >> input;

        start = high_resolution_clock::now();
        //insert search function here
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        printTimeTakenHashMap(duration);

        start = high_resolution_clock::now();
        //insert search function here
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        printTimeTakenGraph(duration);

        break;

    case 8:

        cout << "Oh so you want what's hot! You got it." << endl;

        start = high_resolution_clock::now();
        //insert search function here
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        printTimeTakenHashMap(duration);

        start = high_resolution_clock::now();
        //insert search function here
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        printTimeTakenGraph(duration);

        break;

    case 9:
        
        cout << "Let's get crazy!!!" << endl;

        start = high_resolution_clock::now();
        //insert search function here
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        printTimeTakenHashMap(duration);

        start = high_resolution_clock::now();
        //insert search function here
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        printTimeTakenGraph(duration);

        break;
    }
}
