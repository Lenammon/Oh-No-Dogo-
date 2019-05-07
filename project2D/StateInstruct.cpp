#include "StateInstruct.h"



StateInstruct::StateInstruct(StateMachine* pStateMachine) : BaseState(pStateMachine)
{

}


StateInstruct::~StateInstruct()
{
}
void StateInstruct::OnEnter()
{

}
void StateInstruct::OnUpdate(float deltaTime)
{

}
void StateInstruct::OnExit()
{

}
void StateInstruct::Draw(aie::Renderer2D* renderer)
{
	renderer->drawText(m_font, "this is a game", 300, 500);
}