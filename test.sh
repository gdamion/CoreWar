#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
CYAN='\033[0;36m'
NC='\033[0m'

make
if [ ! -d "./vm_champs" ]
then
	printf "${RED}No ./vm_champs folder here. Please pull it from project page and try again\n${NC}"
	exit 1
fi

function check_asm {
	printf "${GREEN}Test the $file file...${NC}\n"
	printf "\n${GREEN}Our asm:${GREEN}${CYAN}\n"
	./asm $1
	printf "\n${GREEN}Main asm:${GREEN}${CYAN}\n"
	./vm_champs/asm $1
	echo -e "${GREEN}"
	printf "If the output isn't printed => ALL GOOD\n\n"
	read -p "Press enter to continue..."
	echo -e "${NC}"
	clear
}

if [ "$1" = "-best" ]
then
clear
echo "Checking all .s files in subdirectories of ./vm_champs/champs/championships/ ..."
for file1 in vm_champs/champs/championships/*
do
	if [ -d "$file1" ]
	then
		for file in $file1/*
		do
			if [[ -f "$file" ]] && [[ $file == *".s" ]];
			then
				check_asm $file
			fi
		done
	fi
done

elif [ "$1" = "-ex" ]
then
clear
echo "Checking all .s files in ./vm_champs/champs/examples/ ..."
for file in vm_champs/champs/examples/*.s
do
	check_asm $file
done

elif [ "$1" = "-main" ]
then
clear
echo "Checking all .s files in ./vm_champs/champs/ ..."
for file in vm_champs/champs/*.s
do
	check_asm $file
done

else
	printf "${RED}You should enter 1 of 3 arguments for showing which group you want to check:${NC}
	1) ${GREEN}-best${NC} - all .s files in subdirectories of ./vm_champs/champs/championships/ ;
	2) ${GREEN}-ex${NC} - all .s files in ./vm_champs/champs/examples;
	3) ${GREEN}-main${NC} - all .s files in ./vm_champs/champs/\n"
fi
exit 0
