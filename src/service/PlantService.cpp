//
// Created by crabletchen on 2022/1/19.
//

#include "PlantService.h"

oatpp::Object<PlantStatusDto> PlantService::createPlant(const oatpp::Object<PlantStatusDto> &dto)
{
    auto dbResult = database->createPlant(dto);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

    // todo: 补充完整这个函数
    return {};
}
