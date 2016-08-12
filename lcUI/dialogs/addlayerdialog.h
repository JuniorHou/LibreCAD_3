#pragma once

#include <QDialog>
#include <QColorDialog>
#include <QToolTip>
#include <QFormLayout>

#include "widgets/linepatternselect.h"
#include "widgets/linewidthselect.h"
#include "widgets/colorselect.h"

#include <cad/meta/layer.h>
#include <cad/meta/metalinewidth.h>
#include <cad/document/document.h>

namespace Ui {
    class AddLayerDialog;
}

class AddLayerDialog : public QDialog {
    Q_OBJECT

    public:
        AddLayerDialog(lc::Document_SPtr document, QWidget* parent = 0);
        AddLayerDialog(lc::Layer_CSPtr oldLayer, lc::Document_SPtr document, QWidget* parent = 0);
        ~AddLayerDialog();

    signals:
        void newLayer(lc::Layer_CSPtr);
        void editLayer(lc::Layer_CSPtr oldLayer, lc::Layer_CSPtr newLayer);

    private slots:
        void accept();

    protected:
        Ui::AddLayerDialog* ui;
        LinePatternSelect* linePatternSelect;
        LineWidthSelect* lineWidthSelect;
        ColorSelect* colorSelect;

    private:
        lc::Layer_CSPtr _oldLayer;
};