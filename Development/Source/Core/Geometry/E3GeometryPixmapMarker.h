/*  NAME:
        E3GeometryPixmapMarker.h

    DESCRIPTION:
        Header file for E3GeometryPixmapMarker.c.

    COPYRIGHT:
        Copyright (c) 1999-2004, Quesa Developers. All rights reserved.

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
#ifndef E3GEOMETRY_PIXMAPMARKER_HDR
#define E3GEOMETRY_PIXMAPMARKER_HDR
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
//      Function prototypes
//-----------------------------------------------------------------------------
TQ3Status			E3GeometryPixmapMarker_RegisterClass(void);
TQ3Status			E3GeometryPixmapMarker_UnregisterClass(void);

TQ3GeometryObject	E3PixmapMarker_New(const TQ3PixmapMarkerData *pixmapMarkerData);
TQ3Status			E3PixmapMarker_Submit(const TQ3PixmapMarkerData *pixmapMarkerData, TQ3ViewObject theView);
TQ3Status			E3PixmapMarker_SetData(TQ3GeometryObject theGeom, const TQ3PixmapMarkerData *pixmapMarkerData);
TQ3Status			E3PixmapMarker_GetData(TQ3GeometryObject theGeom, TQ3PixmapMarkerData *pixmapMarkerData);
TQ3Status			E3PixmapMarker_EmptyData(TQ3PixmapMarkerData *pixmapMarkerData);
TQ3Status			E3PixmapMarker_GetPosition(TQ3GeometryObject pixmapMarker, TQ3Point3D *position);
TQ3Status			E3PixmapMarker_SetPosition(TQ3GeometryObject pixmapMarker, const TQ3Point3D *position);
TQ3Status			E3PixmapMarker_GetXOffset(TQ3GeometryObject pixmapMarker, TQ3Int32 *xOffset);
TQ3Status			E3PixmapMarker_SetXOffset(TQ3GeometryObject pixmapMarker, TQ3Int32 xOffset);
TQ3Status			E3PixmapMarker_GetYOffset(TQ3GeometryObject pixmapMarker, TQ3Int32 *yOffset);
TQ3Status			E3PixmapMarker_SetYOffset(TQ3GeometryObject pixmapMarker, TQ3Int32 yOffset);
TQ3Status			E3PixmapMarker_GetPixmap(TQ3GeometryObject pixmapMarker, TQ3StoragePixmap *pixmap);
TQ3Status			E3PixmapMarker_SetPixmap(TQ3GeometryObject pixmapMarker, const TQ3StoragePixmap *pixmap);





//=============================================================================
//		C++ postamble
//-----------------------------------------------------------------------------
#ifdef __cplusplus
}
#endif

#endif

