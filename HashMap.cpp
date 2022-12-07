#include "HashMap.h"
#include <ctime>

HashMap::HashMap(){
	for (int i = 0; i < 10000; i++) {
		arr[i] = nullptr;
	}
}

std::vector<Music*> HashMap::search(int type, std::string input)
{
	std::vector<Music*> returnList;
	srand((unsigned)time(0));
	int currIndex;

	if (type == 1) {
		// artist by name
		if (get(input) != nullptr) {
			returnList.push_back(get(input));
		}
	}

	for (int i = 0; i < 10000; i++) {
		if (arr[i] == nullptr) {
			continue;
		}
		if (returnList.size() >= 10) {
			break;	
		}
		switch (type) {
			
			case 2:
				// artist by hotness
				if (arr[i]->artist_hotness >= std::stof(input) -.1 && arr[i]->artist_hotness <= std::stof(input) + .1) {
					returnList.push_back(arr[i]);
				}
				break;
			case 3:
				// artist by genre/terms
				if (arr[i]->artist_terms == input) {
					returnList.push_back(arr[i]);
				}
				break;
			case 4:
				// artist/song by year
				if (arr[i]->song_year == std::stoi(input)) {
					returnList.push_back(arr[i]);
				}
				break;
			case 5:
				// CRAZY SEARCH
				switch (rand() % 3) 
				{
					case 0:
						// Loudness
						if (arr[i]->song_loudness < -25.0f) {
							returnList.push_back(arr[i]);
						}
						break;
					case 1:
						// year and hotness, 0 and 0, ur mom
						if (arr[i]->artist_hotness > 0.5f && arr[i]->song_year < 1975) {
							returnList.push_back(arr[i]);
						}
						break;
					case 2:
						if (arr[i]->artist_latitude < 45.0f) {
							returnList.push_back(arr[i]);
						}
						break;
					default:
						break;
				}
				break;
			default:
				break;
		}
	}
	return returnList;
}

void HashMap::put(Music* m)
{
	int hV = 0;
	hV += (int)m->artist_id.at(m->artist_id.size() - 1);
	hV += (int)m->artist_id.at(m->artist_id.size() - 2) * 100;
	hV = hV % 10000;

	arr[hV] = m;
}

Music* HashMap::get(std::string artist_id)
{
	int key = 0;
	key += (int) artist_id.at(artist_id.size() - 1);
	key += (int) artist_id.at(artist_id.size() - 2) * 100;

	return arr[key % 10000];
}
