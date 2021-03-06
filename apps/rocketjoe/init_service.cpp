#include "init_service.hpp"

#include <goblin-engineer/components/root_manager.hpp>
#include <services/interactive_python/interactive_python.hpp>

using goblin_engineer::components::make_manager_service;
using goblin_engineer::components::make_service;
using goblin_engineer::components::root_manager;
using namespace goblin_engineer::components;

void init_service(goblin_engineer::components::root_manager&, components::configuration&, components::log_t&) {}
