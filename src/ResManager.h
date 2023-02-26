//
// Created by tursh on 2/26/23.
//

#ifndef GRINDGAME_RESMANAGER_H
#define GRINDGAME_RESMANAGER_H

#include <map>
#include <raylib.h>
#include "TextureAtlas.h"

typedef const void *Resource;
typedef struct AtlasInfo
{
	Resource textureRes;
	Vector2 size;
} AtlasInfo;

#define ATLAS_TINY_DUNGEON {ResManager::TINY_DUNGEON_TEXTURE, {12, 11}}

/**
 * Resource manager singleton
 */
class ResManager
{
	std::map<Resource, Texture2D> textureBuffer;

protected:
	ResManager() = default;

public:
	ResManager(ResManager const &) = delete;

	void operator=(ResManager const &) = delete;

	static ResManager &getInstance();

	constexpr const static Resource TINY_DUNGEON_TEXTURE = (void *) "res/tiny-dungeon-atlas.png";

	/**
	 * Checkup if resource was already loaded then return it, else it loads it into memory.
	 * @param res [ResManager::*]. must not be a local string.
	 * Don't do `getTexture("myresource")`, use as `getTexture(ResManager::MY_RESOURCE)`
	 * @return Texture2D ref
	 */
	Texture2D &getTexture(Resource res);

	/**
	 * Get texture and calculate sprite size
	 * @param atlasInfo Atlas texture resource info and size. Check [ResManager::*]
	 * @return Texture atlas
	 */
	TextureAtlas getTextureAtlas(AtlasInfo atlasInfo);
};


#endif //GRINDGAME_RESMANAGER_H
