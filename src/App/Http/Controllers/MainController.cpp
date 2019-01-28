// CPPCMS
#include <cppcms/http_response.h>
#include <cppcms/service.h>
#include <cppcms/url_dispatcher.h>
#include <cppcms/url_mapper.h>

// C++
#include <iostream>

// Framework
#include "EchoController.h"

// Definition
#include "MainController.h"

using namespace App::Http::Controllers;

std::vector<std::pair<std::string, ::cppcms::application *>> MainController::controllers = {};

MainController::MainController(::cppcms::service &srv) : cppcms::application(srv)
{
    for (std::pair<std::string, ::cppcms::application*> controller : this->controllers)
    {
        this->attach(controller.first, controller.second);
    }
}

void MainController::attach(const std::string& name, application *app)
{
    application::attach(app, name, "/" + name + "{1}", "/" + name + "(/(.*))?", 1);
}
