#include <SDL.h>
#include <gLog.h>

#include "Level.h"
#include "Display.h"
#include "TextureMap.h"

#include <unistd.h>

int main(int argc, char* args[])
{

	GLOG_INFO("Loading...");

	Level lev = {};
	lev.init(16,4);

	Camera c = {0,0,0,0,16,4};

	Display d;
	d.setLevel(&lev);
	d.setCamera(&c);

	d.init();
	d.createWindow(800,600,"Bawl");
	d.showWindow();

	TextureMap::init(&d);

    while(1)
    {
	    d.drawDisplay();
    }

	return 0;
}