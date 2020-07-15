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

#pragma once

#include <memory>

#include "EbsdLib/EbsdLib.h"
#include "EbsdLib/LaueOps/CubicOps.h"

#include "SIMPLib/Utilities/ColorTable.h"

class CubicOpsMisoColor : public CubicOps
{
public:
  using Self = CubicOpsMisoColor;
  using Pointer = std::shared_ptr<Self>;
  using ConstPointer = std::shared_ptr<const Self>;
  using WeakPointer = std::weak_ptr<Self>;
  using ConstWeakPointer = std::weak_ptr<const Self>;
  static Pointer NullPointer();

  /**
   * @brief Returns the name of the class for CubicOpsMisoColor
   */
  std::string getNameOfClass() const override;
  /**
   * @brief Returns the name of the class for CubicOpsMisoColor
   */
  static QString ClassName();

  static Pointer New();

  CubicOpsMisoColor();
  ~CubicOpsMisoColor() override;

  /**
   * @brief generateMisorientationColor Generates a color based on the method developed by C. Schuh and S. Patala.
   * @param q Quaternion representing the direction
   * @param refDir The sample reference direction
   * @return Returns the ARGB Quadruplet SIMPL::Rgb
   */
  SIMPL::Rgb generateMisorientationColor(const QuatD& q, const QuatD& refFrame) const override;

public:
  CubicOpsMisoColor(const CubicOpsMisoColor&) = delete;            // Copy Constructor Not Implemented
  CubicOpsMisoColor(CubicOpsMisoColor&&) = delete;                 // Move Constructor Not Implemented
  CubicOpsMisoColor& operator=(const CubicOpsMisoColor&) = delete; // Copy Assignment Not Implemented
  CubicOpsMisoColor& operator=(CubicOpsMisoColor&&) = delete;      // Move Assignment Not Implemented

private:
};
