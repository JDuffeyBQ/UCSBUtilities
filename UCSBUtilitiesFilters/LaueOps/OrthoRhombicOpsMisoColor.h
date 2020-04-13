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

#include <QtCore/QString>

#include "EbsdLib/EbsdLib.h"
#include "EbsdLib/LaueOps/OrthoRhombicOps.h"

#include "SIMPLib/Utilities/ColorTable.h"

class OrthoRhombicOpsMisoColor : public OrthoRhombicOps
{
  public:
    using Self = OrthoRhombicOpsMisoColor;
    using Pointer = std::shared_ptr<Self>;
    using ConstPointer = std::shared_ptr<const Self>;
    using WeakPointer = std::weak_ptr<Self>;
    using ConstWeakPointer = std::weak_ptr<const Self>;
    static Pointer NullPointer();

    /**
     * @brief Returns the name of the class for OrthoRhombicOpsMisoColor
     */
    QString getNameOfClass() const override;
    /**
     * @brief Returns the name of the class for OrthoRhombicOpsMisoColor
     */
    static QString ClassName();

    static Pointer New();

    OrthoRhombicOpsMisoColor();
    ~OrthoRhombicOpsMisoColor() override;

    /**
     * @brief generateMisorientationColor Generates a color based on the method developed by C. Schuh and S. Patala.
     * @param q Quaternion representing the direction
     * @param refDir The sample reference direction
     * @return Returns the ARGB Quadruplet SIMPL::Rgb
     */
    SIMPL::Rgb generateMisorientationColor(const QuatType& q, const QuatType& refFrame) const override;

  public:
    OrthoRhombicOpsMisoColor(const OrthoRhombicOpsMisoColor&) = delete; // Copy Constructor Not Implemented
    OrthoRhombicOpsMisoColor(OrthoRhombicOpsMisoColor&&) = delete;      // Move Constructor Not Implemented
    OrthoRhombicOpsMisoColor& operator=(const OrthoRhombicOpsMisoColor&) = delete; // Copy Assignment Not Implemented
    OrthoRhombicOpsMisoColor& operator=(OrthoRhombicOpsMisoColor&&) = delete;      // Move Assignment Not Implemented

  private:
};


