#!/bin/bash

NC="\033[0m"
RED="\033[5;31m"
YELLOW="\033[1;33m"
WHITE="\033[1;37m"
BLACK="\033[0;30m"
GREEN="\033[0;32m"
BLUE="\033[0;34m"
PURPLE="\033[0;35m"
CYAN="\033[0;36m"

make
# gcc src/asm/*.c libft/libft.a -I./inc/ -I./libft/includes/ -o asm
if [ ! -d "./vm_champs" ]
then
	printf "${RED}No ./vm_champs folder here. Please pull it from project page and try again\n${NC}"
	exit 1
fi

function check_asm {
	NAME1=$(echo $1 | rev | cut -c 2- | rev)mycor
	NAME2=$(echo $1 | rev | cut -c 2- | rev)cor
	rm -f $NAME1 $NAME2

	printf "${GREEN}1) Test the $file file...${NC}\n"

	printf "\n${YELLOW}OUR ASM COMPILER${NC}\n"
	./asm "$1"

	printf "\n${YELLOW}MAIN ASM COMPILER:${NC}\n"
	./vm_champs/asm "$1"

	if [[ -f "$NAME1" || -f "$NAME2" ]]
	then
		printf "\n${GREEN}2) Compare the files${NC}\n"
		RES=$(cmp -b $NAME1 $NAME2 | cat -e)
		printf "${RED}$RES${NC}\n"
		# if [ ! -z "$RES" ]
		# then

		# fi
			# printf "\n${GREEN}My $NAME1 contains:${NC}\n"
			# cat $NAME1
			# printf "\n\n${GREEN}Original $NAME2 contains:${NC}\n"
			# cat $NAME2
	else
		printf "\n${RED}2) Can't compare files $NAME1 and $NAME2, they don't exist${NC}\n"
	fi

	printf "\n\n${GREEN}"
	read -p "Press enter to continue..."
	printf "${EOC}"
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
	1) ${GREEN}-best${NC} - all .s files in subdirectories of ./vm_champs/champs/championships/
	2) ${GREEN}-ex${NC} - all .s files in ./vm_champs/champs/examples
	3) ${GREEN}-main${NC} - all .s files in ./vm_champs/champs/\n"
fi
exit 0
