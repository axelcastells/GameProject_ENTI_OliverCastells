#pragma once

#include "Scene.hpp"
#include "GameObject.hpp"
#include "Vector.hpp"
#include "System.hpp"
#include <deque>
#include <math.h>
#include "InputManager.hpp"
#include "TimeManager.hpp"

#define INITIAL_LIVES 3

class PlayerController
{
private:
	GameObject* controlledObject;
	GameObject* apple;

	Scene* ownerScene;

	std::deque<Vector> body;
	GameObjectType collider;
	int rotation;

	int speed;

	int eatenApples;
	int foodInc;


	void Die();
	void Move();
	void CheckCollision();
	void InitSnake();
	void LevelUp();

public:
	PlayerController(Scene*);
	~PlayerController();

	void Update();

	long int score;
	int level;
	int lives;
};