#pragma once
#include "PointsVectors.h"
#include "UTILS.h"

class circle
{
public:
	int amountOfPoints = 0;

	vec2 pos;
	vec2 * pointPos;
	double radius = 5.0f;

	circle(vec2 cord);
	circle();

	void draw();
};