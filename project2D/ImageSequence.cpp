#include"ImageSequence.h"
#include "Texture.h"
ImageSequence::ImageSequence()
{
	m_level[0] = new aie::Texture("./textures/level_1.png");// not working 
	m_level[1] = new aie::Texture("./textures/level_2.png");
	m_level[2] = new aie::Texture("./textures/level_3.png");
	m_level[3] = new aie::Texture("./textures/level_4.png");
	m_level[4] = new aie::Texture("./textures/level_5.png");

}
ImageSequence::~ImageSequence()
{

}
