/* Morse Code Tone/Flasher Beacon – Optimized */

#include <Arduino.h>

/* ---------------- Hardware ---------------- */
constexpr uint8_t buzzerPin = 9;
constexpr uint8_t ledPin = 13;  // onboard LED

/* ---------------- Audio ---------------- */
constexpr uint16_t tonefreq = 2500;  // enter tone frequency between 31 - 65,535 Hz
constexpr bool toneMode = true;      // enter true = tone(), false = DC keying

/* ---------------- Timing ---------------- */
constexpr uint8_t wpm = 10;  // enter code speed in words per minute
constexpr uint16_t dotlength = 1200 / wpm;
constexpr uint16_t dashlength = dotlength * 3;
constexpr uint16_t inter = dotlength;     // interelement gap
constexpr uint16_t lgap = dotlength * 2;  // letter gap
constexpr uint16_t wgap = dotlength * 4;  // word gap

/* ---------------- Message ---------------- */
const char message[] PROGMEM = "W6SFM       ";  // enter text to be sent


/* ----------------- Helper ------------------*/
int8_t morseIndex(char c) {
  if (c >= 'A' && c <= 'Z') return c - 'A';
  if (c >= '0' && c <= '9') return 26 + (c - '0');

  switch (c) {
    case '.': return 36;
    case ',': return 37;
    case '?': return 38;
    case '\'': return 39;
    case '!': return 40;
    case '/': return 41;
    case '(': return 42;
    case ')': return 43;  // KN
    case '&': return 44;
    case ':': return 45;
    case ';': return 46;
    case '=': return 47;  // BT
    case '+': return 48;  // AR
    case '-': return 49;
    case '_': return 50;
    case '"': return 51;
    case '$': return 52;
    case '@': return 53;
    case '%': return 54;  // AS
    case ']': return 55;  // SK
    default: return -1;
  }
}

/* ---------------- Morse Table ----------------
   Bits are sent MSB first
   1 = dah, 0 = dit
*/
struct Morse {
  uint8_t pattern;
  uint8_t length;
};

const Morse morseTable[] PROGMEM = {

/* A–Z (0–25) */
{0b01,2},{0b1000,4},{0b1010,4},{0b100,3},{0b0,1},{0b0010,4},
{0b110,3},{0b0000,4},{0b00,2},{0b0111,4},{0b101,3},{0b0100,4},
{0b11,2},{0b10,2},{0b111,3},{0b0110,4},{0b1101,4},{0b010,3},
{0b000,3},{0b1,1},{0b001,3},{0b0001,4},{0b011,3},{0b1001,4},
{0b1011,4},{0b1100,4},

/* 0–9 (26–35) */
{0b11111,5},{0b01111,5},{0b00111,5},{0b00011,5},{0b00001,5},
{0b00000,5},{0b10000,5},{0b11000,5},{0b11100,5},{0b11110,5},

/* Punctuation & Procedural (36+) */

/* . */ { 0b010101, 6 },
  /* , */ { 0b110011, 6 },
  /* ? */ { 0b001100, 6 },
  /* ' */ { 0b011110, 6 },
  /* ! */ { 0b101011, 6 },
  /* / */ { 0b10010, 5 },
  /* ( */ { 0b10110, 5 },
  /* ) KN */ { 0b101101, 6 },
  /* & */ { 0b01000, 5 },
  /* : */ { 0b111000, 6 },
  /* ; */ { 0b101010, 6 },
  /* = BT */ { 0b10001, 5 },
  /* + AR */ { 0b01010, 5 },
  /* - */ { 0b100001, 6 },
  /* _ */ { 0b001101, 6 },
  /* " */ { 0b010010, 6 },
  /* $ */ { 0b0001001, 7 },
  /* @ */ { 0b011010, 6 },

  /* Prosigns encoded as single chars */
  /* % AS */ { 0b01000, 5 },
  /* ] SK */ { 0b000101, 6 }
};

/* ---------------- Functions ---------------- */

inline void keyDown() {
  toneMode ? tone(buzzerPin, tonefreq) : digitalWrite(buzzerPin, HIGH);
}

inline void keyUp() {
  toneMode ? noTone(buzzerPin) : digitalWrite(buzzerPin, LOW);
}

void dit() {
  keyDown();
  delay(dotlength);
  keyUp();
  delay(inter);
}

void dah() {
  keyDown();
  delay(dashlength);
  keyUp();
  delay(inter);
}

void sendMorse(char c) {
  // Convert lowercase → uppercase (ASCII-safe)
  if (c >= 'a' && c <= 'z') {
    c -= ('a' - 'A');
  }

  if (c == ' ') {
    delay(wgap);
    return;
  }

  int8_t idx = morseIndex(c);
  if (idx < 0) return;

  Morse m;
  memcpy_P(&m, &morseTable[idx], sizeof(Morse));

  for (int8_t i = m.length - 1; i >= 0; i--) {
    (m.pattern & (1 << i)) ? dah() : dit();
  }

  delay(lgap);
}

/* ---------------- Arduino ---------------- */

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for (uint8_t i = 0; i < strlen_P(message); i++) {
    char c = pgm_read_byte(&message[i]);
    sendMorse(c);
  }
}
