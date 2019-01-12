#include "transform2d.h"
#include "UTILS.h"
#include <cmath>

transform2d::transform2d()
{
	localPos = { 0,0 };
	localRot = 0;
	localScale = { 1,1 };
	parent = nullptr;
}

void transform2d::translate(const vec2 & offset)
{
	localPos = offset;
}

void transform2d::rotate(const float angle)
{
	localRot += angle;
}

void transform2d::lookAt(const transform2d & target)
{
	vec2 alpha = target.localPos - localPos;

	alpha.getNormalized();

	localRot = -(atan2(alpha.y, alpha.x) + 1.5708);
}

void transform2d::lookAt(const vec2 & mouse)
{
	vec2 alpha = mouse - localPos;

	alpha.getNormalized();

	localRot = -(atan2(alpha.y, alpha.x) + 1.5708);
}

vec2 transform2d::forward() const
{
	vec2 alpha = vec2(cos(localRot), sin(localRot)).getNormalized();
	return alpha;
}

void transform2d::setForward(const vec2 & newFwd)
{
	vec2 alpha = newFwd - localPos;

	alpha.getNormalized();

	localRot = atan2(alpha.y, alpha.x);
}

mat3 transform2d::getTRSMatrix() const
{
	mat3 alpha;

	alpha.xAxis = { localPos.x, cosf(localRot), localScale.x };
	alpha.yAxis = { localPos.y, sin(localRot), localScale.y };
	alpha.zAxis = { 0, 0, 1 };

	return alpha;
}

mat3 transform2d::getTSMatrix() const
{
	mat3 alpha;

	alpha.xAxis = { localScale.x, 0, localPos.x };
	alpha.yAxis = { 0, localScale.y, localPos.y };
	alpha.zAxis = {0, 0, 1};

	return alpha;
}

/*------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*/

vec2 transform2d::worldPosition() const
{
	if (parent != nullptr) //If you have a parent
	{
		mat3 concat = getTSMatrix() * parent->getTSMatrix();
		return vec2(concat.m3, concat.m6);
	}

	return localPos;
}

float transform2d::worldRotation() const
{
	if (parent != nullptr) //If you have a parent
	{
		return localRot * parent->worldRotation();
	}

	return localRot;
}

vec2 transform2d::worldScale() const
{
	if (parent != nullptr) //If you have a parent
	{
		mat3 concat = getTSMatrix() * parent->getTSMatrix();
		return vec2(concat.m1, concat.m5);
	}

	return localPos;
}


void transform2d::setParent(transform2d * _parent)
{
	parent = _parent;
	parent->children.push_back(this);
}

transform2d * transform2d::getParent()
{
	return parent;
}

transform2d const * transform2d::getParent() const
{
	return parent;
}

transform2d * transform2d::getChildren()
{
	if (children.size() > 0)
	{
	return children[0];
	}
	return nullptr;
}

transform2d * const * transform2d::getChildren() const
{
	if (children.size() > 0)
	{
		return &children[0];
	}
	return nullptr;
}

size_t transform2d::getChildrenCount() const
{
	return children.size();
}
