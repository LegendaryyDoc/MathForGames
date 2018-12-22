#include <iostream>
#include "raylib.h"
#include "PointsVectors.h" 
#include "UTILS.h"
#include "vec3.h"
#include "player.h"
#include "assert.h"
#include <string>
#include "assert.h"
#include "lerp.h"
#include "healthBar.h"
#include "particleSimulation.h"
#include "particleSpawner.h"
#include "UITransitions.h"
#include "Easing.h"
#include <cfloat>
#include "Matrices.h"

#undef min
#undef max


int main()
{
	float a[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	float b[9] = { 10, 11, 12, 13, 14, 15, 16, 17, 18 };
	//float b[9] = { 1,0,0,0,1,0,0,0,1 };

	float x = 5;
	float y = 2;

	mat3 m3a, m3b, m3c, m3d, m3e, m3f, m3g, m3h;
	vec2 v1 = { 5,2 };

	m3a = a;
	m3b = b;

	m3a *= m3b; 

	m3d = m3a.identity();
	m3e = m3a.translation(x, y);
	m3f = m3a.translation(v1);
	m3g = m3a.scale(2, 2);
	m3h = m3a.rotation(90);

	for (int i = 0; i < 3; i++)
	{
		//std::cout << m3a[i].x << " " << m3a[i].y << " " << m3a[i].z << std::endl;
	}

	nassert("Matrix3 multiply", m3a, mat3(138,171,204,174,216,258,210,261,312));
	nassert("Matrix3 identity", m3d, mat3(1,0,0,0,1,0,0,0,1));
	nassert("Matrix3 translation1", m3e, mat3(1, 0, 0, 0, 1, 0, 5, 2, 1));
	nassert("Matrix3 translation2", m3f, mat3(1, 0, 0, 0, 1, 0, 5, 2, 1));
	nassert("Matrix3 scale", m3g, mat3(2, 2, 0, 2, 2, 0, 2, 2, 0));
	nassert("Matrix3 rotate", m3h, mat3(-0.44807361612, -.8939966636, 0, 0.8939966636, -0.44807361612, 0, 0, 0, 1));

	return 0;
}

//int main()
//{
//	vec3 v3a(13.5f, -48.23f, 862), v3b(5, 3.99f, -12), v3c;
//	v3a = vec3(13.5f, -48.23f, 862);
//	v3b = vec3(5, 3.99f, -12);
//	float dot3 = v3a.dot(v3b);
//
//	/*int up = min(2, 3);
//	int down = max(12, 2);
//	int c = clamp(83, 12, 82);
//	double rad = DEG_TO_RAD(30.0f);
//	double deg = RAD_TO_DEG(0.5235f);
//	int absolute = abs(-10);
//	int power = pow(2, 4);
//	bool sqrt = isPowerOfTwo(4);
//	int next = nextPowerOfTwo(64);
//	float move = moveTowards(5, 12, 1);
//
//	std::cout << "Min: " << up << std::endl;
//	std::cout << "Max: " << down << std::endl;
//	std::cout << "Clamp: " << c << std::endl;
//	std::cout << "DtoR: " << rad << std::endl;
//	std::cout << "RtoD: " << deg << std::endl;
//	std::cout << "Abs: " << absolute << std::endl;
//	std::cout << "Pow: " << power << std::endl;
//	std::cout << "SqrtOf2: " << sqrt << std::endl;
//	std::cout << "Next Power of Two: " << next << std::endl;
//	std::cout << "Move Towards: " << move << std::endl;
//
//	std::cout << "\n\n";
//
//	// addition
//	vec2 v2a(13.5f, -48.23f), v2b(5, 3.99f), v2c;
//	v2c = v2a + v2b;
//	std::cout << "Vec2 addition: " << v2c.x << "," << v2c.y << std::endl;
//
//	// subtraction
//	v2a = vec2(13.5f, -48.23f);
//	v2b = vec2(5, 3.99f);
//	v2c = v2a - v2b;
//	std::cout << "Vec2 subtraction: " << v2c.x << "," << v2c.y << std::endl;
//
//	// +=
//	v2a = vec2(13.5f, -48.23f);
//	v2b = vec2(5, 3.99f);
//	v2c = { 0,0 };
//	v2c += {10,10};
//	std::cout << "Vec2 +=: " << v2c.x << "," << v2c.y << std::endl;
//
//	// -=
//	v2a = vec2(13.5f, -48.23f);
//	v2b = vec2(5, 3.99f);
//	v2c = { 30,25 };
//	v2c -= {10, 10};
//	std::cout << "Vec2 -=: " << v2c.x << "," << v2c.y << std::endl;
//
//	// == 
//	v2a = { 0, 1 };
//	v2b = { 0, 0 };
//	if (v2a == v2b)
//	{
//		std::cout << "Vec2 ==: YEP " << std::endl;
//	}
//
//	// !=
//	v2a = { 1, 0 };
//	v2b = { 0, 0 };
//	if (v2a != v2b)
//	{
//		std::cout << "Vec2 !=: YEP " << std::endl;
//	}
//
//	// negative
//	v2a.x = 22;
//	v2c.x = -v2a.x;
//	std::cout << "Vec2 -: " << v2c.x << std::endl;
//
//	// float *
//	v2a = { 22, 89 };
//	float* val = v2a;
//	std::cout << "Vec2 float* 0: " << val[0] << std::endl;
//	std::cout << "Vec2 float* 1: " << val[1] << std::endl;
//
//	vec3 v3a, v3b, v3c;
//
//	v3a = { 10, 20, 16 };
//	v3b = { 30, 15, 12 };
//	v3c = v3a + v3b;
//	std::cout << "Vec3 addition: " << v3c.x << "," << v3c.y << "," << v3c.z << std::endl;*/
//	/*
//	// Initialization
//	//--------------------------------------------------------------------------------------
//	int screenWidth = 800;
//	int screenHeight = 450;
//
//	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
//
//	player p;
//	p.pos = { 100,100 };
//	p.speed = 100.0f;
//
//	vec2 cursor;
//
//	SetTargetFPS(60);
//	//--------------------------------------------------------------------------------------
//
//	// Main game loop
//	while (!WindowShouldClose())    // Detect window close button or ESC key
//	{
//		cursor = GetMousePosition();
//
//		// Update
//		p.distanceAway();
//
//		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
//		{
//			p.dest = cursor;
//
//			std::cout << p.d << std::endl;
//		}
//		//p.move();
//
//		if (p.pos.x + (p.cSize) > screenWidth || p.pos.x - (p.cSize) < screenWidth - screenWidth)
//		{
//			p.xreverse = true;	
//		}
//
//		if (p.pos.y + (p.cSize) > screenHeight || p.pos.y - (p.cSize) < screenHeight - screenHeight)
//		{
//			p.yreverse = true;
//		}
//		p.randomMove();
//
//		//----------------------------------------------------------------------------------
//		// TODO: Update your variables here
//		//----------------------------------------------------------------------------------
//
//		// Draw
//		//----------------------------------------------------------------------------------
//		BeginDrawing();
//
//		ClearBackground(BLACK);
//
//		//DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
//
//		p.draw();
//
//		EndDrawing();
//		//----------------------------------------------------------------------------------
//	}
//	
//	// De-Initialization
//	//--------------------------------------------------------------------------------------   
//	CloseWindow();        // Close window and OpenGL context
//						  //--------------------------------------------------------------------------------------
//						  */
//
//	/*  Assert Unit Testing  */
//
//	/*
//	nassert("true is true", true);  // PASS
//	nassert("the opposite of false is true", !false); // PASS
//	nassert("1+1=2", 1 + 1 == 2); // PASS
//	nassert("1+2=4", 1 + 2 == 4); // FAIL
//
//	std::cout << " " << std::endl;
//
//	nassert("min", 3, nmath::min(3.0f, 7.0f)); // PASS
//	nassert("max", 7, nmath::max(3.0f, 7.0f)); // PASS
//	nassert("clamp", 9, nmath::clamp(5.0f, 3.0f, 7.0f)); // FAIL
//
//	std::cout << " " << std::endl;
//
//	vec2 a = { 2,2 };
//	vec2 b = { 1,1 };
//	vec2 diff = a - b;
//
//	nassert("diff x", 1.0f, diff.x, .0001f); // PASS
//	nassert("diff y", 1.0f, diff.y, .0001f); // PASS
//	*/
//
//	/*  Interpolation  */
//
//	int screenWidth = 800;
//	int screenHeight = 450;
//
//	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
//
//	SetTargetFPS(60);
//
//	vec2 cursor;
//
//	/*  Player  */
//
//	lerpPlayer lp;
//	lp.pos = { 200,200 };
//
//	/*  Player Health  */
//
//	healthBar playerHealth;
//
//	particleSimulation ps;
//
//	/*  WayPoint  */
//
//	std::vector<vec2> wayPoint;
//
//	wayPoint.push_back(vec2{ lp.pos });
//
//	particleSpawner spawner;
//
//	/*  UI Transitions  */
//
//	button click;
//
//	Rectangle cursorRec;
//	cursorRec.height = 1;
//	cursorRec.width = 1;
//
//	/*  Easing Functions  */
//
//	easingPlayer ep;
//	ep.pos = { 400, 200 };
//	vec2 currentPos = ep.pos;
//	vec2 currentCursor = ep.pos;
//
//	// Main game loop
//	while (!WindowShouldClose())
//	{
//		cursorRec.x = GetMouseX();
//		cursorRec.y = GetMouseY();
//
//		cursor = GetMousePosition();
//
//		ep.elapse += GetFrameTime();
//
//		/*---------------------------------------------------------------------*/
//
//		//playerHealth.update();
//
//		/*---------------------------------------------------------------------*/
//
//		//ps.update();
//
//		/*---------------------------------------------------------------------*/
//
//		//spawner.create();
//
//		/*---------------------------------------------------------------------*/
//
//		//click.update(cursorRec);
//
//		/*---------------------------------------------------------------------*/
//		
//		if (ep.elapse >= ep.duration)
//		{
//			ep.elapse = 0;
//			currentPos = ep.pos;
//		}
//		
//		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
//		{
//			ep.elapse = 0;
//			currentPos = ep.pos;
//			currentCursor = cursor;
//		}
//
//		if (ep.pos <= currentCursor + 10 && ep.pos >= currentCursor - 10)
//		{ 
//			ep.moveTo(currentPos, currentCursor);
//		}
//
//		std::cout << ep.pos.x << " " << ep.pos.y << " " << ep.elapse <<  std::endl;
//
//		/*---------------------------------------------------------------------*/
//
//		/*if (lp.elapse >= lp.duration)
//		{
//			lp.elapse = 0;
//		}
//
//		//std::cout << lp.elapse << std::endl;
//
//		vec2 cursor = GetMousePosition();
//
//		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
//		{
//			wayPoint.push_back(vec2{cursor.x, cursor.y});
//		}
//
//		if (wayPoint.size() > 1)
//		{
//			lp.elapse += GetFrameTime();
//			lp.moveTo(wayPoint[lp.currentWayPoint], wayPoint[(lp.currentWayPoint + 1) % wayPoint.size()], wayPoint.size());
//		}*/
//
//		/*---------------------------------------------------------------------*/
//		/*---------------------------------------------------------------------*/
//
//		BeginDrawing();
//
//		ClearBackground(BLACK);
//
//		// DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
//
//		/*---------------------------------------------------------------------*/
//
//		/*
//		for (int i = 0; i < wayPoint.size(); i++)
//		{
//			DrawCircle(wayPoint[i].x, wayPoint[i].y, 5.0f, BLUE);
//		}*/
//
//		/*---------------------------------------------------------------------*/
//
//		//lp.draw();
//
//		/*---------------------------------------------------------------------*/
//
//		//spawner.draw();
//
//		/*---------------------------------------------------------------------*/
//
//		//ps.draw();
//
//		/*---------------------------------------------------------------------*/
//
//		//playerHealth.draw();
//
//		/*---------------------------------------------------------------------*/
//
//		//click.draw();
//
//		/*---------------------------------------------------------------------*/
//
//		ep.draw();
//
//		/*---------------------------------------------------------------------*/
//
//		EndDrawing();
//	}
//	CloseWindow();
//
//	return 0;
//}
//
