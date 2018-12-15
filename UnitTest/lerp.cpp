#include "lerp.h"

void lerpPlayer::moveTo(vec2 startPoint, vec2 endPoint, int size)
{
	if (elapse / duration > 1.0f)
	{
		currentWayPoint = (currentWayPoint + 1)% size;
	}
	pos = lerp(startPoint, endPoint, elapse / duration);
}

void lerpPlayer::draw()
{
	DrawCircle(pos.x, pos.y, 10.0f, GREEN);
}
