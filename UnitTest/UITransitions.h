#pragma once
#include "raylib.h"

enum buttonTransition
{
	Normal,
	Hover,
	Pressed, 
	Disabled
};

class button
{
public:
	Texture2D mySprite;

	Color action;

	Rectangle rec;

	float width = GetScreenWidth();
	float height = GetScreenHeight();

	void update(Rectangle rec2);
	void draw();

	button();
	~button();
};