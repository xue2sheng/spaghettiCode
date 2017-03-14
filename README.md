# Spaghetti Code
How to write test cases for spaghetti code, trying not to resort into spaghetti code as well.

![GitHub Logo](/images/logo.jpg)

## Logic as UML diagrams

Using [Boost SML](http://boost-experimental.github.io/sml/index.html) in order to avoid typical massive **if else** or **switch case** logic which tends to grow out of any kind of control after several feature additions. 

Besides, it's possible to visualize that *state machine* into automatically generated [PlantUML](http://plantuml.com) diagrams in order to discuss corner cases or just feedback the usual [Doxygen](http://www.stack.nl/~dimitri/doxygen), [Markdown](https://guides.github.com/features/mastering-markdown), or [Wiki pages](https://www.mediawiki.org/wiki/MediaWiki) documentation. In a perfect word, that **plantuml** diagrams should generate **c++** code.

The [trickiest point](http://www.cplusplus.com/forum/beginner/100627) is process all the *typeid* info into something more human friendly. Only **gcc** solution is implemented on this example.

## Example

**Boost SML** state machine can be automatically dumped as a **UML** diagram:

           @startuml logic.png
           [*] --> idle
           idle --> state1 : event1
           state1 --> state2 : event2 [guard] / action
           state2 --> state1 : event3 [guard]
           state2 --> [*] : event4 / action
           @enduml 

And converted into a **png**:

           java -jar /opt/plantuml/plantuml.jar -o images/  README.md

So the image looks like:

![Logic diagram](/images/logic.png)

