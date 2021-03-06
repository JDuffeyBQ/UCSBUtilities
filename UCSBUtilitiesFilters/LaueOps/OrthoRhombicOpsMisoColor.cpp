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

#include "OrthoRhombicOpsMisoColor.h"

#include <cassert>

// Include this FIRST because there is a needed define for some compiles
// to expose some of the constants needed below
#include "SIMPLib/Math/SIMPLibMath.h"
#include "SIMPLib/Utilities/ColorTable.h"
#include "SIMPLib/Utilities/ColorUtilities.h"

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
OrthoRhombicOpsMisoColor::OrthoRhombicOpsMisoColor() = default;

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
OrthoRhombicOpsMisoColor::~OrthoRhombicOpsMisoColor() = default;

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
SIMPL::Rgb OrthoRhombicOpsMisoColor::generateMisorientationColor(const QuatType& q, const QuatType& refFrame) const
{
  assert(false);
	#if 0
  double n1, n2, n3, w;
  double x, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11;
  double y, y1, y2, y3, y4, y5, y6, y7, y8, y9, y10, y11;
  double z, z1, z2, z3, z4, z5, z6, z7, z8, z9, z10, z11;
  double k, h, s, v, c, r, g, b;

  //get misorientation as rodriguez vector in FZ (eq. c1.1)
  QuatType q1 = q;
  QuatType q2 = refFrame;
  w = getMisoQuat(q1, q2, n1, n2, n3);
  OrientArrayType rod(n1, n2, n3, tan(w / 2.0f));
  rod = getMDFFZRod(rod);
  x = rod[0] * rod[3];
  y = rod[1] * rod[3];
  z = rod[2] * rod[3];

  //eq c1.2
  k = x + y + z;
  k = (0.0f == k) ? 1.0f: 1.0f / k;
  k *= sqrt(3.0f) * std::max(x, std::max(y, z));
  x1 = x * k;
  y1 = y * k;
  z1 = z * k;

  //eq c1.3
  //3 rotation matricies (in paper) can be multiplied into one (here) for simplicity / speed
  //g1*g2*g3 = {{sqrt(2/3), -1/sqrt(6), -1/sqrt(6)},{0, 1/sqrt(2), -1/sqrt(2)},{1/sqrt(3), 1/sqrt(3), 1/sqrt(3)}}
  x2 = x1 * (SIMPLib::Constants::k_Sqrt2 / SIMPLib::Constants::k_Sqrt3) - (y1 + z1) / (SIMPLib::Constants::k_Sqrt2 * SIMPLib::Constants::k_Sqrt3);
  y2 = (y1 - z1) / SIMPLib::Constants::k_Sqrt2;
  z2 = (x1 + y1 + z1) / SIMPLib::Constants::k_Sqrt3;

  //eq c1.4
  k = atan2(y2, x2);
  if(k < 0.0f) {k += SIMPLib::Constants::k_2Pi;}
  x3 = sqrt(x2 * x2 + y2 * y2) * sin(SIMPLib::Constants::k_Pi / 6.0f + fmod(k, SIMPLib::Constants::k_2Pi / 3.0f)) / SIMPLib::Constants::k_HalfSqrt2;
  y3 = x3;
  x3 *= cos(k);
  y3 *= sin(k);
  z3 = z2 - 1.0f;

  //eq c1.5
  k = sqrt(x3 * x3 + y3 * y3 + z3 * z3);
  k = (k > 0.0f) ? 1.0f / k : 1.0f;
  k *= sqrt(x3 * x3 + y3 * y3) - z3;
  x4 = x3 * k;
  y4 = y3 * k;
  z4 = z3 * k;

  //eq c1.6, 7, and 8 (from matlab code not paper)
  k = atan2(y4, x4);
  if(k < 0.0f) {k += SIMPLib::Constants::k_2Pi;}
  k *= 3.0f / SIMPLib::Constants::k_2Pi;
  size_t type = 0;
  if(0.0f < k && k < 1.0f) {type = 1;}
  else if(1.0f < k && k < 2.0f) {type = 2;}
  else if(2.0f < k && k < 3.0f) {type = 3;}

  switch(type) {
    case 1:
      x5 = (x4 + y4 * SIMPLib::Constants::k_Sqrt3) / 2.0f;
      y5 = (-x4 * SIMPLib::Constants::k_Sqrt3 + y4) / 2.0f;
      z5 = z4;
      break;

    case 2:
      x5 = -x4;
      y5 = -y4;
      z5 = z4;
      break;

    case 3:
      x5 = (x4 - y4 * SIMPLib::Constants::k_Sqrt3) / 2.0f;
      y5 = (x4 * SIMPLib::Constants::k_Sqrt3 + y4) / 2.0f;
      z5 = z4;
      break;
  }

  switch(type) {
    case 1://intentional fall through
    case 2://intentional fall through
    case 3:
      k = 1.5f * atan2(y5, x5);
      x6 = sqrt(x5 * x5 + y5 * y5);
      y6 = x6;
      x6 *= cos(k);
      y6 *= sin(k);
      z6 = z5;

      k = 2.0f * atan2(x6, -z6);
      x7 = sqrt(x6 * x6 + z6 * z6);
      z7 = x7;
      x7 *= sin(k);
      y7 = y6;
      z7 *= -cos(k);

      k = (2.0f / 3.0f) * atan2(y7, x7);
      x8 = sqrt(x7 * x7 + y7 * y7);
      y8 = x8;
      x8 *= cos(k);
      y8 *= sin(k);
      z8 = z7;
  }

  switch(type) {
    case 1:
      x9 = (x8 - y8 * SIMPLib::Constants::k_Sqrt3) / 2.0f;
      y9 = (x8 * SIMPLib::Constants::k_Sqrt3 + y8) / 2.0f;
      z9 = z8;
      break;

    case 2:
      x9 = -x8;
      y9 = -y8;
      z9 = z8;
      break;

    case 3:
      x9 = (x8 + y8 * SIMPLib::Constants::k_Sqrt3) / 2.0f;
      y9 = (-x8 * SIMPLib::Constants::k_Sqrt3 + y8) / 2.0f;
      z9 = z8;
      break;

    default:
      x9 = x4;
      y9 = y4;
      z9 = z4;
  }

  //c1.9
  x10 = (x9 - y9 * SIMPLib::Constants::k_Sqrt3) / 2.0f;
  y10 = (x9 * SIMPLib::Constants::k_Sqrt3 + y9) / 2.0f;
  z10 = z9;

  //cartesian to traditional hsv
  x11 = sqrt(x10 * x10 + y10 * y10 + z10 * z10); //r
  y11 = (x11 > 0.0f) ? acos(z10 / x11) : 0.0f;//theta
  z11 = (x11 > 0.0f) ? atan2(y10, x10) : 0.0f;//rho

  h = z11 - SIMPLib::Constants::k_2Pi / 3.0f;
  if(h < 0.0f) {h += SIMPLib::Constants::k_2Pi;}
  h /= SIMPLib::Constants::k_2Pi;

  if(y11 < SIMPLib::Constants::k_Pi / 2.0f) {
    s = (4.0f * x11 * y11) / (SIMPLib::Constants::k_Pi * (1.0f + x11));
    v = (x11 + 1.0f) / 2.0f;
  } else {//>= pi/2
    v = 2.0f * x11 * (0.75f - y11 / SIMPLib::Constants::k_Pi) + 0.5f;
    k = (v > 0.0f) ? 0.5f / v : 1.0f;
    s = 1.0f - (1.0f - x11) * k;
  }

  //convert to rgb and invert
  SIMPL::Rgb rgb = ColorUtilities::convertHSVtoRgb(h, s, v);
#endif
  SIMPL::Rgb rgb = 0xFFFFFFFF;
  return RgbColor::dRgb(255 - RgbColor::dRed(rgb), 255 - RgbColor::dGreen(rgb), 255 - RgbColor::dBlue(rgb), 0);
}

// -----------------------------------------------------------------------------
OrthoRhombicOpsMisoColor::Pointer OrthoRhombicOpsMisoColor::NullPointer()
{
  return Pointer(static_cast<Self*>(nullptr));
}

// -----------------------------------------------------------------------------
QString OrthoRhombicOpsMisoColor::getNameOfClass() const
{
  return QString("OrthoRhombicOpsMisoColor");
}

// -----------------------------------------------------------------------------
QString OrthoRhombicOpsMisoColor::ClassName()
{
  return QString("OrthoRhombicOpsMisoColor");
}

// -----------------------------------------------------------------------------
OrthoRhombicOpsMisoColor::Pointer OrthoRhombicOpsMisoColor::New()
{
  Pointer sharedPtr(new(OrthoRhombicOpsMisoColor));
  return sharedPtr;
}
