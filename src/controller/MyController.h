//
// Created by crablet on 2022/1/13.
//

#ifndef PRINCESSSGARDENSERVER_MYCONTROLLER_H
#define PRINCESSSGARDENSERVER_MYCONTROLLER_H

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include "dto/DTOs.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class MyController : public oatpp::web::server::api::ApiController
{
public:
    /**
    * Constructor with object mapper.
    * @param objectMapper - default object mapper used to serialize/deserialize DTOs.
    */
    explicit MyController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
        : oatpp::web::server::api::ApiController(objectMapper)
    {}

public:
    ENDPOINT("GET", "/", root)
    {
        auto dto = MyDto::createShared();
        dto->statusCode = 200;
        dto->message = "Hello my princess!";

        return createDtoResponse(Status::CODE_200, dto);
    }

    ENDPOINT("GET", "/user", getUser, QUERY(String, user, "id"))
    {
        auto dto = TestGetParamDto::createShared();
        dto->statusCode = 200;
        dto->param = user.getValue("");

        return createDtoResponse(Status::CODE_200, dto);
    }
};

#include OATPP_CODEGEN_END(ApiController)

#endif //PRINCESSSGARDENSERVER_MYCONTROLLER_H
