#pragma once
#include "PointsVectors.h"
#include "Matrices.h"

/*------------------------------------------------------------------------*/
/*-----------------------------Transform2D--------------------------------*/
/*------------------------------------------------------------------------*/

struct transform2d
{
	transform2d();

	vec2 localPos;
	float localRot;
	vec2 localScale;

	void translate(const vec2 &offset);
	void rotate(const float angle);

	void lookAt(const transform2d &target);
	vec2 forward() const;
	void setForward(const vec2 &newFwd);

	mat3 getTRSMatrix() const;
};