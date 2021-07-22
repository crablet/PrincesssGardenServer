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
        // todo: 这里应该从配置文件里读位置，禁止硬编码
        migration.addFile(1, "/home/ubuntu/PrincesssGardenServer/sql/PlantInit.sql");
        migration.migrate();

        auto version = executor->getSchemaVersion();
        OATPP_LOGD("PlantDb", "Migration - OK. Version=%lld.", version);
    }

    QUERY(createPlant,
          "INSERT INTO Plant "
          "(name, maturity) VALUES "
          "(:plant.name, :plant.maturity);",
          PARAM(oatpp::Object<PlantStatusDto>, plant));

    QUERY(getPlantById,
          "SELECT * FROM Plant WHERE id=:id",
          PARAM(oatpp::Int32, id))
};

#include OATPP_CODEGEN_END(DbClient)

#endif //PRINCESSSGARDENSERVER_PLANTDB_HPP
