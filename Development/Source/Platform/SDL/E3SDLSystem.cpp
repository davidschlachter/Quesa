//=============================================================================
//      Include files
//-----------------------------------------------------------------------------
#include "E3Prefix.h"
#include "E3System.h"

//=============================================================================
//      Public functions
//-----------------------------------------------------------------------------
//      E3SDLSystem_Initialise : Initialise the system.
//-----------------------------------------------------------------------------
TQ3Status
E3SDLSystem_Initialise(void)
{
	// You are responsible for calling SDL_Init,
	// but you must let Quesa set up the GL context.
	if ((SDL_INIT_VIDEO & SDL_WasInit(0)) &&
	    !SDL_GL_GetCurrentWindow() )
	{
		return kQ3Success;
	}

	return kQ3Failure;
}

//=============================================================================
//      E3WindowsSystem_Terminate : Terminate the system.
//-----------------------------------------------------------------------------
void
E3SDLSystem_Terminate(void)
{
	// Terminate the system

	E3CloseLog();
}

