#include <SDL.h>
#include <gLog.h>

#include "Level.h"
#include "Display.h"
#include "TextureMap.h"
#include "GameHandler.h"

#include <unistd.h>

int main(int argc, char* args[])
{

	GLOG_INFO("Loading...");

	GameHandler g;

	g.enter();

	return 0;
}