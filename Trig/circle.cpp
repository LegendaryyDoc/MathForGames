#include "circle.h"
#include "PointsVectors.h"
#include "UTILS.h"
#include <cfloat>
#include "raylib.h"
#include <cmath>

circle::circle(vec2 cord)
{
	pos.x = cord.x;
	pos.y = cord.y;
}

circle::circle()
{
}

void circle::draw()
{
	radius = 50;

	for (double angle = 0; angle <= 2 * PI; angle += .01f)
	{
		++amountOfPoints;
		pointPos = new vec2[amountOfPoints];

		for (int i = 0; i < amountOfPoints; i++)
		{
			pointPos[i].x = pos.x + radius * cos(i);
			pointPos[i].y = pos.y + radius * sin(i);
		}

		for (int i = 0; i < amountOfPoints - 2; ++i)
		{
			DrawLine(pointPos[i].x, pointPos[i].y, pointPos[i + 1].x, pointPos[i + 1].y, GREEN);
		}
	}
	
	amountOfPoints = 0;
}