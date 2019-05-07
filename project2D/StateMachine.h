#pragma once
#include "Renderer2D.h"
#include "BaseState.h"
enum EState
{
	ESTATE_MENU,
	ESTATE_INSTRUCT,
	ESTATE_GAME,
	ESTATE_ENDGAME,
	ESTATE_RESET,
	

	ESTATE_COUNT, // counts how many states there are.
	ESTATE_NONE
};
class StateMachine
{
public:
	StateMachine();
	~StateMachine();
	void Update(float deltaTime);
	void Draw(aie::Renderer2D* renderer);

	void ChangeState(EState eNewSate);

	private :
		BaseState* m_pStateList[ESTATE_COUNT];
		EState m_eCurrentState;
};

