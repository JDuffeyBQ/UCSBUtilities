
#include "UCSBHelpers.h"

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
UCSBHelpers::UCSBHelpers()
{

}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
UCSBHelpers::~UCSBHelpers()
{

}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
IDataArray::Pointer UCSBHelpers::ReorderCopy(StatsDataArray::Pointer array, QVector<size_t> newOrderMap)
{
  if( static_cast<size_t>(newOrderMap.size()) != array->getNumberOfTuples())
  {
    return IDataArray::Pointer();
  }
  StatsDataArray::Pointer daCopyPtr = StatsDataArray::New();
  daCopyPtr->resize(array->getNumberOfTuples());
  daCopyPtr->initializeWithZeros();
  StatsDataArray& daCopy = *daCopyPtr;
  for(size_t i = 0; i < array->getNumberOfTuples(); i++)
  {
    daCopy[newOrderMap[i]] = array->getStatsData(i);
  }

  return daCopyPtr;
}


/**
 * @brief reorderCopy
 * @param newOrderMap
 * @return
 */
IDataArray::Pointer UCSBHelpers::ReorderCopy(StringDataArray::Pointer array, QVector<size_t> newOrderMap)
{
  if(static_cast<size_t>(newOrderMap.size()) != array->getNumberOfTuples())
  {
    return IDataArray::NullPointer();
  }
  StringDataArray::Pointer daCopy = StringDataArray::CreateArray(array->getNumberOfTuples(), array->getName());
  daCopy->initializeWithZeros();
  for(QVector<QString>::size_type i = 0; i < array->getNumberOfTuples(); ++i)
  {
    daCopy->setValue(newOrderMap[i], array->getValue(i));
  }
  return daCopy;
}



// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
IDataArray::Pointer UCSBHelpers::ReorderCopy(ModifiedLambertProjectionArray::Pointer array, QVector<size_t> newOrderMap)
{
  if( static_cast<size_t>(newOrderMap.size()) != array->getNumberOfTuples())
  {
    return IDataArray::NullPointer();
  }
  ModifiedLambertProjectionArray::Pointer daCopyPtr = ModifiedLambertProjectionArray::New();
  daCopyPtr->resize(array->getNumberOfTuples());
  daCopyPtr->initializeWithZeros();
  ModifiedLambertProjectionArray& daCopy = *daCopyPtr;
  for(size_t i = 0; i < array->getNumberOfTuples(); i++)
  {
    daCopy[newOrderMap[i]] = array->getModifiedLambertProjection(i);
  }

  return daCopyPtr;
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
void UCSBHelpers::SubtractBackground(std::vector<int64_t>& xshifts, std::vector<int64_t>& yshifts,
                                     int64_t dims[3])
{
    int64_t slice = 0;

    /**fit x and y shifts to lines
   *
   * y = mx + b
   *
   * m = (n*sum(x_i * y_i) - sum(x_i) * sum(y_i)) / (n*sum(x_i^2)-sum(x_i)^2
   *
   * b = (sum(y_i)-m*sum(x_i))/n
   *
   */

    // same for both
    double sumX = 0.0; // sum(x_i)
    double sumX_2 = 0.0; // sum(x_i^2)

    // x shift line
    double x_sumY = 0.0; // sum(y_i)
    double x_sumXY = 0.0; // sum(x_i * y_i)

    // y shift line
    double y_sumY = 0.0; // sum(y_i)
    double y_sumXY = 0.0; // sum(x_i * y_i)

    for (int64_t iter = 0; iter < dims[2]; iter++)
    {
      slice = static_cast<int64_t>( (dims[2] - 1) - iter );
      sumX = static_cast<double>(sumX + iter);
      sumX_2 = static_cast<double>(sumX_2 + iter * iter);
      x_sumY = static_cast<double>(x_sumY + xshifts[iter]);
      x_sumXY = static_cast<double>(x_sumXY + iter * xshifts[iter]);
      y_sumY = static_cast<double>(y_sumY + yshifts[iter]);
      y_sumXY = static_cast<double>(y_sumXY + iter * yshifts[iter]);
    }

    double mx = static_cast<double>((dims[2] * x_sumXY - x_sumXY) / (dims[2] * sumX_2 - sumX));
    double my = static_cast<double>((dims[2] * y_sumXY - y_sumXY) / (dims[2] * sumX_2 - sumX));

    // adjust shifts so that fit line has 0 slope (~ends of the sample are fixed)
    for (int64_t iter = 1; iter < dims[2]; iter++)
    {
      slice = (dims[2] - 1) - iter;
      xshifts[iter] = static_cast<int64_t>(xshifts[iter] - iter * mx);
      yshifts[iter] = static_cast<int64_t>(yshifts[iter] - iter * my);
    }


}
