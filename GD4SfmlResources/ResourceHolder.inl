template<typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string& filename)
{
	//Create and load the resource
	std::unique_ptr<Resource> resource = std::make_unique<Resource>();
	if (!resource->loadFromFile(filename))
	{
		throw std::runtime_error("ResourceHolder::load - failed to load " + filename);
	}
	//if loading is successful, insert resource into map
	insertResource(id, std::move(resource));
}

template<typename Resource, typename Identifier>
template<typename Parameter>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string& filename, const Parameter& secondParameter)
{
	//Create and load the resource
	std::unique_ptr<Resource> resource = std::make_unique<Resource>();
	if (!resource.loadFromFile(filename, secondParameter))
	{
		throw std::runtime_error("ResourceHolder::load - failed to load " + filename);
	}
	//if loading is successful, insert resource into map
	insertResource(id, std::move(resource));
}


template<typename Resource, typename Identifier>
Resource& ResourceHolder<Resource, Identifier>::get(Identifier id)
{
	auto found = mResourceMap.find(id);
	assert(found != mResourceMap.end());
	return *(found->second);
}

template<typename Resource, typename Identifier>
const Resource& ResourceHolder<Resource, Identifier>::get(Identifier id) const
{
	auto found = mResourceMap.find(id);
	assert(found != mResourceMap.end());
	return *(found->second);
}

template<typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::insertResource(Identifier id, std::unique_ptr<Resource> resource)
{
	//Insert and check for success
	auto inserted = mResourceMap.insert(std::make_pair(id, std::move(resource)));
	assert(inserted.second);
}


