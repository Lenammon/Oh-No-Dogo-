#pragma once
#include "BaseState.h"
#include "Renderer2D.h"
#include "Font.h" 
class StateReset : public BaseState
{
public:
	StateReset(StateMachine* pStatMachine);
	~StateReset();
	void OnEnter();
	void OnUpdate(float deltaTime);
	void OnExit();
	void Draw(aie::Renderer2D* renderer);
private:
	aie::Font* m_font;
};

