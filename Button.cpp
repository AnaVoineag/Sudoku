#include "Button.h"

Button::Button(float x, float y, float width, float height, sf::Font* font,
    std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color pressedColor)
{
    this->buttonState = BTN_IDLE;
    this->shape.setPosition(sf::Vector2f(x, y));
    this->shape.setSize(sf::Vector2f(width, height));

    this->font = font;
    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(40);
    this->text.setPosition(
        this->shape.getPosition().x / 2.f - this->text.getGlobalBounds().width / 2.f,
        this->shape.getPosition().y / 2.f - this->text.getGlobalBounds().height / 2.f
    );

    this->idleColor = idleColor;
    this->hoverColor = hoverColor;
    this->pressedColor = pressedColor;

    this->shape.setFillColor(this->idleColor);

}

Button::~Button()
{

}

const bool Button::isPressed() const
{
    if (this->buttonState == BTN_PRESSED)
        return true;
    return false;
}


//Functions

void Button::update(const sf::Vector2f mousePos)
{
    //Update the booleans for hover and pressed

    //Idle
    this->buttonState = BTN_IDLE;
    //Hover
    if (this->shape.getGlobalBounds().contains(mousePos))
    {
        this->buttonState = BTN_HOVER;

        //Pressed
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->buttonState = BTN_PRESSED;
        }
    }

    switch (this->buttonState)
    {
    case BTN_IDLE:
        this->shape.setFillColor(this->idleColor);
        break;

    case BTN_HOVER:
        this->shape.setFillColor(this->hoverColor);
        break;

    case BTN_PRESSED:
        this->shape.setFillColor(this->pressedColor);
        break;

    default:
        this->shape.setFillColor(sf::Color::Red);
        break;
    }
}

void Button::render(sf::RenderTarget* target)
{
    target->draw(this->shape);
}
