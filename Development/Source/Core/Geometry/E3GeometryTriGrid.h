/*  NAME:
        E3GeometryTriGrid.h

    DESCRIPTION:
        Header file for E3GeometryTriGrid.c.

    COPYRIGHT:
        Quesa Copyright � 1999-2003, Quesa Developers.
        
        For the list of Quesa Developers, and contact details, see:
        
            Documentation/contributors.html

        For the current version of Quesa, see:

        	<http://www.quesa.org/>

		This library is free software; you can redistribute it and/or
		modify it under the terms of the GNU Lesser General Public
		License as published by the Free Software Foundation; either
		version 2 of the License, or (at your option) any later version.

		This library is distributed in the hope that it will be useful,
		but WITHOUT ANY WARRANTY; without even the implied warranty of
		MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
		Lesser General Public License for more details.

		You should have received a copy of the GNU Lesser General Public
		License along with this library; if not, write to the Free Software
		Foundation Inc, 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
    ___________________________________________________________________________
*/
#ifndef E3GEOMETRY_TRIGRID_HDR
#define E3GEOMETRY_TRIGRID_HDR
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
TQ3Status			E3GeometryTriGrid_RegisterClass(void);
TQ3Status			E3GeometryTriGrid_UnregisterClass(void);

TQ3GeometryObject	E3TriGrid_New(const TQ3TriGridData *triGridData);
TQ3Status			E3TriGrid_Submit(const TQ3TriGridData *triGridData, TQ3ViewObject theView);
TQ3Status			E3TriGrid_SetData(TQ3GeometryObject triGrid, const TQ3TriGridData *triGridData);
TQ3Status			E3TriGrid_GetData(TQ3GeometryObject triGrid, TQ3TriGridData *triGridData);
TQ3Status			E3TriGrid_EmptyData(TQ3TriGridData *triGridData);
TQ3Status			E3TriGrid_GetVertexPosition(TQ3GeometryObject triGrid, TQ3Uns32 rowIndex, TQ3Uns32 columnIndex, TQ3Point3D *position);
TQ3Status			E3TriGrid_SetVertexPosition(TQ3GeometryObject triGrid, TQ3Uns32 rowIndex, TQ3Uns32 columnIndex, const TQ3Point3D *position);
TQ3Status			E3TriGrid_GetVertexAttributeSet(TQ3GeometryObject triGrid, TQ3Uns32 rowIndex, TQ3Uns32 columnIndex, TQ3AttributeSet *attributeSet);
TQ3Status			E3TriGrid_SetVertexAttributeSet(TQ3GeometryObject triGrid, TQ3Uns32 rowIndex, TQ3Uns32 columnIndex, TQ3AttributeSet attributeSet);
TQ3Status			E3TriGrid_GetFacetAttributeSet(TQ3GeometryObject triGrid, TQ3Uns32 faceIndex, TQ3AttributeSet *facetAttributeSet);
TQ3Status			E3TriGrid_SetFacetAttributeSet(TQ3GeometryObject triGrid, TQ3Uns32 faceIndex, TQ3AttributeSet facetAttributeSet);





//=============================================================================
//		C++ postamble
//-----------------------------------------------------------------------------
#ifdef __cplusplus
}
#endif

#endif

