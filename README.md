# Spaghetti Code
How to write test cases for spaghetti code, trying not to resort into spaghetti code as well.

![GitHub Logo](/images/logo.jpg)

## Logic as UML diagrams

Using [Boost SML](http://boost-experimental.github.io/sml/index.html) in order to avoid typical massive **if else** or **switch case** logic which tends to grow out of any kind of control after several feature additions. 

Besides, it's possible to visualize that *state machine* into automatically generated [PlantUML](http://plantuml.com) diagrams in order to discuss corner cases or just feedback the usual [Doxygen](http://www.stack.nl/~dimitri/doxygen), [Markdown](https://guides.github.com/features/mastering-markdown), or [Wiki pages](https://www.mediawiki.org/wiki/MediaWiki) documentation. In a perfect word, that **plantuml** diagrams should generate **c++** code.

The [trickiest point](http://www.cplusplus.com/forum/beginner/100627) is to process all the *typeid* info into something more human friendly. Only **g++** solution is implemented on this example but it seems to work as well for *macos* **clang++**.

## What is the rationale behind

Developers try to avoid writting spaghetti code as much as possible in order to make their lives easier when it comes down to debugging in the future but life is a bitch:

<img src="/images/perfection.jpg" alt="Perfection" width="250" height="250"/>

Even if you start with a clean design and it got implemented in the cleanest **if else** logic ever, you're doomed to add new funtionality along the time. 'Doomed' is not the correct word, you're 'lucky' your application is a big success with lots of users asking for new features and you got no time to refactor all your original design just to add an 'extra' branch into your **if else** logic.

At the same time, taking for granted you keep up your **test cases** to those changes, they can suffer the very same out-of-control grow with more and more corner cases to cover. Or there aren't any sort of *test cases* associated to current new features and you must begin from scratch for them, tempted to copy & paste previous old cases and modify them with more **if else** branches.

In that scenario it's where you might tackle your **testing** with a different approach: think *abstractly* about the real **business model** in your code under test, get the simplest (and easier to maintain) **State Machine** possible and write test cases testing that state machine. Don't forget to generate all the UML diagrams in order to discuss failing tests or just get ready for future code refactoring. 

## Technical details

**Boost SML** state machine as the following:

           *"idle"_s + event<event1> = "state1"_s
           , "state1"_s + event<event2> [ guard ] / action = "state2"_s
           , "state2"_s + event<event3> [ guard ] = "state1"_s
           , "state2"_s + event<event4> / action = X

Can be automatically dumped as a **UML** diagram:

           @startuml logic.png
           [*] --> idle
           idle --> state1 : event1
           state1 --> state2 : event2 [guard] / action
           state2 --> state1 : event3 [guard]
           state2 --> [*] : event4 / action
           @enduml 

To be converted into a **png**:

           java -jar /opt/plantuml/plantuml.jar -o images/  README.md

That looks like:

![Logic diagram](/images/logic.png)

## Summary

Test cases based on documented UML state machines are easier to maintain and it can make the difference when it comes to refactor your base code in the future:

### Refactoring without proper test case

<img src="/images/madness.jpg" alt="Madness" width="250" height="250"/>

### Refactoring with test cases documented with UML diagrams

<img src="/images/easy.jpg" alt="Piece of cake" width="250" height="250"/>

