#include "Button.h"
#include "Renderer2D.h"
#include "Font.h"
#include<iostream>
#include "input.h"
#include"Texture.h"

Button::Button(const char* buttonText,const char* buttontexture, float x, float y, float width, float height )
{
	// store the text that will appear on the button 
	strcpy_s(m_buttonText, 64, buttonText);
	//load a font to use to display the text
	m_font = new aie::Font("./font/consolas.ttf", 24);

	//create texture dog temp 
	m_Texture = new aie::Texture(buttontexture);
	//store the buttons positions, width and height
	m_posX = x;
	m_posY = y;
	m_width = width;
	m_height = height;

}
Button::~Button()
{
	delete m_font;
	delete m_Texture;
}
void Button::Draw(aie::Renderer2D* renderer)
{
	//draw a coloured box for the button background 
	renderer->setRenderColour(0.7f, 0.5f, 0.8f, 1.0f); //rgba violet colour 
	renderer->drawSprite(m_Texture,m_posX, m_posY, m_width, m_height); //draws box
	renderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);

	//calculating the centred text
	float textWidth = m_font->getStringWidth(m_buttonText);
	float textHeight = m_font->getStringHeight(m_buttonText);
	float centredPosX = m_posX - (textWidth * 0.5f) + 2;
	float centredPosY = m_posY - (textHeight * 0.5f) + 5;
	// draw text on the button
	renderer->drawText(m_font, m_buttonText, centredPosX, centredPosY);
}
bool Button::Update()
{
	aie::Input* input = aie::Input::getInstance();
	// get mouse postion 
	int mouseX = input->getMouseX();
	int mouseY = input->getMouseY();
	//calculate the 4 sides of the button
	float left = m_posX - (m_width * 0.5f);
	float right = m_posX + (m_width * 0.5f);
	float bottom = m_posY - (m_height * 0.5f);
	float top = m_posY + (m_height * 0.5f);
	// check to see if the mouse is inside the box made by the 4 side
	if (mouseX > left && mouseX < right && mouseY > bottom && mouseY < top)
	{
		// return whether the mouse button is clicked while colliding
		return input->wasMouseButtonPressed(aie::INPUT_MOUSE_BUTTON_LEFT);
		
	}
	return false;
}