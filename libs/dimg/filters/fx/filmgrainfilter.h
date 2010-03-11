/* ============================================================
 *
 * This file is a part of digiKam project
 * http://www.digikam.org
 *
 * Date        : 2005-05-25
 * Description : filter to add Film Grain to image.
 * 
 * Copyright (C) 2005-2010 by Gilles Caulier <caulier dot gilles at gmail dot com>
 * Copyright (C) 2005-2010 by Marcel Wiesweg <marcel dot wiesweg at gmx dot de>
 * 
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GNU General
 * Public License as published by the Free Software Foundation;
 * either version 2, or (at your option)
 * any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * ============================================================ */
  
#ifndef FILMGRAINFILTER_H
#define FILMGRAINFILTER_H

// Local includes

#include "digikam_export.h"
#include "dimgthreadedfilter.h"
#include "globals.h"

namespace Digikam
{

class DIGIKAM_EXPORT FilmGrainContainer
{

public:

    FilmGrainContainer()
    {
        lum_sensibility    = 400;
        lum_shadows        = 100;
        lum_midtones       = 100; 
        lum_highlights     = 100;

        chroma_sensibility = 400;
        chroma_shadows     = 100;
        chroma_midtones    = 100;
        chroma_highlights  = 100;
    };

    ~FilmGrainContainer(){};

public:

    int lum_sensibility;
    int lum_shadows;
    int lum_midtones;
    int lum_highlights;

    int chroma_sensibility;
    int chroma_shadows; 
    int chroma_midtones;
    int chroma_highlights;
};

// -----------------------------------------------------------------------------------------------
  
class DIGIKAM_EXPORT FilmGrainFilter : public DImgThreadedFilter
{

public:

    explicit FilmGrainFilter(DImg* orgImage, QObject* parent=0, const FilmGrainContainer& settings=FilmGrainContainer());
    // Constructor for slave mode: execute immediately in current thread with specified master filter
    explicit FilmGrainFilter(DImgThreadedFilter* parentFilter, const DImg& orgImage, const DImg& destImage,
                             int progressBegin=0, int progressEnd=100,
                             const FilmGrainContainer& settings=FilmGrainContainer());    
    ~FilmGrainFilter(){};

private:

    void filterImage();
    double interpolate(int shadows, int midtones, int highlights, double x);
    int    randomize  (int value, bool sixteenbit, int range);
    
private:

    FilmGrainContainer m_settings;
};

}  // namespace Digikam

#endif /* FILMGRAINFILTER_H */
