#pragma once
#include <string>

using namespace std;

class Music {
public:
    float artist_hotness;
    string artist_id;
    float artist_latitude;
    float artist_longitude;
    string artist_name;
    string artist_terms;
    float artist_terms_freq;
    string song_id;
    float song_loudness;
    int song_year;

    Music();

	Music(float artist_hotness, string artist_id, float artist_latitude, float artist_longitude, string artist_name,
		string artist_terms, float artist_terms_freq,
		string song_id, float song_loudness, int song_year);
};
