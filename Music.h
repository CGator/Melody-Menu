#pragma once
#include <string>

using namespace std;

class Music {
public:
    float artist_familiarity;
    float artist_hotness;
    string artist_id;
    float artist_latitude;
    int artist_location;
    float artist_longitude;
    string artist_name;
    float artist_similar;
    string artist_terms;
    float artist_terms_freq;
    int release_id;
    int release_name;
    float song_artist_mbtags;
    float song_artist_mbtags_count;
    float song_bars_confidence;
    float song_bars_start;
    float song_beats_confidence;
    float song_beats_start;
    float song_duration;
    float song_end_of_fade_in;
    float song_hotness;
    string song_id;
    float song_key;
    float song_key_confidence;
    float song_loudness;
    int song_mode;
    float song_mode_confidence;
    float song_start_of_fade_out;
    float song_tatums_confidence;
    float song_tatums_start;
    float song_tempo;
    float song_time_signature;
    float song_time_signature_confidence;
    int song_title;
    int song_year;

    Music();

    Music(float artist_familiarity, float artist_hotness, string artist_id, float artist_latitude, int artist_location, float artist_longitude, string artist_name,
        float artist_similar, string artist_terms, float artist_terms_freq, int release_id, int release_name, float song_artist_mtbags, float song_artist_mtbags_count,
        float song_bars_confidence, float song_bars_start, float song_beats_confidence, float song_beats_start, float song_duration, float song_end_of_fade_in, float song_hotness,
        string song_id, float song_key, float song_key_confidence, float song_loudness, int song_mode, float song_mode_confidence, float song_start_of_fade_out, float song_tatums_confidence,
        float song_tatums_start, float song_tempo, float song_time_signature, float song_time_signature_confidence, int song_title, int song_year);
};