int incomingByte = 0; // for incoming serial data

void setup() {
  Serial1.begin(11500); // opens serial port, sets data rate to 9600 bps
  Serial2.begin(115200);
}

void loop() {
  // reply only when you receive data:
  if (Serial2.available() ) {
    // read the incoming byte:
    incomingByte = Serial2.read();

    // say what you got:
    Serial1.print("I received: ");
    Serial1.println(incomingByte, DEC);
  }
}
