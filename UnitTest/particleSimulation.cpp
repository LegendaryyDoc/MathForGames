#include "particleSimulation.h"

void particleSimulation::update()
{
	elapse += GetFrameTime();

	if (elapse >= duration)
	{
		elapse = 0;
	}

	r = lerp(r, 0, elapse / duration);
	b = lerp(b, 0, elapse / duration);
	g = lerp(g, 0, elapse / duration);
	//o = lerp(o, 0, elapse / duration);
}

void particleSimulation::draw()
{
	DrawTextureEx(mySprite, { pos.x, pos.y }, 0, size, { (unsigned char)r, (unsigned char)b, (unsigned char)g, (unsigned char)o });
}

particleSimulation::particleSimulation()
{
	mySprite = LoadTexture("magic_03.png");
}

particleSimulation::~particleSimulation()
{
	UnloadTexture(mySprite);
}
