#include "HashMap.h"

std::vector<Music> HashMap::search(int type, std::string input)
{

	for (int i = 0; i < end; i++) {
		switch (type) {
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			default:
				std::cout << "uh oh";
				break;
		}
	}
	return std::vector<Music>();
}

void HashMap::put(Music* m)
{
	int hV = 0;
	hV += (int)m->artist_id.at(m->artist_id.size() - 1);
	hV += (int)m->artist_id.at(m->artist_id.size() - 2) * 100;
	hV = hV % 10000;

	if (arr[hV] != nullptr) {
		end++;
	}

	arr[hV] = m;
}

Music HashMap::get(std::string artist_id)
{
	int key;
	key += (int) artist_id.at(artist_id.size() - 1);
	key += (int) artist_id.at(artist_id.size() - 2) * 100;
	return *arr[key % 10000];
}
