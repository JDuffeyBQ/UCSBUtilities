/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                                               *
 * Copyright (c) 2015 The Regents of the University of California, Author: William Lenthe        *
 *                                                                                               *
 * This program is free software: you can redistribute it and/or modify it under the terms of    *
 * the GNU Lesser General Public License as published by the Free Software Foundation, either    *
 * version 2 of the License, or (at your option) any later version.                              *
 *                                                                                               *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;     *
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.     *
 * See the GNU Lesser General Public License for more details.                                   *
 *                                                                                               *
 * You should have received a copy of the GNU Lesser General Public License                      *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.                         *
 *                                                                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef _ORTHORHOMBICOpsMisoColor_H_
#define _ORTHORHOMBICOpsMisoColor_H_

#include "SIMPLib/SIMPLib.h"
#include "SIMPLib/Common/SIMPLibSetGetMacros.h"
#include "SIMPLib/DataArrays/DataArray.hpp"
#include "SIMPLib/Math/QuaternionMath.hpp"

#include "OrientationLib/OrientationLib.h"
#include "OrientationLib/SpaceGroupOps/OrthoRhombicOps.h"



class OrthoRhombicOpsMisoColor : public OrthoRhombicOps
{
  public:
    SIMPL_SHARED_POINTERS(OrthoRhombicOpsMisoColor)
    SIMPL_TYPE_MACRO_SUPER(OrthoRhombicOpsMisoColor, OrthoRhombicOpsMisoColor)
    SIMPL_STATIC_NEW_MACRO(OrthoRhombicOpsMisoColor)

    OrthoRhombicOpsMisoColor();
    virtual ~OrthoRhombicOpsMisoColor();


    /**
     * @brief generateMisorientationColor Generates a color based on the method developed by C. Schuh and S. Patala.
     * @param q Quaternion representing the direction
     * @param refDir The sample reference direction
     * @return Returns the ARGB Quadruplet DREAM3D::Rgb
     */
    virtual DREAM3D::Rgb generateMisorientationColor(const QuatF& q, const QuatF& refFrame);


  protected:


  private:
    OrthoRhombicOpsMisoColor(const OrthoRhombicOpsMisoColor&); // Copy Constructor Not Implemented
    void operator=(const OrthoRhombicOpsMisoColor&); // Operator '=' Not Implemented
};

#endif /* ORTHORHOMBICOpsMisoColor_H_ */

