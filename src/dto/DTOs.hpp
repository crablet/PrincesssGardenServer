//
// Created by crablet on 2022/1/13.
//

#ifndef PRINCESSSGARDENSERVER_DTOS_HPP
#define PRINCESSSGARDENSERVER_DTOS_HPP

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 *  Data Transfer Object. Object containing fields only.
 *  Used in API for serialization/deserialization and validation
 */
class MyDto : public oatpp::DTO
{
    DTO_INIT(MyDto, DTO)

    DTO_FIELD(Int32, statusCode);
    DTO_FIELD(String, message);
};

class TestGetParamDto : public oatpp::DTO
{
    DTO_INIT(TestGetParamDto, DTO)

    DTO_FIELD(Int32, statusCode);
    DTO_FIELD(String, param);
};

class TimeMachineDto : public oatpp::DTO
{
    DTO_INIT(TimeMachineDto, DTO)

    DTO_FIELD(Int32, statusCode);
    DTO_FIELD(Int32, year);
    DTO_FIELD(Int32, month);
    DTO_FIELD(Int32, day);
    DTO_FIELD(String, textTitle);
    DTO_FIELD(String, textBody);
    DTO_FIELD(String, gift);
};

class PlantStatusDto : public oatpp::DTO
{
    DTO_INIT(PlantStatusDto, DTO)

    DTO_FIELD(Int32, id);           // 唯一id
    DTO_FIELD(String, name);                    // 名称
    DTO_FIELD(Int32, maturity);     // 成熟时间
    DTO_FIELD(Int32, growth);       // 成长值
    DTO_FIELD(Int32, period);       // 第几期
    DTO_FIELD(Int32, sun);          // 阳光值
    DTO_FIELD(Int32, water);        // 露水值
    DTO_FIELD(Int32, fertilizer);   // 肥料值
};

class GardenStatusDto : public oatpp::DTO
{
    DTO_INIT(GardenStatusDto, DTO)

    DTO_FIELD(Int32, statusCode);
    DTO_FIELD(String, type);
    DTO_FIELD(List<Object<PlantStatusDto>>, plantList);
};

class PlantInfoForShopDto : public oatpp::DTO
{
    DTO_INIT(PlantInfoForShopDto, DTO)

    DTO_FIELD(String, name);    // 名称
    DTO_FIELD(Int32, price);    // 单价
    DTO_FIELD(Int32, maturity); // 成熟期
    DTO_FIELD(Int32, ratio);    // 一颗种子结多少个果
    DTO_FIELD(Int32, left);     // 余量
};

class ShopInfoDto : public oatpp::DTO
{
    DTO_INIT(ShopInfoDto, DTO)

    DTO_FIELD(Int32, statusCode);
    DTO_FIELD(List<Object<PlantInfoForShopDto>>, plantList);
};

class WateredResultDto : public oatpp::DTO
{
    DTO_INIT(WateredResultDto, DTO)

    DTO_FIELD(Int32, statusCode);
    DTO_FIELD(Int32, id);
    DTO_FIELD(Int32, water);
};

#include OATPP_CODEGEN_END(DTO)

#endif //PRINCESSSGARDENSERVER_DTOS_HPP
