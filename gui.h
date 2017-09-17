#pragma once

#include "../objsdl/objsdl.h"
#include "../mylibraries/nocopy.h"

namespace gui
{
	SDL::Font font;
	void Init(std::string file, uint32 size=12)
	{
		SDL::Init();
		font.Open(file, size);
	}
	#include "widget.h"
	#include "label.h"
	#include "button.h"
	#include "chars.h"
	#include "textinputbox.h"
	#include "dialog.h"
}