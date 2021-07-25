// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// AssetManager.h                                                            //
// ========================================================================= //

#ifndef ASSET_MANAGER_H_
#define ASSET_MANAGER_H_

#include "univer/core/UDefines.h"

#include <string>
#include <memory>

namespace univer { class ImageAsset; }
namespace univer { class SoundAsset; }
namespace univer { class ImageInAtlas; }
namespace univer { class TextLoader; }
namespace univer { class AssetManagerImpl; }
namespace univer { class Asset; }

namespace univer
{
class UVR_API AssetManager
{
public:
	static AssetManager& GetInstance()
	{
		static AssetManager instance;
		return instance;
	}

public:
	~AssetManager();

	const bool existsAsset( const std::string& path ) const;
	const std::unique_ptr< Asset >& getAsset( const std::string& path ) const;

	std::string getAssetPath( const std::string& filename ) const;

	const ImageAsset* getImageAsset( const std::string& path ) const;
	const SoundAsset* getSoundAsset( const std::string& path ) const;
	std::string getTextAsset( const std::string& path ) const;

	bool loadAssetGroup( const std::string& group );
	bool unloadAssetGroup( const std::string& group );

	bool loadAtlasBundle( const std::string& xmlPath );
	bool unloadAtlasBundle( const std::string& xmlPath );

	bool existsImageInAtlasBundles( const std::string& name, std::string& bundleContainer ) const;
	const std::unique_ptr< ImageInAtlas >& getImageInAtlas( const std::string& bundleContainer, const std::string& name ) const;

	bool loadText( const std::string& xmlPath );
	const std::unique_ptr< TextLoader >& textLoader() const;

	void clearAll();

private:
	explicit AssetManager();
	AssetManager( const AssetManager& am ) = delete;
	AssetManager& operator=( const AssetManager& ) = delete;

private:
	AssetManagerImpl* m_pimpl;

};
}

#endif // ASSET_MANAGER_H_