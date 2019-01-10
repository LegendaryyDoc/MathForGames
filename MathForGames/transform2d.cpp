#include "transform2d.h"
#include "UTILS.h"
#include <cmath>

transform2d::transform2d()
{
	localPos = { 0,0 };
	localRot = 0;
	localScale = { 1,1 };
}

void transform2d::translate(const vec2 & offset)
{
	localPos = offset;
}

void transform2d::rotate(const float angle)
{
	localRot = tan(angle);
}

void transform2d::lookAt(const transform2d & target) // still need to do
{
	vec2 angle;
	float rot;

	angle.x = target.localPos.x - localPos.x;
	angle.y = target.localPos.y - localPos.y;

	rot = *angle.normalize();

	rot = rot * PI/180;

	localRot = tan(rot);
}

vec2 transform2d::forward() const
{
	return vec2();
}

void transform2d::setForward(const vec2 & newFwd)
{

}
