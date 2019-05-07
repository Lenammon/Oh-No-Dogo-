#include "StateBack.h"



StateBack::StateBack(StateMachine* pStateMachine) : BaseState(pStateMachine)
{
	m_font = new aie::Font("./font/consolas.tff", 32);
}

StateBack::~StateBack()
{
}

void StateBack::OnEnter()
{
 
}
void StateBack::OnUpdate(float deltaTime)
{

}

void StateBack::OnExit()
{

}

void StateBack::Draw(aie::Renderer2D* renderer)
{
	renderer->drawText(m_font, "back", 400, 500);
}

