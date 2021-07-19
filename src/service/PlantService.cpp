//
// Created by crabletchen on 2022/1/19.
//

#include "PlantService.h"

oatpp::Object<PlantStatusDto> PlantService::createPlant(const oatpp::Object<PlantStatusDto> &dto)
{
    auto dbResult = database->createPlant(dto);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

    auto plantId = oatpp::sqlite::Utils::getLastInsertRowId(dbResult->getConnection());
    return getPlantById(static_cast<v_int32>(plantId));
}

oatpp::Object<PlantStatusDto> PlantService::getPlantById(const oatpp::Int32 &id,
                                                         const oatpp::provider::ResourceHandle<oatpp::orm::Connection> &connection)
{
    auto dbResult = database->getPlantById(id, connection);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Plant not found");

    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<PlantStatusDto>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");

    return result[0];
}
