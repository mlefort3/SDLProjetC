#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <iostream>

//g++ -o main main.cpp -lSDL2 pour linux

int game2players() {
	SDL_Window *window = nullptr;
	SDL_Surface *windowSurface = nullptr;
	SDL_Surface *imageSurface1 = nullptr;
	SDL_Surface *currentImage = nullptr;
	int image;
	

	bool isRunning = true;
	SDL_Event ev;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "Video Initialization Error: " << SDL_GetError() << std::endl;
	}
	else {
		window = SDL_CreateWindow("SDL Coding Made Easy Series", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_SHOWN);
		if (window == NULL) {
			std::cout << "Window Creation Error : " << SDL_GetError() <<std::endl;
		}	
		else {

			//Window created
			windowSurface = SDL_GetWindowSurface(window);
			imageSurface1 = SDL_LoadBMP("plateau.bmp");
			currentImage = imageSurface1;
			image = 1;

			if (currentImage == NULL) {
				std::cout << "Image Creation Error : " << SDL_GetError() << std::endl;
			}
			else {

				while (isRunning) {

					while (SDL_PollEvent(&ev) != 0) {
						SDL_BlitSurface(currentImage, NULL, windowSurface, NULL);										
                            
                        if (ev.type == SDL_QUIT) {
                            isRunning = false;
                        }
						SDL_UpdateWindowSurface(window);
					}
				}
			}
		}
	}

	SDL_FreeSurface(currentImage);
	imageSurface1 = nullptr;
	currentImage = nullptr;

	SDL_DestroyWindow(window);
	window = nullptr;
	windowSurface = nullptr;
	SDL_Quit();

	return 0;
}

int main() {
    int i;
    i = game2players();
}