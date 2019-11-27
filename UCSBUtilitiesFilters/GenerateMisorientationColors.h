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

#include "SIMPLib/SIMPLib.h"
#include "SIMPLib/FilterParameters/FloatVec3FilterParameter.h"
#include "SIMPLib/Filtering/AbstractFilter.h"
#include "SIMPLib/DataArrays/DataArray.hpp"

#include "UCSBUtilities/UCSBUtilitiesDLLExport.h"

/**
 * @brief The GenerateMisorientationColors class. See [Filter documentation](@ref generateipfcolors) for details.
 */
class UCSBUtilities_EXPORT GenerateMisorientationColors : public AbstractFilter
{
    Q_OBJECT

#ifdef SIMPL_ENABLE_PYTHON
    PYB11_CREATE_BINDINGS(GenerateMisorientationColors SUPERCLASS AbstractFilter)
    PYB11_SHARED_POINTERS(GenerateMisorientationColors)
    PYB11_FILTER_NEW_MACRO(GenerateMisorientationColors)
    PYB11_FILTER_PARAMETER(FloatVec3Type, ReferenceAxis)
    PYB11_FILTER_PARAMETER(float, ReferenceAngle)
    PYB11_FILTER_PARAMETER(DataArrayPath, CellPhasesArrayPath)
    PYB11_FILTER_PARAMETER(DataArrayPath, QuatsArrayPath)
    PYB11_FILTER_PARAMETER(DataArrayPath, CrystalStructuresArrayPath)
    PYB11_FILTER_PARAMETER(DataArrayPath, GoodVoxelsArrayPath)
    PYB11_FILTER_PARAMETER(QString, MisorientationColorArrayName)
    PYB11_FILTER_PARAMETER(bool, UseGoodVoxels)
    PYB11_PROPERTY(FloatVec3Type ReferenceAxis READ getReferenceAxis WRITE setReferenceAxis)
    PYB11_PROPERTY(float ReferenceAngle READ getReferenceAngle WRITE setReferenceAngle)
    PYB11_PROPERTY(DataArrayPath CellPhasesArrayPath READ getCellPhasesArrayPath WRITE setCellPhasesArrayPath)
    PYB11_PROPERTY(DataArrayPath QuatsArrayPath READ getQuatsArrayPath WRITE setQuatsArrayPath)
    PYB11_PROPERTY(DataArrayPath CrystalStructuresArrayPath READ getCrystalStructuresArrayPath WRITE setCrystalStructuresArrayPath)
    PYB11_PROPERTY(DataArrayPath GoodVoxelsArrayPath READ getGoodVoxelsArrayPath WRITE setGoodVoxelsArrayPath)
    PYB11_PROPERTY(QString MisorientationColorArrayName READ getMisorientationColorArrayName WRITE setMisorientationColorArrayName)
    PYB11_PROPERTY(bool UseGoodVoxels READ getUseGoodVoxels WRITE setUseGoodVoxels)
#endif

  public:
    using Self = GenerateMisorientationColors;
    using Pointer = std::shared_ptr<Self>;
    using ConstPointer = std::shared_ptr<const Self>;
    using WeakPointer = std::weak_ptr<Self>;
    using ConstWeakPointer = std::weak_ptr<const Self>;
    static Pointer NullPointer();

    static std::shared_ptr<GenerateMisorientationColors> New();

    /**
     * @brief Returns the name of the class for GenerateMisorientationColors
     */
    QString getNameOfClass() const override;
    /**
     * @brief Returns the name of the class for GenerateMisorientationColors
     */
    static QString ClassName();

    ~GenerateMisorientationColors() override;

    /**
     * @brief Setter property for ReferenceAxis
     */
    void setReferenceAxis(const FloatVec3Type& value);
    /**
     * @brief Getter property for ReferenceAxis
     * @return Value of ReferenceAxis
     */
    FloatVec3Type getReferenceAxis() const;

    Q_PROPERTY(FloatVec3Type ReferenceAxis READ getReferenceAxis WRITE setReferenceAxis)

    /**
     * @brief Setter property for ReferenceAngle
     */
    void setReferenceAngle(float value);
    /**
     * @brief Getter property for ReferenceAngle
     * @return Value of ReferenceAngle
     */
    float getReferenceAngle() const;

    Q_PROPERTY(float ReferenceAngle READ getReferenceAngle WRITE setReferenceAngle)

    /**
     * @brief Setter property for CellPhasesArrayPath
     */
    void setCellPhasesArrayPath(const DataArrayPath& value);
    /**
     * @brief Getter property for CellPhasesArrayPath
     * @return Value of CellPhasesArrayPath
     */
    DataArrayPath getCellPhasesArrayPath() const;

    Q_PROPERTY(DataArrayPath CellPhasesArrayPath READ getCellPhasesArrayPath WRITE setCellPhasesArrayPath)

    /**
     * @brief Setter property for QuatsArrayPath
     */
    void setQuatsArrayPath(const DataArrayPath& value);
    /**
     * @brief Getter property for QuatsArrayPath
     * @return Value of QuatsArrayPath
     */
    DataArrayPath getQuatsArrayPath() const;

    Q_PROPERTY(DataArrayPath QuatsArrayPath READ getQuatsArrayPath WRITE setQuatsArrayPath)

    /**
     * @brief Setter property for CrystalStructuresArrayPath
     */
    void setCrystalStructuresArrayPath(const DataArrayPath& value);
    /**
     * @brief Getter property for CrystalStructuresArrayPath
     * @return Value of CrystalStructuresArrayPath
     */
    DataArrayPath getCrystalStructuresArrayPath() const;

    Q_PROPERTY(DataArrayPath CrystalStructuresArrayPath READ getCrystalStructuresArrayPath WRITE setCrystalStructuresArrayPath)

    /**
     * @brief Setter property for GoodVoxelsArrayPath
     */
    void setGoodVoxelsArrayPath(const DataArrayPath& value);
    /**
     * @brief Getter property for GoodVoxelsArrayPath
     * @return Value of GoodVoxelsArrayPath
     */
    DataArrayPath getGoodVoxelsArrayPath() const;

    Q_PROPERTY(DataArrayPath GoodVoxelsArrayPath READ getGoodVoxelsArrayPath WRITE setGoodVoxelsArrayPath)

    /**
     * @brief Setter property for MisorientationColorArrayName
     */
    void setMisorientationColorArrayName(const QString& value);
    /**
     * @brief Getter property for MisorientationColorArrayName
     * @return Value of MisorientationColorArrayName
     */
    QString getMisorientationColorArrayName() const;

    Q_PROPERTY(QString MisorientationColorArrayName READ getMisorientationColorArrayName WRITE setMisorientationColorArrayName)

    /**
     * @brief Setter property for UseGoodVoxels
     */
    void setUseGoodVoxels(bool value);
    /**
     * @brief Getter property for UseGoodVoxels
     * @return Value of UseGoodVoxels
     */
    bool getUseGoodVoxels() const;

    Q_PROPERTY(bool UseGoodVoxels READ getUseGoodVoxels WRITE setUseGoodVoxels)

    /**
     * @brief getCompiledLibraryName Reimplemented from @see AbstractFilter class
     */
    QString getCompiledLibraryName() const override;

    /**
     * @brief getBrandingString Returns the branding string for the filter, which is a tag
     * used to denote the filter's association with specific plugins
     * @return Branding string
    */
    QString getBrandingString() const override;

    /**
     * @brief getFilterVersion Returns a version string for this filter. Default
     * value is an empty string.
     * @return
     */
    QString getFilterVersion() const override;

    /**
     * @brief newFilterInstance Reimplemented from @see AbstractFilter class
     */
    AbstractFilter::Pointer newFilterInstance(bool copyFilterParameters) const override;

    /**
     * @brief getGroupName Reimplemented from @see AbstractFilter class
     */
    QString getGroupName() const override;

    /**
     * @brief getSubGroupName Reimplemented from @see AbstractFilter class
     */
    QString getSubGroupName() const override;

    /**
     * @brief getUuid Return the unique identifier for this filter.
     * @return A QUuid object.
     */
    QUuid getUuid() const override;

    /**
     * @brief getHumanLabel Reimplemented from @see AbstractFilter class
     */
    QString getHumanLabel() const override;

    /**
     * @brief setupFilterParameters Reimplemented from @see AbstractFilter class
     */
    void setupFilterParameters() override;

    /**
     * @brief readFilterParameters Reimplemented from @see AbstractFilter class
     */
    void readFilterParameters(AbstractFilterParametersReader* reader, int index) override;

    /**
     * @brief execute Reimplemented from @see AbstractFilter class
     */
    void execute() override;

    /**
    * @brief preflight Reimplemented from @see AbstractFilter class
    */
    void preflight() override;

  signals:
    /**
     * @brief updateFilterParameters Emitted when the Filter requests all the latest Filter parameters
     * be pushed from a user-facing control (such as a widget)
     * @param filter Filter instance pointer
     */
    void updateFilterParameters(AbstractFilter* filter);

    /**
     * @brief parametersChanged Emitted when any Filter parameter is changed internally
     */
    void parametersChanged();

    /**
     * @brief preflightAboutToExecute Emitted just before calling dataCheck()
     */
    void preflightAboutToExecute();

    /**
     * @brief preflightExecuted Emitted just after calling dataCheck()
     */
    void preflightExecuted();

  protected:
    GenerateMisorientationColors();

    /**
     * @brief dataCheck Checks for the appropriate parameter values and availability of arrays
     */
    void dataCheck();

    /**
     * @brief Initializes all the private instance variables.
     */
    void initialize();


  private:
    std::weak_ptr<DataArray<int32_t>> m_CellPhasesPtr;
    int32_t* m_CellPhases = nullptr;
    std::weak_ptr<DataArray<float>> m_QuatsPtr;
    float* m_Quats = nullptr;
    std::weak_ptr<DataArray<uint32_t>> m_CrystalStructuresPtr;
    uint32_t* m_CrystalStructures = nullptr;
    std::weak_ptr<DataArray<bool>> m_GoodVoxelsPtr;
    bool* m_GoodVoxels = nullptr;
    std::weak_ptr<DataArray<uint8_t>> m_MisorientationColorPtr;
    uint8_t* m_MisorientationColor = nullptr;

    FloatVec3Type m_ReferenceAxis = {};
    float m_ReferenceAngle = {};
    DataArrayPath m_CellPhasesArrayPath = {};
    DataArrayPath m_QuatsArrayPath = {};
    DataArrayPath m_CrystalStructuresArrayPath = {};
    DataArrayPath m_GoodVoxelsArrayPath = {};
    QString m_MisorientationColorArrayName = {};
    bool m_UseGoodVoxels = {};

  public:
    GenerateMisorientationColors(const GenerateMisorientationColors&) = delete; // Copy Constructor Not Implemented
    GenerateMisorientationColors(GenerateMisorientationColors&&) = delete;      // Move Constructor Not Implemented
    GenerateMisorientationColors& operator=(const GenerateMisorientationColors&) = delete; // Copy Assignment Not Implemented
    GenerateMisorientationColors& operator=(GenerateMisorientationColors&&) = delete;      // Move Assignment Not Implemented
};

