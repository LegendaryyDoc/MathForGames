#pragma once
#include "raylib.h"
#include "vec2.h"
#include "UTILS.h"
#include <cfloat>
#include <cmath>

#include <iostream>
#include <string>

class circle
{
private:
	float angle = 0.0;
	float offset = 0.0;

	float scale = 1.0;
	float speed = 3;

	bool add = false;

public:
	int spriteNumber = 8;

	float rotation = ((2 * PI) / speed);

	Texture2D * mySprite = new Texture2D[spriteNumber];
	Texture2D sprite;
	vec2 * spritePos = new vec2[spriteNumber];

	/*-------------------------------------------*/
	/*-------------------------------------------*/
	
	vec2 pos;
	
	double radius = 150.0f;

	circle(vec2 cord);
	circle();
	~circle();

	void update();
	void draw();
	void spriteDraw();
};