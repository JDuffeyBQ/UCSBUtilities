

#include "TrigonalLowOpsMisoColor.h"

// Include this FIRST because there is a needed define for some compiles
// to expose some of the constants needed below
#include "SIMPLib/Math/SIMPLibMath.h"
#include "SIMPLib/Utilities/ColorTable.h"


// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
TrigonalLowOpsMisoColor::TrigonalLowOpsMisoColor() :
  TrigonalLowOps()
{

}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
TrigonalLowOpsMisoColor::~TrigonalLowOpsMisoColor()
{
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
DREAM3D::Rgb TrigonalLowOpsMisoColor::generateMisorientationColor(const QuatF& q, const QuatF& refFrame)
{
  DREAM3D::Rgb rgb = RgbColor::dRgb(0, 0, 0, 0);

  BOOST_ASSERT(false);

  return rgb;
}

