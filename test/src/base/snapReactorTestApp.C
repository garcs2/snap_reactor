//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "snapReactorTestApp.h"
#include "snapReactorApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
snapReactorTestApp::validParams()
{
  InputParameters params = snapReactorApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

snapReactorTestApp::snapReactorTestApp(InputParameters parameters) : MooseApp(parameters)
{
  snapReactorTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

snapReactorTestApp::~snapReactorTestApp() {}

void
snapReactorTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  snapReactorApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"snapReactorTestApp"});
    Registry::registerActionsTo(af, {"snapReactorTestApp"});
  }
}

void
snapReactorTestApp::registerApps()
{
  registerApp(snapReactorApp);
  registerApp(snapReactorTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
snapReactorTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  snapReactorTestApp::registerAll(f, af, s);
}
extern "C" void
snapReactorTestApp__registerApps()
{
  snapReactorTestApp::registerApps();
}
