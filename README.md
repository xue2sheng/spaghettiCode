# Spaghetti Code
How to write test cases for spaghetti code, trying not to resort into spaghetti code as well.

![GitHub Logo](/images/logo.jpg)

## Logic as UML diagrams

Using [Boost SML](http://boost-experimental.github.io/sml/index.html) in order to avoid typical massive **if else** or **switch case** logic which tends to grow out of any kind of control after several feature additions. 

Besides, it's possible to visualize that *state machine* into automatically generated [PlantUML](http://plantuml.com) diagrams in order to discuss corner cases or just feedback the usual [Doxygen](http://www.stack.nl/~dimitri/doxygen), [Markdown](https://guides.github.com/features/mastering-markdown), or [Wiki pages](https://www.mediawiki.org/wiki/MediaWiki) documentation. In a perfect word, that **plantuml** diagrams should generate **c++** code.

The [trickiest point](http://www.cplusplus.com/forum/beginner/100627) is process all the *typeid* info into something more human friendly. Only **gcc** solution is implemented on this example.

## What is the rationale behind

Developers try to avoid writting spaghetti code as much as possible in order to make their lives easier when it comes down to debugging in the future but life is a bitch:

<img src="/images/perfection.jpg" alt="Perfection" width="250" height="250"/>

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

