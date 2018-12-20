#include "Easing.h"

void easingPlayer::moveTo(vec2 startPoint, vec2 endPoint)
{
	vec2 change = endPoint - startPoint;

	pos = easeInSine(elapse, startPoint, change, duration);
}

void easingPlayer::draw()
{
	DrawCircle(pos.x, pos.y, 10.0f, GREEN);
}
