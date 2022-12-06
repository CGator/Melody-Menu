#include "Music.h"

Music::Music() {}

Music::Music(float artist_hotness, string artist_id, float artist_latitude, float artist_longitude, 
    string artist_name, string artist_terms, float artist_terms_freq,
    string song_id, float song_loudness, int song_year) {

    this->artist_hotness = artist_hotness;
    this->artist_id = artist_id;
    this->artist_latitude = artist_latitude;
    this->artist_longitude = artist_longitude;
    this->artist_name = artist_name;
    this->artist_terms = artist_terms;
    this->artist_terms_freq = artist_terms_freq;
    this->song_id = song_id;
    this->song_loudness = song_loudness;
    this->song_year = song_year;
}
