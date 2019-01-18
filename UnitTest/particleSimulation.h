#pragma once
#include "Interpolation.h"
#include "raylib.h"
#include "vec2.h"
#include <string>
#include <ctime>

class particleSimulation
{
public:
	vec2 pos = {400, 100};
	Texture2D mySprite;

	int r = 255;
	int b = 255;
	int g = 255;
	int o = 255;

	float size = .5f;

	float elapse = 0.0f;
	float duration = 30.0f;

	void update();
	void draw();

	particleSimulation();
	~particleSimulation();
};