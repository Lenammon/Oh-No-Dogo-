#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Button.h"
#include "StateMachine.h"

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_texture;
	aie::Texture*		m_shipTexture;
	aie::Font*			m_font;
	 
	aie::Texture* m_gumbaTexture;
	aie::Texture* m_DogTemp;
	//replace textures with dogs
	aie::Texture* m_tankRed;
	aie::Texture* m_tankBlue;
	aie::Texture* m_tankBeige;
	aie::Texture* m_tankGreen;
	//create buttons for dog and call them correct names you dope 
	Button* m_MenuButton;
	Button* m_InstructButton;
	Button* m_BackButton;

	Button* m_button;
	Button* m_button1;
	Button* m_button2;
	Button* m_button3;

	//Button* m_buttonPressedThisFrame = nullptr; finn

	int points;
	float m_timer;
	EState currentState;
};