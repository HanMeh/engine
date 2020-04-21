/**
 * @file
 */

#pragma once

#include "ui/imgui/IMGUIApp.h"
#include "RenderShaders.h"
#include "voxelrender/WorldRenderer.h"
#include "frontend/ClientEntity.h"
#include "frontend/PlayerAction.h"
#include "render/Axis.h"
#include "frontend/PlayerMovement.h"
#include "voxelrender/PlayerCamera.h"
#include "voxelformat/MeshCache.h"
#include "voxelworld/CachedFloorResolver.h"
#include "video/Camera.h"
#include "animation/AnimationCache.h"
#include "video/Buffer.h"
#include "voxelworld/WorldMgr.h"
#include "voxelworld/WorldPager.h"
#include "stock/Stock.h"
#include "stock/StockDataProvider.h"
#include "testcore/DepthBufferRenderer.h"

/**
 * @brief This is the map viewer
 *
 * @ingroup Tools
 */
class MapView: public ui::imgui::IMGUIApp {
protected:
	using Super = ui::imgui::IMGUIApp;
	animation::AnimationCachePtr _animationCache;
	voxelrender::WorldRenderer _worldRenderer;
	voxelworld::WorldMgrPtr _worldMgr;
	voxelworld::WorldPagerPtr _worldPager;
	render::Axis _axis;
	core::VarPtr _rotationSpeed;
	frontend::ClientEntityPtr _entity;
	frontend::PlayerMovement _movement;
	frontend::PlayerAction _action;
	stock::StockDataProviderPtr _stockDataProvider;
	voxelformat::VolumeCachePtr _volumeCache;
	voxelformat::MeshCachePtr _meshCache;
	voxelrender::PlayerCamera _camera;
	testcore::DepthBufferRenderer _depthBufferRenderer;
	voxelworld::CachedFloorResolver _floorResolver;

	bool _lineModeRendering = false;
	bool _freelook = false;
	bool _updateWorld = true;
	int _drawCallsWorld = 0;
	float _timeScaleFactor = 480.0f;
	float _worldTime = 0.0f;

	core::VarPtr _meshSize;

	glm::ivec3 _singleExtractionPoint = glm::zero<glm::ivec3>();
	/**
	 * @brief Used for debugging a single position mesh extraction in the world
	 */
	bool _singlePosExtraction = false;

	bool onKeyPress(int32_t key, int16_t modifier) override;
	void onWindowResize(int windowWidth, int windowHeight) override;
	void beforeUI() override;

public:
	MapView(const metric::MetricPtr& metric, const animation::AnimationCachePtr& animationCache,
			const stock::StockDataProviderPtr& stockDataProvider,
			const io::FilesystemPtr& filesystem, const core::EventBusPtr& eventBus,
			const core::TimeProviderPtr& timeProvider, const voxelworld::WorldMgrPtr& world,
			const voxelworld::WorldPagerPtr& worldPager,
			const voxelformat::VolumeCachePtr& volumeCache,
			const voxelformat::MeshCachePtr& meshCache);
	~MapView();

	core::AppState onConstruct() override;
	core::AppState onInit() override;
	void onRenderUI() override;
	core::AppState onCleanup() override;
	core::AppState onRunning() override;
};
