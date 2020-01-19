#include "E3Prefix.h"
#include "E3DrawContext.h"
#include "E3Main.h"
#include <SDL.h>

class E3SDLDrawContext : public E3DrawContext  // This is a leaf class so no other classes use this,
								// so it can be here in the .c file rather than in
								// the .h file, hence all the fields can be public
								// as nobody should be including this file
{
	Q3_CLASS_ENUMS(kQ3DrawContextTypeSDL, E3SDLDrawContext, E3DrawContext);
public:
	TQ3DrawContextUnionData				instanceData;
};

static TQ3Status
e3drawcontext_sdl_new(TQ3Object theObject, void* privateData, const void* paramData)
{
	TQ3DrawContextUnionData* instanceData = (TQ3DrawContextUnionData*)privateData;
	const TQ3SDLDrawContextData* sdlData = (const TQ3SDLDrawContextData*)paramData;
#pragma unused(theObject)



	// Initialise our instance data
//	instanceData->data.win32Data.theData = *sdlData;
//	e3drawcontext_win32dc_get_dimensions_from_DC(instanceData->data.win32Data.theData.hdc,
//		&instanceData->data.win32Data.windowRect);
	instanceData->data.sdlData.theData = *sdlData;

	E3DrawContext_InitialiseData(&instanceData->data.sdlData.theData.drawContextData);

	return(kQ3Success);
}

static void
e3drawcontext_sdl_get_dimensions(E3SDLDrawContext* theDrawContext, TQ3Area* thePane)
{
	auto window = theDrawContext->instanceData.data.sdlData.theData.sdlWindow;
	int w = 0;
	int h = 0;
	SDL_GetWindowSize(window, &w, &h);
	thePane->min.x = 0.0f;
	thePane->min.y = 0.0f;
	thePane->max.x = (float)w;
	thePane->max.y = (float)h;
}

static TQ3Status
e3drawcontext_sdl_update(E3SDLDrawContext* theDrawContext)
{
	// Check whether the window has been resized.
	TQ3Area		newArea;
	e3drawcontext_sdl_get_dimensions(theDrawContext, &newArea);
	if ((newArea.max.x != theDrawContext->instanceData.data.sdlData.windowRect.max.x) ||
		(newArea.max.y != theDrawContext->instanceData.data.sdlData.windowRect.max.y))
	{
		theDrawContext->instanceData.data.sdlData.windowRect = newArea;
		theDrawContext->instanceData.theState = kQ3XDrawContextValidationWindowSize;
	}
	return(kQ3Success);
}

static TQ3XFunctionPointer
e3drawcontext_sdl_metahandler(TQ3XMethodType methodType)
{
	TQ3XFunctionPointer		theMethod = NULL;

	// Return our methods
	switch (methodType) {
	case kQ3XMethodTypeObjectNew:
		theMethod = (TQ3XFunctionPointer)e3drawcontext_sdl_new;
		break;
		
		/*
	case kQ3XMethodTypeObjectDelete:
		theMethod = (TQ3XFunctionPointer)e3drawcontext_sdl_delete;
		break;
		*/

	case kQ3XMethodTypeDrawContextUpdate:
		theMethod = (TQ3XFunctionPointer)e3drawcontext_sdl_update;
		break;

	case kQ3XMethodTypeDrawContextGetDimensions:
		theMethod = (TQ3XFunctionPointer)e3drawcontext_sdl_get_dimensions;
		break;
	}
	

	return(theMethod);
}

TQ3Status
E3SDLDrawContext_RegisterClass(void)
{
	TQ3Status		qd3dStatus;



	// Register the class
	qd3dStatus = Q3_REGISTER_CLASS(kQ3ClassNameDrawContextSDL,
		e3drawcontext_sdl_metahandler, E3SDLDrawContext);

	return(qd3dStatus);
}

TQ3Status
E3SDLDrawContext_UnregisterClass(void)
{
	TQ3Status		qd3dStatus;



	// Unregister the classes
	qd3dStatus = E3ClassTree::UnregisterClass(kQ3DrawContextTypeSDL, kQ3True);

	return(qd3dStatus);
}

TQ3Status
E3SDLDrawContext_GetWindow(TQ3DrawContextObject drawContext, SDL_Window** sdlWindow)
{
	TQ3DrawContextUnionData* instanceData = (TQ3DrawContextUnionData*)drawContext->FindLeafInstanceData();



	// Get the field
	*sdlWindow = instanceData->data.sdlData.theData.sdlWindow;

	return(kQ3Success);
}
