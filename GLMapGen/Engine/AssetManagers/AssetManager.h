#pragma once
#include <memory>
#include <map>

template <class T>
class AssetManager {
public:
	typedef std::shared_ptr<T> PTR;

	PTR add(std::string name, T& asset) {
		mAssets.insert(std::make_pair(name,std::make_shared<T>(asset)));
		return mAssets.at(name);
		
	}

	PTR add(std::string name, PTR assetPtr) {
		mAssets.insert(std::make_pair(name, assetPtr));
	}

	PTR get(std::string name) {
		auto it = mAssets.find(name);
		if (it == mAssets.end()) {
			return nullptr;
		} else {
			return *it;
		}
	}
	

private:
	std::map<std::string, PTR> mAssets;

};