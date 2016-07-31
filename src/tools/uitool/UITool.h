/**
 * @file
 */

#pragma once

#include "core/App.h"
#include "ui/TurboBadger.h"
#include "ui/UIDummies.h"

class UITool: public core::App {
private:
	DummyRenderer _renderer;
public:
	UITool(io::FilesystemPtr filesystem, core::EventBusPtr eventBus);

	core::AppState onInit() override;
	core::AppState onRunning() override;
	core::AppState onCleanup() override;
};
