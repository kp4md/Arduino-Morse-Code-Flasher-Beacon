# Arduino-Morse-Code-Flasher-Beacon
This Arduino Nano Sketch flashes a bright LED light and 90 dB buzzer with a repeating message in Morse Code.  It includes punctuation and ITU prosigns.
It is originally designed to flash a 100 lumen Harbor Freight 24 LED Superbright Worklight/Flashlight which is visible over 1 km at night and can simultaneously sound a 90 dB 2500 Hz buzzer.

[<img width="1193" height="675" alt="Screenshot 2025-12-28 213411" src="https://github.com/user-attachments/assets/79c41407-99a4-4de0-bdc4-e55201be43d0" />](https://www.youtube.com/watch?v=QWzxtAXYNEI)

Try the Online Simulator at https://wokwi.com/projects/451637704092110849

<img width="1920" height="1080" alt="Morse Code Flasher Wokwi" src="https://github.com/user-attachments/assets/47994211-fb66-4717-bc7b-9aabdefcc88f" />

The MOSFETs are two BS170's and the buzzer is a passive 5.5Ω electromagnetic type. 
The 24 parallel LED's, the 1.8Ω resistor and the 4.5V battery (3 AAA cells) are the original internal flashlight circuit. 

Schematic diagram: https://www.circuit-diagram.org/circuits/6f26bf8eb881425b98d788584593bcd9

Arduino sketch & WOKWI Simulation: https://wokwi.com/projects/451637704092110849

<img width="580" height="538" alt="Morse Code Flasher Beacon" src="https://github.com/user-attachments/assets/7e6d9b4f-1662-4bb8-8056-f4674fe605ab" />

Detail of opening and adding the cable to the Harbor Freight LED Worklight #67227
1.  Remove the three rear screws to expose the battery compartment
2.  Remove four screw to separate the battery compartment from the front of the light.
3.  Remove the two screws on either side of the switch to expose the back of the LED board.
4.  Solder two wires to the switch contacts.
5.  Reassemble the flashlight.

![IMG_6428](https://github.com/user-attachments/assets/f89a769a-8e14-4b37-a5f9-ab44c4e57221)
![IMG_6425](https://github.com/user-attachments/assets/c7d6b02a-e7c5-4c6b-acda-36bf6f7a1041)
![IMG_6426](https://github.com/user-attachments/assets/aff491ed-95e8-4f0d-9d27-77535359a6c3)
![IMG_6427](https://github.com/user-attachments/assets/bd0248a6-f7c2-4664-bf72-1db77929a390)

The Morse Code Flasher Beacon is soldered onto a perfboard.
The beacon is visible over 1 km at night and can simultaneously sound a buzzer with 90 dB at 2500 Hz.  
It flashed for over twelve hours using a fresh 9 volt alkaline battery and three AAA cells.

[<img width="1193" height="675" alt="vlcsnap-2026-01-11-15h16m41s656" src="https://github.com/user-attachments/assets/c6a0bd36-08b2-43fa-849d-423ea171b498" />](https://www.youtube.com/watch?v=F7K6tVZFt3o)
