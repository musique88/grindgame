//
// Created by tursh on 2/26/23.
//

#include "ResManager.h"

class ResManagerConstruct : public ResManager
{
public:
	ResManagerConstruct() : ResManager() {}
};

Texture2D &ResManager::getTexture(Resource res)
{
	auto it = textureBuffer.find(res);

	if (it == textureBuffer.end())
	{
		Texture2D newTexture = LoadTexture((const char *) res);
		textureBuffer[res] = newTexture;
		return textureBuffer[res];
	}

	return it->second;
}

ResManager &ResManager::getInstance()
{
	static ResManagerConstruct resManager;
	return resManager;
}

TextureAtlas ResManager::getTextureAtlas(AtlasInfo atlasInfo)
{
	return {getTexture(atlasInfo.textureRes), atlasInfo.size};
}
