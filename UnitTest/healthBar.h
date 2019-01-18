#pragma once
#include "vec2.h"
#include "Interpolation.h"
#include "raylib.h"

class healthBar
{
public:
	vec2 pos = {675,25};

	float damage = 10.0f;

	float healthBarSize = 100.0f;
	float currentHealth = healthBarSize;

	void update();
	void draw();
};