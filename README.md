# Spaghetti Code
How to write test cases for spaghetti code, trying not to resort into spaghetti code as well.

![GitHub Logo](/images/logo.jpg)

## Logic as UML diagrams

Using [Boost SML](http://boost-experimental.github.io/sml/index.html) in order to avoid typical massive **if else** or **switch case** logic which tends to grow out of any kind of control after several feature addtions. 

Besides, it's possible to visualize that *state machine* into automatically generated [PlantUML](http://plantuml.com) diagrams in order to discuss corner cases or just feedback the usual [Doxygen](http://www.stack.nl/~dimitri/doxygen), [Markdown](https://guides.github.com/features/mastering-markdown), or [Wiki pages](https://www.mediawiki.org/wiki/MediaWiki) documentation. In a perfect word, that **plantuml** diagrams should generate **c++** code.

The [trickest point](http://www.cplusplus.com/forum/beginner/100627) is process all the *typeid* info into something more human friendly. Only **gcc** solution is implemented on this example.
