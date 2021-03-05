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
Text GLabel 4925 4000 2    50   Input ~ 0
GND
Text GLabel 4825 4175 0    50   Input ~ 0
GND
Wire Wire Line
	4825 4175 5075 4175
Text GLabel 4925 3825 2    50   Input ~ 0
3V3
Text GLabel 4825 4275 0    50   Input ~ 0
3V3
Wire Wire Line
	4825 4275 5075 4275
$Comp
L Connector_Generic:Conn_01x03 U3
U 1 1 60360A17
P 5275 4275
F 0 "U3" V 5239 4455 50  0000 L CNN
F 1 "DHT11" V 5148 4455 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x03_P2.54mm_Vertical" H 5275 4275 50  0001 C CNN
F 3 "~" H 5275 4275 50  0001 C CNN
	1    5275 4275
	1    0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x08 U2
U 1 1 60385ED6
P 6475 3400
F 0 "U2" H 6555 3392 50  0000 L CNN
F 1 "CJMCU-811" H 6555 3301 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x08_P2.54mm_Vertical" H 6475 3400 50  0001 C CNN
F 3 "~" H 6475 3400 50  0001 C CNN
	1    6475 3400
	1    0    0    -1  
$EndComp
Text Notes 6425 3100 0    50   ~ 0
VCC
Text Notes 6425 3200 0    50   ~ 0
GND
Text Notes 6425 3300 0    50   ~ 0
SCL
Text Notes 6425 3400 0    50   ~ 0
SDA
Text Notes 6425 3500 0    50   ~ 0
WAK
Text Notes 6425 3600 0    50   ~ 0
INT
Text Notes 6425 3700 0    50   ~ 0
RST
Text Notes 6425 3800 0    50   ~ 0
ADO
Text GLabel 6125 3200 0    50   Input ~ 0
GND
Text GLabel 6125 3100 0    50   Input ~ 0
3V3
Wire Wire Line
	6125 3100 6275 3100
Wire Wire Line
	6125 3200 6275 3200
Text GLabel 6175 3500 0    50   Input ~ 0
GND
Wire Wire Line
	6175 3500 6275 3500
NoConn ~ 6275 3600
NoConn ~ 6275 3700
NoConn ~ 6275 3800
$Comp
L Bukaerako_Erronka-rescue:ESP-32_HONA_2_ESP-32_HONA_2-Bukaerako_Erronka-cache U1
U 1 1 603649B6
P 3425 3150
F 0 "U1" H 4325 3375 50  0000 C CNN
F 1 "ESP-32_HONA_2_ESP-32_HONA_2" H 4325 3284 50  0000 C CNN
F 2 "ESP_32_444:ESP_32_HONA_V3" H 3425 2850 50  0001 C CNN
F 3 "" H 3425 2850 50  0001 C CNN
	1    3425 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4825 3900 4925 3900
Wire Wire Line
	4825 4000 4925 4000
Text Notes 4450 2675 0    118  Italic 24
LORA\n
Text GLabel 4825 4375 0    50   Input ~ 0
17
Wire Wire Line
	5075 4375 4825 4375
Text GLabel 4950 3200 2    50   Input ~ 0
17
Wire Wire Line
	4825 3200 4950 3200
Text GLabel 5000 3600 2    50   Input ~ 0
22
Wire Wire Line
	4825 3600 5000 3600
Wire Wire Line
	3825 3150 3650 3150
Text GLabel 4950 3350 2    50   Input ~ 0
15
Text GLabel 5125 3250 2    50   Input ~ 0
4
Wire Wire Line
	4825 3250 5125 3250
Wire Wire Line
	4825 3350 4950 3350
Text GLabel 5650 4100 1    50   Input ~ 0
4
Text GLabel 6075 4100 1    50   Input ~ 0
15
Text GLabel 6300 4100 1    50   Input ~ 0
22
Text GLabel 5850 4100 1    50   Input ~ 0
21
Wire Wire Line
	5650 4100 5650 4375
Wire Wire Line
	6075 4100 6075 4375
Wire Wire Line
	6075 4375 6100 4375
Wire Wire Line
	6300 4100 6300 4375
Wire Wire Line
	5850 4100 5850 4375
Text Notes 5925 4325 1    50   ~ 0
SDA
Text Notes 5725 4350 1    50   ~ 0
SDA
Text Notes 6375 4325 1    50   ~ 0
SCL
Text Notes 6150 4325 1    50   ~ 0
SCL
Wire Wire Line
	4925 3825 4925 3900
Text GLabel 4025 4350 2    50   Input ~ 0
GND
Wire Wire Line
	3025 4500 3025 4550
Wire Wire Line
	2875 4500 3025 4500
$Comp
L Connector:Screw_Terminal_01x02 J1
U 1 1 6037A76A
P 2675 4400
F 0 "J1" H 2593 4075 50  0000 C CNN
F 1 "Screw_Terminal_01x02" H 2593 4166 50  0000 C CNN
F 2 "TerminalBlock:TerminalBlock_bornier-2_P5.08mm" H 2675 4400 50  0001 C CNN
F 3 "~" H 2675 4400 50  0001 C CNN
	1    2675 4400
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x04 J4
U 1 1 603CB44B
P 5725 2550
F 0 "J4" H 5643 2125 50  0000 C CNN
F 1 "Led Neopixel" H 5643 2216 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Vertical" H 5725 2550 50  0001 C CNN
F 3 "~" H 5725 2550 50  0001 C CNN
	1    5725 2550
	-1   0    0    1   
$EndComp
Text Notes 5775 2525 2    50   ~ 0
DIN
Text Notes 5775 2450 2    50   ~ 0
GND
Text Notes 5775 2625 2    50   ~ 0
4-7VDC
Text Notes 5775 2725 2    50   ~ 0
GND
Text GLabel 6075 2550 2    50   Input ~ 0
3V3
Text GLabel 6075 2650 2    50   Input ~ 0
GND
Wire Wire Line
	5925 2650 5975 2650
Text GLabel 6225 2450 2    50   Input ~ 0
13
$Comp
L Device:R R1
U 1 1 603F1ACF
P 6075 2450
F 0 "R1" V 6282 2450 50  0000 C CNN
F 1 "470" V 6191 2450 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 6005 2450 50  0001 C CNN
F 3 "~" H 6075 2450 50  0001 C CNN
	1    6075 2450
	0    -1   -1   0   
$EndComp
$Comp
L Bukaerako_Erronka-cache:Connector_Generic_Conn_01x03 J5
U 1 1 60400297
P 5750 4575
F 0 "J5" V 5622 4387 50  0000 R CNN
F 1 "Connector_Generic_Conn_01x03" V 5713 4387 50  0000 R CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x03_P2.54mm_Vertical" H 5750 4575 50  0001 C CNN
F 3 "" H 5750 4575 50  0001 C CNN
	1    5750 4575
	0    -1   1    0   
$EndComp
$Comp
L Bukaerako_Erronka-cache:Connector_Generic_Conn_01x03 J6
U 1 1 60402789
P 6200 4575
F 0 "J6" V 6072 4387 50  0000 R CNN
F 1 "Connector_Generic_Conn_01x03" V 6163 4387 50  0000 R CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x03_P2.54mm_Vertical" H 6200 4575 50  0001 C CNN
F 3 "" H 6200 4575 50  0001 C CNN
	1    6200 4575
	0    -1   1    0   
$EndComp
Text GLabel 6125 3300 0    50   Input ~ 0
SCL
Text GLabel 6125 3400 0    50   Input ~ 0
SDA
Wire Wire Line
	6125 3300 6275 3300
Wire Wire Line
	6125 3400 6275 3400
Text GLabel 6175 4125 1    50   Input ~ 0
SCL
Text GLabel 5750 4150 1    50   Input ~ 0
SDA
Wire Wire Line
	6175 4125 6175 4375
Wire Wire Line
	6175 4375 6200 4375
Wire Wire Line
	5750 4150 5750 4375
Wire Wire Line
	5925 2550 6050 2550
$Comp
L Device:CP C1
U 1 1 603ECDA2
P 5975 2825
F 0 "C1" H 6093 2871 50  0000 L CNN
F 1 "CP" H 6093 2780 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D10.0mm_P3.80mm" H 6013 2675 50  0001 C CNN
F 3 "~" H 5975 2825 50  0001 C CNN
	1    5975 2825
	0    1    -1   0   
$EndComp
Wire Wire Line
	6050 2550 6050 2750
Wire Wire Line
	6050 2750 6125 2750
Wire Wire Line
	6125 2750 6125 2825
Connection ~ 6050 2550
Wire Wire Line
	6050 2550 6075 2550
Wire Wire Line
	5825 2825 5825 2700
Wire Wire Line
	5825 2700 5975 2700
Wire Wire Line
	5975 2700 5975 2650
Connection ~ 5975 2650
Wire Wire Line
	5975 2650 6075 2650
$Comp
L Converter_ACDC:HLK-PM03 PS1
U 1 1 6042DD28
P 3625 4450
F 0 "PS1" H 3625 4775 50  0000 C CNN
F 1 "HLK-PM03" H 3625 4684 50  0000 C CNN
F 2 "Converter_ACDC:Converter_ACDC_HiLink_HLK-PMxx" H 3625 4150 50  0001 C CNN
F 3 "http://www.hlktech.net/product_detail.php?ProId=59" H 4025 4100 50  0001 C CNN
	1    3625 4450
	1    0    0    1   
$EndComp
Wire Wire Line
	3025 4550 3225 4550
Wire Wire Line
	3225 4400 3225 4350
Text GLabel 4025 4550 2    50   Input ~ 0
3V3
$Comp
L Device:Fuse F1
U 1 1 60439041
P 3025 4400
F 0 "F1" V 3222 4400 50  0000 C CNN
F 1 "Fuse" V 3131 4400 50  0000 C CNN
F 2 "Fuse:Fuseholder_Cylinder-5x20mm_Stelvio-Kontek_PTF78_Horizontal_Open" V 2955 4400 50  0001 C CNN
F 3 "~" H 3025 4400 50  0001 C CNN
	1    3025 4400
	0    -1   1    0   
$EndComp
Wire Wire Line
	3175 4400 3225 4400
Text GLabel 3650 3150 0    50   Input ~ 0
21
Text GLabel 3650 3250 0    50   Input ~ 0
13
Wire Wire Line
	3650 3250 3650 3200
Wire Wire Line
	3650 3200 3825 3200
Text GLabel 6100 2375 2    50   Input ~ 0
GND
Wire Wire Line
	5925 2350 6100 2350
Wire Wire Line
	6100 2350 6100 2375
$EndSCHEMATC
