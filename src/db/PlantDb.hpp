//
// Created by crabletchen on 2022/1/19.
//

#ifndef PRINCESSSGARDENSERVER_PLANTDB_HPP
#define PRINCESSSGARDENSERVER_PLANTDB_HPP

#include "oatpp-sqlite/orm.hpp"

#include "dto/DTOs.hpp"

#include OATPP_CODEGEN_BEGIN(DbClient)

class PlantDb : public oatpp::orm::DbClient
{
public:
    explicit PlantDb(const std::shared_ptr<oatpp::orm::Executor> &executor)
        : oatpp::orm::DbClient(executor)
    {
        oatpp::orm::SchemaMigration migration(executor);
        migration.addFile(1, DATABASE_MIGRATIONS "PlantInit.sql");
        migration.migrate();

        auto version = executor->getSchemaVersion();
        OATPP_LOGD("PlantDb", "Migration - OK. Version=%lld.", version);
    }

    QUERY(createPlant,
          "INSERT INTO Plant "
          "(name, maturity) VALUES "
          "(:plant.name, :plant.maturity);",
          PARAM(oatpp::Object<PlantStatusDto>, plant));
};

#include OATPP_CODEGEN_END(DbClient)

#endif //PRINCESSSGARDENSERVER_PLANTDB_HPP
