#include "gun.h"

tankGun::tankGun()
{
	std::cout << "Loading Sprite!" << std::endl;
	mySprite = LoadTexture("Resources/barrelBlack.png");

	gun.localPos = { 0, 0 };
	gun.localRot = 0;
	gun.localScale = { 1, 1 };
}

tankGun::~tankGun()
{
	std::cout << "Unloading Sprite!" << std::endl;
	UnloadTexture(mySprite);
}

void tankGun::findParent(transform2d * obj)
{
	gun.setParent(obj);
}

void tankGun::update()
{
	gun.lookAt(GetMousePosition());
}

void tankGun::draw(vec2 offset)
{
	//DrawTextureEx(mySprite, { gun.worldPosition().x - offset.x, gun.worldPosition().y - offset.y }, gun.worldRotation() + 90, 1, WHITE);
	Rectangle sourceRect = { 0, 0, mySprite.width, mySprite.height };
	Rectangle destRect = { gun.worldPosition().x, gun.worldPosition().y, mySprite.width, mySprite.width };

	DrawTexturePro(mySprite, sourceRect, destRect, { (float)mySprite.width / 2, (float)mySprite.height / 2 }, (gun.worldRotation() * 180 / PI - 90), WHITE);
	std::cout << gun.worldRotation() << std::endl;
}
