#pragma once
#include <string>
#include <renderer.h>

namespace model {
    class AbstractObject {
		private:	
            int x, y;
            int w, h;
            int dx,dy;
            int ddx,ddy;
            int layer;
        public:
            SDL_Texture * texture;

            AbstractObject();
            ~AbstractObject();

            virtual void draw(core::Renderer *renderer);
            virtual void update(Uint32 dt, const Uint8 * input);
            virtual SDL_Texture * getTexture();
            virtual SDL_Rect * getSrcRect();
            virtual SDL_Rect * getDestRect();
            virtual AbstractObject * loadTexture(std::string path);
            virtual AbstractObject * setLayer(int layer);
            virtual int * getLayer();
			virtual AbstractObject * setX(int x);
			virtual AbstractObject * setY(int y);
			virtual AbstractObject * setDX(int dx);
			virtual AbstractObject * setDY(int dy);
			virtual AbstractObject * setDDX(int ddx);
			virtual AbstractObject * setDDY(int ddy);
			virtual AbstractObject * setWidth(int w);
			virtual AbstractObject * setHeight(int h);
    };
}
