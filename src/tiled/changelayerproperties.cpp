/*
 * changelayerproperties.cpp
 * Copyright 2010, Jeff Bland <jksb@member.fsf.org>
 * Copyright 2010, Thorbjørn Lindeijer <thorbjorn@lindeijer.nl>
 * Copyright 2011, Gregory Nickonov <gregory@nickonov.ru>
 * Copyright 2012, Le Coz Florent <louiz@louiz.org>
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

#include "changelayerproperties.h"
#include "mapdocument.h"
#include "layer.h"

#include <QCoreApplication>

using namespace Tiled;
using namespace Tiled::Internal;

ChangeLayerProperties::ChangeLayerProperties(MapDocument *mapDocument,
                                             Layer *layer,
                                             const QPoint &newOffset):
  QUndoCommand(
      QCoreApplication::translate(
          "Undo Commands", "Change Layer Properties")),
  mMapDocument(mapDocument),
  mLayer(layer),
  mUndoOffset(layer->getOffset()),
  mRedoOffset(newOffset)
{
}

#include <iostream>

void ChangeLayerProperties::redo()
{
  mLayer->setOffset(mRedoOffset);
}

void ChangeLayerProperties::undo()
{
  mLayer->setOffset(mUndoOffset);
}
