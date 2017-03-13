#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE UnitTest

#include <boost/test/unit_test.hpp>

#include "spaghettiCode.h"
#include <boost/sml.hpp>
#include <cassert> 
namespace sml = boost::sml;
namespace test = spaghettiCode;

// just logging something ( --log_level=message )


/************* BEGIN:  Model your spaghetti code in as UML state machine ************/
 struct e1 {};
 struct e2 {};
 struct e3 {};

 struct Data {
    test::Input i;
    test::Output o;
 };

 struct testing {
  auto operator()() const noexcept {
    using namespace sml;

    const auto guard = [](Data& d) { return !d.o.z; };
    const auto action = [](Data& d) { d.o.z = d.i.x + d.i.y; };

    return make_transition_table(
       *"idle"_s + event<e1> = "s1"_s
      , "s1"_s + event<e2> = "s2"_s
      , "s2"_s + event<e3> [guard] / action = X // transition under test
    );
  }
 };
/************* END:  Model your spaghetti code in as UML state machine ************/

// if needed global init for all the test cases
struct GlobalInit {
  GlobalInit() {}
 ~GlobalInit() {}
};
BOOST_GLOBAL_FIXTURE( GlobalInit );

BOOST_AUTO_TEST_CASE( test000 ) {
   BOOST_TEST_MESSAGE( "\ntest000: Basic example" );
   test::Input input{5,3};
   test::Output output{};
   if( test::mess(input, output) ) {
     BOOST_TEST_MESSAGE( output.toStdString() );

     // test the logic
     using namespace sml;
     Data data{{5,3}, {}};
     sml::sm<::testing, sml::testing> sm{data};
     sm.__set_current_states("s2"_s);
     sm.process_event(e3{});
     BOOST_CHECK( sm.is(X) ); 
     BOOST_CHECK( output.z == data.o.z ); 

   } else {
     BOOST_TEST_MESSAGE( output.toStdString() );
     BOOST_CHECK( false ); 
   }
}

