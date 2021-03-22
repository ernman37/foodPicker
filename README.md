# foodPicker
setup.sh: (bash)

 -Creates c++ program with correct file names compiled as Picker
 
 -Optional: Adds alias to .bash_aliases or .bash_profile if it finds them in ~ directory
 
 
restaurants.txt:

 -List of restaurants to eat at
 
 -Seperated into diffent options i.e brekfast, seperator value is '~'


main.cpp: (C++11 and above)
 
 -Takes option value for type what type of random place you want to eat
  
  -b: brekfast places
  
  -f: Fast food places
  
  -s: Sit down places
  
  -n: Nice places
  
  -d: Drink places
  
  -F: Fry places
  
  -p: Print all places from selected options
  
  -a: All true but -p(unless specified) 
 
 -Reads certain parts of file based on options
 
 -Outputs random restuarant from each selected option


Starting:

Option 1:

-run './setup.sh'

-Answer prompts if you have .bash_alias or .bash_profile

-If you add alias dont forget to source the file!

-run new alias like "ALIAS -h'

-this outputs help screen


Option 2:

-if you want to be able to create well working alias add path route inside main.cpp

-compile main.cpp

-use new program in alias file


Option 3:

-Run the program given

-Create alias that cds into program directory then uses program then cd - back


Editing:

-If you edit main.cpp then setup.sh most likely will not work as it is set up to change a specific line(105) to make personalized program

-If you want to add more options ie(type of restraunts):

-Add new section to restuarants.txt with proper formatting '~'!

-Add bool values to Args struct

-Go to getoptions function

-Add more options into the string

-add more case statements

-Go to addv function:

-add more case statements to represent which part of file we are in

-If you want setup.sh to still work change find where the string file is declared in main.cpp

-In sh find line where it is comparing line number to 105 change to new value of string file in main.cpp


