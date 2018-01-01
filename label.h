#pragma once

class Label: public Widget
{
protected:
	std::string text;
public:
	Label()=default;
	Label(const std::string& text, const SDL::Point& position)
		:Widget(SDL::Rect(position, font.TextSize(text))), text(text){}
	std::string GetText()const
	{
		return text;
	}
	void SetText(const std::string& str)
	{
		text=str;
	}
	virtual void DrawOn(SDL::DrawBase& rend)override
	{
		rend.Draw(font, text, SDL::Color(0,0,0), position.Position());
	}
	virtual bool Catch(const SDL::Event& evt)override
	{
		return false;
	}
};

class CentredLabel: public Label
{
public:
	CentredLabel()=default;
	CentredLabel(const std::string& text, const SDL::Rect& position)
		:Label(text, SDL::Point())
	{
		Widget::position=position;
	}
	virtual void DrawOn(SDL::DrawBase& rend)override
	{
		rend.Draw(font, text, SDL::Color(0,0,0), position);
	}
};