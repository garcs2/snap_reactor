#include "snapReactorApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
snapReactorApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

snapReactorApp::snapReactorApp(InputParameters parameters) : MooseApp(parameters)
{
  snapReactorApp::registerAll(_factory, _action_factory, _syntax);
}

snapReactorApp::~snapReactorApp() {}

void 
snapReactorApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<snapReactorApp>(f, af, s);
  Registry::registerObjectsTo(f, {"snapReactorApp"});
  Registry::registerActionsTo(af, {"snapReactorApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
snapReactorApp::registerApps()
{
  registerApp(snapReactorApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
snapReactorApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  snapReactorApp::registerAll(f, af, s);
}
extern "C" void
snapReactorApp__registerApps()
{
  snapReactorApp::registerApps();
}
