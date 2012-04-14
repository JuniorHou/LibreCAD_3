#ifndef SELECTIONMANAGERIMPL_H
#define SELECTIONMANAGERIMPL_H

#include <QGraphicsView>

#include "cad/const.h"

#include "cad/document/selectionmanager.h"
#include "cad/document/layermanager.h"
#include "cad/base/cadentity.h"

/**
  * Selection manager can be used to request the selected items on the screen
  * It uses QGraphicsView to get a list of possible items that can be selected because QGraphicsView uses BSP for some function that returns itmes in a area.
  * This will reduce the number of hit test when zoomed in into portions of tgeh drawing
  */
class SelectionManagerImpl : public lc::SelectionManager {
    public:
        SelectionManagerImpl(lc::LayerManagerPtr layerManager, QGraphicsView* scene);

        virtual QList<lc::EntityDistance> getEntitiesNearCoordinate(const lc::geo::Coordinate& point, double distance) const;
        virtual QList<lc::CADEntityPtr> getEntitiesInArea(const lc::geo::Area& area) const;

    public slots:

    private:
        lc::LayerManagerPtr _layerManager;
        QGraphicsView* _view;
};
#endif // SELECTIONMANAGERIMPL_H
