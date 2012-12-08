#include "Main.h"

SDL_Color textColor = { 255, 255, 255 };
SDL_Event Event;
SDL_Surface *screen = NULL;

int main(int argc, char* args[])
{
    bool quit = false;

    //Initialize
    if(init() == false)
    {
        return 1;    
    }
	if(load() == false)
	{
		return 1;
	}
	
	while(quit == false)
    {
		//While there's an event to handle
        while(SDL_PollEvent(&Event))
        {
			//If the user has Xed out the window
            if(Event.type == SDL_QUIT)
            {
                //Quit the program
                quit = true;
            }    
			else if (Event.type == SDL_KEYDOWN)
			{
				if (Event.key.keysym.sym == SDLK_ESCAPE)
				{
					quit = true;
				}
			}
			else if (Event.type == SDL_MOUSEBUTTONDOWN)
			{
				//Event.button.x/y
			}
        }
  
    
		//Update the screen
		if(SDL_Flip(screen) == -1)
		{
			return 1;    
		}
    }

    //Quit SDL
    SDL_Quit();
    
    return 0;    
}

bool init()
{

    //Initialize all SDL subsystems
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        return false;    
    }
    
    //Set up the screen
    screen = SDL_SetVideoMode(600, 400, 32, SDL_SWSURFACE);
    
    //If there was an error in setting up the screen
    if(screen == NULL)
    {
        return false;    
    }
    
    //Set the window caption
    SDL_WM_SetCaption("chemPowder", NULL);
    
    //If everything initialized fine
    return true;
}

bool load()
{
	
    //If everything loaded fine
    return true;    
}

void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination)
{
    //Make a temporary rectangle to hold the offsets
    SDL_Rect offset;
    
    //Give the offsets to the rectangle
    offset.x = x;
    offset.y = y;
	//Blit the surface
    SDL_BlitSurface( source, NULL, destination, &offset );
}