#!/usr/bin/env python
#Submitted by: Patricia Ann T. Trinidad AB-3L
###Date created: 02-07-2016
##Date Submitted: 02-14-2016
#Sources: www.quora.com/How-do-I-convert-numbers-to-words-in-python
#http://stackoverflow.com/questions/8982163/how-do-i-tell-python-to-convert-integers-into-words
#declaration of arrays

numToWords1 = {0:'zero',1: 'one', 2: 'two', 3: 'three', 4: 'four', 5: 'five', 6:'six', \
            7:'seven', 8:'eight', 9: 'nine', 10: 'ten', 11: 'eleven', 12: 'twelve'\
            ,13: 'thirteen', 14: 'fourteen', 15: 'fifteen', 16: 'sixteen', 17:'seventeen'\
            ,18: 'eighteen', 19: 'nineteen',20:'twenty',30:'thirty',40:'forty',50:'fifty',60:'sixty',70:'seventy',80:'eighty',90:'ninety'}
numToWords3 = [' hundred', ' thousand ', ' million ']

wordsToNum1 = {'zero':0, 'one':1, 'two':2, 'three':3, 'four':4, 'five':5, 'six':6, \
               'seven':7, 'eight':8, 'nine':9, 'ten':10, 'eleven':11, 'twelve':12, \
               'thirteen':13, 'fourteen':14, 'fifteen':15, 'sixteen':16, 'seventeen':17\
               ,'eighteen' : 18, 'nineteen':19, 'twenty':20, 'thirty':30, 'forty':40, 'fifty':50, 'sixty':60, 'seventy':70\
               ,'eighty':80, 'ninety':90}

               
#formulas derived from stackoverflow
def numToWords(integer):	#number to words conversion
    current2 = ""
    if integer >= 0 and integer <= 19: return ' ' + numToWords1[integer]	#1-19
    elif integer < 100:
        if integer % 10 == 0 : return numToWords1[integer]
        else: return numToWords1[integer // 10*10]  + ' ' + numToWords1[integer % 10]
    elif integer >= 100 and integer <= 999:
        if integer % 100 == 0: return numToWords1[integer // 100] + ' ' + 'hundred'
        else: return numToWords1[integer//100] + ' hundred ' + numToWords(integer % 100)
    elif integer >= 1000 and integer <= 9999:
        if integer % 1000 == 0: return numToWords1[integer] + ' ' + 'thousand'
        else: return numToWords1[integer//1000] + ' thousand ' + numToWords(integer % 1000)
    elif integer % 1000000 == 0: return "One million"
    elif integer >= 10000 and integer <= 99999:
        if integer % 10000 == 0: return numToWords2[integer//10000] + ' ' + ' thousand '
        else: return numToWords(integer //1000) + ' thousand ' + numToWords(integer % 1000)
    elif integer >= 100000 and integer <= 999999:
        if integer % 10000 == 0: return numToWords1[integer//10000] + ' ' + 'hundred thousand '
        else: return numToWords(integer // 1000) + ' thousand ' + numToWords(integer % 1000)
    return

#pass the tokenized string array and convert them to str using str() function
#return the concatenated string
def wordsToCurrency(money,currency):
			res1 = str(wordsToNum(money.split(" ")))
			return currency + res1

def numberDelimited(money,delimiter,jumps):	#delimiting the string
	res1 = ""
	length = len(str(money))
	letters = str(money)	#converting the integer to a string
	string = list(letters)	#converting the string to  list
	
	i = 0		#i counter
	for char in string: #for-loop
		if i % jumps == 0 and i is not 0:	#if i is divisible to jumps and not 0
			res1 += delimiter; res1 += char	#concatenate delimiter and string[index] to res1
		else: res1 += char		#else only concatenate string[index] to res1
		i+=1							#increment 1
		if i == length: break	#if end of list, break loop

	return (res1)					#return res1

#doesn't work in all cases, only works on basic words
def wordsToNum(stringArray):
		#initialization of variables
		integer2 = 0
		ones = 0 ; tens = 0 ; hundreds = 0; thousands = 0

		i = 0
		try:	#traverses the stringArray list
			 while stringArray[i]:
				if stringArray[i] == "zero":
						integer2 = integer2 + 0
				elif stringArray[i]  == "one":
						integer2 = integer2 + 1
				elif stringArray[i]  == "two":
						integer2 = integer2 + 2
				elif stringArray[i]  == 'three':
						integer2 = integer2 + 3
				elif stringArray[i]  == "four":
						integer2 = integer2 + 4
				elif stringArray[i]  == "five":
						integer2 = integer2 + 5
				elif stringArray[i]  == "six":
						integer2 = integer2 + 6
				elif stringArray[i]  == "seven":
						integer2 = integer2 + 7
				elif stringArray[i]  == "eight":
						integer2 = integer2 + 8
				elif stringArray[i]  == "nine":
						integer2 = integer2 + 9
				elif stringArray[i]  == "ten":
						integer2 = integer2 + 10
				elif stringArray[i]  == "eleven":
						integer2 = integer2 + 11
				elif stringArray[i]  == "twelve":
						integer2 = integer2 + 12		
				elif stringArray[i]  == "thirteen":
						integer2 = integer2 + 13
				elif stringArray[i]  == "fourteen":
						integer2 = integer2 + 14
				elif stringArray[i]  == "fifteen":
						integer2 = integer2 + 15
				elif stringArray[i]  == "sixteen":
						integer2 = integer2 + 16
				elif stringArray[i]  == "seventeen":
						integer2 = integer2 + 17
				elif stringArray[i]  == "eighteen":
						integer2 = integer2 + 18
				elif stringArray[i]  == "nineteen":
						integer2 = integer2 + 19
				elif stringArray[i]  == "twenty":
						integer2 = integer2 + 20
				elif stringArray[i]  == "thirty":
						integer2 = integer2 + 30
				elif stringArray[i]  == "forty":
						integer2 = integer2 + 40
				elif stringArray[i]  == 'fifty':
						integer2 = integer2 + 50
				elif stringArray[i]  == "sixty":
						integer2 = integer2 + 60
				elif stringArray[i]  == "seventy":
						integer2 = integer2 + 70
				elif stringArray[i]  == "eighty":
						integer2 = integer2 + 80
				elif stringArray[i]  == "ninety":
					integer2 = integer2 + 90
				elif stringArray[i] == "hundred" and stringArray[i+1] == "thousand":
					thousands = integer2 * 100000
					integer2 = 0
					i+=2
				elif stringArray[i]  == "hundred":
						hundreds = integer2 * 100
				elif stringArray[i]  == "thousand":
						thousands = integer2 * 1000
						integer2 = 0
				elif stringArray[i]  == "million":
					integer2 = integer2 * 1000000			
				i += 1
		except IndexError:
				pass
				return (thousands+hundreds+integer2)  #hard-coded sheezzz

#used for testing the library    	
print('THIS WAS MADE FOR TESTING PURPOSES ONLY.')
print('[1]Number To Words Converter')
print('[2]Words To Number Converter')
print('[3]Words To Currency Converter')
print('[4]Number Delimiter')
choice = int(input("Choice: "))

#numToWords() testing
if choice == 1:
	integer = int(input("Enter the amount(in numbers): ")) #string is stored in integer
	current = ""
	current = numToWords(integer)
	print (current)

#wordsToNum() testing
elif choice == 2:
	string2 = raw_input("Enter the amount(in words): ")	#stored as a data type string
	string3 = string2.split(" ")	#tokenize string
	result2 = wordsToNum(string3)
	print (result2)

#wordsToCurrency() testing
elif choice == 3:
	money = raw_input("Enter the amount(in words): ")
	currency = raw_input("Enter the currency(min. of 3 letters):")
	result = wordsToCurrency(money,currency)
	print (result)

#NumberDelimiter() testing
elif choice == 4:
	money = int(input("Enter the amount(in numbers): "))
	delimiter = raw_input("Enter a delimited(single char ONLY): ")
	jumps = int(input("Enter the no. of jumps when the delimiter appears: "))
	result = numberDelimited(money,delimiter,jumps)
	print (result)
