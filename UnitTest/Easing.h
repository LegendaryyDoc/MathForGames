#pragma once
#include "EasingFunctions.h"
#include "raylib.h"
#include "PointsVectors.h"

class easingPlayer
{
public:
	vec2 pos;

	float elapse = 0.0f;
	float duration = 3.0f;
	int currentWayPoint = 0;

	void moveTo(vec2 startPoint, vec2 endPoint);
	void draw();
};