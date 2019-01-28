#include "routes.h"

#include <cppcms/service.h>

#include "App/Http/Controllers/MainController.h"
#include "App/Http/Controllers/EchoController.h"

using namespace App::Http::Controllers;

void setUpRoutes(cppcms::service &srv)
{
    MainController::controllers.push_back({"echo", new EchoController(srv)});
}
