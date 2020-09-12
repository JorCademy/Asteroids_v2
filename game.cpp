#include "precomp.h" // include this first in every .cpp file
#include "game.h"
#include "player.h"
#include "bullet.h"
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

	// Instantiate bullet objects
	Bullet playerBullet1;
	Bullet playerBullet2;
	Bullet playerBullet3;
	Bullet playerBullet4;
	Bullet playerBullet5;

	bool shootPlayerBullet_1 = false;
	bool shootPlayerBullet_2 = false;
	bool shootPlayerBullet_3 = false;
	bool shootPlayerBullet_4 = false;
	bool shootPlayerBullet_5 = false;

	// Making array for bullet vectors
	Bullet playerBullets[5] = { playerBullet1, playerBullet2, playerBullet3, playerBullet4, playerBullet5 };
	bool shootPlayerBullets[5] = { shootPlayerBullet_1, shootPlayerBullet_2, shootPlayerBullet_3, shootPlayerBullet_4, shootPlayerBullet_5 };

	// bool shootPlayerBullet[5] = { false, false, false, false, false };   

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
			/*
			for (int i = 0; i < sizeof(shootPlayerBullets); i++)
			{
				if (shootPlayerBullets[i] == false)
				{
					shootPlayerBullets[i];
					break;
				}
				else if (shootPlayerBullets[i] == true)
				{
					continue;
				}
			}
			*/

			// Decide which bullet to shoot
			if (shootPlayerBullet_1 == false)
			{
				shootPlayerBullet_1 = true;
			}
			/*
			else if (shootPlayerBullet_2 == false)
			{
				shootPlayerBullet_2 = true;
			}
			else if (shootPlayerBullet_3 == false)
			{
				shootPlayerBullet_3 = true;
			}
			else if (shootPlayerBullet_4 == false)
			{
				shootPlayerBullet_4 = true;
			}
			else if (shootPlayerBullet_5 == false)
			{
				shootPlayerBullet_5 = true;
			}
			*/
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

		// clear the graphics window
		screen->Clear(0);

		// Draw bullet objects

		/*
		for (int i = 0; i < sizeof(playerBullets - 1); i++)
		{
			playerBullets[i].DrawSprite(screen);
		}
		*/

		playerBullet1.DrawSprite(screen);
		playerBullet2.DrawSprite(screen);
		playerBullet3.DrawSprite(screen);
		playerBullet4.DrawSprite(screen);
		playerBullet5.DrawSprite(screen);
		
		/* Moving the bullets */

		/*
		for (int i = 0; i < sizeof(shootPlayerBullets); i++)
		{
			if (shootPlayerBullets[i] == false)
			{
				// Set the bullet's position equal to the player's position
				playerBullets[i].m_bulletPosition_x = player.position_x;
				playerBullets[i].m_bulletPosition_y = player.position_y;
				playerBullets[i].m_bulletRotation = player.frameForRotation;

				continue;
			}
			else if (shootPlayerBullets[i] == true)
			{
				playerBullets[i].m_bulletPosition_x += sin(playerBullets[i].m_bulletRotation * 10 * (PI / 180)) * deltaTime;
				playerBullets[i].m_bulletPosition_y -= cos(playerBullets[i].m_bulletRotation * 10 * (PI / 180)) * deltaTime;

				if (playerBullets[i].CheckOutOfFrame())
				{
					playerBullets[i].m_bulletPosition_x = player.position_x;
					playerBullets[i].m_bulletPosition_y = player.position_y;
				}
			}
		}
		*/

		if (!shootPlayerBullet_1)
		{
			playerBullet1.SetEqualToObject(player.position_x, player.position_y, player.frameForRotation);

			/*
			playerBullet1.m_bulletPosition_x = player.position_x;
			playerBullet1.m_bulletPosition_y = player.position_y;
			playerBullet1.m_bulletRotation = player.frameForRotation;
			*/
		}
		else if (shootPlayerBullet_1)
		{
			playerBullet1.ShootBullet(screen, deltaTime);
			/*
			playerBullet1.m_bulletPosition_x += sin(playerBullet1.m_bulletRotation * 10 * (PI / 180)) * deltaTime;
			playerBullet1.m_bulletPosition_y -= cos(playerBullet1.m_bulletRotation * 10 * (PI / 180)) * deltaTime;
			*/
			if (playerBullet1.CheckOutOfFrame())
			{
				playerBullet1.m_bulletPosition_x = player.position_x;
				playerBullet1.m_bulletPosition_y = player.position_y;

				shootPlayerBullet_1 = false;
			}
		}

		/*
		if (!shootPlayerBullet_2)
		{
			playerBullet2.m_bulletPosition_x = player.position_x;
			playerBullet2.m_bulletPosition_y = player.position_y;
			playerBullet2.m_bulletRotation = player.frameForRotation;
		}
		else if (shootPlayerBullet_2)
		{
			playerBullet2.m_bulletPosition_x += sin(playerBullet2.m_bulletRotation * 10 * (PI / 180)) * deltaTime;
			playerBullet2.m_bulletPosition_y -= cos(playerBullet2.m_bulletRotation * 10 * (PI / 180)) * deltaTime;

			if (playerBullet2.CheckOutOfFrame())
			{
				playerBullet2.m_bulletPosition_x = player.position_x;
				playerBullet2.m_bulletPosition_y = player.position_y;

				shootPlayerBullet_2 = false;
			}
		}

		if (!shootPlayerBullet_3)
		{
			playerBullet3.m_bulletPosition_x = player.position_x;
			playerBullet3.m_bulletPosition_y = player.position_y;
			playerBullet3.m_bulletRotation = player.frameForRotation;
		}
		else if (shootPlayerBullet_3)
		{
			playerBullet3.m_bulletPosition_x += sin(playerBullet3.m_bulletRotation * 10 * (PI / 180)) * deltaTime;
			playerBullet3.m_bulletPosition_y -= cos(playerBullet3.m_bulletRotation * 10 * (PI / 180)) * deltaTime;

			if (playerBullet2.CheckOutOfFrame())
			{
				playerBullet3.m_bulletPosition_x = player.position_x;
				playerBullet3.m_bulletPosition_y = player.position_y;

				shootPlayerBullet_3 = false;
			}
		}

		if (!shootPlayerBullet_4)
		{
			playerBullet4.m_bulletPosition_x = player.position_x;
			playerBullet4.m_bulletPosition_y = player.position_y;
			playerBullet4.m_bulletRotation = player.frameForRotation;
		}
		else if (shootPlayerBullet_4)
		{
			playerBullet4.m_bulletPosition_x += sin(playerBullet4.m_bulletRotation * 10 * (PI / 180)) * deltaTime;
			playerBullet4.m_bulletPosition_y -= cos(playerBullet4.m_bulletRotation * 10 * (PI / 180)) * deltaTime;

			if (playerBullet4.CheckOutOfFrame())
			{
				playerBullet4.m_bulletPosition_x = player.position_x;
				playerBullet4.m_bulletPosition_y = player.position_y;

				shootPlayerBullet_4 = false;
			}
		}

		if (!shootPlayerBullet_5)
		{
			playerBullet5.m_bulletPosition_x = player.position_x;
			playerBullet5.m_bulletPosition_y = player.position_y;
			playerBullet5.m_bulletRotation = player.frameForRotation;
		}
		else if (shootPlayerBullet_5)
		{
			playerBullet5.m_bulletPosition_x += sin(playerBullet5.m_bulletRotation * 10 * (PI / 180)) * deltaTime;
			playerBullet5.m_bulletPosition_y -= cos(playerBullet5.m_bulletRotation * 10 * (PI / 180)) * deltaTime;

			if (playerBullet5.CheckOutOfFrame())
			{
				playerBullet5.m_bulletPosition_x = player.position_x;
				playerBullet5.m_bulletPosition_y = player.position_y;

				shootPlayerBullet_5 = false;
			}
		}
		*/

		// draw a sprite
		player.DrawSprite(screen);

		/* Managing rotation and movement - Action */
		player.RotationManagement(screen);

		/* Make the player Spawn to the opposite
		   border when touching one */
		player.PlayerBorderCollision();
	}
};