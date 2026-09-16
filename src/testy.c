#include "../include/esclib.h"

int main(void) 
{
	InitTui(60,TUI_DYNAMIC);

	while(true)
	{
		BeginFrame();
		ClearTui(BLACK,TERMWHITE);
		EndFrame();
	}

	CloseTui();
}
