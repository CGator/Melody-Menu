#pragma once
#include <map>
#include <vector>
#include <iostream>
#include "Music.h"

class HashMap {
	// using Music placeholder until we have the actual datastructure ready

	//	Data:
	Music **arr = new Music*[10000];
	int end = 0;
	std::vector<int> indices;
	
public:
	//	Functions:
	std::vector<Music> search(int type, std::string input);

	void put(Music* m);
	Music get(std::string key);
};
