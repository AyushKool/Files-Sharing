#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

class Example : public olc::PixelGameEngine
{
public:
	Example()
	{
		sAppName = "Example";
	}
	olc::Sprite* sprite = nullptr;
	olc::Decal* decal = nullptr;

public:
	bool OnUserCreate() override
	{
		sprite = new olc::Sprite("./Rainbow.png");
		decal = new olc::Decal(sprite);
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		Clear(olc::WHITE);
		olc::vf2d mouse = { float(GetMouseX()), float(GetMouseY()) };

		//DrawSprite(mouse, sprite);

		DrawDecal(mouse, decal, { .2f, .2f });

		return true;
	}
};


int main()
{
	Example demo;
	if (demo.Construct(640, 480, 2, 2))
		demo.Start();

	return 0;
}