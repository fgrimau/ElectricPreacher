#include "../includes/button.h"

//Constructors
Button::Button(){}
Button::~Button(){}

//Getters
SDL_Rect Button::get_rect() const{
    return m_rect;
}

SDL_Color Button::get_background_color() const{
    return m_background_color;
}

SDL_Color Button::get_foreground_color() const{
    return m_foreground_color;
}

//Setters
void Button::set_rect(SDL_Rect rect){
    m_rect = rect;
}

void Button::set_rect(int x, int y, int w, int h){
    m_rect.x = x;
    m_rect.y = y;
    m_rect.w = w;
    m_rect.h = h;
}

void Button::set_position(SDL_Rect rect){
    m_rect.x = rect.x;
    m_rect.y = rect.y;
}

void Button::set_position(int x, int y){
    m_rect.x = x;
    m_rect.y = y;
}

void Button::set_size(SDL_Rect rect){
    m_rect.w = rect.w;
    m_rect.h = rect.h;
}

void Button::set_size(int w, int h){
    m_rect.w = w;
    m_rect.h = h;
}