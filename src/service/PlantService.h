//
// Created by crabletchen on 2022/1/19.
//

#ifndef PRINCESSSGARDENSERVER_PLANTSERVICE_H
#define PRINCESSSGARDENSERVER_PLANTSERVICE_H

#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/core/macro/component.hpp"

#include "dto/DTOs.hpp"
#include "db/PlantDb.hpp"

class PlantService
{
private:
    using Status = oatpp::web::protocol::http::Status;

private:
    OATPP_COMPONENT(std::shared_ptr<PlantDb>, database);

public:
    oatpp::Object<PlantStatusDto> createPlant(const oatpp::Object<PlantStatusDto> &dto);
    oatpp::Object<PlantStatusDto> getPlantById(const oatpp::Int32 &id,
                                               const oatpp::provider::ResourceHandle<oatpp::orm::Connection> &connection = nullptr);
};


#endif //PRINCESSSGARDENSERVER_PLANTSERVICE_H
