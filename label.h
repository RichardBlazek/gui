#pragma once

class Label: public Widget
{
protected:
	std::string text;
public:
	Label()=default;
	Label(const std::string& text, const SDL::Point& position)
		:Widget(SDL::Rect(position, font.TextSize(text))), text(text) {}
	Label(const std::string& text, const SDL::Rect& position)
		:Widget(position), text(text) {}
	std::string GetText()const
	{
		return text;
	}
	void SetText(const std::string& str)
	{
		text=str;
	}
	void RecalculateSize()
	{
		Widget::position=SDL::Rect(position.Position(), font.TextSize(text));
	}
	virtual void DrawOn(SDL::DrawBase& rend)override
	{
		rend.Draw(font, text, SDL::Color(0,0,0), position);
	}
	virtual bool Catch(const SDL::events::Event& evt)override
	{
		return false;
	}
};