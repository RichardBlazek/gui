#pragma once

class Button: public CentredLabel
{
public:
	enum class State {Normal, MouseOn, MouseDown};
private:
	State state=State::Normal;
public:
	using CentredLabel::CentredLabel;
	virtual void DrawOn(SDL::DrawBase& rend)override
	{
		if(state==State::MouseOn)
		{
			rend.Draw(position, SDL::Color(128,128,128));
		}
		else
		{
			rend.Draw(position, SDL::Color(10,180,0));
		}
		auto tmp=font.Style();
		font.SetStyle(SDL::Font::Flags::Bold);
		rend.Draw(font, text, SDL::Color(255,255,255), position);
		font.SetStyle(tmp);
	}
	bool Catch(const SDL::events::Event& evt)
	{
		if(state==State::MouseOn&&evt.Type()==SDL::events::Type::MouseButtonDown)
		{
			state=State::MouseDown;
		}
		if(state==State::MouseDown&&evt.Type()==SDL::events::Type::MouseButtonUp)
		{
			state=State::Normal;
			return true;
		}
		if(evt.Type()==SDL::events::Type::MouseMotion)
		{
			if(state==State::Normal&&position.Encloses(evt.MouseMotion().Absolute))
			{
				state=State::MouseOn;
			}
			if(state!=State::Normal&&!position.Encloses(evt.MouseMotion().Absolute))
			{
				state=State::Normal;
			}
		}
		return false;
	}
};