# GPS-TRACKING-WITH-ARDUINO-UNO-R3


| Component     | Arduino Pin | Notes                                              |
| ------------- | ----------- | -------------------------------------------------- |
| GPS6MUZ VCC   | 5V          | Power supply                                       |
| GPS6MUZ GND   | GND         | Common ground                                      |
| GPS6MUZ TX    | D4          | SoftwareSerial RX                                  |
| GPS6MUZ RX    | D3          | SoftwareSerial TX                                  |
| Green LED (+) | D7          | GPS update / moving indicator (with 220Ω resistor) |
| Red LED (+)   | D9          | Satellite searching (with 220Ω resistor)           |
| LED (-)       | GND         | Common ground                                      |
| Buzzer (+)    | D8          | Beep every update                                  |
| Buzzer (-)    | GND         | Ground                                             |
| Arduino Power | USB / 5V    | Stable power                                       |




🔌 Wiring Step by Step (Updated)
1️⃣ GPS6MUZ

Same as before

VCC → 5V

GND → GND

TX → D4

RX → D3

2️⃣ Green LED (GPS update)

Green LED anode → 220Ω resistor → D7

Cathode → GND

3️⃣ Red LED (Searching satellite)

Red LED anode → 220Ω resistor → D9

Cathode → GND

4️⃣ Buzzer

→ D8

→ GND
