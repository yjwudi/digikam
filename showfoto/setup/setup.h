/* ============================================================
 *
 * This file is a part of digiKam project
 * http://www.digikam.org
 *
 * Date        : 2005-04-02
 * Description : showFoto setup dialog.
 *
 * Copyright (C) 2005-2009 by Gilles Caulier <caulier dot gilles at gmail dot com>
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

#ifndef SETUP_H
#define SETUP_H

// KDE includes

#include <kpagedialog.h>


namespace ShowFoto
{

class SetupPrivate;

class Setup : public KPageDialog
{
    Q_OBJECT

public:

    enum Page
    {
        LastPageUsed = -1,
        EditorPage = 0,
        MetadataPage,
        ToolTipPage,
        DcrawPage,
        IOFilesPage,
        SlideshowPage,
        ICCPage
    };

    Setup(QWidget* parent=0, const char* name=0, Page page=LastPageUsed);
    ~Setup();

private Q_SLOTS:

    void slotOkClicked();

private:

    Setup::Page activePageIndex();
    void showPage(Setup::Page page);

private:

    SetupPrivate* const d;
};

}   // namespace ShowFoto

#endif  /* SETUP_H  */
