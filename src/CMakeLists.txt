set(includeDir "${PROJECT_SOURCE_DIR}/include")

set(headers

        "${includeDir}/geo/MapView.hpp"

        "${includeDir}/geo/lod/LODControl.hpp"
        "${includeDir}/geo/lod/LODFrustum.hpp"
        "${includeDir}/geo/lod/LODRadial.hpp"
        "${includeDir}/geo/lod/LODRaycast.hpp"

        "${includeDir}/geo/nodes/MapNode.hpp"
        "${includeDir}/geo/nodes/MapPlaneNode.hpp"

        "${includeDir}/geo/geometries/MapNodeGeometry.hpp"

        "${includeDir}/geo/providers/MapProvider.hpp"
        "${includeDir}/geo/providers/BingMapsProvider.hpp"
        "${includeDir}/geo/providers/DebugMapsProvider.hpp"
        "${includeDir}/geo/providers/OpenStreetMapsProvider.hpp"

        "${includeDir}/geo/utils/UnitUtils.hpp"
        "${includeDir}/geo/utils/URLFetcher.hpp"
)

set(sources
        "LODRaycast.cpp"
        "MapNode.cpp"
        "MapView.cpp"
)

add_library(geolib ${sources} ${headers})
target_include_directories(geolib PUBLIC "${includeDir}")
target_link_libraries(geolib PUBLIC threepp::threepp CURL::libcurl)
