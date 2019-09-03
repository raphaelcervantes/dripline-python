#include "pybind11/stl.h"

#include "constants_pybind.hh"
#include "_endpoint_pybind.hh"
#include "endpoint_trampoline.hh"
#include "error_pybind.hh"
#include "message_pybind.hh"
//#include "run_simple_service_pybind.hh"
#include "specifier_pybind.hh"
#include "service_pybind.hh"

PYBIND11_MODULE( _dripline, dripline_mod )
{
    std::list< std::string > all_members;
    // The bound classes belong in a submodule, create that
    pybind11::module dripline_core_mod = dripline_mod.def_submodule( "core", "Core dripline standard implementation classes" );
    // Call exporters for the dripline.core namespace
    all_members.splice( all_members.end(), dripline_pybind::export_constants( dripline_core_mod ) );
    all_members.splice( all_members.end(), dripline_pybind::export_endpoint( dripline_core_mod ) );
    all_members.splice( all_members.end(), dripline_pybind::export_error( dripline_core_mod ) );
    all_members.splice( all_members.end(), dripline_pybind::export_message( dripline_core_mod ) );
    //all_members.splice( all_members.end(), dripline_pybind::export_run_simple_service( dripline_core_mod ) );
    all_members.splice( all_members.end(), dripline_pybind::export_specifier( dripline_core_mod ) );
    all_members.splice( all_members.end(), dripline_pybind::export_service( dripline_core_mod ) );
    // add __all__
    dripline_core_mod.attr( "__all__" ) = all_members;
}
