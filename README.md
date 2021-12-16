# ATtiny25-Pulse-train-generator-with-high-frequency-filling
Simple ATtiny25 pulse pack generator.  
The pause time between pulse packs is controlled by the ADC using a potentiometer.  
The pulse amplitude is 5 V, the pack duration is 2 ms, the pulse frequency in the pack is 10 kHz, the pack frequency is adjustable (10-100 Hz).
Example of an output signal:  

![Alt-текст](https://raw.githubusercontent.com/nikitarem/ATtiny25-Pulse-train-generator-with-high-frequency-filling/main/img/vout.png "Output signal")
  
Application circuit diagram:  

![Alt-текст](https://raw.githubusercontent.com/nikitarem/ATtiny25-Pulse-train-generator-with-high-frequency-filling/main/img/circuit.png "Output Circuit")
  
# Components:
DD1 = ATtiny25  

**RESET circuit:**  
R1 = 20 kOhm  
C1 = 47 uF  

**CLK circuit:**  
ZQ1 = 1 MHz  
C2, C3 = 22 pF  

**Bypass cap:**  
C4 = 100 nF  

**Period control potentiometer:**  
R2 = 150 kOhm
