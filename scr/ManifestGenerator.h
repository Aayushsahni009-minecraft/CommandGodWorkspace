#pragma once
#include <nlohmann/json.hpp>
#include <string>

using json = nlohmann::json;

class ManifestGenerator {
public:
    static std::string CreateBehaviorPackManifest(const std::string& packName, const std::string& description) {
        json manifest;
        
        manifest["format_version"] = 2;
        manifest["header"] = {
            {"name", packName},
            {"description", description},
            {"uuid", "YOUR-DYNAMIC-UUID-HERE"}, // You'll want to add a UUID generator function later
            {"version", {1, 0, 0}},
            {"min_engine_version", {1, 20, 0}}
        };
        manifest["modules"] = json::array({{
            {"type", "data"},
            {"uuid", "SECOND-DYNAMIC-UUID-HERE"},
            {"version", {1, 0, 0}}
        }});

        // The '4' adds indentation so the JSON is highly readable
        return manifest.dump(4); 
    }
};