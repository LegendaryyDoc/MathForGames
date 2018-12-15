#include "particleSpawner.h"
#include <iostream>

void particleSpawner::create()
{
	spawnTimer += GetFrameTime();

	std::cout << spawnTimer << std::endl;

	if (spawner.size() == NULL || spawnTimer >= 2.5f)
	{
		spawnTimer = 0;

		if (spawner.size() < 15)
		{
			spawner.push_back(new particleSimulation);
		}

		for (int i = 0; i < spawner.size(); i++)
		{
			spawner[i]->pos = { (float)(rand() % 700), (float)(rand() % 400) };
			spawner[i]->r = rand() % 255;
			spawner[i]->b = rand() % 255;
			spawner[i]->g = rand() % 255;
			spawner[i]->size = (rand() / RAND_MAX)+.1;
			spawner[i]->duration = rand() % 75 + 50;
		}
	}

	

	for (int i = 0; i < spawner.size(); i++)
	{
		spawner[i]->update();
	}
}

void particleSpawner::destruction()
{
	for (int i = 0; i < spawner.size(); i++)
	{
		if (spawner[i]->elapse / spawner[i]->duration)
		{

		}
	}
}

void particleSpawner::draw()
{
	for (int i = 0; i < spawner.size(); i++)
	{
		spawner[i]->draw();
	}
}
