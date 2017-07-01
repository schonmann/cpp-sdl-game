#pragma once
#include <string>
#include <renderer.h>
#include <vector2.h>

namespace model {
    class AbstractObject {
		private:	
            int x, y;
            int w, h;
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
            virtual AbstractObject * setLayer(int layer);
            virtual int getLayer();

			virtual AbstractObject * setX(int x);
            virtual int getX();

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

			virtual AbstractObject * setY(int y);
            virtual int getY();

			virtual AbstractObject * setDX(double dx);
            virtual double getDX();

			virtual AbstractObject * setDY(double dy);
			virtual AbstractObject * setDDX(double ddx);
			virtual AbstractObject * setDDY(double ddy);
			virtual AbstractObject * setWidth(int w);
            virtual int getWidth();
			virtual AbstractObject * setHeight(int h);
            virtual int getHeight();
    };
}
