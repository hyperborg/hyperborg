# IMPORTANT INFORMATION

As of 2023-04-24, the HyperBorg project is currently not compilable. The main reason for that it is in an intermediate merging state. It is assimilating an older GPL Flower tool which makes it possible to configure the whole project in NODE-Red style. It will not contain NODE-Red, just the interface would be similar.

(The current code contains some references to this, which is called HSM - Hyperborg State Machine). The codebase is coming from the authors previous GPL code, just needs to be updated to Qt6.

Please hang on while the integration process is ongoing.  


# Hyperborg Project

Project website (with screenshots): https://hyperborg.com

## About

The current home automatization scene has wonderful projects, like Domoticz and Home Assistant. They are nice, powerful and recommended, but they have some design differences permitting them to be fully useful in some scenarios. 

The HyperBorg is a new contender in this area that would like to learn from the mistakes from the big and old ones.

HyperBorg is focusing on security, stability and decentralization, as well as easy-peasy installation and maintenance.

It targets both non-IT users as well as hardcore home automatization people.

Based on Qt Framework, it brings advanced features as well as unique scalability.

Get on board!
Resistance is flutile ...

## Current status

Currently the Proof-Of-Concept is being built: It aims a minimal GUI for a simple system with 3 nodes supporting 1-wire for thermometers and i2c for relays and also I2c optos for reading "old" physical switches.

You might experience that there are some days where there are no progress is made. Please keep in mind, that this project is early stage, thus no other developers are joined yet and also there is a need to build up the necesseary hardware elements for testing and compilation farms. Sp, when the sw is not changed, there is certainly an update in the hardware background :D

## Please :)

If you think this is a good project, please just star it and come back frequently to check on the upgrades! Also, if you have any idea, wish or anything that could make this project bette, open an issue! :D

## Current state & DEMO

Currently there is a 5 nodes setup running in a test network in order to make the mesh communication working. When mesh communication is finished, the sensor and actuator implementation stats.

Since there are numerous request of how the GUI looks like, there is a demo available at https://hyperborg.com/demo2 It updated every hour when there is a change in the source code. Please keep in mind, that the uplink of the server is slow, so it could be a minute while the application starts in your browser. Normally it is less than 1 sec on a local network. Therefore, after the application is downloaded and compiled for your browers, it wouls restart much faster second time. 


