#pragma once
#include <map>
#include <memory>
#include <cassert>
#include <SFML/Graphics.hpp>
#include "TextureIDs.hpp"

class TextureHolder
{
public:
	void load(TextureIDs id, const std::string& filename);
	sf::Texture& get(TextureIDs id);
	const sf::Texture& get(TextureIDs id) const;
private:
	std::map<TextureIDs, std::unique_ptr<sf::Texture>> mTextureMap;
};