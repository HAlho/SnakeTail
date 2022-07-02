#include "SDL.h"

enum class MenuState{start, none, exit};

//criteria 3: use of OOP
//criteria 4: members are organized into public and private
//criteria 5: initializer list used
class menu{
  public:
  	menu(SDL_Renderer* r, const char* l, const char* m):rend(r),logoImageDir(l),menuImageDir(m){}
        
  	bool runMenu();

  private:
  	SDL_Renderer* rend;
  	const char* logoImageDir;
    const char* menuImageDir;
    void showLogo();
    //criteria 7: two functions that use pass by reference
    void LoadImage(const char* directory);
  	void getStateFromInput(MenuState &selection);
 
};