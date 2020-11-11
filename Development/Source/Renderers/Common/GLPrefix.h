/*  NAME:
        GLPrefix.h

    DESCRIPTION:
        Global prefix file for OpenGL.

    COPYRIGHT:
        Copyright (c) 1999-2019, Quesa Developers. All rights reserved.

        For the current release of Quesa, please see:

            <https://github.com/jwwalker/Quesa>
        
        Redistribution and use in source and binary forms, with or without
        modification, are permitted provided that the following conditions
        are met:
        
            o Redistributions of source code must retain the above copyright
              notice, this list of conditions and the following disclaimer.
        
            o Redistributions in binary form must reproduce the above
              copyright notice, this list of conditions and the following
              disclaimer in the documentation and/or other materials provided
              with the distribution.
        
            o Neither the name of Quesa nor the names of its contributors
              may be used to endorse or promote products derived from this
              software without specific prior written permission.
        
        THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
        "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
        LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
        A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
        OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
        SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
        TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
        PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
        LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
        NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
        SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
    ___________________________________________________________________________
*/
#ifndef GLPREFIX_HDR
#define GLPREFIX_HDR
//=============================================================================
//      Include files
//-----------------------------------------------------------------------------
// Quesa
#include "Quesa.h"
#include <stdint.h>

// OpenGL
#if QUESA_OS_MACINTOSH

	#if 0 // test GL3
		#include <OpenGL/gl3.h>
		#include "glu3.h"
	#else
		#include <OpenGL/gl.h>
		#include <OpenGL/glu.h>
	#endif

#elif QUESA_OS_WIN32
    #include <GL/gl.h>
    #include <GL/glu.h>
	#include <stdint.h>
	typedef intptr_t GLintptr;
	typedef intptr_t GLsizeiptr;

#elif QUESA_OS_UNIX
// for glXGetProcAddressARB
    #define GLX_GLXEXT_PROTOTYPES 1

    #include <GL/glx.h>
    #include <GL/glu.h>

#elif (QUESA_OS_SDL && QUESA_OS_AGNOSTIC)

	#include <SDL_opengl.h>
	#include <SDL_opengl_glext.h>
	#if __APPLE__
		#include <OpenGL/glu.h>
	#else
		#include <GL/glu.h>
	#endif

#endif





//=============================================================================
//      Macros
//-----------------------------------------------------------------------------



//=============================================================================
//      Types
//-----------------------------------------------------------------------------
namespace QORenderer
{
	class PerPixelLighting;
}

// OpenGL extension availability flags
struct TQ3GLExtensions
{
	TQ3Boolean				multiSample;			// GL_SAMPLE_BUFFERS_ARB > 0
};


/*!
	@class		CQ3GLContext
	@abstract	Abstract base class for an OpenGL context.
	@discussion	The concrete subclasses will be platform-dependent.
	
				A subclass constructor should get the address for
				bindFrameBufferFunc.  It is usually necessary to make the GL
				context current and perhaps check for the FBO extension before
				doing so, hence the base class constructor cannot do it.
*/
class CQ3GLContext
{
public:
						CQ3GLContext( TQ3DrawContextObject inDC )
							: quesaDrawContext( inDC )
							, currentFrameBufferID( 0 )
							, currentFrameBufferTarget( 0 )
							, bindFrameBufferFunc( nullptr ) {}
				
	virtual				~CQ3GLContext() {}
	
	virtual void		SwapBuffers() = 0;
	
	virtual void		StartFrame( QORenderer::PerPixelLighting& inPPL ) {}

						// Make the platform OpenGL context current, but
						// do not alter the framebuffer binding.
	virtual void		SetCurrentBase( TQ3Boolean inForceSet ) = 0;
	
						// Set the active framebuffer (FBO), or use 0 to select
						// no FBO.  Returns true if the framebuffer ID changed.
	virtual bool		BindFrameBuffer( GLenum inTarget, GLuint inFrameBufferID );
	
	GLuint				GetCurrentFrameBuffer() const { return currentFrameBufferID; }
	
						// Make the context current.  Normally this will use
						// SetCurrentBase and BindFrameBuffer.
	virtual void		SetCurrent( TQ3Boolean inForceSet ) = 0;
	
	virtual bool		UpdateWindowPosition() { return false; }
	
	virtual bool		UpdateWindowSize() { return false; }
	
	TQ3DrawContextObject	GetDrawContext() const { return quesaDrawContext; }

protected:
	TQ3Object			quesaDrawContext;
	GLuint				currentFrameBufferID;
	GLenum				currentFrameBufferTarget;
	void*				bindFrameBufferFunc;
};


/*!
	@typedef		TQ3GLContext
	@abstract		Opaque pointer to a GL context.  What it points to is
					platform-dependent, and may be a private Quesa structure
					rather than simply a platform GL context.
*/
typedef	void*		TQ3GLContext;


// GLU callback
#ifndef CALLBACK
	#define CALLBACK
#endif

#if QUESA_OS_MACINTOSH && defined(__GNUC__) && (__GNUC__ >= 4) && defined(__APPLE_CC__)

	typedef GLvoid (CALLBACK *GLcallback)(...);
#else

	typedef void (CALLBACK *GLcallback)();

#endif

//=============================================================================
//      Functions
//-----------------------------------------------------------------------------

inline GLvoid* GLBufferObPtr( GLuint offset )
{
	return reinterpret_cast<GLvoid*>( static_cast<uintptr_t>( offset ) );
}

inline GLvoid* GLBufferObPtr( GLsizeiptr offset )
{
	return reinterpret_cast<GLvoid*>( static_cast<uintptr_t>( offset ) );
}

#endif
