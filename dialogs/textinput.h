#pragma once

using InputDescription=std::pair<std::string, bool>;

std::vector<std::pair<Label, TextInputBox>> MakeDialogLabelsAndEntries(std::vector<InputDescription> label_names, uint32 input_size)
{
	std::vector<std::pair<Label, TextInputBox>> labels_entries(label_names.size());
	labels_entries[0].first=Label(label_names[0].first, SDL::Point(20,10));
	auto entry_pos=labels_entries[0].first.GetPosition().w;
	for(size_t i=1;i<labels_entries.size();++i)
	{
        labels_entries[i].first=Label(label_names[i].first, labels_entries[i-1].first.GetPosition().LeftDown()+SDL::Point(0,12));
        if(labels_entries[i].first.GetPosition().w>entry_pos)
		{
			entry_pos=labels_entries[i].first.GetPosition().w;
		}
	}
	entry_pos+=30;
	for(size_t i=0;i<labels_entries.size();++i)
	{
		labels_entries[i].second=TextInputBox(SDL::Rect(entry_pos, labels_entries[i].first.GetPosition().y-4, input_size, 0), label_names[i].second);
	}
	return func::Move(labels_entries);
}

std::vector<std::string> Dialog(const std::string& title, const std::vector<InputDescription>& label_names, const std::string& confirm, uint32 input_size)
{
	if(label_names.size()==0)
	{
		throw std::invalid_argument("gui::Dialog requires at least 1 label name");
	}
	auto labels_entries=MakeDialogLabelsAndEntries(label_names, input_size);
	auto buttonsize=font.TextSize(confirm)+SDL::Point(100,20);
	SDL::Window screen(title, SDL::Rect(SDL::Window::CenteredPos, labels_entries[0].second.GetPosition().x+input_size+30, labels_entries.back().second.GetPosition().Down()+buttonsize.y+15));
	SDL::Renderer rend(screen);
	Button submit(confirm, SDL::Rect((screen.Size().x-buttonsize.x)/2, labels_entries.back().second.GetPosition().Down()+5, buttonsize));
	SDL::TextInput::Start();
	for(;;)
	{
		for(auto& event:SDL::events::Handler())
		{
			if(event.Type()==SDL::events::Type::Quit)
			{
				return std::vector<std::string>();
			}
			else
			{
				for(auto& le:labels_entries)
				{
					le.second.Catch(event);
				}
				if(submit.Catch(event))
				{
					std::vector<std::string> result(labels_entries.size());
					for(size_t i=0;i<result.size();++i)
					{
						result[i]=labels_entries[i].second.GetText();
					}
					return func::Move(result);
				}
			}
		}
		rend.Repaint(SDL::Color(255,255,255));
		for(auto& le:labels_entries)
		{
			le.first.DrawOn(rend);
			le.second.DrawOn(rend);
		}
		submit.DrawOn(rend);
		rend.Show();
		SDL::Wait(50);
	}
}