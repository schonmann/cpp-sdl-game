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
            virtual void updateXMotion(float dt);
            virtual void updateYMotion(float dt);
        public:
            SDL_Texture * texture;

            AbstractObject();
            ~AbstractObject();

            virtual void draw(core::Renderer *renderer);
            virtual void update(float dt, const Uint8 * input);
            virtual SDL_Texture * getTexture();
            virtual SDL_Rect * getSrcRect();
            virtual SDL_Rect * getDestRect();
            virtual AbstractObject * loadTexture(char * path);
            virtual AbstractObject * setLayer(int layer);
            virtual int getLayer();

			virtual AbstractObject * setX(int x);
            virtual int getX();

            virtual AbstractObject * addX(int x);

            virtual AbstractObject * setS(double s);

			virtual AbstractObject * setSX(double sx);
            virtual double getSX();

			virtual AbstractObject * setSY(double sy);
            virtual double getSY();

			virtual AbstractObject * setY(int y);
            virtual int getY();

			virtual AbstractObject * setDX(double dx);
            virtual int getDX();
			virtual AbstractObject * setDY(double dy);
			virtual AbstractObject * setDDX(double ddx);
			virtual AbstractObject * setDDY(double ddy);
			virtual AbstractObject * setWidth(int w);
            virtual int getWidth();
			virtual AbstractObject * setHeight(int h);
            virtual int getHeight();
    };
}
