# Web Bluetooth and Arduino Nano 33 BLE
An example of using Web Bluetooth API with Arduino BLE board.

*Tested on Google Chrome desktop and mobile and Arduino Nano 33 BLE, may work with different compatible browser/Arduino combinations.*

*Please notice that Web Bluetooth won't work on IOS.*

### Repository consists of:
- A simple web app that leverages the very basics of Web Bluetooth API using async/await. Nothing special.
- A simple Arduino peripheral code which connects to a web browser to notify with raw accelerometer data.
- A more sophisticated Arduino example to send calculated euler angles from IMU.

*Each example can toggle the build-in LED on Arduino pin 13.*

*It's important to remember that Web Bluetooth can't initialize connection on its own. It must be triggered by user event. In this case - pressing a HTML button.*
