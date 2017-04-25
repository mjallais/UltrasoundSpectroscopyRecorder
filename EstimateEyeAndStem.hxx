
#ifndef __EstimateEyeAndStem_h
#define __EstimateEyeAndStem_h

#include "itkImage.h"

typedef  float  PixelType;
typedef itk::Image< PixelType, 2 >  ImageType;

//Storage for eye and stem location and sizes
struct Eye {
  ImageType::IndexType initialCenterIndex;
  ImageType::PointType initialCenter;
  ImageType::IndexType centerIndex;
  ImageType::PointType center;
  double initialRadius = -1;
  double minor = -1;
  double major = -1;

  double initialRadiusX = -1;
  double initialRadiusY = -1;

  ImageType::Pointer aligned;
  };

struct Stem {
  ImageType::IndexType initialCenterIndex;
  ImageType::PointType initialCenter;
  ImageType::IndexType centerIndex;
  ImageType::PointType center;
  double initialWidth = -1;
  double width = -1;

  ImageType::Pointer aligned;
  ImageType::RegionType originalImageRegion;
  };

Eye fitEye( ImageType::Pointer inputImage, const std::string &prefix, bool alignEllipse );
Stem fitStem( ImageType::Pointer inputImage, Eye &eye, const std::string &prefix, bool alignStem );

#endif