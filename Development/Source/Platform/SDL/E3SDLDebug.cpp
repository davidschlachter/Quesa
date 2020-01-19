#include "E3Prefix.h"
#include "E3Debug.h"
#include "SDL.h"

extern int gDebugMode;


//=============================================================================
//      E3IsValidPtr : Check a pointer for validity.
//-----------------------------------------------------------------------------
TQ3Boolean
E3IsValidPtr(const void* thePtr)
{


    // Check the pointer
    if (thePtr == nullptr)
        return(kQ3False);



    // If we're still here, it looks OK	
    return(kQ3True);
}


//=============================================================================
//      E3Assert : Report failed assertions.
//-----------------------------------------------------------------------------
void
E3Assert(
        const char *srcFile,
        TQ3Uns32 lineNum,
        const char *theAssertion)
{
    char theString[kQ3StringMaximumLength];

    // Check our parameters
    if (srcFile == NULL)
        srcFile = "Unknown";

    if (theAssertion == NULL)
        theAssertion = "Unknown";

    // Report the assertion failure
    sprintf(theString,
            "Quesa Assertion:\n'%s' failed\non line %d of %s\n",
            theAssertion, lineNum, srcFile);

    E3LogMessage( theString );

    SDL_ShowSimpleMessageBox(
            SDL_MESSAGEBOX_ERROR,
            "Quesa Assertion",
            theString,
            nullptr);

    // DebugBreak caused a problem when not running under a debugger, or when
    // running under Delphi's debugger.
#if QUESA_USE_DEBUGBREAK
    DebugBreak();
#endif
    abort();
}


//=============================================================================
//      E3LogMessage : Write a message to a log file.
//-----------------------------------------------------------------------------
void E3LogMessage( const char* inMessage )
{
    if (gDebugMode >= 0)
    {
        printf( "[Quesa] %s", inMessage  );
    }
}


//=============================================================================
//      E3CloseLog : Close the log file.
//-----------------------------------------------------------------------------
void E3CloseLog()
{
}
