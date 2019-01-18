#pragma once
#include <iostream>
#include "raylib.h"
#include "vec2.h"
#include "Matrices.h"
#include "transform2d.h"
#include "UTILS.h"

class tankBody
{
public:
	Texture2D mySprite;

	transform2d body;

	tankBody();
	~tankBody();

	void update();
	void draw(vec2 offset);
};