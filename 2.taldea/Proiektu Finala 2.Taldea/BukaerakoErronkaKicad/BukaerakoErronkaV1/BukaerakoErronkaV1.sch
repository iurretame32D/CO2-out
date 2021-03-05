EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L BukaerakoErronkaV1-rescue:Conn_01x03-Connector_Generic J2
U 1 1 6034F307
P 4850 1300
F 0 "J2" H 4930 1342 50  0000 L CNN
F 1 "Conn_01x03" H 4930 1251 50  0000 L CNN
F 2 "Connector_JST:JST_EH_B3B-EH-A_1x03_P2.50mm_Vertical" H 4850 1300 50  0001 C CNN
F 3 "~" H 4850 1300 50  0001 C CNN
	1    4850 1300
	0    -1   -1   0   
$EndComp
Text GLabel 4400 2150 2    50   Input ~ 0
GND
Text GLabel 4400 2450 2    50   Input ~ 0
GND
NoConn ~ 4400 2550
NoConn ~ 4400 2650
NoConn ~ 4400 2750
Text Notes 4650 1350 1    47   ~ 0
DHT 11
Text Notes 4000 1950 0    47   ~ 0
CJMCU-811\n
Text Notes 4250 2050 0    20   Italic 4
VCC
Text Notes 4250 2150 0    20   Italic 4
GND
Text Notes 4250 2250 0    20   Italic 4
SCL\n
Text Notes 4250 2350 0    20   Italic 4
SDA
Text Notes 4250 2450 0    20   Italic 4
WAK
Text Notes 4250 2550 0    20   Italic 4
INT\n
Text Notes 4250 2650 0    20   Italic 4
RST
Text Notes 4250 2750 0    20   Italic 4
ADD
Text Notes 4950 1400 1    20   Italic 4
17
Text Notes 4850 1400 1    20   Italic 4
VCC
Text Notes 4750 1400 1    20   Italic 4
GND
Text GLabel 5300 3350 0    50   Input ~ 0
GND
Text GLabel 5300 3150 0    50   Input ~ 0
3V3
Text GLabel 6350 1750 2    50   Input ~ 0
17
Text GLabel 4950 1500 3    50   Input ~ 0
17
Text GLabel 4750 1500 3    50   Input ~ 0
GND
Text GLabel 6350 3150 2    50   Input ~ 0
3V3
Text GLabel 6350 3350 2    50   Input ~ 0
GND
Text GLabel 6350 3050 2    50   Input ~ 0
GND
$Comp
L BukaerakoErronkaV1-rescue:TTGO-ESP32-LIB U1
U 1 1 603672B1
P 5550 1550
F 0 "U1" H 5800 1650 50  0000 C CNN
F 1 "TTGO-ESP32" H 5850 1550 50  0000 C CNN
F 2 "liburua:TTGO-ESP32" H 5550 1550 20  0001 C CNN
F 3 "" H 5550 1550 20  0001 C CNN
	1    5550 1550
	1    0    0    -1  
$EndComp
$Comp
L BukaerakoErronkaV1-rescue:Conn_01x08-Connector_Generic J1
U 1 1 6034F84D
P 4200 2350
F 0 "J1" H 4250 2900 50  0000 C CNN
F 1 "Conn_01x08" H 4200 2850 50  0000 C CNN
F 2 "Connector_JST:JST_EH_B8B-EH-A_1x08_P2.50mm_Vertical" H 4200 2350 50  0001 C CNN
F 3 "~" H 4200 2350 50  0001 C CNN
	1    4200 2350
	-1   0    0    -1  
$EndComp
Text GLabel 6350 2550 2    50   Input ~ 0
22
Text GLabel 5300 1650 0    50   Input ~ 0
21
Text GLabel 6350 1850 2    50   Input ~ 0
4
Text GLabel 6350 2050 2    50   Input ~ 0
15
$Comp
L BukaerakoErronkaV1-rescue:Conn_01x04-Connector_Generic J4
U 1 1 603D14DF
P 5850 3750
F 0 "J4" H 5930 3742 50  0000 L CNN
F 1 "Conn_01x04" H 5800 3450 50  0000 L CNN
F 2 "Connector_JST:JST_EH_B4B-EH-A_1x04_P2.50mm_Vertical" H 5850 3750 50  0001 C CNN
F 3 "~" H 5850 3750 50  0001 C CNN
	1    5850 3750
	1    0    0    -1  
$EndComp
Text GLabel 5650 3650 0    50   Input ~ 0
GND
Text GLabel 5100 3750 0    50   Input ~ 0
DIN
Text GLabel 5600 3850 0    50   Input ~ 0
3.3V
$Comp
L BukaerakoErronkaV1-rescue:R-Device R1
U 1 1 603D20FE
P 5250 3750
F 0 "R1" V 5043 3750 50  0000 C CNN
F 1 "470" V 5134 3750 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5180 3750 50  0001 C CNN
F 3 "~" H 5250 3750 50  0001 C CNN
	1    5250 3750
	0    1    1    0   
$EndComp
Text GLabel 4400 2350 2    50   Input ~ 0
SDA
Text GLabel 4400 2250 2    50   Input ~ 0
SCL
Wire Wire Line
	5400 3750 5650 3750
Text GLabel 4150 3150 0    50   Input ~ 0
21
Text GLabel 6900 2650 0    50   Input ~ 0
15
Text GLabel 4150 3250 0    50   Input ~ 0
SDA
Text GLabel 4150 3350 0    50   Input ~ 0
4
Text GLabel 6900 2450 0    50   Input ~ 0
22
$Comp
L BukaerakoErronkaV1-rescue:CP-Device C1
U 1 1 603CCB24
P 6400 3800
F 0 "C1" V 6655 3800 50  0000 C CNN
F 1 "CP" V 6564 3800 50  0000 C CNN
F 2 "Capacitor_THT:CP_Radial_D10.0mm_P3.80mm" H 6438 3650 50  0001 C CNN
F 3 "~" H 6400 3800 50  0001 C CNN
	1    6400 3800
	-1   0    0    1   
$EndComp
$Comp
L BukaerakoErronkaV1-rescue:Conn_01x03-Connector_Generic J5
U 1 1 603D1E22
P 7100 2550
F 0 "J5" H 7180 2592 50  0000 L CNN
F 1 "Conn_01x03" H 7180 2501 50  0000 L CNN
F 2 "Connector_JST:JST_EH_B3B-EH-A_1x03_P2.50mm_Vertical" H 7100 2550 50  0001 C CNN
F 3 "~" H 7100 2550 50  0001 C CNN
	1    7100 2550
	1    0    0    -1  
$EndComp
$Comp
L BukaerakoErronkaV1-rescue:Conn_01x03-Connector_Generic J6
U 1 1 603D380A
P 4350 3250
F 0 "J6" H 4430 3292 50  0000 L CNN
F 1 "Conn_01x03" H 4430 3201 50  0000 L CNN
F 2 "Connector_JST:JST_EH_B3B-EH-A_1x03_P2.50mm_Vertical" H 4350 3250 50  0001 C CNN
F 3 "~" H 4350 3250 50  0001 C CNN
	1    4350 3250
	1    0    0    -1  
$EndComp
NoConn ~ 6350 3250
NoConn ~ 5300 3250
$Comp
L BukaerakoErronkaV1-rescue:Screw_Terminal_01x02-Connector J7
U 1 1 603DF44E
P 6850 3700
F 0 "J7" H 6850 3500 50  0000 C CNN
F 1 "Screw_Terminal_01x02" V 7200 3600 50  0000 C CNN
F 2 "TerminalBlock:TerminalBlock_bornier-2_P5.08mm" H 6850 3700 50  0001 C CNN
F 3 "~" H 6850 3700 50  0001 C CNN
	1    6850 3700
	0    1    1    0   
$EndComp
$Comp
L BukaerakoErronkaV1-rescue:Fuse-Device F1
U 1 1 603DFDCB
P 6850 3350
F 0 "F1" H 6910 3396 50  0000 L CNN
F 1 "Fuse" H 6910 3305 50  0000 L CNN
F 2 "Fuse:Fuseholder_Cylinder-5x20mm_Stelvio-Kontek_PTF78_Horizontal_Open" V 6780 3350 50  0001 C CNN
F 3 "~" H 6850 3350 50  0001 C CNN
	1    6850 3350
	1    0    0    -1  
$EndComp
Text GLabel 8000 3200 2    50   Input ~ 0
GND
Text GLabel 8000 3000 2    50   Input ~ 0
3V3
$Comp
L BukaerakoErronkaV1-rescue:HLK-PM03-Converter_ACDC PS1
U 1 1 603E09F3
P 7350 3100
F 0 "PS1" H 7350 3425 50  0000 C CNN
F 1 "HLK-PM03" H 7350 3334 50  0000 C CNN
F 2 "Converter_ACDC:Converter_ACDC_HiLink_HLK-PMxx" H 7350 2800 50  0001 C CNN
F 3 "http://www.hlktech.net/product_detail.php?ProId=59" H 7750 2750 50  0001 C CNN
	1    7350 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	6850 3200 6950 3200
Wire Wire Line
	6750 3000 6750 3500
Wire Wire Line
	6750 3000 6950 3000
Wire Wire Line
	6000 3650 6000 3500
Wire Wire Line
	6000 3500 5700 3500
Wire Wire Line
	5700 3500 5700 3650
Wire Wire Line
	5700 3650 5650 3650
Wire Wire Line
	6150 3850 6150 3950
Wire Wire Line
	5600 3850 5650 3850
Connection ~ 5650 3850
Wire Wire Line
	5650 3850 6150 3850
Wire Wire Line
	7750 3200 8000 3200
Wire Wire Line
	7750 3000 8000 3000
Wire Wire Line
	6400 3650 6000 3650
Wire Wire Line
	6150 3950 6400 3950
Text GLabel 5300 1750 0    50   Input ~ 0
DIN
Text GLabel 5650 3950 0    50   Input ~ 0
GND
$Comp
L BukaerakoErronkaV1-rescue:R-Device R2
U 1 1 60418A8C
P 4750 2050
F 0 "R2" V 4543 2050 50  0000 C CNN
F 1 "puente" V 4634 2050 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P15.24mm_Horizontal" V 4680 2050 50  0001 C CNN
F 3 "~" H 4750 2050 50  0001 C CNN
	1    4750 2050
	0    1    1    0   
$EndComp
Wire Wire Line
	4400 2050 4600 2050
$Comp
L BukaerakoErronkaV1-rescue:R-Device R3
U 1 1 60418DA4
P 5250 1100
F 0 "R3" V 5043 1100 50  0000 C CNN
F 1 "puente" V 5134 1100 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5180 1100 50  0001 C CNN
F 3 "~" H 5250 1100 50  0001 C CNN
	1    5250 1100
	0    1    1    0   
$EndComp
Wire Wire Line
	5400 1100 6650 1100
Wire Wire Line
	6650 1100 6650 3150
Wire Wire Line
	6650 3150 6350 3150
Text GLabel 4850 1600 3    50   Input ~ 0
Vcc
Wire Wire Line
	4850 1500 4850 1600
Text GLabel 4900 2050 2    50   Input ~ 0
Vcc
Text GLabel 5100 1100 0    50   Input ~ 0
Vcc
$Comp
L BukaerakoErronkaV1-rescue:R-Device R5
U 1 1 6042609E
P 7850 1950
F 0 "R5" V 7643 1950 50  0000 C CNN
F 1 "puente" V 7734 1950 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 7780 1950 50  0001 C CNN
F 3 "~" H 7850 1950 50  0001 C CNN
	1    7850 1950
	0    1    1    0   
$EndComp
$Comp
L BukaerakoErronkaV1-rescue:R-Device R4
U 1 1 60426C97
P 7350 1950
F 0 "R4" V 7143 1950 50  0000 C CNN
F 1 "puente" V 7234 1950 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 7280 1950 50  0001 C CNN
F 3 "~" H 7350 1950 50  0001 C CNN
	1    7350 1950
	0    1    1    0   
$EndComp
Wire Wire Line
	7500 1950 7700 1950
Text GLabel 7100 1950 0    50   Input ~ 0
scl
Wire Wire Line
	7100 1950 7200 1950
Text GLabel 6900 2550 0    50   Input ~ 0
scl
Text GLabel 8000 1950 2    50   Input ~ 0
SCL
$EndSCHEMATC
