#pragma once
#include <vector>
#include "particleSimulation.h"
#include "raylib.h"

class particleSpawner
{
public:
	std::vector<particleSimulation*> spawner;

	float spawnTimer = 0.0f;

	void create();			
	void destruction();
	void draw();
};

/*  need to do  */

// make sure that the size is more random
// delete a object if the object is black