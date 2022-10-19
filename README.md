# Web Bluetooth and Arduino Nano 33 BLE
An example of using Web Bluetooth API with Arduino BLE board.

*Sometimes I show it to my students when we are working on a project requiring Bluetooth Low Energy and a simple App. It's easier to prototype such thing with HTML + JS rather than learning other development tools in a limited amount of time.*


### Repository consists of:
- A simple web app that leverages the very basics of Web Bluetooth API using async/await. Nothing special.
- A simple Arduino peripheral code which connects to a web browser to notify with raw accelerometer data.
- A more sophisticated Arduino example to send calculated euler angles from IMU (without magnetometer).

*Each example can toggle the build-in LED on Arduino pin 13.*

### FAQ
- *Web Bluetooth can't initialize connection on its own. It must be triggered by user event. In this case - pressing a HTML button.*
- *Tested on Google Chrome desktop and mobile and Arduino Nano 33 BLE, may work with different compatible browser/Arduino combinations.*
- *Please notice that Web Bluetooth won't work on IOS.*
