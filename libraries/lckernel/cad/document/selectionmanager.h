#ifndef SELECTIONMANAGER_H
#define SELECTIONMANAGER_H

#include <QObject>
#include <QPoint>
#include <QList>

#include "cad/const.h"

#include "cad/geometry/geoarea.h"
#include "cad/vo/entitydistance.h"
#include "cad/base/cadentity.h"

namespace lc {

    class SelectionManager : public QObject {
            Q_OBJECT
        public:
            /**
              * Return a list of entities within a distance from a coordinate
              *
              * @param Coordinate   coordinate to test again
              * @param double within what distance the entity must be
              * @return QList<EntityDistance> list of EntityDistance objects
              */
            virtual QList<EntityDistance> getEntitiesNearCoordinate(const geo::Coordinate& coordinate, double withinDistance) const = 0;

            /**
              * Return a list of entities within a specific area
              *
              * @param Area Area to find entities in
              * @return QList<CADEntityPtr> List of CAD Entities
              */
            virtual QList<CADEntityPtr> getEntitiesInArea(const geo::Area& area) const = 0;

    };
    typedef shared_ptr<lc::SelectionManager> SelectionManagerPtr;

}
#endif // SELECTIONMANAGER_H
