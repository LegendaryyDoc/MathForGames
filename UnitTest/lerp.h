#pragma once
#include "PointsVectors.h"
#include <vector>
#include "raylib.h"
#include "Interpolation.h"

class lerpPlayer
{
public:
	vec2 pos;

	float elapse = 0.0f;
	float duration = 3.0f;
	int currentWayPoint = 0;

	void moveTo(vec2 startPoint, vec2 endPoint, int size);
	void draw();
};