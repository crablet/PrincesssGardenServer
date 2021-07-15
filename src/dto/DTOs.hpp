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

#include OATPP_CODEGEN_END(DTO)

#endif //PRINCESSSGARDENSERVER_DTOS_HPP
