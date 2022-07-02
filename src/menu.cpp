#include "menu.h"
#include <iostream>

//criteria 1: a variety of control structures: while, do while, if
//criteria 6: functions do what their name describes

void menu::LoadImage(const char* directory){
     //sources:
     //1. https://lazyfoo.net/tutorials/SDL/02_getting_an_image_on_the_screen/index.php
    //2. https://caveofprogramming.com/guest-posts/drawing-an-image-sdl.html

    //load to RAM
    SDL_Surface* surface = SDL_LoadBMP(directory);
  	if( surface == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError() );
    }

    //load to graphics
    SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface);
  
    SDL_FreeSurface(surface);//free pointer
  
    //SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
      
    SDL_RenderClear(rend);       // clear the window
    SDL_RenderCopy(rend, tex, NULL, NULL); // draw the image to the window
    SDL_RenderPresent(rend);
 }


  void menu::getStateFromInput(MenuState &selection){
    //criteria 2: accepts input from user
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      selection=MenuState::exit;
    } else if (e.type == SDL_KEYDOWN) {
      if(e.key.keysym.sym) {
 
        selection=MenuState::start;
      }
     }
   }
   
  }

void menu::showLogo(){
  
     Uint32 start=SDL_GetTicks();
     Uint32 end;
  
     do{
       	SDL_Delay(500); //delay half second
     	LoadImage(logoImageDir);
        end=SDL_GetTicks();
     }while(end-start < 5000); //loop until 5 seconds passed
}

bool menu::runMenu(){
    showLogo();

    MenuState selection(MenuState::none);

    while(selection==MenuState::none){
      LoadImage(menuImageDir);
      getStateFromInput(selection);
      if(selection==MenuState::exit)
        return false;
    }

    return true; //return true if state is start

}
  
  