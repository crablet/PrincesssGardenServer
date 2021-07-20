//
// Created by crabletchen on 2022/1/23.
//

#ifndef PRINCESSSGARDENSERVER_DATABASECOMPONENT_HPP
#define PRINCESSSGARDENSERVER_DATABASECOMPONENT_HPP

#include "db/PlantDb.hpp"

class DatabaseComponent
{
public:
    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::provider::Provider<oatpp::sqlite::Connection>>,
                           dbConnectionProvider)([]
    {
    }());
};

#endif //PRINCESSSGARDENSERVER_DATABASECOMPONENT_HPP
