EESchema Schematic File Version 4
LIBS:AS5600-breakout-cache
EELAYER 29 0
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
L AS5600:AS5600 U1
U 1 1 5CF771DC
P 4550 2400
F 0 "U1" H 4700 2837 60  0000 C CNN
F 1 "AS5600" H 4700 2731 60  0000 C CNN
F 2 "SOIC127P600X175-8N:SOIC127P600X175-8N" H 4550 2400 60  0001 C CNN
F 3 "" H 4550 2400 60  0001 C CNN
	1    4550 2400
	1    0    0    -1  
$EndComp
$Comp
L pspice:CAP C1
U 1 1 5CF7799C
P 3250 2850
F 0 "C1" H 3428 2896 50  0000 L CNN
F 1 "100nF" H 3428 2805 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D4.7mm_W2.5mm_P5.00mm" H 3250 2850 50  0001 C CNN
F 3 "~" H 3250 2850 50  0001 C CNN
	1    3250 2850
	1    0    0    -1  
$EndComp
$Comp
L pspice:CAP C2
U 1 1 5CF77A7D
P 3900 2850
F 0 "C2" H 4078 2896 50  0000 L CNN
F 1 "1uF" H 4078 2805 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.00mm" H 3900 2850 50  0001 C CNN
F 3 "~" H 3900 2850 50  0001 C CNN
	1    3900 2850
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5CF77B50
P 5350 2150
F 0 "R1" H 5420 2196 50  0000 L CNN
F 1 "4.7k" H 5420 2105 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5280 2150 50  0001 C CNN
F 3 "~" H 5350 2150 50  0001 C CNN
	1    5350 2150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5CF77C73
P 5650 2250
F 0 "R2" H 5720 2296 50  0000 L CNN
F 1 "4.7k" H 5720 2205 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5580 2250 50  0001 C CNN
F 3 "~" H 5650 2250 50  0001 C CNN
	1    5650 2250
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0101
U 1 1 5CF77CEB
P 5350 1900
F 0 "#PWR0101" H 5350 1750 50  0001 C CNN
F 1 "+5V" H 5365 2073 50  0000 C CNN
F 2 "" H 5350 1900 50  0001 C CNN
F 3 "" H 5350 1900 50  0001 C CNN
	1    5350 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 2350 3900 2350
Wire Wire Line
	3900 2350 3900 2600
Wire Wire Line
	3250 2250 3250 2600
Wire Wire Line
	3250 2250 3600 2250
$Comp
L power:GND #PWR0102
U 1 1 5CF77E5A
P 3250 3350
F 0 "#PWR0102" H 3250 3100 50  0001 C CNN
F 1 "GND" H 3255 3177 50  0000 C CNN
F 2 "" H 3250 3350 50  0001 C CNN
F 3 "" H 3250 3350 50  0001 C CNN
	1    3250 3350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 5CF77E86
P 3900 3350
F 0 "#PWR0103" H 3900 3100 50  0001 C CNN
F 1 "GND" H 3905 3177 50  0000 C CNN
F 2 "" H 3900 3350 50  0001 C CNN
F 3 "" H 3900 3350 50  0001 C CNN
	1    3900 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 2300 5350 2350
Wire Wire Line
	5350 2350 5200 2350
Wire Wire Line
	5200 2450 5650 2450
Wire Wire Line
	5650 2450 5650 2400
Text GLabel 5750 2450 2    50   Input ~ 0
SDA
Text GLabel 6050 2350 2    50   Input ~ 0
SCL
Wire Wire Line
	5750 2450 5650 2450
Connection ~ 5650 2450
Wire Wire Line
	5350 2350 6050 2350
Connection ~ 5350 2350
$Comp
L power:+5V #PWR0105
U 1 1 5CF7895E
P 5650 2000
F 0 "#PWR0105" H 5650 1850 50  0001 C CNN
F 1 "+5V" H 5665 2173 50  0000 C CNN
F 2 "" H 5650 2000 50  0001 C CNN
F 3 "" H 5650 2000 50  0001 C CNN
	1    5650 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 2000 5650 2100
Wire Wire Line
	5350 1900 5350 2000
$Comp
L Connector:Conn_01x03_Male J4
U 1 1 5CF78AF4
P 4800 1400
F 0 "J4" H 4773 1330 50  0000 R CNN
F 1 "Conn_01x03_Male" H 4773 1421 50  0000 R CNN
F 2 "AS5600-breakout:SOIC127_solder_switch" H 4800 1400 50  0001 C CNN
F 3 "~" H 4800 1400 50  0001 C CNN
	1    4800 1400
	-1   0    0    1   
$EndComp
Text GLabel 5200 2050 1    50   Input ~ 0
DIR
Wire Wire Line
	5200 2050 5200 2250
Text GLabel 4350 1400 0    50   Input ~ 0
DIR
Wire Wire Line
	4350 1400 4600 1400
$Comp
L power:+5V #PWR0106
U 1 1 5CF78F13
P 4500 1200
F 0 "#PWR0106" H 4500 1050 50  0001 C CNN
F 1 "+5V" H 4515 1373 50  0000 C CNN
F 2 "" H 4500 1200 50  0001 C CNN
F 3 "" H 4500 1200 50  0001 C CNN
	1    4500 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 1300 4500 1300
Wire Wire Line
	4500 1300 4500 1200
$Comp
L power:GND #PWR0107
U 1 1 5CF7906F
P 4500 1600
F 0 "#PWR0107" H 4500 1350 50  0001 C CNN
F 1 "GND" H 4505 1427 50  0000 C CNN
F 2 "" H 4500 1600 50  0001 C CNN
F 3 "" H 4500 1600 50  0001 C CNN
	1    4500 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 1500 4500 1500
Wire Wire Line
	4500 1500 4500 1600
Wire Wire Line
	3900 3100 3900 3350
Wire Wire Line
	3250 3100 3250 3350
Text GLabel 4150 2450 0    50   Input ~ 0
OUT
Wire Wire Line
	4200 2450 4150 2450
$Comp
L power:GND #PWR0108
U 1 1 5CF79891
P 4200 2600
F 0 "#PWR0108" H 4200 2350 50  0001 C CNN
F 1 "GND" H 4250 2450 50  0000 C CNN
F 2 "" H 4200 2600 50  0001 C CNN
F 3 "" H 4200 2600 50  0001 C CNN
	1    4200 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 2550 4200 2600
$Comp
L power:+5V #PWR0109
U 1 1 5CF79B59
P 6600 2200
F 0 "#PWR0109" H 6600 2050 50  0001 C CNN
F 1 "+5V" H 6615 2373 50  0000 C CNN
F 2 "" H 6600 2200 50  0001 C CNN
F 3 "" H 6600 2200 50  0001 C CNN
	1    6600 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6600 2300 6600 2200
Text GLabel 6600 2500 0    50   Input ~ 0
SDA
Text GLabel 6600 2400 0    50   Input ~ 0
SCL
Wire Wire Line
	6600 2700 6600 2750
Text GLabel 6600 2600 0    50   Input ~ 0
OUT
$Comp
L power:+5V #PWR0111
U 1 1 5CF7ABC9
P 3250 2150
F 0 "#PWR0111" H 3250 2000 50  0001 C CNN
F 1 "+5V" H 3265 2323 50  0000 C CNN
F 2 "" H 3250 2150 50  0001 C CNN
F 3 "" H 3250 2150 50  0001 C CNN
	1    3250 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3250 2150 3250 2250
Connection ~ 3250 2250
$Comp
L Connector_Generic:Conn_01x02 J2
U 1 1 5CF7AFD7
P 3700 2550
F 0 "J2" V 3700 2650 50  0000 L CNN
F 1 "Conn_01x02" V 3800 2250 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 3700 2550 50  0001 C CNN
F 3 "~" H 3700 2550 50  0001 C CNN
	1    3700 2550
	0    1    1    0   
$EndComp
Wire Wire Line
	3900 2350 3700 2350
Connection ~ 3900 2350
Wire Wire Line
	3600 2350 3600 2250
Connection ~ 3600 2250
Wire Wire Line
	3600 2250 4200 2250
$Comp
L Connector:Conn_01x05_Female J3
U 1 1 5CF784F9
P 6900 2500
F 0 "J3" H 6927 2526 50  0000 L CNN
F 1 "Conn_01x05_Female" H 6927 2435 50  0000 L CNN
F 2 "Connector_Molex:Molex_KK-254_AE-6410-05A_1x05_P2.54mm_Vertical" H 6900 2500 50  0001 C CNN
F 3 "~" H 6900 2500 50  0001 C CNN
	1    6900 2500
	1    0    0    1   
$EndComp
Wire Wire Line
	6700 2300 6600 2300
Wire Wire Line
	6700 2600 6600 2600
Wire Wire Line
	6600 2700 6700 2700
$Comp
L power:GND #PWR0104
U 1 1 5CFD15D0
P 6600 2750
F 0 "#PWR0104" H 6600 2500 50  0001 C CNN
F 1 "GND" H 6605 2577 50  0000 C CNN
F 2 "" H 6600 2750 50  0001 C CNN
F 3 "" H 6600 2750 50  0001 C CNN
	1    6600 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	6700 2400 6600 2400
Wire Wire Line
	6600 2500 6700 2500
$Comp
L Mechanical:MountingHole H1
U 1 1 5CFDB7FC
P 4750 3050
F 0 "H1" H 4850 3096 50  0000 L CNN
F 1 "MountingHole" H 4850 3005 50  0000 L CNN
F 2 "AS5600-breakout:MountingHole_2.2mm_M2_small" H 4750 3050 50  0001 C CNN
F 3 "~" H 4750 3050 50  0001 C CNN
	1    4750 3050
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H2
U 1 1 5CFDC0C0
P 5050 3050
F 0 "H2" H 5150 3096 50  0000 L CNN
F 1 "MountingHole" H 5150 3005 50  0000 L CNN
F 2 "AS5600-breakout:MountingHole_2.2mm_M2_small" H 5050 3050 50  0001 C CNN
F 3 "~" H 5050 3050 50  0001 C CNN
	1    5050 3050
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H3
U 1 1 5CFDC689
P 5350 3050
F 0 "H3" H 5450 3096 50  0000 L CNN
F 1 "MountingHole" H 5450 3005 50  0000 L CNN
F 2 "AS5600-breakout:MountingHole_2.2mm_M2_small" H 5350 3050 50  0001 C CNN
F 3 "~" H 5350 3050 50  0001 C CNN
	1    5350 3050
	1    0    0    -1  
$EndComp
$EndSCHEMATC
