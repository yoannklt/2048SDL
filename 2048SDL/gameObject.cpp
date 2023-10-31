#include "gameObject.hpp"

GameObject::GameObject()
{
	src.x = src.y = 0;
	src.w = 64;
	src.h = 64;

	dest.x = 0;
	dest.y = 0;
	dest.w = src.w * 2;
	dest.h = src.h * 2;
}




GameObject::~GameObject()
{}