//////////////////////////////////////////////////////////////////////////////
//
//    SETUPGENERAL.CPP
//
//    Copyright (C) 2003-2004 Renchi Raju <renchi at pooh.tam.uiuc.edu>
//                            Gilles CAULIER <caulier dot gilles at free.fr>
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program; if not, write to the Free Software
//    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
//
//////////////////////////////////////////////////////////////////////////////

// QT includes.

#include <qlayout.h>
#include <qvbuttongroup.h>
#include <qvgroupbox.h>
#include <qhgroupbox.h>
#include <qgroupbox.h>
#include <qradiobutton.h>
#include <qcheckbox.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qdir.h>
#include <qlistbox.h>
#include <qwhatsthis.h>

// KDE includes.

#include <klocale.h>
#include <kdialog.h>
#include <kfiledialog.h>
#include <kurl.h>
#include <kmessagebox.h>
#include <klineeditdlg.h>

// // Local includes.

#include "thumbnailsize.h"
#include "albumsettings.h"
#include "setupgeneral.h"


SetupGeneral::SetupGeneral(QWidget* parent )
            : QWidget(parent)
{
   QVBoxLayout *layout = new QVBoxLayout( parent, 10);
   layout->setSpacing( KDialog::spacingHint() );

   // --------------------------------------------------------

   QHGroupBox *albumPathBox = new QHGroupBox(parent);
   albumPathBox->setTitle(i18n("Album Library Path"));

   albumPathEdit = new QLineEdit(albumPathBox);
   QWhatsThis::add( albumPathEdit, i18n("<p>Here you can set the main path to the Digikam Albums "
                                        "library in your computer."));
                                                
   QPushButton *changePathButton = new QPushButton(i18n("&Change..."),
                                                   albumPathBox);
   connect(changePathButton, SIGNAL(clicked()),
           this, SLOT(slotChangeAlbumPath()));

   layout->addWidget(albumPathBox);

   // --------------------------------------------------------

   QVGroupBox *tagSettingBox = new QVGroupBox(parent);
   tagSettingBox->setTitle(i18n("Tag Settings"));

   recurseTagsBox_ = new QCheckBox(tagSettingBox);
   recurseTagsBox_->setText(i18n("When showing items in a Tag, also "
                                 "show items in sub-Tags"));
   
   layout->addWidget(tagSettingBox);

   // --------------------------------------------------------

   QButtonGroup *iconSizeButtonGroup = new QButtonGroup(1, Qt::Horizontal, 
                                                        i18n("Default Thumbnail Size"),
                                                        parent);
   
   iconSizeButtonGroup->setRadioButtonExclusive(true);

   smallIconButton_ = new QRadioButton(iconSizeButtonGroup);
   smallIconButton_->setText( i18n( "Small (64x64)" ) );

   mediumIconButton_ = new QRadioButton(iconSizeButtonGroup);
   mediumIconButton_->setText( i18n( "Medium (100x100)" ) );
   
   largeIconButton_ = new QRadioButton(iconSizeButtonGroup);
   largeIconButton_->setText( i18n( "Large (160x160)" ) );

   hugeIconButton_ = new QRadioButton(iconSizeButtonGroup);
   hugeIconButton_->setText( i18n( "Huge (256x256)" ) );

   layout->addWidget(iconSizeButtonGroup);

   // --------------------------------------------------------

   QGroupBox *iconTextGroup = new QGroupBox(1,
                                            Qt::Horizontal, 
                                            i18n("Extra Information in Thumbnails View"),
                                            parent);

   iconShowNameBox_ = new QCheckBox(iconTextGroup);
   iconShowNameBox_->setText(i18n("Show file name"));

   iconShowTagsBox_ = new QCheckBox(iconTextGroup);
   iconShowTagsBox_->setText(i18n("Show file tags"));

   iconShowSizeBox_ = new QCheckBox(iconTextGroup);
   iconShowSizeBox_->setText(i18n("Show file size"));

   iconShowDateBox_ = new QCheckBox(iconTextGroup);
   iconShowDateBox_->setText(i18n("Show file modification date"));

   iconShowCommentsBox_ = new QCheckBox(iconTextGroup);
   iconShowCommentsBox_->setText(i18n("Show Digikam comments"));

   iconShowFileCommentsBox_ = new QCheckBox(iconTextGroup);
   iconShowFileCommentsBox_->setText(i18n("Show comments stored in file (Warning: Slow)"));

   iconShowResolutionBox_ = new QCheckBox(iconTextGroup);
   iconShowResolutionBox_->setText(i18n("Show image dimensions (Warning: Slow)"));

   layout->addWidget(iconTextGroup);
   
   // --------------------------------------------------------

   layout->addStretch();

   readSettings();
}

SetupGeneral::~SetupGeneral()
{
}

void SetupGeneral::applySettings()
{
    AlbumSettings* settings = AlbumSettings::instance();
    
    if (!settings) return;

    settings->setAlbumLibraryPath(albumPathEdit->text());
    
    int iconSize = ThumbnailSize::Medium;
    
    if (smallIconButton_->isChecked())
        iconSize = ThumbnailSize::Small;
    
    if (largeIconButton_->isChecked())
        iconSize = ThumbnailSize::Large;
    
    if (hugeIconButton_->isChecked())
        iconSize = ThumbnailSize::Huge;
    
    settings->setDefaultIconSize(iconSize);
    settings->setRecurseTags(recurseTagsBox_->isChecked());
        
    settings->setIconShowName(iconShowNameBox_->isChecked());
    settings->setIconShowTags(iconShowTagsBox_->isChecked());
    settings->setIconShowSize(iconShowSizeBox_->isChecked());
    settings->setIconShowDate(iconShowDateBox_->isChecked());
    settings->setIconShowResolution(iconShowResolutionBox_->isChecked());
    settings->setIconShowComments(iconShowCommentsBox_->isChecked());
    settings->setIconShowFileComments(iconShowFileCommentsBox_->isChecked());

    settings->saveSettings();
}

void SetupGeneral::readSettings()
{
    AlbumSettings* settings = AlbumSettings::instance();
    
    if (!settings) return;

    albumPathEdit->setText(settings->getAlbumLibraryPath());
    
    switch(settings->getDefaultIconSize()) {
    case(ThumbnailSize::Small): {
        smallIconButton_->setChecked(true);
        break;
    }
    case(ThumbnailSize::Large): {
        largeIconButton_->setChecked(true);
        break;
    }
    case(ThumbnailSize::Huge): {
        hugeIconButton_->setChecked(true);
        break;
    }
    default:
        mediumIconButton_->setChecked(true);
        break;
    }

    recurseTagsBox_->setChecked(settings->getRecurseTags());
    
    iconShowNameBox_->setChecked(settings->getIconShowName());
    iconShowTagsBox_->setChecked(settings->getIconShowTags());
    iconShowSizeBox_->setChecked(settings->getIconShowSize());
    iconShowDateBox_->setChecked(settings->getIconShowDate());
    iconShowResolutionBox_->setChecked(settings->getIconShowResolution());
    iconShowCommentsBox_->setChecked(settings->getIconShowComments());
    iconShowFileCommentsBox_->setChecked(settings->getIconShowFileComments());
}

void SetupGeneral::slotChangeAlbumPath()
{
    QString  result =
        KFileDialog::getExistingDirectory(
            albumPathEdit->text(),
            this);

    if (KURL(result).equals(KURL(QDir::homeDirPath()), true)) {
        KMessageBox::sorry(0, i18n("Sorry; cannot use home directory as Albums library."));
        return;
    }

    if (!result.isEmpty()) {
        albumPathEdit->setText(result);
    }
}


#include "setupgeneral.moc"
