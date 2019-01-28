#pragma once

// CPPCMS
#include <cppcms/application.h>

namespace cppcms
{
class service;
}; // namespace cppcms

namespace App::Http::Controllers
{
class MainController : public ::cppcms::application
{
public:
  // Constructor
  MainController(::cppcms::service &);

  void attach(std::string const &, application *);

  static std::vector<std::pair<std::string, ::cppcms::application *>> controllers;
};
} // namespace App::Http::Controllers
