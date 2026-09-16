#include "../include/esclib.h"

int main(void) 
{
	InitTui(60,TUI_DYNAMIC);

	while(true)
	{
		BeginFrame();
		EndFrame();
	}

	CloseTui();
}
