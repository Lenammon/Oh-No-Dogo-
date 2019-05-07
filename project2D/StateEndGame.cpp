#include "StateEndGame.h"



StateEndGame::StateEndGame(StateMachine* pStateMachine) : BaseState(pStateMachine)
{
	
}


StateEndGame::~StateEndGame()
{
}

void StateEndGame::OnEnter()
{

}
void StateEndGame::OnUpdate(float deltaTime)
{

}
void StateEndGame::OnExit()
{

}
void StateEndGame::Draw(aie::Renderer2D* renderer)
{
	renderer->drawText(m_font, "end of dog game", 300, 500);
}