//
// Created by crablet on 2022/1/13.
//

#include <iostream>

#include "oatpp/network/Server.hpp"

#include "./controller/MyController.h"
#include "./AppComponent.hpp"

void run()
{
    /* Register Components in scope of run() method */
    AppComponent components;

    /* Get router component */
    OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router);

    /* Create MyController and add all of its endpoints to router */
    router->addController(std::make_shared<MyController>());

    /* Get connection handler component */
    OATPP_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, connectionHandler);

    /* Get connection provider component */
    OATPP_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, connectionProvider);

    /* Create server which takes provided TCP connections and passes them to HTTP connection handler */
    oatpp::network::Server server(connectionProvider, connectionHandler);

    /* Print info about server port */
    OATPP_LOGI("PrincesssGardenServer", "Server is running on port %s", connectionProvider->getProperty("port").getData());

    /* Run server */
    server.run();
}

int main()
{
    oatpp::base::Environment::init();

    run();

    oatpp::base::Environment::destroy();

    return 0;
}
