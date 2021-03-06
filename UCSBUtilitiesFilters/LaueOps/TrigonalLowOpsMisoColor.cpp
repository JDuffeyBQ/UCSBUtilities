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

#include "TrigonalLowOpsMisoColor.h"

// Include this FIRST because there is a needed define for some compiles
// to expose some of the constants needed below
#include "SIMPLib/Math/SIMPLibMath.h"
#include "SIMPLib/Utilities/ColorTable.h"


// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
TrigonalLowOpsMisoColor::TrigonalLowOpsMisoColor() = default;

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
TrigonalLowOpsMisoColor::~TrigonalLowOpsMisoColor() = default;

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
SIMPL::Rgb TrigonalLowOpsMisoColor::generateMisorientationColor(const QuatType& q, const QuatType& refFrame) const
{
  SIMPL::Rgb rgb = RgbColor::dRgb(0, 0, 0, 0);

  Q_ASSERT(false);

  return rgb;
}

// -----------------------------------------------------------------------------
TrigonalLowOpsMisoColor::Pointer TrigonalLowOpsMisoColor::NullPointer()
{
  return Pointer(static_cast<Self*>(nullptr));
}

// -----------------------------------------------------------------------------
QString TrigonalLowOpsMisoColor::getNameOfClass() const
{
  return QString("TrigonalLowOpsMisoColor");
}

// -----------------------------------------------------------------------------
QString TrigonalLowOpsMisoColor::ClassName()
{
  return QString("TrigonalLowOpsMisoColor");
}

// -----------------------------------------------------------------------------
TrigonalLowOpsMisoColor::Pointer TrigonalLowOpsMisoColor::New()
{
  Pointer sharedPtr(new(TrigonalLowOpsMisoColor));
  return sharedPtr;
}
