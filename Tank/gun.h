#pragma once
#include <iostream>
#include "raylib.h"
#include "PointsVectors.h"
#include "Matrices.h"
#include "transform2d.h"
#include "UTILS.h"
#include "body.h"

class tankGun
{
public:
	Texture2D mySprite;

	transform2d gun;

	tankGun();
	~tankGun();

	void findParent(transform2d * obj);
	void update();
	void draw(vec2 offset);
};