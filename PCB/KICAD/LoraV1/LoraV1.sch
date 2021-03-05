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
L LoraV1-rescue:DHT11-dht11 U3
U 1 1 6034FCFC
P 4300 4300
F 0 "U3" H 4056 4346 50  0000 R CNN
F 1 "DHT11" H 4056 4255 50  0000 R CNN
F 2 "Sensor:Aosong_DHT11_5.5x12.0_P2.54mm" H 4300 3900 50  0001 C CNN
F 3 "" H 4450 4550 50  0001 C CNN
	1    4300 4300
	0    1    1    0   
$EndComp
NoConn ~ 7000 3550
NoConn ~ 7000 3650
NoConn ~ 7000 3750
$Comp
L Connector_Generic:Conn_01x02 J1
U 1 1 60391AE5
P 2900 3400
F 0 "J1" H 2980 3392 50  0000 L CNN
F 1 "Conn_01x02" H 2980 3301 50  0000 L CNN
F 2 "TerminalBlock:TerminalBlock_bornier-2_P5.08mm" H 2900 3400 50  0001 C CNN
F 3 "~" H 2900 3400 50  0001 C CNN
	1    2900 3400
	-1   0    0    -1  
$EndComp
$Comp
L Device:Fuse F1
U 1 1 603CCBAC
P 3450 3500
F 0 "F1" H 3510 3546 50  0000 L CNN
F 1 "Fuse" H 3510 3455 50  0000 L CNN
F 2 "fusiblekutxa:fusiblea" V 3380 3500 50  0001 C CNN
F 3 "~" H 3450 3500 50  0001 C CNN
	1    3450 3500
	0    1    1    0   
$EndComp
Wire Wire Line
	3100 3500 3300 3500
Wire Wire Line
	3600 3500 3800 3500
Wire Wire Line
	3100 3400 3800 3400
$Comp
L Device:R R1
U 1 1 603D10C7
P 6650 4450
F 0 "R1" V 6443 4450 50  0000 C CNN
F 1 "470" V 6534 4450 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 6580 4450 50  0001 C CNN
F 3 "~" H 6650 4450 50  0001 C CNN
	1    6650 4450
	0    1    1    0   
$EndComp
$Comp
L LED:NeoPixel_THT D1
U 1 1 603DC863
P 7250 4450
F 0 "D1" H 7594 4496 50  0000 L CNN
F 1 "NeoPixel_THT" H 7594 4405 50  0000 L CNN
F 2 "LED_SMD:LED_Inolux_IN-PI554FCH_PLCC4_5.0x5.0mm_P3.2mm" H 7300 4150 50  0001 L TNN
F 3 "https://www.adafruit.com/product/1938" H 7350 4075 50  0001 L TNN
	1    7250 4450
	1    0    0    -1  
$EndComp
$Comp
L Device:Jumper_NC_Dual JP1
U 1 1 603F48E1
P 6350 3000
F 0 "JP1" H 6350 3239 50  0000 C CNN
F 1 "Jumper_NC_Dual" H 6350 3148 50  0000 C CNN
F 2 "jumperona:jumperxabi" H 6350 3000 50  0001 C CNN
F 3 "~" H 6350 3000 50  0001 C CNN
	1    6350 3000
	0    -1   -1   0   
$EndComp
$Comp
L LoraV1-rescue:RJCMU-811-RJCMU-811 U4
U 1 1 6034B84B
P 7100 2750
F 0 "U4" H 7428 2146 50  0000 L CNN
F 1 "RJCMU-811" H 7428 2055 50  0000 L CNN
F 2 "RJCMU-811:RJCMU-811" H 7250 2700 50  0001 C CNN
F 3 "" H 7250 2700 50  0001 C CNN
	1    7100 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 3000 6500 3000
Wire Wire Line
	6500 3000 6500 3250
Wire Wire Line
	6500 3250 7000 3250
Wire Wire Line
	6350 3250 6350 3350
Wire Wire Line
	6350 3350 5000 3350
Wire Wire Line
	5000 3350 5000 3900
Wire Wire Line
	5000 3900 5100 3900
Wire Wire Line
	5100 4150 4950 4150
Wire Wire Line
	4950 4150 4950 2750
Wire Wire Line
	4950 2750 6350 2750
$Comp
L Device:Jumper_NC_Dual JP2
U 1 1 60401E41
P 6350 3700
F 0 "JP2" V 6396 3802 50  0000 L CNN
F 1 "Jumper_NC_Dual" V 6305 3802 50  0000 L CNN
F 2 "jumperona:jumperxabi" H 6350 3700 50  0001 C CNN
F 3 "~" H 6350 3700 50  0001 C CNN
	1    6350 3700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7000 3350 6650 3350
Wire Wire Line
	6650 3350 6650 3700
Wire Wire Line
	6650 3700 6450 3700
Wire Wire Line
	6350 3950 6350 4350
Wire Wire Line
	6350 4350 5800 4350
Wire Wire Line
	6350 3450 6350 3400
Wire Wire Line
	6350 3400 5450 3400
Wire Wire Line
	5450 3400 5450 4500
Wire Wire Line
	5450 4500 5000 4500
Wire Wire Line
	5000 4500 5000 4250
Wire Wire Line
	5000 4250 5100 4250
Wire Wire Line
	7000 3150 6900 3150
Wire Wire Line
	6550 3150 6550 2700
Wire Wire Line
	6550 2700 5850 2700
Wire Wire Line
	5850 2700 5850 3500
Wire Wire Line
	5850 3500 5800 3500
Wire Wire Line
	6750 3300 6750 3050
Wire Wire Line
	6750 3050 7000 3050
Wire Wire Line
	4600 4300 5100 4300
NoConn ~ 7550 4450
Wire Wire Line
	7000 3450 6900 3450
Wire Wire Line
	6900 3450 6900 3150
Connection ~ 6900 3150
Wire Wire Line
	6900 3150 6550 3150
Wire Wire Line
	7250 4750 6900 4750
Wire Wire Line
	6900 4750 6900 3450
Connection ~ 6900 3450
$Comp
L Device:CP C1
U 1 1 6042652B
P 7850 4400
F 0 "C1" H 7968 4446 50  0000 L CNN
F 1 "CP" H 7968 4355 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D10.0mm_P3.80mm" H 7888 4250 50  0001 C CNN
F 3 "~" H 7850 4400 50  0001 C CNN
	1    7850 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 4150 7250 4150
Wire Wire Line
	6150 4450 6500 4450
Wire Wire Line
	6800 4450 6950 4450
Wire Wire Line
	7850 4250 7850 4150
Wire Wire Line
	7850 4150 7250 4150
Connection ~ 7250 4150
Wire Wire Line
	7850 4550 7850 4750
Wire Wire Line
	7850 4750 7250 4750
Connection ~ 7250 4750
$Comp
L LoraV1-rescue:TTGO-ESP32-TTGO U2
U 1 1 6047F430
P 5700 3350
F 0 "U2" H 5450 3415 50  0000 C CNN
F 1 "TTGO" H 5450 3324 50  0000 C CNN
F 2 "TTGO:ESP32" H 5450 3300 50  0001 C CNN
F 3 "" H 5450 3300 50  0001 C CNN
	1    5700 3350
	1    0    0    -1  
$EndComp
$Comp
L Converter_ACDC:HLK-PM03 PS1
U 1 1 604AE66B
P 4250 3450
F 0 "PS1" H 4250 3775 50  0000 C CNN
F 1 "HLK-PM03" H 4250 3684 50  0000 C CNN
F 2 "Converter_ACDC:Converter_ACDC_HiLink_HLK-PMxx" H 4250 3150 50  0001 C CNN
F 3 "http://www.hlktech.net/product_detail.php?ProId=59" H 4650 3100 50  0001 C CNN
	1    4250 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3800 3500 3800 3550
Wire Wire Line
	3800 3550 3850 3550
Wire Wire Line
	3800 3400 3800 3350
Wire Wire Line
	3800 3350 3850 3350
Wire Wire Line
	6050 4150 6050 3600
Wire Wire Line
	5800 4300 6150 4300
Wire Wire Line
	6150 4300 6150 4450
Wire Wire Line
	4000 4300 4000 3750
Wire Wire Line
	5800 3600 6050 3600
Wire Wire Line
	4750 3500 4750 3550
Wire Wire Line
	4750 3550 4650 3550
Wire Wire Line
	4850 3600 4850 3350
Wire Wire Line
	4850 3350 4800 3350
Wire Wire Line
	4800 3300 4800 3350
Wire Wire Line
	4800 3300 6750 3300
Connection ~ 4800 3350
Wire Wire Line
	4800 3350 4650 3350
Wire Wire Line
	4850 3600 5100 3600
Wire Wire Line
	4750 3500 5100 3500
Wire Wire Line
	4000 3750 4750 3750
Wire Wire Line
	4750 3750 4750 3550
Connection ~ 4750 3550
$EndSCHEMATC
