#include "precomp.h" // include this first in every .cpp file
#include "game.h"
#include "player.h"
#include "bullet.h"
#include <cstdio>
#include <iostream>

namespace Tmpl8
{
	// -----------------------------------------------------------
	// Initialize the application
	// -----------------------------------------------------------
	void Game::Init()
	{

	}

	// -----------------------------------------------------------
	// Close down application
	// -----------------------------------------------------------
	void Game::Shutdown()
	{

	}

	// Creating new PlayerShip object
	PlayerShip player;

	// Creating a new Bullet object
	// Bullet playerBullet(player.position_x, player.position_y);

	// bool shootPlayerBullet = false;

	/* Managing rotation and movement - Trigger */
	void Game::KeyDown(int key)
	{
		if (key == 79) // Start rotating to the right
		{
			player.rotatingToRight = true;
		}
		else if (key == 80) // Start rotating to the left
		{
			player.rotatingToLeft = true;
		}
		else if (key == 82) // Start moving in the chosen direction
		{
			player.movement = true;
		} 
		else if (key == 44)
		{
			player.bulletPosition_x = player.position_x;
			player.bulletPosition_y = player.position_y;
			player.bulletRotation = 360 + (player.frameForRotation * 10);
			player.shootPlayerBullet = true;
		}
	}

	/* Managing rotation and movement - Trigger */
	void Game::KeyUp(int key)
	{
		if (key == 79) // Stop rotating to the right
		{
			player.rotatingToRight = false;
		}
		else if (key == 80) // Stop rotating to the left
		{
			player.rotatingToLeft = false;
		}
		if (key == 82) // Stop moving in the chosen direction
		{
			player.movement = false;
		}
	}

	void Game::Start(Surface* screen, float deltaTime)
	{
		// clear the graphics window
		screen->Clear(0);

		// draw a sprite
		player.DrawSprite(screen);

		/* Managing rotation and movement - Action */
		player.RotationManagement(screen);

		/* Make the player Spawn to the opposite
		   border when touching one */
		player.PlayerBorderCollision();

		/* Drawing a bullet on the screen */
		if (player.shootPlayerBullet)
		{
			player.ShootBullet(screen, deltaTime);
		}
	}

	// -----------------------------------------------------------
	// Main application tick function
	// -----------------------------------------------------------
	void Game::Tick(float deltaTime)
	{
		// Setting the player speed
		player.speed = deltaTime * 0.3f;

		// Checking for keyboard events
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN)
			{
				KeyDown(event.key.keysym.scancode);
			}
			else if (event.type == SDL_KEYUP)
			{
				KeyUp(event.key.keysym.scancode);
			}
		}

		Game::Start(screen, deltaTime);
	}
};