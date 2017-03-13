#ifndef LOGIC_H
#define LOGIC_H

#include <boost/sml.hpp>
#include "utils/sml2plantuml.h"
#include "spaghettiCode.h"

namespace sml = boost::sml;
namespace test = spaghettiCode;

namespace spaghettiCode::logic {

 static constexpr const char* const image_name {"logic.png"};

 struct e1 {};
 struct e2 {};
 struct e3 {};

 struct Data {
    test::Input i{};
    test::Output o{};
 };

 struct guard {
   bool operator()(Data& d) { return !d.o.z; };
 } guard;

 struct action {
   bool operator()(Data& d) { d.o.z = d.i.x + d.i.y; };
 } action;

 struct testing {
  auto operator()() const noexcept {
    using namespace sml;
    return make_transition_table(
       *"idle"_s + event<e1> = "s1"_s
      , "s1"_s + event<e2> = "s2"_s
      , "s2"_s + event<e3> [guard] / action = X // transition under test
    );
  }
 };

 static void dump() {
     Data data{{},{}};
     ::dump(sml::sm<test::logic::testing, sml::testing>{data}, image_name);
 }

} // namespace


#endif // _H

