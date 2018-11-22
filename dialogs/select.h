#pragma once

size_t DialogSelect(std::string question, const std::vector<std::string>& options)
{
	std::vector<Button> buttons(options.size());
	Label q(question, SDL::Rect(10, 10, 400, font.TextSize("").y+20));
	uint32 pos=q.GetPosition().Down()+10;
	for(size_t i=0; i<options.size(); ++i)
	{
		buttons[i]=Button(options[i], SDL::Rect(10, pos, q.GetPosition().Size()));
		pos+=buttons[i].GetPosition().h+10;
	}
	SDL::Window screen("", SDL::Window::UndefinedPos, SDL::Point(420, pos), SDL::Window::Flags::Borderless);
	SDL::Renderer rend(screen);
	for(;;)
	{
		for(auto& event:SDL::events::Handler())
		{
			if(event.Type()==SDL::events::Type::Quit)
			{
				return options.size();
			}
			for(size_t i=0; i<options.size(); ++i)
			{
				if(buttons[i].Catch(event))
				{
					return i;
				}
			}
		}
		rend.Repaint(SDL::Color(255,255,255));
		q.DrawOn(rend);
		for(auto& button:buttons)
		{
			button.DrawOn(rend);
		}
		rend.Show();
		SDL::Wait(50);
	}
}