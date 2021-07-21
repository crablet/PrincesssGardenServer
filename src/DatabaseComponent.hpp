//
// Created by crabletchen on 2022/1/23.
//

#ifndef PRINCESSSGARDENSERVER_DATABASECOMPONENT_HPP
#define PRINCESSSGARDENSERVER_DATABASECOMPONENT_HPP

#include "db/PlantDb.hpp"

class DatabaseComponent
{
public:
    /**
     * Create database client
     */
    OATPP_CREATE_COMPONENT(std::shared_ptr<PlantDb>, plantDb)([] {

        /* Get database ConnectionProvider component */
        OATPP_COMPONENT(std::shared_ptr<oatpp::provider::Provider<oatpp::sqlite::Connection>>, connectionProvider);

        /* Create database-specific Executor */
        auto executor = std::make_shared<oatpp::sqlite::Executor>(connectionProvider);

        /* Create MyClient database client */
        return std::make_shared<PlantDb>(executor);

    }());
};

#endif //PRINCESSSGARDENSERVER_DATABASECOMPONENT_HPP
