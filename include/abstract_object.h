#pragma once
#include <string>
#include <renderer.h>
#include <vector2.h>

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

            int layer;

        protected:
            virtual void updateDDX(float dt);
            virtual void updateDDY(float dt);
            virtual void updateDX(float dt);
            virtual void updateDY(float dt);
            virtual void updateX(float dt);
            virtual void updateY(float dt);
        public:
            SDL_Texture * texture;

            AbstractObject();
            ~AbstractObject();

            virtual void draw(core::Renderer *renderer);
            virtual void update(float dt);
            virtual SDL_Texture * getTexture();
            virtual SDL_Rect * getSrcRect();
            virtual SDL_Rect * getDestRect();
            virtual AbstractObject * loadTexture(char * path);
            virtual AbstractObject * loadTexture(SDL_Surface * surface);
            virtual AbstractObject * setLayer(int layer);
            virtual int getLayer();

			virtual AbstractObject * setX(double x);
            virtual double getX();

            virtual AbstractObject * addX(double x);
            virtual AbstractObject * addDX(double x);
            virtual AbstractObject * addDDX(double x);
            virtual AbstractObject * addY(double x);
            virtual AbstractObject * addDY(double x);
            virtual AbstractObject * addDDY(double x);

            virtual AbstractObject * setS(double s);
            
			virtual AbstractObject * setSX(double sx);
            virtual double getSX();

			virtual AbstractObject * setSY(double sy);
            virtual double getSY();

			virtual AbstractObject * setY(double y);
            virtual double getY();

			virtual AbstractObject * setDX(double dx);
            virtual double getDX();

			virtual AbstractObject * setDDX(double ddx);
            virtual double getDDX();

			virtual AbstractObject * setDY(double dy);
            virtual double getDY();

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
    };
}
