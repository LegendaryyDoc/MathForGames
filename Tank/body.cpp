#include "body.h"

tankBody::tankBody() // constructor
{
	std::cout << "Loading texture!" << std::endl;
	mySprite = LoadTexture("Resources/tankBlack.png");

	body.localPos = { 0, 0 };
	body.localRot = 0;
	body.localScale = { 1, 1 };
}

tankBody::~tankBody() // deconstructor
{
	std::cout << "Destroying texture!" << std::endl;
	UnloadTexture(mySprite);
}

void tankBody::update()
{
	/*  Movement Forwards and Backwards  */

	if (IsKeyDown(KEY_W))
	{
		/*  Move in the direction that is forward  */
		body.localPos.x += body.forward().x + GetFrameTime();
		body.localPos.y += body.forward().y + GetFrameTime();
	}
	if (IsKeyDown(KEY_S))
	{
		/*  Move in the direction that is backwards  */
		body.localPos.x -= body.forward().x + GetFrameTime();
		body.localPos.y -= body.forward().y + GetFrameTime();
	}

	/*  Rotation to change the direction forwards and backwards is  */

	if (IsKeyDown(KEY_A))
	{
		/*  Rotate counter clockwise  */
		body.rotate(.01);
	}
	if (IsKeyDown(KEY_D))
	{
		/*  Rotate clockwise  */
		body.rotate(-.01);
	}
}

void tankBody::draw(vec2 offset) // drawing tank body
{
	//DrawTextureEx(mySprite, { body.worldPosition().x - offset.y, body.worldPosition().y - offset.y }, body.worldRotation() + 90, 1, WHITE);
	/*DrawTexturePro(mySprite, sourceRec, destRec, { 37.5, 35 }, body.worldRotation() + 90, WHITE);
	std::cout << body.localPos.x << " " << body.localPos.y << std::endl;*/

	Rectangle sourceRect = { 0, 0, mySprite.width, mySprite.height };
	Rectangle destRect = { body.worldPosition().x, body.worldPosition().y, mySprite.width, mySprite.width };

	DrawTexturePro(mySprite, sourceRect, destRect, { (float)mySprite.width / 2, (float)mySprite.height / 2 }, body.worldRotation() * 180/PI - 90, WHITE);
}