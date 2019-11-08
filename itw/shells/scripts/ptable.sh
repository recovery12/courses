#!/bin/bash
#This script is used to tell the details of elements when atomic number of that element is given as input

if [ $# -ne 0 ]
then
	echo -e "\e[1;31m !!Synatx Error!!\e[0m \n see the \e[1;34m Syntax: ./ptable.sh\e[0m"
	exit 1
fi
echo -e "\e[0;31m 1.Hydrogen       11.Sodium         21.Scandium     \e[0m"
echo -e "\e[0;32m 2.Helium         12.Magnesium      22.Titanium     \e[0m"
echo -e "\e[0;33m 3.Lithium        13.Aluminium      23.Vanadium     \e[0m"
echo -e "\e[0;34m 4.Beryllium      14.Silicon        24.Chromium     \e[0m"
echo -e "\e[0;35m 5.Boron          15.Phosphorus     25.Manganese    \e[0m"
echo -e "\e[0;36m 6.Carbon         16.Sulphur        26.Iron	     \e[0m"
echo -e "\e[1;30m 7.Nitrogen       17.Chlorine       27.Cobalt       \e[0m"
echo -e "\e[1;31m 8.Oxygen         18.Argon          28.Nickel       \e[0m"
echo -e "\e[1;32m 9.Fluorine       19.Potassium      29.Copper       \e[0m"
echo -e "\e[1;36m 10.Neon          20.Calcium        30.Zinc         \e[0m"
echo -e "\e[0;31m 31.Gallium       41.Niobium        51.Antimony     \e[0m"
echo -e "\e[0;32m 32.Germanium     42.Molybdenum     52.Tellurium    \e[0m"
echo -e "\e[0;33m 33.Arsenic       43.Technetium     53.Iodine       \e[0m"
echo -e "\e[0;34m 34.Selenium      44.Ruthenium      54.Xenon        \e[0m"
echo -e "\e[0;35m 35.Bromine       45.Rhodium        55.Caesium      \e[0m"
echo -e "\e[0;36m 36.Krypton       46.Palladium      56.Barium       \e[0m"
echo -e "\e[1;30m 37.Rubidium      47.Silver         57.Lanthanum    \e[0m"
echo -e "\e[1;31m 38.Strontium     48.Cadmium        58.Cerium       \e[0m"
echo -e "\e[1;32m 39.Yttrium       49.Indium         59.Praseodymium \e[0m"
echo -e "\e[1;36m 40.Zirconium     50.Tin            60.Neodymium    \e[0m"
echo -e "\e[0;31m 61.Promethium    71.Lutetium       81.Thallium     \e[0m"
echo -e "\e[0;32m 62.Samarium      72.Hafnium        82.Lead         \e[0m"
echo -e "\e[0;33m 63.Europium      73.Tantalum       83.Bismuth      \e[0m"
echo -e "\e[0;34m 64.Gadolinium    74.Tungsten       84.Polonium     \e[0m"
echo -e "\e[0;35m 65.Terbium       75.Rhenium        85.Astatine     \e[0m"
echo -e "\e[0;36m 66.Dysprosium    76.Osmium         86.Radon        \e[0m"
echo -e "\e[1;30m 67.Holmium       77.Iridium        87.Francium     \e[0m"
echo -e "\e[1;31m 68.Erbium        78.Platinum       88.Radium       \e[0m"
echo -e "\e[1;32m 69.Thulium       79.Gold           89.Actinium     \e[0m"
echo -e "\e[1;36m 70.Ytterbium     80.Mercury        90.Thorium      \e[0m"
echo -e "\e[0;31m 91.Protactinium  101.Mendelevium   111.Roentgenium \e[0m"
echo -e "\e[0;32m 92.Uranium       102.Nobelium      112.Copernicium \e[0m"
echo -e "\e[0;33m 93.Neptunium     103.Lawrencium    113.Nihonium    \e[0m"
echo -e "\e[0;34m 94.Plutonium     104.Rutherfordium 114.Flerovium   \e[0m"
echo -e "\e[0;35m 95.Americium     105.Dubnium       115.Moscovium   \e[0m"
echo -e "\e[0;36m 96.Curium        106.Seaborgium    116.Livermorium \e[0m"
echo -e "\e[1;30m 97.Berkelium     107.Bohrium       117.Tennessine  \e[0m"
echo -e "\e[1;31m 98.Californium   108.Hassium       118.Oganesson   \e[0m"
echo -e "\e[1;32m 99.Einsteinium   109.Meitnerium                    \e[0m"
echo -e "\e[1;36m 100.Fermium      110.Darmstdtium                   \e[0m"

read -p "Select an atomic number: " a ; clear

case $a
in 
	1)echo -e "\e[0;31m Name: Hydrogen \n Atomic Weight: 1.0079 \n Atomic number: 1 \n Latin name: No latin name \n Class: Non-metal \n Symbol: \n $(figlet -c H)\e[0m";;
	2)echo -e "\e[0;32m Name: Helium \n Atomic Weight: 4.00 \n Atomic number: 2 \n Latin name: no latin name \n Class: Nobel gas \n Symbol: \n $(figlet -c He)\e[0m";;
	3)echo -e "\e[0;33m Name: Lithium \n Atomic Weight: 6.94 \n Atomic number: 3 \n Latin name: no latin name \n Class: Alkali metals \n Symbol: \n $(figlet -c Li)\e[0m";;
	4)echo -e "\e[0;34m Name: Beryllium \n Atomic Weight: 9.01 \n Atomic number: 4 \n Latin name: no latin name \n Class: Alkaline earth metals \n Symbol: \n $(figlet -c Be)\e[0m";;
	5)echo -e "\e[0;35m Name: Boron \n Atomic Weight: 10.81 \n Atomic number: 5 \n Latin name: no latin name \n Class: Metalliod \n Symbol: \n $(figlet -c B)\e[0m";;
	6)echo -e "\e[0;36m Name: Carbon \n Atomic Weight: 12.01 \n Atomic number: C \n Latin name: no latin name \n Class: Non-metal \n Symbol: \n $(figlet -c C)\e[0m";;
	7)echo -e "\e[1;30m Name: Nitrogen \n Atomic Weight: 14.0067 \n Atomic number: 7 \n Latin name: no latin name \n Class: Non-metal \n Symbol: \n $(figlet -c N)\e[0m";;
	8)echo -e "\e[1;31m Name: Oxygen \n Atomic Weight: 16.00 \n Atomic number: 8 \n Latin name: no latin name \n Class: Non-metal \n Symbol: \n $(figlet -c O)\e[0m";;
	9)echo -e "\e[1;32m Name: Fluorine \n Atomic Weight: 19.00 \n Atomic number: 9 \n Latin name: no latin name \n Class: Non-metal \n Symbol: \n $(figlet -c F)\e[0m";;
	10)echo -e "\e[1;36m Name: Neon \n Atomic Weight: 20.18 \n Atomic number: 10 \n Latin name: no latin name \n Class: Nobel gas \n Symbol: \n $(figlet -c Ne)\e[0m";;
	11)echo -e "\e[0;31m Name: Sodium \n Atomic Weight: 22.99 \n Atomic number: 11 \n Latin name: Natrium \n Class: Alkali metals \n Symbol: \n $(figlet -c Na)\e[0m";;
	12)echo -e "\e[0;32m Name: Magnesium \n Atomic Weight: 24.31 \n Atomic number: 12 \n Latin name: no latin name \n Class: Alkaline earth metals \n Symbol: \n $(figlet -c Mg)\e[0m";;
	13)echo -e "\e[0;33m Name: Aluminium \n Atomic Weight: 26.98 \n Atomic number: 13 \n Latin name: no latin name \n Class: Post-transition metal \n Symbol: \n $(figlet -c Al)\e[0m";;
	14)echo -e "\e[0;34m Name: Silicon \n Atomic Weight: 28.08 \n Atomic number: 14 \n Latin name: no latin name \n Class: Metalliod \n Symbol: \n $(figlet -c Si)\e[0m";;
	15)echo -e "\e[0;35m Name: Phosphorus \n Atomic Weight: 30.97 \n Atomic number: 15 \n Latin name: no latin name \n Class: Non-metal \n Symbol: \n $(figlet -c P)\e[0m";;
	16)echo -e "\e[0;36m Name: Sulphur \n Atomic Weight: 32.06 \n Atomic number: 16 \n Latin name: no latin name \n Class: Non-metal \n Symbol: \n $(figlet -c S)\e[0m";;
	17)echo -e "\e[1;30m Name: Chlorine \n Atomic Weight: 35.45 \n Atomic number: 17 \n Latin name: no latin name \n Class: Non-metal \n Symbol: \n $(figlet -c Cl)\e[0m";;
	18)echo -e "\e[1;31m Name: Argon \n Atomic Weight: 39.95 \n Atomic number: 18 \n Latin name: no latin name \n Class: Nobel gas \n Symbol: \n $(figlet -c Ar)\e[0m";;
	19)echo -e "\e[1;32m Name: Potassium \n Atomic Weight: 39.10 \n Atomic number: 19 \n Latin name: kalium \n Class: Alkali metals \n Symbol: \n $(figlet -c K)\e[0m";;
	20)echo -e "\e[1;36m Name: Calcium \n Atomic Weight: 40.08 \n Atomic number: 20 \n Latin name: no latin name \n Class: Alkaline earth metals \n Symbol: \n $(figlet -c Ca)\e[0m";;
	21)echo -e "\e[0;31m Name: Scandium \n Atomic Weight: 44.96 \n Atomic number: 21 \n Latin name: no latin name \n Class: Transition metal \n Symbol: \n $(figlet -c Sc)\e[0m";;
	22)echo -e "\e[0;32m Name: Titanium \n Atomic Weight: 47.88 \n Atomic number: 22 \n Latin name: no latin name \n Class: Transition metal \n Symbol: \n $(figlet -c Ti)\e[0m";;
	23)echo -e "\e[0;33m Name: Vanadium \n Atomic Weight: 50.94 \n Atomic number: 23 \n Latin name: no latin name \n Class: Transition metal \n Symbol: \n $(figlet -c V)\e[0m";;
	24)echo -e "\e[0;34m Name: Chromium \n Atomic Weight: 52.00 \n Atomic number: 24 \n Latin name: no latin name \n Class: Transition metal \n Symbol: \n $(figlet -c Cr)\e[0m";;
	25)echo -e "\e[0;35m Name: Manganese \n Atomic Weight: 54.94 \n Atomic number: 25 \n Latin name: no latin name \n Class: Transition metal \n Symbol: \n $(figlet -c Mn)\e[0m";;
	26)echo -e "\e[0;36m Name: Iron \n Atomic Weight: 55.85 \n Atomic number: 26 \n Latin name: Ferrum \n Class: Transition metal \n Symbol: \n $(figlet -c Fe)\e[0m";;
	27)echo -e "\e[1;30m Name: Cobalt \n Atomic Weight: 58.93 \n Atomic number: 27 \n Latin name: no latin name \n Class: Transition metal \n Symbol: \n $(figlet -c Co)\e[0m";;
	28)echo -e "\e[1;31m Name: Nickel \n Atomic Weight: 58.71 \n Atomic number: 28 \n Latin name: no latin name \n Class: Transition metal \n Symbol: \n $(figlet -c Ni)\e[0m";;
	29)echo -e "\e[1;32m Name: Copper \n Atomic Weight: 63.54 \n Atomic number: 29 \n Latin name: cuprum \n Class: Transition metal \n Symbol: \n $(figlet -c Cu)\e[0m";;
	30)echo -e "\e[1;36m Name: Zinc \n Atomic Weight: 65.37 \n Atomic number: 30 \n Latin name: no latin name \n Class: Transition metal \n Symbol: \n $(figlet -c Zn)\e[0m";;
	31)echo -e "\e[0;31m Name: Gallium \n Atomic Weight: 69.72 \n Atomic number: 31 \n Latin name: No latin name \n Class: Post-transition metal \n Symbol: \n $(figlet -c Ga)\e[0m";;
	32)echo -e "\e[0;32m Name: Germanium \n Atomic Weight: 72.63 \n Atomic number: 32 \n Latin name: No latin name \n Class: Metalliod \n Symbol: \n $(figlet -c Ge)\e[0m";;
	33)echo -e "\e[0;33m Name: Arsenic \n Atomic Weight: 74.92 \n Atomic number: 33 \n Latin name: No latin name \n Class: Metalliod \n Symbol: \n $(figlet -c As)\e[0m";;
	34)echo -e "\e[0;34m Name: Selenium \n Atomic Weight: 78.97 \n Atomic number: 34 \n Latin name: No latin name \n Class: Non-metal \n Symbol: \n $(figlet -c Se)\e[0m";;
	35)echo -e "\e[0;35m Name: Bromine \n Atomic Weight: 79.90 \n Atomic number: 35 \n Latin name: No latin name \n Class: Non-metal \n Symbol: \n $(figlet -c Br)\e[0m";;
	36)echo -e "\e[0;36m Name: Krypton \n Atomic Weight: 83.79 \n Atomic number: 36 \n Latin name: No latin name \n Class: Nobel gas \n Symbol: \n $(figlet -c Kr)\e[0m";;
	37)echo -e "\e[1;30m Name: Rubidium \n Atomic Weight: 85.46 \n Atomic number: 37 \n Latin name: No latin name \n Class: Alkali metals \n Symbol: \n $(figlet -c Ru)\e[0m";;
	38)echo -e "\e[1;31m Name: Strontium \n Atomic Weight: 87.62 \n Atomic number: 38 \n Latin name: No latin name \n Class: Alkaline earth metals \n Symbol: \n $(figlet -c Sr)\e[0m";;
	39)echo -e "\e[1;32m Name: Yttrium \n Atomic Weight: 88.90 \n Atomic number: 39 \n Latin name: No latin name \n Class: Transition metal \n Symbol: \n $(figlet -c Y)\e[0m";;
	40)echo -e "\e[1;36m Name: Zirconium \n Atomic Weight: 91.22 \n Atomic number: 40 \n Latin name: No latin name \n Class: Transition metal \n Symbol: \n $(figlet -c Zr)\e[0m";;
	41)echo -e "\e[0;31m Name: Niobium \n Atomic Weight: 92.90 \n Atomic number: 41 \n Latin name: No latin name \n Class: Transition metal \n Symbol: \n $(figlet -c Nb)\e[0m";;
	42)echo -e "\e[0;32m Name: Molybdenum \n Atomic Weight: 95.95 \n Atomic number: 42 \n Latin name: No latin name \n Class: Transition metal \n Symbol: \n $(figlet -c Mo)\e[0m";;
	43)echo -e "\e[0;33m Name: Technetium* \n Atomic Weight: (98) \n Atomic number: 43 \n Latin name: No latin name \n Class: Transition metal \n Symbol: \n $(figlet -c Tc) \n ----------------------------------------- \n *means its a radioactive element. \e[0m";;
	44)echo -e "\e[0;34m Name: Ruthenium \n Atomic Weight: 101.07 \n Atomic number: 44 \n Latin name: No latin name \n Class: Transition metal \n Symbol: \n $(figlet -c Ru)\e[0m";;	
	45)echo -e "\e[0;35m Name: Rhodium \n Atomic Weight: 102.91 \n Atomic number: 45 \n Latin name: No latin name \n Class: Transition metal \n Symbol: \n $(figlet -c Rh)\e[0m";;
	46)echo -e "\e[0;36m Name: Palladium \n Atomic Weight: 106.42 \n Atomic number: 46 \n Latin name: No latin name \n Class: Transition metal \n Symbol: \n $(figlet -c Pd)\e[0m";;
	47)echo -e "\e[1;30m Name: Silver \n Atomic Weight: 107.87 \n Atomic number: 47 \n Latin name: Argentum \n Class: Transition metal \n Symbol: \n $(figlet -c Ag)\e[0m";;
	48)echo -e "\e[1;31m Name: Cadmium \n Atomic Weight: 112.41 \n Atomic number: 48 \n Latin name: No latin name \n Class: Transition metal \n Symbol: \n $(figlet -c Cd)\e[0m";;
	49)echo -e "\e[1;32m Name: Indium \n Atomic Weight: 114.82 \n Atomic number: 49 \n Latin name: No latin name  \n Class: Post-transition metal \n Symbol: \n $(figlet -c In)\e[0m";;
	50)echo -e "\e[1;36m Name: Tin \n Atomic Weight: 118.71 \n Atomic number: 50 \n Latin name: Stannum \n Class: Post-transition metal \n Symbol: \n $(figlet -c Sn)\e[0m";;
	51)echo -e "\e[0;31m Name: Antimony \n Atomic Weight: 121.76 \n Atomic number: 51 \n Latin name: Stibium \n Class: Metalliod \n Symbol: \n $(figlet -c Sb)\e[0m";;
	52)echo -e "\e[0;32m Name: Tellurium \n Atomic Weight: 127.60 \n Atomic number: 52 \n Latin name: No latin name \n Class: Metalliod \n Symbol: \n $(figlet -c Te)\e[0m";;
	53)echo -e "\e[0;33m Name: Iodine \n Atomic Weight: 126.90 \n Atomic number: 53 \n Latin name: No latin name \n Class: Non-metal \n Symbol: \n $(figlet -c I)\e[0m";;
	54)echo -e "\e[0;34m Name: Xenon \n Atomic Weight: 131.29 \n Atomic number: 54 \n Latin name: No latin name \n Class: Nobel gas \n Symbol: \n $(figlet -c Xe)\e[0m";;
	55)echo -e "\e[0;35m Name: Caesium \n Atomic Weight: 132.91 \n Atomic number: 55 \n Latin name: No latin name \n Class: Alkali metals \n Symbol: \n $(figlet -c Cs)\e[0m";;
	56)echo -e "\e[0;36m Name: Barium \n Atomic Weight: 137.33 \n Atomic number: 56 \n Latin name: No latin name \n Class: Alkaline earth metals \n Symbol: \n $(figlet -c Ba)\e[0m";;
	57)echo -e "\e[1;30m Name: Lanthanum \n Atomic Weight: 138.91 \n Atomic number: 57 \n Latin name: No latin name \n Class: Lanthanoid \n Symbol: \n $(figlet -c La)\e[0m";;
	58)echo -e "\e[1;31m Name: Cerium \n Atomic Weight: 140.12 \n Atomic number: 58 \n Latin name: No latin name \n Class: Lanthanoid \n Symbol: \n $(figlet -c Ce)\e[0m";;
	59)echo -e "\e[1;32m Name: Praseodymium \n Atomic Weight: 140.91 \n Atomic number: 59 \n Latin name: No latin name \n Class: Lanthanoid \n Symbol: \n $(figlet -c Pr)\e[0m";;
	60)echo -e "\e[1;36m Name: Neodymium \n Atomic Weight: 144.24 \n Atomic number: 60 \n Latin name: No latin name \n Class: Lanthanoid \n Symbol: \n $(figlet -c Nd)\e[0m";;
	61)echo -e "\e[0;31m Name: Promethium \n Atomic Weight: (145) \n Atomic number: 61 \n Latin name: No latin name \n Class: Lanthanoid \n Symbol: \n $(figlet -c Pm)\e[0m";;
	62)echo -e "\e[0;32m Name: Samarium \n Atomic Weight: 150.36 \n Atomic number: 62 \n Latin name: No latin name \n Class: Lanthanoid \n Symbol: \n $(figlet -c Sm)\e[0m";;
	63)echo -e "\e[0;33m Name: Europium \n Atomic Weight: 151.96 \n Atomic number: 63 \n Latin name: No latin name \n Class: Lanthanoid \n Symbol: \n $(figlet -c Eu)\e[0m";;
	64)echo -e "\e[0;34m Name: Gadolinium \n Atomic Weight: 157.25 \n Atomic number: 64 \n Latin name: No latin name \n Class: Lanthanoid \n Symbol: \n $(figlet -c Gd)\e[0m";;
	65)echo -e "\e[0;35m Name: Terbium \n Atomic Weight: 158.93 \n Atomic number: 65 \n Latin name: No latin name \n Class: Lanthanoid \n Symbol: \n $(figlet -c Tb)\e[0m";;
	66)echo -e "\e[0;36m Name: Dysproium \n Atomic Weight: 162.50 \n Atomic number: 66 \n Latin name: No latin name \n Class: Lanthanoid \n Symbol: \n $(figlet -c Dy)\e[0m";;
	67)echo -e "\e[1;30m Name: Holmium \n Atomic Weight: 164.93 \n Atomic number: 67 \n Latin name: No latin name \n Class: Lanthanoid \n Symbol: \n $(figlet -c Ho)\e[0m";;
	68)echo -e "\e[1;31m Name: Erbium \n Atomic Weight: 167.26 \n Atomic number: 68 \n Latin name: No latin name \n Class: Lanthanoid \n Symbol: \n $(figlet -c Er)\e[0m";;
	69)echo -e "\e[1;32m Name: Thulium \n Atomic Weight: 168.93 \n Atomic number: 69 \n Latin name: No latin name \n Class: Lanthanoid \n Symbol: \n $(figlet -c Tm)\e[0m";;
	70)echo -e "\e[1;36m Name: Ytterbium \n Atomic Weight: 173.05 \n Atomic number: 70 \n Latin name: No latin name \n Class: Lanthanoid \n Symbol: \n $(figlet -c Yb)\e[0m";;
	71)echo -e "\e[0;31m Name: Lutetium \n Atomic Weight: 174.97 \n Atomic number: 71 \n Latin name: No latin name \n Class: Lanthanoid \n Symbol: \n $(figlet -c Lu)\e[0m";;
	72)echo -e "\e[0;32m Name: Hafnium \n Atomic Weight: 178.49 \n Atomic number: 72 \n Latin name: No latin name \n Class: Transition metal \n Symbol: \n $(figlet -c Hf)\e[0m";;
	73)echo -e "\e[0;33m Name: Tantalum \n Atomic Weight: 180.95 \n Atomic number: 73 \n Latin name: No latin name \n Class: Transition metal \n Symbol: \n $(figlet -c Ta)\e[0m";;
	74)echo -e "\e[0;34m Name: Tungsten \n Atomic Weight: 183.84 \n Atomic number: 74 \n Latin name: Wolfram \n Class: Transition metal \n Symbol: \n $(figlet -c W)\e[0m";;
	75)echo -e "\e[0;35m Name: Rhenium \n Atomic Weight: 186.21 \n Atomic number: 75 \n Latin name: No latin name \n Class: Transition metal \n Symbol: \n $(figlet -c Re)\e[0m";;
	76)echo -e "\e[0;36m Name: Osmium \n Atomic Weight: 190.23 \n Atomic number: 76 \n Latin name: No latin name \n Class: Transition metal \n Symbol: \n $(figlet -c Os)\e[0m";;
	77)echo -e "\e[1;30m Name: Iridium \n Atomic Weight: 192.22 \n Atomic number: 77 \n Latin name: No latin name \n Class: Transition metal \n Symbol: \n $(figlet -c Ir)\e[0m";;
	78)echo -e "\e[1;31m Name: Platinum \n Atomic Weight: 195.08 \n Atomic number: 78 \n Latin name: No latin name \n Class: Transition metal \n Symbol: \n $(figlet -c Pt)\e[0m";;
	79)echo -e "\e[1;32m Name: Gold \n Atomic Weight: 196.97 \n Atomic number: 79 \n Latin name: Aurum \n Class: Transition metal \n Symbol: \n $(figlet -c Au)\e[0m";;
	80)echo -e "\e[1;36m Name: Mercury \n Atomic Weight: 200.59 \n Atomic number: 80 \n Latin name: No latin name \n Class: Transition metal \n Symbol: \n $(figlet -c Hg)\e[0m";;
	81)echo -e "\e[0;31m Name: Thallium \n Atomic Weight: 204.38 \n Atomic number: 81 \n Latin name: No latin name \n Class: Post-transition metal \n Symbol: \n $(figlet -c Tl)\e[0m";;
	82)echo -e "\e[0;33m Name: Lead \n Atomic Weight: 207.2 \n Atomic number: 82 \n Latin name: Plumbum \n Class: Post-transition metal \n Symbol: \n $(figlet -c Pb)\e[0m";;
	83)echo -e "\e[0;34m Name: Bismuth \n Atomic Weight: 208.98 \n Atomic number: 83 \n Latin name: No latin name \n Class: Post-transition metal \n Symbol: \n $(figlet -c Bi)\e[0m";;
	84)echo -e "\e[0;35m Name: Polonium* \n Atomic Weight: (209) \n Atomic number: 84 \n Latin name: No latin name \n Class: Post-transition metal \n Symbol: \n $(figlet -c Po) \n ----------------------------------------- \n *means its a radioactive element.\e[0m";;
	85)echo -e "\e[0;36m Name: Astatine* \n Atomic Weight: (210) \n Atomic number: 85 \n Latin name: No latin name \n Class: Metalliod \n Symbol: \n $(figlet -c At) \n ----------------------------------------- \n *means its a radioactive element.\e[0m";;
	86)echo -e "\e[1;30m Name: Radon* \n Atomic Weight: (222) \n Atomic number: 86 \n Latin name: No latin name \n Class: Nobel gas \n Symbol: \n $(figlet -c Rn) \n ----------------------------------------- \n *means its a radioactive element.\e[0m";;
	87)echo -e "\e[1;31m Name: Francium* \n Atomic Weight: (223) \n Atomic number: 87 \n Latin name: No latin name \n Class: Alkali metal \n Symbol: \n $(figlet -c Fr) \n ----------------------------------------- \n *means its a radioactive element.\e[0m";;
	88)echo -e "\e[0;35m Name: Radium* \n Atomic Weight: (226) \n Atomic number: 88 \n Latin name: No latin name \n Class: Alkaline earth metal \n Symbol: \n $(figlet -c Ra) \n ----------------------------------------- \n *means its a radioactive element.\e[0m";;
	89)echo -e "\e[1;32m Name: Actinium* \n Atomic Weight: (227) \n Atomic number: 89 \n Latin name: No latin name \n Class: Actinoid \n Symbol: \n $(figlet -c Ac) \n ----------------------------------------- \n *means its a radioactive element.\e[0m";;
	90)echo -e "\e[1;36m Name: Thorium \n Atomic Weight: 232.04 \n Atomic number: 90 \n Latin name: No latin name \n Class: Actinoid \n Symbol: \n $(figlet -c Th)\e[0m";;
	91)echo -e "\e[0;31m Name: Protactinium* \n Atomic Weight: 231.04 \n Atomic number: 91 \n Latin name: No latin name \n Class: Actinoid \n Symbol: \n $(figlet -c Pa) \n ----------------------------------------- \n *means its a radioactive element.\e[0m";;
	92)echo -e "\e[0;32m Name: Uranium \n Atomic Weight: 238.03 \n Atomic number: 92 \n Latin name: No latin name \n Class: Actinoid \n Symbol: \n $(figlet -c U)\e[0m";;
	93)echo -e "\e[0;33m Name: Neptunium* \n Atomic Weight: (237) \n Atomic number: 93 \n Latin name: No latin name \n Class: Actinoid \n Symbol: \n $(figlet -c Np) \n ----------------------------------------- \n *means its a radioactive element.\e[0m";;
	94)echo -e "\e[0;34m Name: Plutonium* \n Atomic Weight: (244) \n Atomic number: 94 \n Latin name: No latin name \n Class: Actinoid \n Symbol: \n $(figlet -c Pu) \n ----------------------------------------- \n *means its a radioactive element.\e[0m";;
	95)echo -e "\e[0;35m Name: Americium* \n Atomic Weight: (243) \n Atomic number: 95 \n Latin name: No latin name \n Class: Actinoid \n Symbol: \n $(figlet -c Am) \n ----------------------------------------- \n *means its a radioactive element.\e[0m";;
	96)echo -e "\e[0;36m Name: Curium* \n Atomic Weight: (247) \n Atomic number: 96 \n Latin name: No latin name \n Class: Actinoid \n Symbol: \n $(figlet -c Cm) \n ----------------------------------------- \n *means its a radioactive element.\e[0m";;
	97)echo -e "\e[1;30m Name: Berkelium* \n Atomic Weight: (247) \n Atomic number: 97 \n Latin name: No latin name \n Class: Actinoid \n Symbol: \n $(figlet -c Bk) \n ----------------------------------------- \n *means its a radioactive element.\e[0m";;
	98)echo -e "\e[1;31m Name: Caliornium* \n Atomic Weight: (251) \n Atomic number: 98 \n Latin name: No latin name \n Class: Actinoid \n Symbol: \n $(figlet -c Cf) \n ----------------------------------------- \n *means its a radioactive element.\e[0m";;
	99)echo -e "\e[1;32m Name: Einsteinium* \n Atomic Weight: (252) \n Atomic number: 99 \n Latin name: No latin name \n Class: Actinoid \n Symbol: \n $(figlet -c Es) \n ----------------------------------------- \n *means its a radioactive element.\e[0m";;
	100)echo -e "\e[1;36m Name: Fermium* \n Atomic Weight: (257) \n Atomic number: 100 \n Latin name: No latin name \n Class: Actinoid \n Symbol: \n $(figlet -c Fm) \n ----------------------------------------- \n *means its a radioactive element.\e[0m";;
	101)echo -e "\e[0;31m Name: Mendelevium* \n Atomic Weight: (258) \n Atomic number: 101 \n Latin name: No latin name \n Class: Actinoid \n Symbol: \n $(figlet -c Md) \n ----------------------------------------- \n *means its a radioactive element.\e[0m";;
	102)echo -e "\e[0;32m Name: Nobelium* \n Atomic Weight: (259) \n Atomic number: 102 \n Latin name: No latin name \n Class: Actinoid \n Symbol: \n $(figlet -c No) \n ----------------------------------------- \n *means its a radioactive element.\e[0m";;
	103)echo -e "\e[0;33m Name: Lawrencium* \n Atomic Weight: (266) \n Atomic number: 103 \n Latin name: No latin name \n Class: Actinoid \n Symbol: \n $(figlet -c Lr) \n ----------------------------------------- \n *means its a radioactive element.\e[0m";;
	104)echo -e "\e[0;34m Name: Rutherfordium* \n Atomic Weight: (267) \n Atomic number: 104 \n Latin name: No latin name \n Class: Transition metal \n Symbol: \n $(figlet -c Rf) \n ----------------------------------------- \n *means its a radioactive element.\e[0m";;
	105)echo -e "\e[0;35m Name: Dubnium* \n Atomic Weight: (268) \n Atomic number: 105 \n Latin name: No latin name \n Class: Transition metal \n Symbol: \n $(figlet -c Db) \n ----------------------------------------- \n *means its a radioactive element.\e[0m";;
	106)echo -e "\e[0;36m Name: Seaborgium* \n Atomic Weight: (269) \n Atomic number: 106 \n Latin name: No latin name \n Class: Transition metal \n Symbol: \n $(figlet -c Sg) \n ----------------------------------------- \n *means its a radioactive element.\e[0m";;
	107)echo -e "\e[1;30m Name: Bohrium* \n Atomic Weight: (270) \n Atomic number: 107 \n Latin name: No latin name \n Class: Transition metal \n Symbol: \n $(figlet -c Bh) \n ----------------------------------------- \n *means its a radioactive element.\e[0m";;
	108)echo -e "\e[1;31m Name: Hassium* \n Atomic Weight: (277) \n Atomic number: 108 \n Latin name: No latin name \n Class: Transition metal \n Symbol: \n $(figlet -c Hs) \n ----------------------------------------- \n *means its a radioactive element.\e[0m";;
	109)echo -e "\e[1;32m Name: Meitnerium* \n Atomic Weight: (278) \n Atomic number: 109 \n Latin name: No latin name \n Symbol: \n $(figlet -c Mt) \n ----------------------------------------- \n *means its a radioactive element.\e[0m";;
	110)echo -e "\e[1;36m Name: Darmstadtium* \n Atomic Weight: (281) \n Atomic number: 110 \n Latin name: No latin name \n Symbol: \n $(figlet -c Ds) \n ----------------------------------------- \n *means its a radioactive element.\e[0m";;
	111)echo -e "\e[0;31m Name: Roentgenium* \n Atomic Weight: (282) \n Atomic number: 111 \n Latin name: No latin name \n Symbol: \n $(figlet -c Rg) \n ----------------------------------------- \n *means its a radioactive element.\e[0m";;
	112)echo -e "\e[0;32m Name: Copernicium* \n Atomic Weight: (285) \n Atomic number: 112 \n Latin name: No latin name \n Class: Transition metal \n Symbol: \n $(figlet -c Cn) \n ----------------------------------------- \n *means its a radioactive element.\e[0m";;
	113)echo -e "\e[0;33m Name: Nihonium* \n Atomic Weight: (286) \n Atomic number: 113 \n Latin name: No latin name \n Symbol: \n $(figlet -c Nh) \n ----------------------------------------- \n *means its a radioactive element.\e[0m";;
	114)echo -e "\e[0;34m Name: Flerovium* \n Atomic Weight: (289) \n Atomic number: 114 \n Latin name: No latin name \n Class: Post-transition metal \n Symbol: \n $(figlet -c Fl) \n ----------------------------------------- \n *means its a radioactive element.\e[0m";;
	115)echo -e "\e[0;35m Name: Moscovium* \n Atomic Weight: (290) \n Atomic number: 115 \n Latin name: No latin name \n Symbol: \n $(figlet -c Mc) \n ----------------------------------------- \n *means its a radioactive element.\e[0m";;
	116)echo -e "\e[0;36m Name: Livermorium* \n Atomic Weight: (293) \n Atomic number: 116 \n Latin name: No latin name \n Symbol: \n $(figlet -c Lv) \n ----------------------------------------- \n *means its a radioactive element.\e[0m";;
	117)echo -e "\e[1;30m Name: Tennessine* \n Atomic Weight: (294) \n Atomic number: 117 \n Latin name: No latin name \n Symbol: \n $(figlet -c Ts) \n ----------------------------------------- \n *means its a radioactive element.\e[0m";;
	118)echo -e "\e[1;31m Name: Oganesson* \n Atomic Weight: (294) \n Atomic number: 118 \n Latin name: No latin name \n Symbol: \n $(figlet -c Og) \n ----------------------------------------- \n *means its a radioactive element.\e[0m";;
	*)echo -e "\e[0;31m :: Unknown Element ::" "\e[0;34m yet to be discovered\e[0m"
esac

