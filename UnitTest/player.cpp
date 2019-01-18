#include "player.h"
#include "vec2.h"

void player::distanceAway()
{	
	distance.x = (dest.x - pos.x);
	distance.y = (dest.y - pos.y);
	d = distance.magnitude();
}

void player::move()
{
	pos += (dest - pos).getNormalized() * speed *GetFrameTime();
}

void player::randomMove()
{
	if (xreverse == true)
	{
		vel.x = -vel.x;
		xreverse = false;
	}

	if (yreverse == true)
	{
		vel.y = -vel.y;
		yreverse = false;
	}

	pos.x += vel.x * GetFrameTime();
	pos.y +=  vel.y * GetFrameTime();

}

void player::draw()
{
	DrawCircle(pos.x, pos.y, cSize, RED);
}
