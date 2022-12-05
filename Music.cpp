#include "Music.h"

Music::Music() {}

Music::Music(float artist_familiarity, float artist_hotness, string artist_id, float artist_latitude, int artist_location, float artist_longitude, string artist_name,
    float artist_similar, string artist_terms, float artist_terms_freq, int release_id, int release_name, float song_artist_mtbags, float song_artist_mtbags_count,
    float song_bars_confidence, float song_bars_start, float song_beats_confidence, float song_beats_start, float song_duration, float song_end_of_fade_in, float song_hotness,
    string song_id, float song_key, float song_key_confidence, float song_loudness, int song_mode, float song_mode_confidence, float song_start_of_fade_out, float song_tatums_confidence,
    float song_tatums_start, float song_tempo, float song_time_signature, float song_time_signature_confidence, int song_title, int song_year) {

    this->artist_familiarity = artist_familiarity;
    this->artist_hotness = artist_hotness;
    this->artist_id = artist_id;
    this->artist_latitude = artist_latitude;
    this->artist_location = artist_location;
    this->artist_longitude = artist_longitude;
    this->artist_name = artist_name;
    this->artist_similar = artist_similar;
    this->artist_terms = artist_terms;
    this->artist_terms_freq = artist_terms_freq;
    this->release_id = release_id;
    this->release_name = release_name;
    this->song_artist_mbtags = song_artist_mbtags;
    this->song_artist_mbtags_count = song_artist_mbtags_count;
    this->song_bars_confidence = song_bars_confidence;
    this->song_bars_start = song_bars_start;
    this->song_beats_confidence = song_beats_confidence;
    this->song_beats_start = song_beats_start;
    this->song_duration = song_duration;
    this->song_end_of_fade_in = song_end_of_fade_in;
    this->song_hotness = song_hotness;
    this->song_id = song_id;
    this->song_key = song_key;
    this->song_key_confidence = song_key_confidence;
    this->song_loudness = song_loudness;
    this->song_mode = song_mode;
    this->song_mode_confidence = song_mode_confidence;
    this->song_start_of_fade_out = song_start_of_fade_out;
    this->song_tatums_confidence = song_tatums_confidence;
    this->song_tatums_start = song_tatums_start;
    this->song_tempo = song_tempo;
    this->song_time_signature = song_time_signature;
    this->song_time_signature_confidence = song_time_signature_confidence;
    this->song_title = song_title;
    this->song_year = song_year;
}