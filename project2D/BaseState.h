//FSM 
#pragma once
#include "Renderer2D.h"
class StateMachine;

class BaseState
{
	public:
		BaseState(StateMachine* pStateMachine)
		{
			m_pStateMachine = pStateMachine;
		};

		virtual ~BaseState() {}; //destructor

		virtual void OnEnter() {};
		virtual void OnUpdate(float deltaTime) {};
		virtual void OnExit() {};

		virtual void Draw(aie::Renderer2D* renderer) {};

protected:
	StateMachine* m_pStateMachine;
};