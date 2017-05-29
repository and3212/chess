/* Author: Liam Lawrence
 * Date: 5.28.17
 * Bluetooth functions over UART
 */
 
// Global bluetooth variables
int bluetoothTx = 2;  // TX-O pin of bluetooth mate, Arduino D2
int bluetoothRx = 3;  // RX-I pin of bluetooth mate, Arduino D3
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

// Initializes data for bluetooth
void bluetoothInit() {
  bluetooth.begin(115200);  // The Bluetooth Mate defaults to 115200bps
  bluetooth.print("$");  // Print three times individually
  bluetooth.print("$");
  bluetooth.print("$");  // Enter command mode
  delay(100);  // Short delay, wait for the Mate to send back CMD
  bluetooth.println("U,9600,N");  // Temporarily Change the baudrate to 9600, no parity
  // 115200 can be too fast at times for NewSoftSerial to relay the data reliably
  bluetooth.begin(9600);  // Start bluetooth serial at 9600
}

// Receives data
char btReceive() {
  if(bluetooth.available()) {
    return (char)bluetooth.read();
  }
}

// Sends data
void btTransmit(char stream) {
  bluetooth.print(stream);
}
