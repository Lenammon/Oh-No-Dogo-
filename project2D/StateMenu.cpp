#include "StateMenu.h"



StateMenu::StateMenu(StateMachine* pStateMachine) : BaseState(pStateMachine)
{
	m_font = new aie::Font("./font/consolas.ttf", 32);
}

StateMenu::~StateMenu()
{
}

void StateMenu::OnEnter()
{

}
void StateMenu::OnUpdate(float deltaTime)
{

}
void StateMenu::OnExit()
{

}
void StateMenu::Draw(aie::Renderer2D* renderer)
{
	renderer->drawText(m_font, "menu", 400, 500);
}