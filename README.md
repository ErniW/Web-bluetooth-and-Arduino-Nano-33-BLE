# Web Bluetooth and Arduino Nano 33 BLE
An example of using Web Bluetooth API with Arduino BLE library.

*Sometimes I show it to my students when we are working on a project requiring Bluetooth Low Energy and a simple App. It's easier to prototype such thing with HTML + JS rather than learning other development tools in a limited amount of time.*


### Repository consists of:
- A simple web app that leverages the very basics of Web Bluetooth API using async/await. Nothing special because I decided to keep it simple.
- A simple Arduino peripheral code which connects to a web browser and notify with accelerometer data.

*Each example can toggle the build-in LED on Arduino pin 13.*

### Notes:
- *Web Bluetooth can't initialize connection on its own. It must be triggered by user event. In this case - pressing a HTML button.*
- *Tested on Google Chrome desktop and mobile with Arduino Nano 33 BLE, may work with different compatible browser/Arduino combinations.*
- *Please notice that Web Bluetooth won't work on IOS.*
- *To receive float type characteristics from Arduino BLE library, conversion to little-endian is required to correctly read the values. (`event.target.value.getFloat32(0, true);`)*
- *`parseFloat(y.toFixed(2));` rounds the float to 2 decimal numbers. I tried to exactly match the values from Arduino and Javascript sides.*
- *Writing to characteristic requires conversion to ArrayBuffer.*
