/**
 * @file
 */

#pragma once

#include "CharacterSkeletonAttribute.h"
#include "animation/AnimationSettings.h"
#include "core/String.h"
#include "core/Common.h"
#include <string>
#include <array>
#include <stdint.h>

namespace animation {

/**
 * @brief Attributes for the character meshes
 * @sa CharacterSkeletonAttribute
 */
struct CharacterSettings : public AnimationSettings {
	CharacterSkeletonAttribute skeletonAttr;
};

extern bool loadCharacterSettings(const std::string& luaString, CharacterSettings& settings);

}
