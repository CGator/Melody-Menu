#include "Graph.h"
#include "GraphNode.h"
#include <vector>
#include <utility>
#include <string>
#include <ctime>
using namespace std;

Graph::Graph() {

}

void Graph::insert(Music* x){
	if (adjList.count(x->artist_terms) > 0) {
		adjList.at(x->artist_terms).push_back(x);
	}
	else {
		vector<Music*>* nV = new vector<Music*>();
		nV->push_back(x);
		adjList[x->artist_terms] = *nV;
	}
}

vector<Music*> Graph::search(int type, string input)
{
	std::vector<Music*> returnList;
	srand((unsigned)time(0));
	int currIndex;

	for (map<string, vector<Music*>>::iterator it = adjList.begin(); it != adjList.end() ; it++) {
		if (it->second.size() <= 0) {
			continue;
		}
		if (returnList.size() >= 10) {
			break;
		}
		switch (type) {
		case 1:
			for (int i = 0; i < it->second.size(); i++) {
				if (it->second.at(i)->artist_name == input && returnList.size() < 10) {
					returnList.push_back(it->second.at(i));
				}
			}
			
			break;
		case 2:
			// artist by hotness
			for (int i = 0; i < it->second.size(); i++) {
				if (it->second.at(i)->artist_hotness >= std::stof(input) - .1 && it->second.at(i)->artist_hotness <= std::stof(input) + .1) {
					returnList.push_back(it->second.at(i));
				}
			}
			break;
		case 3:
			// artist by genre/terms
			for (int i = 0; i < it->second.size(); i++) {
				if (it->second.at(i)->artist_terms == input) {
					returnList.push_back(it->second.at(i));
				}
			}
			break;
		case 4:
			// artist/song by year
			for (int i = 0; i < it->second.size(); i++) {
				if (it->second.at(i)->song_year == std::stoi(input)) {
					returnList.push_back(it->second.at(i));
				}
			}
			break;
		case 5:
			// CRAZY SEARCH
			switch (rand() % 3)
			{
			case 0:
				// Loudness
				for (int i = 0; i < it->second.size(); i++) {
					if (it->second.at(i)->song_loudness < -25.0f) {
						returnList.push_back(it->second.at(i));
					}
				}
			case 1:
				// year and hotness, 0 and 0, ur mom
				for (int i = 0; i < it->second.size(); i++) {
					if (it->second.at(i)->artist_hotness > 0.5f && it->second.at(i)->song_year < 1975) {
						returnList.push_back(it->second.at(i));
					}
				}
				break;
			case 2:
				for (int i = 0; i < it->second.size(); i++) {
					if (it->second.at(i)->artist_latitude < 45.0f) {
						returnList.push_back(it->second.at(i));
					}
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
