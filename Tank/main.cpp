#include <iostream>
#include "vec2.h"

#include "raylib.h"

#include "body.h"
#include "gun.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	tankBody tb;
	tankGun tg;

	vec2 offset;

	offset.y = tb.mySprite.height;
	offset.x = tb.mySprite.width / 2;

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		vec2 cursor;

		cursor.x = GetMouseX();
		cursor.y = GetMouseY();

		tg.findParent(&tb.body);

		//----------------------------------------------------------------------------------
		// TODO: Update your variables here

		tb.update();
		tg.update();

		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);

		//DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

		tb.draw(offset);
		tg.draw(offset);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

	return 0;
}