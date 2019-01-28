#include <vector>

// CPPCMS
#include <cppcms/application.h>
#include <cppcms/applications_pool.h>
#include <cppcms/http_response.h>
#include <cppcms/service.h>

#include "routes.h"

// Controllers
#include "App/Http/Controllers/MainController.h"

int main(int argc, char **argv)
{
    try
    {
        cppcms::service srv(argc, argv);
        setUpRoutes(srv);
        srv.applications_pool().mount(cppcms::applications_factory<::App::Http::Controllers::MainController>());
        srv.run();
    }
    catch (std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
