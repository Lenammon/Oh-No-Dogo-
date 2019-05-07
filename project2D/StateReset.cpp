#include "StateReset.h"



StateReset::StateReset(StateMachine* pStatMachine) : BaseState(pStatMachine)
{
}


StateReset::~StateReset()
{
}

void StateReset::OnEnter()
{

}
void StateReset::OnUpdate(float deltaTime)
{
}
void StateReset::OnExit()
{
}
void StateReset::Draw(aie::Renderer2D* renderer)
{
	renderer->drawText(m_font, "new level", 300, 500);
}
