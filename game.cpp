#include "precomp.h" // include this first in every .cpp file
#include "game.h"
#include "player.h"
#include "bullet.h"
#include "asteroid.h"
#include "enemyship.h"
#include "enemybullet.h"
#include <iostream>

namespace Tmpl8
{
	PlayerShip player;

	EnemyShip enemyShip;

	// Bullet playerBullets[5] = { Bullet(player.m_position_x, player.m_position_y, player.m_rotation) };

	Bullet playerBullet = Bullet(player.m_position_x, player.m_position_y, player.m_rotation);
	bool shootPlayerBullet = false;

	EnemyBullet enemyBullet;
	bool shootEnemyBullet = false;

	int timer = 0;

	/* Find out how to make dynamic asteroid objects using an array of objects */
	Asteroid newAsteroid1(0, 0, 0.3, player.m_position_x, player.m_position_y, 40, 40, 3);
	Asteroid newAsteroid2(1, 1, 0.2, player.m_position_x, player.m_position_y, 40, 40, 2);
	Asteroid newAsteroid3(2, 2, 0.3, player.m_position_x, player.m_position_y, 40, 40, 2);
	Asteroid newAsteroid4(0, 3, 0.2, player.m_position_x, player.m_position_y, 40, 40, 3);
	Asteroid newAsteroid5(1, 4, 0.3, player.m_position_x, player.m_position_y, 40, 40, 3);
	Asteroid newAsteroid6(2, 5, 0.2, player.m_position_x, player.m_position_y, 40, 40, 2);
	Asteroid newAsteroid7(0, 6, 0.3, player.m_position_x, player.m_position_y, 40, 40, 3);
	Asteroid newAsteroid8(1, 7, 0.2, player.m_position_x, player.m_position_y, 40, 40, 2);
	Asteroid newAsteroid9(0, 8, 0.3, player.m_position_x, player.m_position_y, 40, 40, 3);
	Asteroid newAsteroid10(1, 9, 0.2, player.m_position_x, player.m_position_y, 40, 40, 2);
	Asteroid newAsteroid11(2, 10, 0.3, player.m_position_x, player.m_position_y, 40, 40, 2);
	Asteroid newAsteroid12(0, 11, 0.2, player.m_position_x, player.m_position_y, 40, 40, 3);
	Asteroid newAsteroid13(1, 12, 0.3, player.m_position_x, player.m_position_y, 40, 40, 3);
	Asteroid newAsteroid14(2, 13, 0.2, player.m_position_x, player.m_position_y, 40, 40, 2);
	Asteroid newAsteroid15(0, 0, 0.3, player.m_position_x, player.m_position_y, 40, 40, 3);
	Asteroid newAsteroid16(1, 1, 0.2, player.m_position_x, player.m_position_y, 40, 40, 2);
	Asteroid newAsteroid17(2, 2, 0.3, player.m_position_x, player.m_position_y, 40, 40, 3);
	Asteroid newAsteroid18(0, 3, 0.2, player.m_position_x, player.m_position_y, 40, 40, 2);
	Asteroid newAsteroid19(1, 4, 0.3, player.m_position_x, player.m_position_y, 40, 40, 3);
	Asteroid newAsteroid20(2, 5, 0.2, player.m_position_x, player.m_position_y, 40, 40, 2);
	Asteroid newAsteroid21(0, 6, 0.2, player.m_position_x, player.m_position_y, 40, 40, 3);
	Asteroid newAsteroid22(1, 7, 0.3, player.m_position_x, player.m_position_y, 40, 40, 3);
	Asteroid newAsteroid23(2, 8, 0.2, player.m_position_x, player.m_position_y, 40, 40, 2);
	Asteroid newAsteroid24(0, 9, 0.3, player.m_position_x, player.m_position_y, 40, 40, 3);
	Asteroid newAsteroid25(1, 10, 0.2, player.m_position_x, player.m_position_y, 40, 40, 2);
	Asteroid newAsteroid26(2, 11, 0.3, player.m_position_x, player.m_position_y, 40, 40, 3);
	Asteroid newAsteroid27(0, 12, 0.2, player.m_position_x, player.m_position_y, 40, 40, 2);
	Asteroid newAsteroid28(1, 13, 0.3, player.m_position_x, player.m_position_y, 40, 40, 3);

	Asteroid asteroidsInScene[28] = {
		newAsteroid1, newAsteroid2, newAsteroid3, newAsteroid4,
		newAsteroid5, newAsteroid6, newAsteroid7, newAsteroid8,
		newAsteroid9, newAsteroid10, newAsteroid11, newAsteroid12,
		newAsteroid13, newAsteroid14, newAsteroid15, newAsteroid16, 
		newAsteroid17, newAsteroid18, newAsteroid19, newAsteroid20, 
		newAsteroid21, newAsteroid22, newAsteroid23, newAsteroid24, 
		newAsteroid25, newAsteroid26, newAsteroid27, newAsteroid28
	};

	/*
	Asteroid* asteroidsInScene[2] = {
		new Asteroid(2, 2, 0.2, player.m_position_x, player.m_position_y, 40, 40, 2), 
		new Asteroid(1, 1, 0.3, player.m_position_x, player.m_position_y, 40, 40, 1)
	};
	*/

	void Game::Init()
	{
		int coordinate_index = 0;
		int angle_index = 0;
		float speed_offset = 0.02;
		int asteroid_size = 0;

		int sizes[3] = { 1, 2, 3 };

		/*
		for (int i = 0; i < sizeof(asteroidsInScene - 1); i++)
		{
			coordinate_index += 3;
			asteroid_size++;
			speed_offset++;
			angle_index++;

			if (coordinate_index > 13)
			{
				coordinate_index = 0;
			}

			if (asteroid_size > 3)
			{
				asteroid_size = 1;
			}

			if (speed_offset > 0.03)
			{
				speed_offset = 0.02;
			}

			if (angle_index > 3)
			{
				angle_index = 0;
			}

			// asteroidsInScene[i] = Asteroid(angle_index, coordinate_index, speed_offset, player.m_position_x, player.m_position_y, 40, 40, asteroid_size);
		}
		*/
	}


	void Game::Shutdown()
	{}

	void Game::KeyDown(int key)
	{
		if (key == 79) 
		{
			player.m_rotatingToRight = true;
		}
		else if (key == 80) 
		{
			player.m_rotatingToLeft = true;
		}
		else if (key == 82) 
		{
			player.m_movement = true;
		}
		else if (key == 44)
		{
			if (m_GameOver)
			{
				player.m_lives = 3;
				player.m_GameOver = false;
				m_GameOver = false;
			}
			else
			{
				shootPlayerBullet = true;
			}
		}
	}

	void Game::KeyUp(int key)
	{
		if (key == 79) 
		{
			player.m_rotatingToRight = false;
		}
		else if (key == 80)
		{
			player.m_rotatingToLeft = false;
		}
		if (key == 82) 
		{
			player.m_movement = false;
		}
		else if (key == 44)
		{
			shootPlayerBullet = false;
		}
	}

	void Game::Tick(float deltaTime)
	{
		for (int i = 0; i < sizeof(asteroidsInScene - 1); i++)
		{
			asteroidsInScene[i].m_speed = deltaTime;
		}

		timer += deltaTime;

		player.m_speed = deltaTime * 0.3;
		enemyShip.m_speed = deltaTime * 0.3;

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

		if (player.m_GameOver)
		{
			m_GameOver = true;
			GameOver(screen, deltaTime);
		}
		else
		{
			/* A reset function might be neat */
			Start(screen, deltaTime);
		}
	}

	/* Maybe I can divide the code within this function into member functions, 
	to make the code easier to read */
	void Game::Start(Surface* screen, float deltaTime)
	{
		screen->Clear(0);

		// Draw Asteroids
		for (unsigned int i = 0; i < sizeof(asteroidsInScene) / sizeof(asteroidsInScene[0]); i++)
		{
			asteroidsInScene[i].DrawSprite(screen);
			asteroidsInScene[i].Movement();
			asteroidsInScene[i].RotationSprite();
		}

		player.DrawLives(screen);

		playerBullet.DrawSprite(screen, "assets/bullet.png", playerBullet.m_bulletPosition_x, playerBullet.m_bulletPosition_y);
		playerBullet.ShootBullet(screen, deltaTime, player.m_position_x, player.m_position_y, player.m_frameForRotation, shootPlayerBullet);

		enemyBullet.DrawSprite(screen, "assets/bullet.png", enemyBullet.m_position_x, enemyBullet.m_position_y);
		enemyBullet.ShootBullet(screen, deltaTime, enemyShip.m_position_x, enemyShip.m_position_y, shootEnemyBullet);

		// Timer Management
		if (timer > 15000)
		{
			enemyShip.startMoving = true;
			enemyBullet.enemyShip_moving = true;

			timer = 0;
		}

		enemyShip.DrawSprite(screen);

		enemyShip.Movement();

		player.DrawSprite(screen);

		player.RotationManagement(screen);

		player.PlayerBorderCollision();

		// Collision Check
		player.m_hitByEnemyShip = enemyShip.CollisionDetection(player.m_position_x, player.m_position_y, 40, 40);
		playerBullet.m_hitByEnemyShip = enemyShip.CollisionDetection(playerBullet.m_bulletPosition_x, playerBullet.m_bulletPosition_y, 30, 30);

		for (unsigned int i = 0; i < sizeof(asteroidsInScene) / sizeof(asteroidsInScene[0]); i = i + 1)
		{
			player.m_hitByAsteroid = asteroidsInScene[i].CollisionDetection(player.m_position_x, player.m_position_y, 40, 40);
			playerBullet.m_hitByAsteroid = asteroidsInScene[i].CollisionDetection(playerBullet.m_bulletPosition_x, playerBullet.m_bulletPosition_y, 30, 30);
			asteroidsInScene[i].HitByPlayer();

			if (asteroidsInScene[i].CollisionDetection(player.m_position_x, player.m_position_y, 40, 40))
			{
				printf("Asteroid hit");
				player.m_lives -= 1;
			}

			/* Still have to make sure that the bullet spawns back to the player's position
			when it has hit an object */
		}

		player.CheckCollision();
		playerBullet.CheckCollision();

		enemyShip.HitByPlayer();
	}

	void Game::GameOver(Surface* screen, float deltaTime)
	{
		screen->Clear(0);

		/* Making the Game Over message appear (maybe by using a sprite first) */
		screen->Print("Game Over!", 400, 250, 0xffffff);
		screen->Print("Press SPACE to play again!", 350, 300, 0xffffff);
	}
};