#include "UITransitions.h"

void button::update(Rectangle rec2)
{
	buttonTransition currentTransition = Normal;
	if (CheckCollisionRecs(rec, rec2) && currentTransition == !Disabled)
	{
		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
		{
			currentTransition = Pressed;
		}
		else
		{
			currentTransition = Hover;
		}
	}
	else
	{
		currentTransition = Normal;
	}


	switch (currentTransition)
	{
	case buttonTransition::Normal:
		action = WHITE;
		break;
	case buttonTransition::Hover:
		action = SKYBLUE;
		break;
	case buttonTransition::Pressed:
		action = DARKBLUE;
		break;
	case buttonTransition::Disabled:
		action = DARKGRAY;
		break;
	}
}

void button::draw()
{
	DrawTextureEx(mySprite, { (width / 2), (height / 2)}, 0, .5f, action);
}

button::button()
{
	mySprite = LoadTexture("magic_03.png");
	rec.height = mySprite.height;
	rec.width = mySprite.height;
	rec.x = width / 2;
	rec.y = height / 2;
}


button::~button()
{
	UnloadTexture(mySprite);
}
