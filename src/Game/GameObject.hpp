#pragma once
//#include "SDL\SDL.h"
#include "Vector.hpp"
//#include "SceneManager.hpp"

class GameObject
{
private:
	Vector position;
	int width, height;
	SDL_Rect* bounds;
	SDL_Texture* texture;

public:	
	GameObject(int, int, int, int, SDL_Texture*);

	void SetPosition(int, int);
	Vector GetPosition();

	virtual void Draw();
	virtual void Update();

	void UpdateBounds();
};

GameObject::GameObject(int posX, int posY, int w, int h, SDL_Texture* tex)
{
	width = w;
	height = h;

	SetPosition(posX, posY);

	texture = tex;
}

void GameObject::SetPosition(int x, int y)
{
	position.x = x;
	position.y = y;
}

Vector GameObject::GetPosition()
{
	return position;
}

void GameObject::Draw()
{
	R.RenderTexture(texture, nullptr, SDL_Rect{ 0,0, 50, 50 });
}

void GameObject::Update()
{
	UpdateBounds();
}

void GameObject::UpdateBounds()
{
	bounds = new SDL_Rect{ position.x - width / 2, position.y - height / 2, position.x + width / 2, position.y + height / 2 };
}