#pragma once
#include <map>
#include <vector>
#include <iostream>
#include "Music.h"

class HashMap {

	//	Data:
	Music **arr = new Music*[10000];

public:

	//	Functions:

	HashMap();

	// Make sure to check vector size!
	std::vector<Music*> search(int type, std::string input);

	// Uses pointers!
	void put(Music* m);

	// Needs nullptr checking when used... if ever used, lol
	Music* get(std::string key);
};
