#pragma once
#include "Renderer2D.h"
#include "Font.h"

class Button
{
public:
	Button(const char* buttonText, const char* buttontexture,  float x, float y, float width, float height);
	~Button();
	
	void Draw(aie::Renderer2D* renderer);

	bool Update();

	//font and text for the button
	aie::Font* m_font;
	char m_buttonText[64];
	//button position, width and height
	float m_posX;
	float m_posY;
	float m_width;
	float m_height;

	//add Texture pointer
	aie::Texture* m_Texture;

};