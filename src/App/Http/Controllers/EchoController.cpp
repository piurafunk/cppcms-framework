// CPPCMS
#include <cppcms/http_response.h>
#include <cppcms/service.h>
#include <cppcms/url_dispatcher.h>
#include <cppcms/url_mapper.h>
#include <cppcms/http_request.h>

// Framework
#include "../../../helpers/string.h"
#include "../../../helpers/json.h"

// Definition
#include "EchoController.h"

using namespace App::Http::Controllers;

EchoController::EchoController(::cppcms::service &srv) : cppcms::application(srv)
{
    dispatcher().assign("", &EchoController::echo, this);
    mapper().assign("");
}

void EchoController::echo()
{
    response().set_header("Content-Type", "application/json");

    // Load the query string into a JSON object
    ::cppcms::json::value object = parseQueryString(this->request().query_string());

    // Print the response
    response().out() << object;
}
