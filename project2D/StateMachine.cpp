#include "StateMachine.h"
#include "StateMenu.h"


StateMachine::StateMachine()
{
	m_pStateList[ESTATE_MENU] = new StateMenu(this);

}

StateMachine::~StateMachine()
{
}
void StateMachine::Update(float deltaTime)
{
	m_pStateList[m_eCurrentState]->OnUpdate(deltaTime);
}

void StateMachine::Draw(aie::Renderer2D* renderer)
{
	m_pStateList[m_eCurrentState]->Draw(renderer);
}

void StateMachine::ChangeState(EState eNewState)
{
	m_pStateList[m_eCurrentState]->OnExit();

	m_eCurrentState = eNewState;

	m_pStateList[m_eCurrentState]->OnEnter();
}
