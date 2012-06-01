/*
 * layerpropertiesdialog.cpp
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

#include "layerpropertiesdialog.h"
#include "changelayerproperties.h"
#include "mapdocument.h"
#include "mapobject.h"
#include "layer.h"

#include <QSpinBox>
#include <QGridLayout>
#include <QLabel>
#include <QUndoStack>

using namespace Tiled;
using namespace Tiled::Internal;

LayerPropertiesDialog::LayerPropertiesDialog(
                                             const QString &kind,
                                             Layer *layer,
                                             MapDocument *mapDocument,
                                             QWidget *parent):
  PropertiesDialog(kind,
                   layer,
                   mapDocument->undoStack(),
                   parent),
  mMapDocument(mapDocument),
  mLayer(layer)
{
  // TODO init the spins with the layer values.
  QGridLayout *grid = new QGridLayout;
  mXSpin = new QSpinBox;
  mXSpin->setSuffix(tr(" px"));
  mXSpin->setValue(layer->getOffset().x());

  mYSpin = new QSpinBox;
  mYSpin->setSuffix(tr(" px"));
  mYSpin->setValue(layer->getOffset().y());

  grid->addWidget(new QLabel(tr("X offset")), 0, 0);
  grid->addWidget(mXSpin, 0, 1);
  grid->addWidget(new QLabel(tr("Y offset")), 1, 0);
  grid->addWidget(mYSpin, 1, 1);
  qobject_cast<QBoxLayout*>(layout())->insertLayout(0, grid);
}

void LayerPropertiesDialog::accept()
{
  QUndoStack *undoStack = mMapDocument->undoStack();
  QPoint newOffset(mXSpin->value(), mYSpin->value());
  undoStack->push(new ChangeLayerProperties(
                            mMapDocument,
                            mLayer,
                            newOffset));
  PropertiesDialog::accept();
}
