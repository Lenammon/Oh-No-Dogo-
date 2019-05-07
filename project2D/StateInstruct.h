#pragma once
#include "BaseState.h"
#include "Renderer2D.h"
#include"Font.h"
class StateInstruct: public  BaseState
{
public:
	StateInstruct(StateMachine* pStateMachine);
	~StateInstruct();
	void OnEnter();
	void OnUpdate(float deltaTime);
	void OnExit();
	void Draw(aie::Renderer2D* renderer);
private:
	aie::Font* m_font;
};

