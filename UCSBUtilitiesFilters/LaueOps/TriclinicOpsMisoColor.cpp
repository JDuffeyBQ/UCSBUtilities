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

#include "TriclinicOpsMisoColor.h"


// Include this FIRST because there is a needed define for some compiles
// to expose some of the constants needed below
#include "SIMPLib/Math/SIMPLibMath.h"
#include "SIMPLib/Utilities/ColorTable.h"


// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
TriclinicOpsMisoColor::TriclinicOpsMisoColor() = default;

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
TriclinicOpsMisoColor::~TriclinicOpsMisoColor() = default;

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
SIMPL::Rgb TriclinicOpsMisoColor::generateMisorientationColor(const QuatType& q, const QuatType& refFrame) const
{
  SIMPL::Rgb rgb = RgbColor::dRgb(0, 0, 0, 0);

  Q_ASSERT(false);

  return rgb;
}

// -----------------------------------------------------------------------------
TriclinicOpsMisoColor::Pointer TriclinicOpsMisoColor::NullPointer()
{
  return Pointer(static_cast<Self*>(nullptr));
}

// -----------------------------------------------------------------------------
QString TriclinicOpsMisoColor::getNameOfClass() const
{
  return QString("TriclinicOpsMisoColor");
}

// -----------------------------------------------------------------------------
QString TriclinicOpsMisoColor::ClassName()
{
  return QString("TriclinicOpsMisoColor");
}

// -----------------------------------------------------------------------------
TriclinicOpsMisoColor::Pointer TriclinicOpsMisoColor::New()
{
  Pointer sharedPtr(new(TriclinicOpsMisoColor));
  return sharedPtr;
}
