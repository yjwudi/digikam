/* ============================================================
 * File  : bcgmodifier.h
 * Author: Renchi Raju <renchi@pooh.tam.uiuc.edu>
 *         Gilles Caulier <caulier dot gilles at free.fr> 
 * Date  : 2005-03-06
 * Description : Brighness/Contrast/Gamma modifier methods
 *               for DImg framework
 * 
 * Copyright 2005 by Renchi Raju, Gilles Caulier
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
 * ============================================================ */

#ifndef BCGMODIFIER_H
#define BCGMODIFIER_H

// Local includes.

#include "digikam_export.h"

namespace Digikam
{

class DImg;

class DIGIKAM_EXPORT BCGModifier
{
public:

    BCGModifier();
    ~BCGModifier();

    void   reset();
    bool   modified() const;
    
    void   setGamma(double val);
    void   setBrightness(double val);
    void   setContrast(double val);
    void   applyBCG(DImg& image);
    
private:

    bool           m_modified;
    
    unsigned short m_map16[65536];
    unsigned char  m_map[256];
    
};

}  // NameSpace Digikam
    
#endif /* BCGMODIFIER_H */
