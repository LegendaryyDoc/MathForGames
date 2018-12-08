#pragma once
#include "raylib.h"
#include "PointsVectors.h"

class player
{
public:
	int speed = 15.0f;
	float cSize = 45.0f;
	vec2 distance = { 0 , 0 };
	int d = 0;

	vec2 vel = { 50, 50 };

	bool xreverse = false;
	bool yreverse = false;

	vec2 dest = { 400,250 };
	vec2 pos = { 378, 256 };
	
	void distanceAway();
	void move();
	void randomMove();
	void draw();
};
