/* ============================================================
 *
 * This file is a part of digiKam project
 * http://www.digikam.org
 *
 * Date        : 2010-12-16
 * Description : Import filters configuration dialog
 *
 * Copyright (C) 2010-2011 by Petri Damstén <petri.damsten@iki.fi>
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

#ifndef IMPORTFILTERS_H
#define IMPORTFILTERS_H

// KDE includes

#include <KDialog>

// local includes

#include "filtercombo.h"

namespace Digikam
{

class ImportFilters : public KDialog
{
    Q_OBJECT

public:

    ImportFilters(QWidget* parent = 0);
    ~ImportFilters();

    void setData(const Filter& filter);
    void getData(Filter* filter);

protected Q_SLOTS:

    void fileNameCheckBoxClicked();
    void pathCheckBoxClicked();
    void mimeCheckBoxClicked();
    void mimeButtonClicked();

private:

    class ImportFiltersPriv;
    ImportFiltersPriv* const   d;
};

} // namespace Digikam

#endif /* IMPORTFILTERS_H */
