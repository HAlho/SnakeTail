#include "menu.h"
  	
void menu::LoadImage(){


      //load to ram
    SDL_Surface* surface = IMG_Load("snake-icon.png");
      //load to graphics
    SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
      
    //draw
      SDL_RenderClear(rend);       // clear the window

      SDL_RenderCopy(rend, tex, NULL, NULL); // draw the image to the window
      SDL_RenderPresent(rend);

    
 }
  void menu::ReadInput(){
  	while(true){
    	//if(key is space)
      		//break;
    }
  }
  
  