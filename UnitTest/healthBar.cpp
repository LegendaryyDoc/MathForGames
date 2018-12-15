#include "healthBar.h"

void healthBar::update()
{
	if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
	{
		currentHealth -= damage;
		currentHealth = lerp(currentHealth - currentHealth, healthBarSize, currentHealth / healthBarSize);
	}
}

void healthBar::draw()
{
	DrawRectangle(pos.x, pos.y, 100, 10, BLACK);
	DrawRectangle(pos.x, pos.y, 100 - (100 - currentHealth), 10, RED);
}
