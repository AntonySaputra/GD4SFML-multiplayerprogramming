#include "TextureHolder.hpp"

void TextureHolder::load(TextureIDs id, const std::string& filename)
{
	std::unique_ptr<sf::Texture> texture = std::make_unique<sf::Texture>();
	if (!texture->loadFromFile(filename))
	{
		throw std::runtime_error("Textureholder::load - Failed to load " + filename);
	}
	auto inserted = mTextureMap.insert(std::make_pair(id, std::move(texture)));
	assert(inserted.second);
}

sf::Texture& TextureHolder::get(TextureIDs id)
{
	auto found = mTextureMap.find(id);
	assert(found != mTextureMap.end());
	return *(found->second);
}

const sf::Texture& TextureHolder::get(TextureIDs id) const
{
	auto found = mTextureMap.find(id);
	assert(found != mTextureMap.end());
	return *(found->second);
}
