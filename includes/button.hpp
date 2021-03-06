#ifndef button_h
    #define button_h

/**
    name : button.h
    purpose : Defines a button and its methods (with animations, ...)
*/

#include <iostream>
#include <SDL2/SDL.h>

#include "screen.hpp"
#include "widgets.hpp"

class Button: public Widget{
    public:
        //Constructors
        Button();
        virtual ~Button();

        //Operators
        Button& operator=(const Button&);

        //Getters
        SDL_Rect get_rect() const;
        SDL_Color get_background_color() const;
        SDL_Color get_foreground_color() const;
        SDL_Color get_contour_color() const;
        SDL_Rect get_text_position(SDL_Surface*) const;
        std::string get_text() const;
        std::string get_action_type() const;
        std::string get_action_operand() const;

        //Setters
        void set_rect(SDL_Rect rect);
        void set_rect(int x, int y, int w, int h);
        void set_position(SDL_Rect pos);
        void set_position(int x, int y);
        void set_text_pos(std::string pos);
        void set_text_pos(int x, int y);
        void set_text_color(int r, int g, int b, int a=255);
        void set_background_color(int r, int g, int b, int a=255);
        void set_contour_color(int r, int g, int b);
        void set_size(SDL_Rect size);
        void set_size(int w, int h);
        void set_text(std::string text);
        void set_action_type(std::string action_type, std::string action_operand="");

        void move(int, int);
        void set_text_offset(int, int);
        void resize(int, int);

        //Others
        int draw(Screen*  screen) override;
        int update(SDL_Event* event, Screen* screen) override;

        int update_layout(Screen*, TTF_Font*);
        int draw_contour(SDL_Surface*, SDL_Color);
        bool collide(SDL_Rect) const;
        bool collide(int x, int y) const;

    private:
        SDL_Rect* m_rect;
        SDL_Rect* m_text_rect;
        SDL_Rect* m_absolute_text_position;
        SDL_Rect* m_text_offset;
        int m_text_position;
        std::string m_action_type;
        std::string m_action_operand;
        bool m_hover;

        SDL_Color m_background_color;
        SDL_Color m_foreground_color;
        SDL_Color m_contour_color;

        SDL_Texture* m_background_texture;
        SDL_Texture* m_foreground_texture;

        std::string m_text;
        bool m_pos_as_text;
        TTF_Font* m_font;
};

#endif
