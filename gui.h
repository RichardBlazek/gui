#pragma once

#include "../objsdl/objsdl.h"
#include "../mylibraries/nocopy.h"

namespace gui
{
	SDL::Font font;
	class Init
	{
	private:
		SDL::Init sdl;
	public:
		Init(std::string file, uint32 size=12)
		{
			font=SDL::Font(file, size);
		}
	};
	#include "widget.h"
	#include "label.h"
	#include "button.h"
	#include "chars.h"
	#include "textinputbox.h"
	#include "dialogs.h"
}