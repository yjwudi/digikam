/** ===========================================================
 * @file
 *
 * This file is a part of digiKam project
 * <a href="http://www.digikam.org">http://www.digikam.org</a>
 *
 * @date  2013-05-18
 * @brief Wrapper class for face recognition
 *
 * @author Copyright (C) 2013 by Marcel Wiesweg
 *         <a href="mailto:marcel dot wiesweg at gmx dot de">marcel dot wiesweg at gmx dot de</a>
 * @author Copyright (C) 2014-2017 by Gilles Caulier
 *         <a href="mailto:caulier dot gilles at gmail dot com">caulier dot gilles at gmail dot com</a>
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GNU General
 * Public License as published by the Free Software Foundation;
 * either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * ============================================================ */

#ifndef FACESENGINE_IDENTITY_H
#define FACESENGINE_IDENTITY_H

// Qt includes

#include <QMap>
#include <QString>
#include <QExplicitlySharedDataPointer>

// Local includes

#include "digikam_export.h"

namespace FacesEngine
{

class DIGIKAM_DATABASE_EXPORT Identity
{

public:

    /**
     * Wraps a face recognition Identity.
     * An identity refers to a natural person.
     * There is an internal id which is used the FacesEngine storage,
     * and a number of attributes which map the identity to the outside.
     * Prespecified attributes:
     * "fullName"   The full name as on the ID card, e.g. "Peter Brown"
     * "name"       The person's name without further specification, e.g. "Peter" or "Dad"
     * "uuid"        A UUID that is assigned to each new identity at creation.
     *
     * For fullName and name, multiple values are allowed.
     *
     * Attributes can be used to map an identity to other fields and services where
     * natural persons play a role.
     */
    Identity();
    Identity(const Identity& other);
    ~Identity();

    Identity& operator=(const Identity& other);

    bool isNull()                          const;
    bool operator==(const Identity& other) const;

    /** Id value accessor.
     */
    int  id() const;
    void setId(int id);

    /** Attribute value accessor.
     */
    QString attribute(const QString& att) const;
    void    setAttribute(const QString& att, const QString& val);

    /** Attributes map accessor.
     */
    QMap<QString, QString> attributesMap() const;
    void setAttributesMap(const QMap<QString, QString>& attributes);

private:

    class Private;
    QExplicitlySharedDataPointer<Private> d;
};

} // namespace FacesEngine

#endif // FACESENGINE_IDENTITY_H
