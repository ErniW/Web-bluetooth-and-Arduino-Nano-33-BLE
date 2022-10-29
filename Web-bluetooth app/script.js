let x, y, z;
let ledState = false;

let xCharacteristic, yCharacteristic, zCharacteristic, ledCharacteristic;

const serviceUUID = "19b10000-e8f2-537e-4f6c-d104768a1214";

const xCharacteristicUUID = "19b10001-e8f2-537e-4f6c-d104768a1214";
const yCharacteristicUUID = "19b10002-e8f2-537e-4f6c-d104768a1214";
const zCharacteristicUUID = "19b10003-e8f2-537e-4f6c-d104768a1214";

const ledCharacteristicUUID = "19b10004-e8f2-537e-4f6c-d104768a1214";

async function connect(){

    const device = await navigator.bluetooth.requestDevice({filters: [{services: [serviceUUID]}]});
    const server = await device.gatt.connect();
    const service = await server.getPrimaryService(serviceUUID);

    xCharacteristic = await service.getCharacteristic(xCharacteristicUUID);
    yCharacteristic = await service.getCharacteristic(yCharacteristicUUID);
    zCharacteristic = await service.getCharacteristic(zCharacteristicUUID);
    
    ledCharacteristic = await service.getCharacteristic(ledCharacteristicUUID);

    await xCharacteristic.startNotifications();
    await yCharacteristic.startNotifications();
    await zCharacteristic.startNotifications();

    xCharacteristic.addEventListener('characteristicvaluechanged', readX);
    yCharacteristic.addEventListener('characteristicvaluechanged', readY);
    zCharacteristic.addEventListener('characteristicvaluechanged', readZ);

}

function readX(event) {
    x = event.target.value.getFloat32(0, true);
    x = parseFloat(x.toFixed(2));
    document.getElementById('x').textContent = x;
}

function readY(event) {
    y = event.target.value.getFloat32(0, true);
    y = parseFloat(y.toFixed(2));
    document.getElementById('y').textContent = y;
}

function readZ(event) {
    z = event.target.value.getFloat32(0, true);
    z = parseFloat(z.toFixed(2));
    document.getElementById('z').textContent = z;
} 

async function toggleLED(){
    ledState = !ledState;

    let buffer = new ArrayBuffer(1);
    let view = new Uint8Array(buffer);
    view[0] = ledState;

    await ledCharacteristic.writeValue(view);
}

document.getElementById('connect').addEventListener("click", connect);
document.getElementById('led').addEventListener("click", toggleLED);