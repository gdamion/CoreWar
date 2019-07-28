#!/bin/bash
#!usr/bin/perl

NC="\033[0m"
RED="\033[1;31m"
YELLOW="\033[1;33m"
WHITE="\033[1;37m"
BLACK="\033[0;30m"
GREEN="\033[0;32m"
BLUE="\033[1;34m"
PURPLE="\033[0;35m"
CYAN="\033[0;36m"

make
if [ ! -d "./vm_champs" ]
then
	printf "${RED}No ./vm_champs folder here. Please pull it from project page and try again\n${NC}"
	exit 1
fi

function usage {
	printf "${RED}USAGE | You should enter 'vm' or 'asm' as the 1-st argument and
	1 of 3 variants as 2-st argument for showing which group you want to check:${NC}
	1) ${GREEN}-best${NC} - all .s files in subdirectories of ./vm_champs/champs/championships/
	2) ${GREEN}-ex${NC} - all .s files in ./vm_champs/champs/examples
	3) ${GREEN}-main${NC} - all .s files in ./vm_champs/champs/\n"
	exit 1
}

function check_asm {
	tput reset
	NAME1=$(echo $1 | rev | cut -c 2- | rev)mycor
	NAME2=$(echo $1 | rev | cut -c 2- | rev)cor

	printf "\n${BLUE}1) Test the $file file...${NC}\n"

	printf "\n${YELLOW}OUR ./ASM COMPILER${NC}\n"
	./asm "$1" -test

	printf "\n${YELLOW}MAIN ./ASM COMPILER:${NC}\n"
	./vm_champs/asm_orig "$1"

	printf "\n${BLUE}2) Compare the "$NAME1" and "$NAME2" files...${NC}\n"
	if [[ -f "$NAME1" && -f "$NAME2" ]]
	then
		RES1=$(cmp -b $NAME1 $NAME2 | cat -e)
		if [ -z "$RES1" ]
		then
			printf "${GREEN}\tFiles are the same ${NC}\n"
			RES2=1
		else
			printf "${RED}$RES1${NC}\n"
			RES2=0
		fi
	else
		printf "${RED}Can't compare files:\n\tThey don't exist${NC}\n"
	fi

	printf "\n${BLUE}3) Check memory leaks of the ./asm with\n\t"$1" file as an argument...${NC}\n\n"
	valgrind --leak-check=full ./asm "$1" -test
	rm -rf asm.dSYM

	printf "\n\n${GREEN}"
	read -p "Press enter to continue..."
	printf "${EOC}"
	rm -f $NAME1 $NAME2
}

function check_vm {
	tput reset
	NAME=$(echo $1 | rev | cut -c 2- | rev)cor

	./asm "$1"
	printf "\n${BLUE}Launching ./corewar withvalgrind and \n\tself-made "$NAME" file as an argument...${NC}\n\n"
	valgrind --leak-check=full ./corewar $NAME
	rm -rf corewar.dSYM
	printf "\n\n${GREEN}"
	read -p "Press enter to continue..."
	printf "${EOC}"
	rm -f $NAME1 $NAME2
}

if [ "$2" = "-best" ]
then
printf "CHECKING ALL .s files in subdirectories of ./vm_champs/champs/championships/ ...\n"
for file1 in vm_champs/champs/championships/*
do
	if [ -d "$file1" ]
	then
		for file in $file1/*
		do
			if [[ -f "$file" ]] && [[ $file == *".s" ]];
			then
				if [ "$1" = "asm" ]
				then
					check_asm $file
				elif [ "$1" = "vm" ]
				then
					check_vm $file
				else
					usage
				fi
			fi
		done
	fi
done

elif [ "$2" = "-ex" ]
then
printf "CHECKING ALL .s files in ./vm_champs/champs/examples/ ...\n"
for file in vm_champs/champs/examples/*.s
do
	if [ "$1" = "asm" ]
	then
		check_asm $file
	elif [ "$1" = "vm" ]
	then
		check_vm $file
	else
		usage
	fi
done

elif [ "$2" = "-main" ]
then
printf "CHECKING ALL .s files in ./vm_champs/champs/ ...\n"
for file in vm_champs/champs/*.s
do
	if [ "$1" = "asm" ]
	then
		check_asm $file
	elif [ "$1" = "vm" ]
	then
		check_vm $file
	else
		usage
	fi
done

else
	usage
fi
exit 0
