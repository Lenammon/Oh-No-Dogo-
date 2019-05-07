#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Button.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

Application2D::Application2D()
{
	
}

Application2D::~Application2D() 
{

}

bool Application2D::startup() 
{
	
	currentState = ESTATE_MENU;// change the game states here if button is clicked then go to menu
		
	
	srand(time(0));

	for (int i = 0; i < 500; i++)
	{
		rand();
	}
	m_2dRenderer = new aie::Renderer2D();

	m_texture = new aie::Texture("./textures/numbered_grid.tga");
	//m_shipTexture = new aie::Texture("./textures/ship.png");
	
	m_gumbaTexture = new aie::Texture("./textures/gumba.png");
	//randomly display textures on the screen 
	m_tankBeige = new aie::Texture("./textures/tankBeige.png");
	m_tankBlue = new aie::Texture("./textures/tankBlue.png");
	m_tankRed = new aie::Texture("./textures/tankRed.png");
	m_tankRed = new aie::Texture("./textures/tankGreen.png");
	//dog temp need to make it randomize (another array)
	m_DogTemp = new aie::Texture("./textures/DogTemp.png");
	// image sequenceing
	

	m_font = new aie::Font("./font/consolas.ttf", 32);
	//ponts
	points = 0; 
	//m_timer = 0;
	// countdown timer
	m_timer = 30;
	// button 
	//menu buttons
	m_MenuButton = new Button("Play", "./textures/tankBlue.png", 400, 400, 120, 50);
	m_InstructButton = new Button("Instructions", "./textures/tankRed.png", 400, 600, 120, 50);
	m_BackButton = new Button("back", "./textures/tankBeige.png", 400, 200, 120, 50);
	//Button* m_button;
	//buttons-------------------------------------------------
	int height = getWindowWidth();
	int min = 10;
	int max = height - 20;
	int random = (rand() % max) + min;
	// finding the scree height need to do width
	m_button = new Button("woof", "./textures/tankBeige.png ", rand()% 200, rand()% 400, 120, 50); //put a texture for the play button 
	m_button1 = new Button("bork", "./textures/tankBlue.png", rand() % 100, rand() % 400, 120, 50);
	m_button2 = new Button(" ", "./textures/tankRed.png", rand() % 300, rand() % 200, 120, 50);
	m_button3 = new Button("missing ", "./textures/tankGreen.png", rand() % 800, rand() % 200, 120, 50);
	//---------------------------------------------------------
	return true;
}

void Application2D::shutdown()
{
	
	delete m_font;
	delete m_texture;
	//delete m_shipTexture;
	delete m_2dRenderer;
	//button
	delete m_button;
	delete m_button1;
}

void Application2D::update(float deltaTime)
{
	// button update should be done here
	//menu choice for button 
	if(m_MenuButton->Update())
	{
		std::cout << "Play button pressed" << std::endl;
		currentState = ESTATE_GAME;
	/*	if(m_button3->Update())
		{
			std::cout << "reset" << std::endl;
			currentState = ESTATE_RESET;
		}*/
		
	}
	else if(m_InstructButton->Update())
	{
		std::cout << "instruction button pressed" << std::endl;
		currentState = ESTATE_INSTRUCT;
	}
	if (m_BackButton->Update())
	{
			
			std::cout << "back button pressed" << std::endl;
			currentState = ESTATE_MENU;
	}
	
	else if (m_timer <= 0 )
	{
		std::cout << "end of game" << std::endl;
		currentState = ESTATE_ENDGAME;
	}



	//m_timer += deltaTime;
	//countdown timer
	m_timer -= deltaTime;
	// input example
	aie::Input* input = aie::Input::getInstance();

	// Update the camera position using the arrow keys
	float camPosX;
	float camPosY;
	m_2dRenderer->getCameraPos(camPosX, camPosY);

	if (input->isKeyDown(aie::INPUT_KEY_UP))
		camPosY += 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
		camPosY -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		camPosX -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		camPosX += 500.0f * deltaTime;

	m_2dRenderer->setCameraPos(camPosX, camPosY);
	//button --------------------------------
	if(m_button->Update())
	{
		std::cout << "button clicked" << std::endl;

	}
	if(m_button1->Update())
	{
		std::cout << "button clicked!" << std::endl;
	}
	if (m_button2->Update())
	{
		std::cout << "button clicked!!" << std::endl;
	}
	if (m_button3->Update())
	{
		std::cout << "you found the dog" << std::endl;
		m_button->m_posX = rand() % 400;
		m_button->m_posY = rand() % 400;

		m_button1->m_posX = rand() % 400;
		m_button1->m_posY = rand() % 400;

		m_button2->m_posX = rand() % 400;
		m_button2->m_posY = rand() % 400;

		m_button3->m_posX = rand() % 400;
		m_button3->m_posY = rand() % 400;
		points++;
	}
	else if (m_button1->Update() || m_button2->Update())
	{
		std::cout << "end of game" << std::endl; //prints out both button clicked and end of game
	}
	//-----------------------------------------------
	
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() 
{
	//draw menu with switch statment 

	// wipe the screen to the background colour
	clearScreen();
	// begin drawing sprites
	m_2dRenderer->begin();
	switch (currentState)
	{
	case ESTATE_MENU:
		// m_2dRenderer->drawText(m_font, "menu", 400, 500);
		m_MenuButton->Draw(m_2dRenderer);
		m_InstructButton->Draw(m_2dRenderer);
		break;
	case ESTATE_INSTRUCT:
		m_2dRenderer->drawText(m_font, "Find as many missing dogs before time runs out!", 0, 500 - 70);
		m_BackButton->Draw(m_2dRenderer);
		
	/*	if (m_BackButton->Update())
		{
			currentState = ESTATE_MENU;
		}*/
		break;

	case ESTATE_GAME:
		/*if(m_button3->Update())
		{
			std::cout << "new level" << std::endl;
			currentState = ESTATE_RESET;
		}
		else
		{
			currentState = ESTATE_GAME;
		}*/
		//button---------------------------------------
		m_button->Draw(m_2dRenderer);
		m_button1->Draw(m_2dRenderer);
		m_button2->Draw(m_2dRenderer);
		m_button3->Draw(m_2dRenderer);

		char fps[32];
		sprintf_s(fps, 32, "FPS: %i", getFPS());
		m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
		m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 720 - 64);

		//count down timer
		//prints out timer

		char timer[32];
		sprintf_s(timer, 32, "Timer %.0f", m_timer);
		m_2dRenderer->drawText(m_font, timer, 0, 400 - 32);
		//when timer reach zero end game.
		/*if (m_timer < 0)
		{
			std::cout << "end of game" << std::endl;
		}*/
		//points 
		char pointText[32];
		sprintf_s(pointText, 32, "Score %i", points);
		m_2dRenderer->drawText(m_font, pointText, 0, 400 - 60);
		//print out missing dog text
		m_2dRenderer->drawText(m_font, "missing!", 0, 720 - 85);
		// draw gumba 
		//m_2dRenderer->setRenderColour(1, 1, 1, 1);
		//m_2dRenderer->drawSprite(m_gumbaTexture, 100, 200, 100, 100);

		//dog temp keep this position 
		m_2dRenderer->setRenderColour(1, 1, 1, 1);
		m_2dRenderer->drawSprite(m_DogTemp, 600, 500, 100, 100);

		// draw a slightly rotated sprite with no texture, coloured yellow
		m_2dRenderer->setRenderColour(1, 1, 0, 1);
		m_2dRenderer->drawSprite(nullptr, 400, 400, 50, 50, 3.14159f * 0.25f, 1);

		break;
	case ESTATE_ENDGAME:
		m_2dRenderer->drawText(m_font, "end of game you ran out of time", 0, 400 - 60);
		char endPointText[32];
		sprintf_s(endPointText, 32, " Your Score is %i", points);
		m_2dRenderer->drawText(m_font, endPointText, 0, 400 - 100);
		break;
	}
		// done drawing sprites
		m_2dRenderer->end();
}
	//button 
	//if(m_button->Update())
//	{

	//}
//	else
	//{
		//clearScreen();
	//	m_2dRenderer->begin();

		//m_2dRenderer->setRenderColour(1, 1, 1, 1);
	//	m_2dRenderer->drawSprite(m_DogTemp, 600, 500, 100, 100);
		

		//m_2dRenderer->end();
	//}

	// demonstrate animation
	//m_2dRenderer->setUVRect(int(m_timer) % 8 / 8.0f, 0, 1.f / 8, 1.f / 8);
	//m_2dRenderer->drawSprite(m_texture, 200, 200, 100, 100);

	// demonstrate spinning sprite
	/*m_2dRenderer->setUVRect(0,0,1,1);
	m_2dRenderer->drawSprite(m_shipTexture, 600, 400, 0, 0, m_timer, 1);*/

	// draw a thin line
	/*m_2dRenderer->drawLine(300, 300, 600, 400, 2, 1);*/

	// draw a moving purple circle
	//m_2dRenderer->setRenderColour(1, 0, 1, 1);
	//m_2dRenderer->drawCircle(sin(m_timer) * 100 + 600, 150, 50);

	// draw a rotating red box
	/*m_2dRenderer->setRenderColour(1, 0, 0, 1);
	m_2dRenderer->drawBox(600, 500, 60, 20, m_timer);*/
	 

	
	// output some text, uses the last used colour