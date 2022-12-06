#pragma once
#include <map>
#include <vector>
#include "Music.h"

class HashMap {
	// using Music placeholder until we have the actual datastructure ready

	//	Data:
	std::map<int, Music> map;
	std::vector<Music> arr;

	//	Functions:
	int Hash(Music m);
	std::vector<Music> linearSearch(int searchType);
	std::vector<Music> search(std::string input);
	Music getByKey(int key);

	void put(const Music &m);
	Music get(std::string key);
};
