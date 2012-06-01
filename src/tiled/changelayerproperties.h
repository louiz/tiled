/*
 * changelayerproperties.h
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

#ifndef CHANGELAYERPROPERTIES_H
#define CHANGELAYERPROPERTIES_H

#include <QPoint>
#include <QUndoCommand>

namespace Tiled {

class Layer;

namespace Internal {

class MapDocument;

class ChangeLayerProperties : public QUndoCommand
{
public:
    /**
     * Constructs a new 'Change Layer Properties' command.
     *
     * @param mapDocument   the map document of the layer's map
     * @param layer         the layer to modify
     * @param newOffset     the new offset to apply
     */
    ChangeLayerProperties(MapDocument *mapDocument,
                               Layer *layer,
                               const QPoint &newOffset);

    void undo();
    void redo();

private:
    MapDocument *mMapDocument;
    Layer *mLayer;
    const QPoint mUndoOffset;
    const QPoint mRedoOffset;
};

} // namespace Internal
} // namespace Tiled

#endif // CHANGELAYERPROPERTIES_H
