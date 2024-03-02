#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>

int main(){
    // Initialize SDL
    int result = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
    /// Sjekker feil
    if(result != 0){
        printf("Noko gekk galt %s\n", SDL_GetError());
    }   
    printf("Me fekk SDL\n");

    //Open a window
    SDL_Window *vindu = SDL_CreateWindow("VINDUET", 0, 0, 500, 500, 0);
    if(!vindu){
        printf("Noko gekk galt me vinduet\n", SDL_GetError());
    }

    // Fill the screen
    /// Hente/lage en SDL_Surface vi kan tegne på 
    SDL_Surface *skjerm = SDL_GetWindowSurface(vindu);
    if(!skjerm){
        printf("Kompis, det e noko galt med å heinte surface %s\n", SDL_GetError());
    }

    // Lag ein main loop

    // Animer farge eneringar på skjermen
    unsigned int color = 0;
    while(1){
        int red = 255;
        int blue = color % 255;
        int kombofarge = red | blue;

        if(SDL_FillRect(skjerm, NULL, kombofarge)){
            printf("Feil me fyllinga, smh... %s\n", SDL_GetError());
        }

        if(SDL_UpdateWindowSurface(vindu) != 0){
            printf("Fekk ikke oppdatert %s\n", SDL_GetError());
        }

    color += 1;
    SDL_Event min_hendelse;
    while(SDL_PollEvent(&min_hendelse)){
        if(min_hendelse.type == SDL_Quit){
            exit(1);
        }
        if(min_hendelse.type == SDL_KEYDOWN){
            if(min_hendelse.keysym.sym == SDLK_ESCAPE){
                printf("Escape\n");
                exit(0);
            } 
        }
    }
    }
    // Håndter ein heindelse

}