#include "../include/esclib.h"

int main(void) 
{
	Vector2i playerPos = (Vector2i){ GetTuiDimensions().x / 2, GetTuiDimensions().y / 2 };
	InitTui(60,TUI_DYNAMIC);
	HideCursor();

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
		
		DrawChar("M",playerPos.x,playerPos.y,WHITE);
		
		EndFrame();
	}

	CloseTui();
}
