#include "SDL.h"
#include "SDL_image.h"


class menu{
  public:
  	menu(SDL_Renderer* r):rend(r){}
  	void startMenu(){
        LoadImage();
        ReadInput();
     }

  private:
  	SDL_Renderer* rend;
  	void LoadImage();
  	void ReadInput();
 
};