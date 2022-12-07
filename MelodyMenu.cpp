#include <iostream>
#include <chrono>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <string>

#include "Music.h"
#include "HashMap.h"

using namespace std;
using namespace std::chrono;

void printWelcome();
void printSearchMenu();
void printOutput(vector<Music>& results);
void printTimeTakenHashMap(std::chrono::milliseconds duration);
void printTimeTakenGraph(std::chrono::milliseconds duration);
void printRepeatProgram();
void runSearch(int menuChoice, set<string>& genres, HashMap& hashmapMusic, vector<Music>& musicData);
void loadData(vector<float>& artist_hotness, vector<string>& artist_id, vector<float>& artist_latitude, vector<float>& artist_longitude,
    vector<string>& artist_name, vector<string>& artist_terms, vector<float>& artist_terms_freq, vector<string>& song_id,
    vector<float>& song_loudness, vector<int>& song_year, vector<Music>& musicData);
void loadHashMap(HashMap& hashmapMusic, vector<Music>& musicData);

int main()
{
    int menuChoice;
    bool continueProgram = true;

    HashMap hashmapMusic;

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

    loadHashMap(hashmapMusic, musicData);

    for (string genre : artist_terms) {
        genres.insert(genre);
    }

    printWelcome();

    while (continueProgram) {
        printSearchMenu();

        cin >> menuChoice;

        while (menuChoice < 0 || menuChoice > 5) {
            cout << "\nPlease choose a valid option!" << endl;

            cin >> menuChoice;
        }

        if (menuChoice != 0) {
            cout << endl;
            runSearch(menuChoice, genres, hashmapMusic, musicData);
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

void loadHashMap(HashMap& hashmapMusic, vector<Music>& musicData) {
    for (int i = 0; i < musicData.size(); i++) {
        hashmapMusic.put(&musicData[i]);
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
    cout << "\t3. Hotness Factor" << endl;
    cout << "\t4. Year" << endl;
    cout << "\t5. Crazy Search" << endl;
    cout << endl;
    cout << "\t0. Exit Program" << endl;
}

void printOutput(vector<Music>& results) {
    cout << endl;
    cout << "Here's your results!!!" << endl;

    for (int i = 0; i < results.size(); i++) {
        cout << "\t" << i + 1 << ". " << results[i].artist_name << endl;
    }

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
void runSearch(int menuChoice, set<string>& genres, HashMap& hashmapMusic, vector<Music>& musicData) {
    string input;
    string name;
    //float inputFloat;
    //int inputInt;
    bool valid;

    vector<Music> resultsHashMap;

    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    switch (menuChoice) {
    case 1:

        cout << "What artist did you have in mind?" << endl;
        getline(cin >> ws, input);

        start = high_resolution_clock::now();
        resultsHashMap = hashmapMusic.search(menuChoice, input);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        printOutput(resultsHashMap);
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
            getline(cin >> ws, input);

            if (genres.find(input) == genres.end()) {
                cout << "Unfortunately we don't have that genre in our database. Maybe try another?" << endl;
            }
            else {
                valid = true;
            }
        }

        start = high_resolution_clock::now();
        resultsHashMap = hashmapMusic.search(menuChoice, input);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        printOutput(resultsHashMap);
        printTimeTakenHashMap(duration);

        start = high_resolution_clock::now();
        //insert search function here
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        printTimeTakenGraph(duration);

        break;

    case 3:

        cout << "How hot do you want it? Enter a number from 0 - 100:" << endl;
        cin >> input;

        start = high_resolution_clock::now();
        resultsHashMap = hashmapMusic.search(menuChoice, input);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        printOutput(resultsHashMap);
        printTimeTakenHashMap(duration);

        start = high_resolution_clock::now();
        //insert search function here
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        printTimeTakenGraph(duration);

        break;

    case 4:

        cout << "Oh you want music from a specific time? You got it. Just give me a year!" << endl;
        cin >> input;

        start = high_resolution_clock::now();
        resultsHashMap = hashmapMusic.search(menuChoice, input);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        printOutput(resultsHashMap);
        printTimeTakenHashMap(duration);

        start = high_resolution_clock::now();
        //insert search function here
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        printTimeTakenGraph(duration);

        break;

    case 5:

        int randomSearchNum = (rand() % 4) + 1;
        int randomMusicNum = rand() % musicData.size();

        cout << "Let's get crazy!!!" << endl;

        start = high_resolution_clock::now();
        resultsHashMap = hashmapMusic.search(randomSearchNum, musicData[randomMusicNum].artist_name);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        printOutput(resultsHashMap);
        printTimeTakenHashMap(duration);

        start = high_resolution_clock::now();
        //insert search function here
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        printTimeTakenGraph(duration);

        break;
    }
}
