#pragma once
#include "circle.h"


circle::circle(vec2 cord)
{
	pos.x = cord.x;
	pos.y = cord.y;

	for (int i = 0; i < spriteNumber; i++)
	{
		mySprite[i] = LoadTexture("nim1.png");
	}
	//sprite = LoadTexture("nim1.png");
}

circle::circle()
{	
}

circle::~circle()
{
	for (int i = 0; i < spriteNumber; i++)
	{
		UnloadTexture(mySprite[i]);
		//UnloadTexture(sprite);
	}
}

void circle::update()
{
	if (add == false)
	{
		radius -= GetFrameTime() * 50;
		if (radius <= 0)
		{
			add = true;
		}
	}
	else if (add == true)
	{
		radius += GetFrameTime() * 50;
		if (radius >= 100)
		{
			add = false;
		}
	}

	angle += (rotation * GetFrameTime());
	for (int i = 0; i < spriteNumber; i++)
	{
		offset = 2 * PI / spriteNumber * i;
		//std::cout << offset / (PI / 180) << std::endl;
		spritePos[i].x = pos.x + radius * cos((angle + offset)) - mySprite[i].width * scale / 2;
		spritePos[i].y = pos.y + radius * sin((angle + offset)) - mySprite[i].height * scale/ 2;
	}

	std::cout << radius << std::endl;
}

void circle::draw()
{
	for (double angle2 = 0; angle2 <= 2 * PI; angle2 += 2 * PI / 180)
	{
		DrawLine(
			pos.x + radius * cos(angle2),
			pos.y + radius * sin(angle2),
			pos.x + radius * cos(angle2 + 2 * PI / 180),
			pos.y + radius * sin(angle2 + 2 * PI / 180), RAYWHITE
		);
	}
		/*for (int i = 0; i < amountOfPoints; i++)
		{
			pointPos[i].x = pos.x + radius * cos(i);
			pointPos[i].y = pos.y + radius * sin(i);
		}*/
	
	/*for (int i = 0; i < amountOfPoints - 2; ++i)
	{
		DrawLine(pointPos[i].x, pointPos[i].y, pointPos[i + 1].x, pointPos[i + 1].y, GREEN);
	}
	amountOfPoints = 0;*/
}

void circle::spriteDraw()
{
	for (int i = 0; i < spriteNumber; i++)
	{
		DrawTextureEx(mySprite[i], spritePos[i], 0, 1, WHITE);
		//DrawCircle(spritePos[i].x + mySprite[i].height * scale / 2, spritePos[i].y + mySprite[i].height * scale / 2, 6, PINK);
	}
}