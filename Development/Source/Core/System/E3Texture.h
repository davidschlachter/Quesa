/*  NAME:
        E3Texture.h

    DESCRIPTION:
        Header file for E3Texture.c.

    COPYRIGHT:
        Copyright (c) 1999-2005, Quesa Developers. All rights reserved.

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
#ifndef E3TEXTURE_HDR
#define E3TEXTURE_HDR
//=============================================================================
//      Include files
//-----------------------------------------------------------------------------
// Include files go here





//=============================================================================
//		C++ preamble
//-----------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif





//=============================================================================
//      Types
//-----------------------------------------------------------------------------

class E3TextureInfo : public E3SharedInfo
	{
	const TQ3XTextureDimensionsMethod textureDimensions ;
	
public :

									E3TextureInfo	(
													TQ3XMetaHandler	newClassMetaHandler,
													E3ClassInfo*	newParent
					 								) ; // constructor	
	friend class E3Texture ;
	} ;




class E3Texture : public E3Shared // This is not a leaf class, but only classes in this,
								// file inherit from it, so it can be declared here in
								// the .c file rather than in the .h file, hence all
								// the fields can be public as nobody should be
								// including this file.
	{
Q3_CLASS_ENUMS ( kQ3SharedTypeTexture, E3Texture, E3Shared )
public :

	// There is no extra data for this class
	
	E3TextureInfo*					GetClass ( void ) { return (E3TextureInfo*) OpaqueTQ3Object::GetClass () ; }

	TQ3Status						GetWidth ( TQ3Uns32* width ) ;
	TQ3Status						GetHeight ( TQ3Uns32* height ) ;

	} ;
	


//=============================================================================
//      Function prototypes
//-----------------------------------------------------------------------------
TQ3Status				E3Texture_RegisterClass(void);
TQ3Status				E3Texture_UnregisterClass(void);

TQ3ObjectType			E3Texture_GetType(	TQ3TextureObject texture);
TQ3Boolean				E3Texture_IsOfMyClass ( TQ3Object object );
//TQ3Status				E3Texture_GetWidth(	TQ3TextureObject texture, TQ3Uns32 *width);
//TQ3Status				E3Texture_GetHeight(TQ3TextureObject texture, TQ3Uns32 *height);

TQ3TextureObject		E3PixmapTexture_New(const TQ3StoragePixmap *pixmap);
TQ3Status				E3PixmapTexture_GetPixmap(	TQ3TextureObject texture, TQ3StoragePixmap *pixmap);
TQ3Status				E3PixmapTexture_SetPixmap(	TQ3TextureObject texture, const TQ3StoragePixmap *pixmap);

TQ3TextureObject		E3MipmapTexture_New(const TQ3Mipmap *mipmap);
TQ3Status				E3MipmapTexture_GetMipmap(TQ3TextureObject texture, TQ3Mipmap *mipmap);
TQ3Status				E3MipmapTexture_SetMipmap(TQ3TextureObject texture, const TQ3Mipmap *mipmap);



//=============================================================================
//		C++ postamble
//-----------------------------------------------------------------------------
#ifdef __cplusplus
}
#endif

#endif

