# Snake Game Extension: A Menu Screen

#### Running Instructions 
1. Install SDL2 Library. ex, ```sudo apt-get install libsdl2-dev```
2. Run ```cmake .. ``` and ```make ``` in the build directory

#### Changes made into project
1. Addition of menu.h and menu.cpp
2. *StartMenu* function in *render.h* to create the menu object and call *runMenu*
3. *StartMenu* is called before the game loop starts  

#### Overview of Code Structure

##### Menu Class
The *menu* class is responsible for displaying the logo and menu scenes and transition to the next possible states: start the game or exit.
When menu's public method, *runMenu*, is called by the renderer object it displays first the logo for 5 seconds, then displays the menu image until the user exits the program or starts the game.

**There are three private member functions:**
1. *LoadImage*:  uses the SDL_Renderer Object to display the image in the argument.
2. *getStateFromInput*: change the MenuState variable, which is passed by reference, based on the input read from the SDL poll event.
3. *showLogo*:  Repeatedly calls *LoadImage* to display the logo for 5 seconds.

A menu object stores the pointers of the SDL_Renderer and the image directories as private members.

##### Renderer and Game Class
The renderer class has an additional public function, *StartMenu* that creates the menu object with the pointer to the SDL_Renderer and calls the method *runMenu*. It redirects the result of startMenu to running variable in class Game. 

#### How this project satisfies the rubric:
**1. The project demonstrates an understanding of C++ functions and control structures:**
Appropriate control structures are used in menu.cpp according to situation such as If statements, do while, and while loops. Found in menu.cpp lines 35,36,53.

**2. The project accepts user input and processes the input:**
The method getStateFromInput gets input from the user and changes the state of the variable selection according to the input. Found in Menu.cpp lines 35-41.

**3. The project uses Object Oriented Programming techniques:**
Implementation of class menu

**4. Classes use appropriate access specifiers for class members:**
Members of the class menu are made private if they will be accessed only inside the class implementation.

**5. Class constructors utilize member initialization lists:**
Intialization list used for all members of the class menu. Found in menu.h line 10.

**6. Classes abstract implementation details from their interfaces:**
Each function in class menu implements what the function name describes. Example, *LoadImage* loads the image specified in the arguments while *showLogo* uses *LoadImage* to repeatedly diplay the image for five seconds. 

**7. The project makes use of references in function declarations:**
All three member variables use pointers while two functions *LoadImage* and *getStateFromInput* use pass-by-reference (the former uses a pointer *, and the later uses an lvalue reference &). Found in menu.h lines 15,16,17,21,22.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
