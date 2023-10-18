#include<bits/stdc++.h>
#include<SDL2/SDL.h>
using namespace std;

void Draw_Circle_For_Game_Project(SDL_Renderer* renderer, int center_x, int center_y, int radius, SDL_Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    for (int x = center_x - radius; x <= center_x + radius; x++) {
        for (int y = center_y - radius; y <= center_y + radius; y++) {
            int distance = (x - center_x) * (x - center_x) + (y - center_y) * (y - center_y);
            if (distance <= radius * radius) {
                SDL_RenderDrawPoint(renderer, x, y);
            }
        }
    }
    SDL_RenderPresent(renderer);
}

int main(int argc,char *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window =nullptr;
    SDL_Renderer* renderer =nullptr;
     SDL_CreateWindowAndRenderer(700,500,0,&window,&renderer);
    
SDL_SetRenderDrawColor(renderer,150,0,255,0);
    SDL_RenderClear(renderer);

   SDL_Rect Rectangle_outsider;
   Rectangle_outsider.w=50;
   Rectangle_outsider.h=50;
   Rectangle_outsider.x=700/2;
   Rectangle_outsider.y=500/2;
SDL_SetRenderDrawColor(renderer,100,50,150,110);

SDL_Color color_for_circle = {150, 150,100};

Draw_Circle_For_Game_Project( renderer, 350, 250 ,50, color_for_circle );
SDL_RenderPresent(renderer);
SDL_Delay(8000);
return 0;
}