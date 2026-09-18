#include "../include/esclib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Bullet 
{
	Vector2i pos;
	char display;
};

int main(void) 
{
	srand((unsigned int)time(NULL));

	InitTui(60,TUI_DYNAMIC);
	Vector2i playerPos = (Vector2i){ GetTuiDimensions().x / 2, GetTuiDimensions().y / 2 };
	HideCursor();
	

	size_t	bulletsCount = 0;
	Vector2i* bullets = NULL;
	int max = GetTuiDimensions().x;

	

	while(true)
	{
		BeginFrame();
		ClearTui(BLACK,TERMWHITE);
		
		if(IsKeyPressed('w')) 
		{
			playerPos.y -= 1;
		}
		if(IsKeyPressed('a'))		
		{
			playerPos.x -= 2;
		}
		if(IsKeyPressed('s')) 
		{
			playerPos.y += 1;
		}
		if(IsKeyPressed('d')) 
		{
			playerPos.x += 2;
		}
		if(IsKeyPressed(KEY_ENTER)) 
		{
			bulletsCount++;
			Vector2i *temp = realloc(bullets, bulletsCount * sizeof(*bullets));
			if (temp != NULL) 
			{
				bullets = temp;
				bullets[bulletsCount - 1].x = rand() % (max + 1);
				bullets[bulletsCount - 1].y = 0;
			}
		}

		for (size_t i = 0;i < bulletsCount;i++) 
		{
			bullets[bulletsCount].y--;
			DrawChar("|", bullets[i].x , bullets[i].y, WHITE);
		}
		
		DrawChar("M",playerPos.x,playerPos.y,WHITE);
		
		EndFrame();
	}
	free(bullets);
	CloseTui();
}


