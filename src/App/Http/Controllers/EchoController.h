#pragma once

// CPPCMS
#include <cppcms/application.h>

namespace cppcms
{
class service;
}; // namespace cppcms

namespace App::Http::Controllers
{
class EchoController : public ::cppcms::application
{
  public:
    // Constructor
    EchoController(::cppcms::service &);

    // Echo function handler
    virtual void echo();
};
} // namespace App::Http::Controllers