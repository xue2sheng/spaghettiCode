/// @file sml2plantuml.h
/// @brief header utility library intended to be used by internal .cpp unit tests.
#ifndef SML2PLANTUML_H
#define SML2PLANTUML_H

#include <boost/sml.hpp>
#include <cassert>
#include <iostream>
#include <string>
#include <typeinfo>

namespace sml = boost::sml;

#ifdef __GNUG__ // GCC

#include <cxxabi.h>
#include <cstdlib>
#include <regex>

static std::string readable_name( const char* mangled_name )
{
    int status ;
    char* temp = __cxxabiv1::__cxa_demangle( mangled_name, nullptr, nullptr, &status ) ;
    if(temp)
    {
        std::string result(temp) ;
        std::free(temp) ;
        return result ;
    }
    else return mangled_name ;
}

static std::string unwrapped_name( const char* mangled_name )
{
    std::string demangled_name{readable_name(mangled_name)};
    return demangled_name;
} 

#else // not GCC

inline std::string readable_name( const char* mangled_name ) { return mangled_name ; }
inline std::string unwrapped_name( const char* mangled_name ) { return mangled_name ; }

#endif // __GNUG__

template <class T>
void dump_transition() noexcept {
  auto src_state = std::string{sml::aux::string<typename T::src_state>{}.c_str()};
  auto dst_state = std::string{sml::aux::string<typename T::dst_state>{}.c_str()};
  if (dst_state == "X") {
    dst_state = "[*]";
  }

  if (T::initial) {
    std::cout << "[*] --> " << src_state << std::endl;
  }

  std::cout << src_state << " --> " << dst_state;

  const auto has_event = !sml::aux::is_same<typename T::event, sml::anonymous>::value;
  const auto has_guard = !sml::aux::is_same<typename T::guard, sml::front::always>::value;
  const auto has_action = !sml::aux::is_same<typename T::action, sml::front::none>::value;

  if (has_event || has_guard || has_action) {
    std::cout << " :";
  }

  if (has_event) {
    std::cout << " " << typeid(typename T::event).name();
  }

  if (has_guard) {
    std::cout << " [" << typeid(typename T::guard).name() << "]";
  }

  if (has_action) {
    std::cout << " / " << typeid(typename T::action).name();
  }

  std::cout << std::endl;
}

template <template <class...> class T, class... Ts>
void dump_transitions(const T<Ts...>&) noexcept {
  int _[]{0, (dump_transition<Ts>(), 0)...};
  (void)_;
}

template <class SM>
void dump(const SM&) noexcept {
  std::cout << "@startuml" << std::endl << std::endl;
  dump_transitions(typename SM::transitions{});
  std::cout << std::endl << "@enduml" << std::endl;
}

#endif // SML2PLANTUML_H
