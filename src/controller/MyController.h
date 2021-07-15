//
// Created by crablet on 2022/1/13.
//

#ifndef PRINCESSSGARDENSERVER_MYCONTROLLER_H
#define PRINCESSSGARDENSERVER_MYCONTROLLER_H

#include <sstream>

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

    ENDPOINT("GET", "/timeMachine", getTimeMachine, QUERY(String, date, "date"))
    {
        const auto dateStr = date.getValue("");
        std::istringstream is(dateStr);
        int year, month, day;
        char delimiter; // todo: 需要判断分隔符吗？还是怎么方便怎么来？这里安全性如何进行考量？
        if (is >> year >> delimiter >> month >> delimiter >> day)
        {
            auto dto = TimeMachineDto::createShared();
            dto->statusCode = 200;
            dto->year = year;
            dto->month = month;
            dto->day = day;
            dto->textTitle = "生日祝福";
            dto->textBody = "公主来到人间的第一天~";
            dto->gift = "我给你准备了一份神秘礼物哦^_^";

            return createDtoResponse(Status::CODE_200, dto);
        }
        else    // 日期格式错误
        {
            auto dto = TimeMachineDto::createShared();
            dto->statusCode = 400;
            dto->year = 0;
            dto->month = 0;
            dto->day = 0;
            dto->textTitle = "";
            dto->textBody = "";
            dto->gift = "";

            return createDtoResponse(Status::CODE_200, dto);
        }
    }

    ENDPOINT("GET", "gardenStatus", getGardenStatus, QUERY(String, type, "type"))
    {
        auto dto = GardenStatusDto::createShared();
        dto->statusCode = 200;
        dto->type = type.getValue("");
        dto->plantList = {};

        for (int i = 0; i < 5; ++i)
        {
            auto plantDto = PlantStatusDto::createShared();
            plantDto->id = 53;
            plantDto->name = "西瓜";
            plantDto->growth = 53;
            plantDto->maturity = 53;
            plantDto->sun = 53;
            plantDto->water = 53;
            plantDto->fertilizer = 53;
            plantDto->period = 53;

            dto->plantList->push_back(plantDto);
        }

        return createDtoResponse(Status::CODE_200, dto);
    }
};

#include OATPP_CODEGEN_END(ApiController)

#endif //PRINCESSSGARDENSERVER_MYCONTROLLER_H
