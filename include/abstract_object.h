#pragma once

#include <string>
#include <renderer.h>
#include <vector2.h>

#include <animation.h>

using namespace animation;

namespace model {
    class AbstractObject {
		private:	
            double x, y;
            double w, h;
            double sx, sy;
            double dx,dy;
            double ddx,ddy;

            Vector2 bounds_x,bounds_y;
            Vector2 bounds_dx,bounds_dy;
            Vector2 bounds_ddx,bounds_ddy;

            animation::Animation *animation;
            SDL_Texture * texture;

            int layer;

        protected:
            virtual void updateDDX(float dt);
            virtual void updateDDY(float dt);
            virtual void updateDX(float dt);
            virtual void updateDY(float dt);
            virtual void updateX(float dt);
            virtual void updateY(float dt);
        public:

            AbstractObject();
            ~AbstractObject();

            virtual void draw(core::Renderer *renderer);
            virtual void update(float dt);
            
            virtual SDL_Texture * getTexture();

            virtual SDL_Rect * getSrcRect();
            virtual SDL_Rect * getDestRect();

            virtual AbstractObject * loadTexture(char * path, int rows, int cols);
            virtual AbstractObject * loadTexture(SDL_Surface * surface, int rows, int cols);

            virtual AbstractObject * setLayer(int layer);
            virtual int getLayer();

            virtual AbstractObject * addX(double x);
            virtual double getX();

            virtual AbstractObject * setS(double s);
            
			virtual AbstractObject * setX(double x);
			virtual AbstractObject * setSX(double sx);
            virtual double getSX();

			virtual AbstractObject * setSY(double sy);
            virtual double getSY();

            virtual AbstractObject * addY(double x);
			virtual AbstractObject * setY(double y);
            virtual double getY();

            virtual AbstractObject * addDX(double x);
			virtual AbstractObject * setDX(double dx);
            virtual double getDX();

            virtual AbstractObject * addDDX(double x);
			virtual AbstractObject * setDDX(double ddx);
            virtual double getDDX();

            virtual AbstractObject * addDY(double x);
			virtual AbstractObject * setDY(double dy);
            virtual double getDY();

            virtual AbstractObject * addDDY(double x);
			virtual AbstractObject * setDDY(double ddy);
            virtual double getDDY();

			virtual AbstractObject * setWidth(double w);
            virtual double getWidth();

			virtual AbstractObject * setHeight(double h);
            virtual double getHeight();

            virtual AbstractObject * setBoundsX(double a, double b);
            virtual AbstractObject * setBoundsY(double a, double b);

            virtual Vector2 getBoundsX();
            virtual Vector2 getBoundsY();

            virtual AbstractObject * setBoundsDX(double a, double b);
            virtual AbstractObject * setBoundsDY(double a, double b);

            virtual Vector2 getBoundsDX();
            virtual Vector2 getBoundsDY();

            virtual Animation * getAnimation();
    };
}
