#include "precomp.h" // include this first in every .cpp file
#include "game.h"
#include "player.h"
#include "bullet.h"
#include "asteroid.h"
#include "enemyship.h"
#include "enemybullet.h"

namespace Tmpl8
{
	Asteroid* asteroidsInScene[28];

	PlayerShip* player = new PlayerShip(5.0);

	EnemyShip* enemyShip = new EnemyShip(5.0);

	Bullet* playerBullet = new Bullet(player->m_position_x, player->m_position_y, player->m_rotation);

	EnemyBullet* enemyBullet = new EnemyBullet();

	void Game::Init()
	{
		int coordinate_index = 0;

		int angle_index = 0;
		
		float speed_offset = 0.3;
		
		int asteroid_size = 0;

		for (int i = 0; i < sizeof(asteroidsInScene - 1); i++)
		{
			coordinate_index += 3;
			
			asteroid_size += 1;
			
			speed_offset += 0.3;
			
			angle_index += 3;

			if (coordinate_index > 13)
			{
				coordinate_index = 0;
			}
			
			if (asteroid_size > 3)
			{
				asteroid_size = 1;
			}
			
			if (speed_offset > 0.6)
			{
				speed_offset = 0.3;
			}
			
			if (angle_index > 2)
			{
				angle_index = 0;
			}

			asteroidsInScene[i] = new Asteroid(angle_index, coordinate_index, speed_offset, player->m_position_x, player->m_position_y, 40, 40, asteroid_size);
		}
	}

	void Game::Shutdown()
	{
		delete player;
		delete enemyShip;
		delete playerBullet;
		delete enemyBullet;

		for (int i = 0; i < sizeof(asteroidsInScene - 1); i++)
		{
			delete asteroidsInScene[i];
		}
	}

	void Game::KeyDown(int key)
	{
		if (key == 79)
		{
			player->m_rotatingToRight = true;
		}
		else if (key == 80)
		{
			player->m_rotatingToLeft = true;
		}
		else if (key == 82)
		{
			player->m_movement = true;
		}
		else if (key == 44)
		{
			if (m_StartMenu)
			{
				m_StartMenu = false;

				player->m_score = 0;

				Reset();
			}
			else if (m_GameOver)
			{
				player->m_lives = 3;

				player->m_GameOver = false;

				m_StartMenu = true;

				m_GameOver = false;
			}
			else
			{
				m_shootPlayerBullet = true;
			}
		}
	}

	void Game::KeyUp(int key)
	{
		if (key == 79)
		{
			player->m_rotatingToRight = false;
		}
		else if (key == 80)
		{
			player->m_rotatingToLeft = false;
		}
		if (key == 82)
		{
			player->m_movement = false;
		}
		else if (key == 44)
		{
			m_shootPlayerBullet = false;
		}
	}

	/* Source reference, converting int to char*: https://www.tek-tips.com/viewthread.cfm?qid=1088107 */
	void Game::DisplayScore(Surface* score)
	{
		char* scoreToChar = new char[10];

		itoa(player->m_score, scoreToChar, 10);

		asteroidsFont->Print(screen, scoreToChar, 50, 10, true);
	}
	
	void Game::DrawAsteroids()
	{
		for (int i = 0; i < sizeof(asteroidsInScene - 1); i++)
		{
			asteroidsInScene[i]->DrawSprite(screen);

			asteroidsInScene[i]->Movement();

			asteroidsInScene[i]->RotationSprite();
		}
	}

	void Game::TimerManagement()
	{
		if (m_timer > 15000)
		{
			enemyShip->m_startMoving = true;

			enemyBullet->m_enemyShip_moving = true;

			m_timer = 0;
		}
	}

	void Game::CollisionCheck()
	{
		player->m_hitByEnemyShip = enemyShip->CollisionDetection(player->m_position_x, player->m_position_y, 40, 40);

		playerBullet->m_hitByEnemyShip = enemyShip->CollisionDetection(playerBullet->m_position_x, playerBullet->m_position_y, 30, 30);

		enemyBullet->m_hitByPlayer = player->CollisionDetection(enemyBullet->m_position_x, enemyBullet->m_position_y, 30, 30, enemyBullet->m_hitByPlayer, player->m_position_x, player->m_position_y, 40, 40);

		if (enemyShip->CollisionDetection(player->m_position_x, player->m_position_y, 40, 40))
		{
			player->m_lives -= 1;
		}

		if (enemyShip->CollisionDetection(playerBullet->m_position_x, playerBullet->m_position_y, 30, 30))
		{
			player->m_score += 200;
		}

		if (player->CollisionDetection(enemyBullet->m_position_x, enemyBullet->m_position_y, 30, 30, enemyBullet->m_hitByPlayer, player->m_position_x, player->m_position_y, 40, 40))
		{
			player->m_lives -= 1;
		}

		for (int i = 0; i < sizeof(asteroidsInScene - 1); i++)
		{
			player->m_hitByAsteroid = asteroidsInScene[i]->CollisionDetection(player->m_position_x, player->m_position_y, 40, 40);

			playerBullet->m_hitByAsteroid = asteroidsInScene[i]->CollisionDetection(playerBullet->m_position_x, playerBullet->m_position_y, 30, 30);

			if (asteroidsInScene[i]->CollisionDetection(playerBullet->m_position_x, playerBullet->m_position_y, 30, 30))
			{
				if (asteroidsInScene[i]->m_size == 3)
				{
					player->m_score += 20;
				}
				else if (asteroidsInScene[i]->m_size == 2)
				{
					player->m_score += 50;
				}
				else
				{
					player->m_score += 100;
				}
			}

			asteroidsInScene[i]->HitByPlayer();

			if (asteroidsInScene[i]->CollisionDetection(player->m_position_x, player->m_position_y, 40, 40))
			{
				if (asteroidsInScene[i]->m_size == 3)
				{
					player->m_score += 20;
				}
				else if (asteroidsInScene[i]->m_size == 2)
				{
					player->m_score += 50;
				}
				else
				{
					player->m_score += 100;
				}

				player->m_position_x = player->m_START_X;
				player->m_position_y = player->m_START_Y;

				player->m_lives -= 1;
			}

			playerBullet->CheckCollision();
		}

		player->CheckCollision();

		playerBullet->CheckCollision();

		enemyBullet->CheckCollision(enemyShip->m_position_x, enemyShip->m_position_y);

		enemyShip->HitByPlayer();

		if (!enemyShip->m_startMoving)
		{
			enemyBullet->m_enemyShip_moving = false;
		}
	}

	void Game::Tick(float deltaTime)
	{
		for (int i = 0; i < sizeof(asteroidsInScene - 1); i++)
		{
			asteroidsInScene[i]->m_speed = deltaTime;
		}

		m_timer += deltaTime;

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

		if (m_StartMenu)
		{
			StartMenu();
		} 
		else if (player->m_GameOver)
		{
			m_GameOver = true;
			GameOver(screen);
		}
		else
		{
			PlayGame(screen, deltaTime);
		}
	}

	void Game::PlayGame(Surface* screen, float deltaTime)
	{
		screen->Clear(0);

		DrawAsteroids();

		player->DrawLives(screen);

		DisplayScore(screen);

		playerBullet->DrawSprite(screen, "assets/bullet.png", playerBullet->m_position_x, playerBullet->m_position_y);
		playerBullet->ShootBullet(screen, deltaTime, player->m_position_x, player->m_position_y, player->m_frameForRotation, m_shootPlayerBullet);

		enemyBullet->DrawSprite(screen, "assets/bullet.png", enemyBullet->m_position_x, enemyBullet->m_position_y);
		enemyBullet->ShootBullet(screen, deltaTime, enemyShip->m_position_x, enemyShip->m_position_y);

		TimerManagement();

		enemyShip->DrawSprite(screen);

		enemyShip->Movement();

		player->DrawSprite(screen);

		player->RotationManagement(screen);

		player->PlayerBorderCollision();

		CollisionCheck();
	}

	void Game::StartMenu()
	{
		static Sprite s_asteroidsLogo(new Surface("assets/asteroids-logo.png"), 1);
		static Sprite s_startMessage(new Surface("assets/start-message.png"), 1);
		
		screen->Clear(0);
		
		DrawAsteroids();

		s_asteroidsLogo.Draw(screen, 100, 50);
		s_startMessage.Draw(screen, 150, 350);
		
		asteroidsFont->Print(screen, "BY NICK JORDAN", 275, 200, true);

		if (!m_StartMenu)
		{
			Reset();
		}
	}

	void Game::GameOver(Surface* screen)
	{
		static Sprite s_gameOverText(new Surface("assets/game-over.png"), 1);
		static Sprite s_startNewGameText(new Surface("assets/start-new-game.png"), 1);

		screen->Clear(0);

		DisplayScore(screen);

		DrawAsteroids();

		s_gameOverText.Draw(screen, 100, 120);
		s_startNewGameText.Draw(screen, 150, 230);
	}

	void Game::Reset()
	{
		player->Reset();

		for (int i = 0; i < sizeof(asteroidsInScene - 1); i++)
		{
			asteroidsInScene[i]->Reset();
		}

		enemyShip->Reset();

		m_timer = 0;
	}
};