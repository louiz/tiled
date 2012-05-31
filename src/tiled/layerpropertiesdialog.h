/*
 * layerpropertiesdialog.h
 * Copyright 2009-2010, Thorbjørn Lindeijer <thorbjorn@lindeijer.nl>
 * Copyright 2010, Michael Woerister <michaelwoerister@gmail.com>
 * Copyright 20012, Florent Le Coz <louiz@louiz.org>
 *
 * This file is part of Tiled.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LAYERPROPERTIESDIALOG_H
#define LAYERPROPERTIESDIALOG_H

#include "propertiesdialog.h"
#include "mapdocument.h"
#include "layer.h"

#include <QSpinBox>

namespace Tiled {
namespace Internal {

class LayerPropertiesDialog: public PropertiesDialog
{
  Q_OBJECT

  public:
  LayerPropertiesDialog(const QString &kind,
                        Layer *layer,
                        MapDocument *MapDocument,
                        QWidget *parent = 0);
  void accept();

protected:
  MapDocument *mMapDocument;

private:
  Layer* mLayer;
  QSpinBox *mXSpin;
  QSpinBox *mYSpin;
};

} // Internal namespace
} // Tiled namespace


#endif // LAYERPROPERTIESDIALOG_H
