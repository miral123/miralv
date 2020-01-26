//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "miralvTestApp.h"
#include "miralvApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
miralvTestApp::validParams()
{
  InputParameters params = miralvApp::validParams();
  return params;
}

miralvTestApp::miralvTestApp(InputParameters parameters) : MooseApp(parameters)
{
  miralvTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

miralvTestApp::~miralvTestApp() {}

void
miralvTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  miralvApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"miralvTestApp"});
    Registry::registerActionsTo(af, {"miralvTestApp"});
  }
}

void
miralvTestApp::registerApps()
{
  registerApp(miralvApp);
  registerApp(miralvTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
miralvTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  miralvTestApp::registerAll(f, af, s);
}
extern "C" void
miralvTestApp__registerApps()
{
  miralvTestApp::registerApps();
}
