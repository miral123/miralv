#include "miralvApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
miralvApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy DirichletBC, that is, set DirichletBC default for preset = true
  params.set<bool>("use_legacy_dirichlet_bc") = false;

  return params;
}

miralvApp::miralvApp(InputParameters parameters) : MooseApp(parameters)
{
  miralvApp::registerAll(_factory, _action_factory, _syntax);
}

miralvApp::~miralvApp() {}

void
miralvApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"miralvApp"});
  Registry::registerActionsTo(af, {"miralvApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
miralvApp::registerApps()
{
  registerApp(miralvApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
miralvApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  miralvApp::registerAll(f, af, s);
}
extern "C" void
miralvApp__registerApps()
{
  miralvApp::registerApps();
}
