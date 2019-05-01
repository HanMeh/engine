/**
 * @file
 */

#include "LayerWindow.h"
#include "core/Assert.h"
#include "core/App.h"
#include "io/Filesystem.h"
#include "tb_message_window.h"
#include "tb_editfield.h"
#include "tb_language.h"
#include "tb_widgets_reader.h"

namespace voxedit {

LayerWindow::LayerWindow(tb::TBWidget *target, const tb::TBID &id, LayerSettings& layerSettings, LayerWindowSettings* settings) :
		Super(target, id, "ui/window/voxedit-layer.tb.txt"), _layerSettings(layerSettings) {
	if (settings != nullptr) {
		_layerWindowSettings = *settings;
	}
}

void LayerWindow::onCreate() {
	if (tb::TBEditField* f = getWidgetByIDAndType<tb::TBEditField>("pos.x")) {
		f->setTextFormatted("%i", _layerSettings.position.x);
	}
	if (tb::TBEditField* f = getWidgetByIDAndType<tb::TBEditField>("pos.y")) {
		f->setTextFormatted("%i", _layerSettings.position.y);
	}
	if (tb::TBEditField* f = getWidgetByIDAndType<tb::TBEditField>("pos.z")) {
		f->setTextFormatted("%i", _layerSettings.position.z);
	}

	if (tb::TBEditField* f = getWidgetByIDAndType<tb::TBEditField>("size.x")) {
		f->setTextFormatted("%i", _layerSettings.size.x);
	}
	if (tb::TBEditField* f = getWidgetByIDAndType<tb::TBEditField>("size.y")) {
		f->setTextFormatted("%i", _layerSettings.size.y);
	}
	if (tb::TBEditField* f = getWidgetByIDAndType<tb::TBEditField>("size.z")) {
		f->setTextFormatted("%i", _layerSettings.size.z);
	}
	if (tb::TBEditField* f = getWidgetByIDAndType<tb::TBEditField>("name")) {
		f->setText(_layerSettings.name.c_str());
	}

	if (_layerWindowSettings.type == LayerWindowType::NewScene) {
		setText(tr("New Scene"));
	} else if (_layerWindowSettings.type == LayerWindowType::Create) {
		setText(tr("New Layer"));
	} else if (_layerWindowSettings.type == LayerWindowType::Edit) {
		setText(tr("Edit Layer"));
	}
}

bool LayerWindow::onEvent(const tb::TBWidgetEvent &ev) {
	if (ev.type == tb::EVENT_TYPE_CHANGED) {
		if (ev.target->getID() == TBIDC("pos.x")) {
			_layerSettings.position.x = atoi(ev.target->getText().c_str());
			return true;
		} else if (ev.target->getID() == TBIDC("pos.y")) {
			_layerSettings.position.y = atoi(ev.target->getText().c_str());
			return true;
		} else if (ev.target->getID() == TBIDC("pos.z")) {
			_layerSettings.position.z = atoi(ev.target->getText().c_str());
			return true;
		} else if (ev.target->getID() == TBIDC("size.x")) {
			_layerSettings.size.x = atoi(ev.target->getText().c_str());
			return true;
		} else if (ev.target->getID() == TBIDC("size.y")) {
			_layerSettings.size.y = atoi(ev.target->getText().c_str());
			return true;
		} else if (ev.target->getID() == TBIDC("size.z")) {
			_layerSettings.size.z = atoi(ev.target->getText().c_str());
			return true;
		} else if (ev.target->getID() == TBIDC("name")) {
			_layerSettings.name = ev.target->getText().c_str();
			return true;
		}
	}
	return Super::onEvent(ev);
}

}
