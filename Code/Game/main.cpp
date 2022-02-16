#include <SDL.h>
#include <gLog.h>

#include "Level.h"
#include "Display.h"
#include " TextureMap.h"

#include <unistd.h>
#define GetCurrentDir getcwd

int main(int argc, char* args[])
{

	GLOG_INFO("Loading...");

	Level lev = {};
	lev.init(4,4);

	Display d;

	d.init();
	d.createWindow(800,600,"Bawl");
	d.showWindow();

	TextureMap::init(&d);

	return 0;
}