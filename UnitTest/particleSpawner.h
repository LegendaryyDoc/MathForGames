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
	void draw();
};