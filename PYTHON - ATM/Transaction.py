import os.path
import os
import sys
from time import sleep


class client_transaction:

	def __init__(self, accno, pin, balance,flag):
		self.accno = accno
		self.pin = int(pin)
		self.balance = int(balance)
		self.flag = int(flag)

	def deposit(self):
		while 1: 
				deposit = int(input('\n\t\t\t Enter deposit amount: '))
				if deposit <= 100:
					print('\n\t\t\t [ Initial deposit amount must be higher than 100php ]')
				elif deposit % 100:
					print('\n\t\t\t [ Cannot deposit coins ] ')
				else:
					total= self.balance + deposit
					client_accno = str(self.accno)
					client_balance = str(total)
					client_pin = str(self.pin)
					client_flag = str(flag)
					driver = open('E:/data.txt','w')
					driver.write(client_accno + client_pin + "\n"+ client_balance + "\n" + client_flag)
					driver.close()
					print('\n===========================================================')
					print('\t\t\t Current Balance : ', total)
					print('===========================================================\n\n\n\n')
					break

	def withdraw(self):
			while 1: 
				withdraw = int(input('\n\t\t\t Enter withdrawal amount: '))
				if withdraw > self.balance :
					print('\n\t\t\t [ Withdrawal amount must not exceed the remaining balance ]')
				elif withdraw == self.balance:
					print('\n\t\t\t [ An initial balance of 100php must remain ] ')
				elif withdraw <= 100:
					print('\n\t\t\t [ Withdrawal amount must be higher than 100php ]')
				elif withdraw % 100:
					print('\n\t\t\t [ Cannot withdraw coins ] ')
				else:
					total= self.balance - withdraw
					client_accno = str(self.accno)
					client_balance = str(total)
					client_pin = str(self.pin)
					client_flag = str(flag)
					driver = open('E:/data.txt','w')
					driver.write(client_accno + client_pin + "\n"+ client_balance + "\n" + client_flag)
					driver.close()
					print('\n===========================================================')
					print('\t\t\t Current Balance : ', total)
					print('===========================================================\n\n\n\n')
					break

	def change_pin(self):

		pin_no = int(self.pin)
		old_pin = int(input("\n\t\t\t Enter Old Pin Number: "))

		while old_pin != pin_no:
				print("\n\t\t\t Pin number invalid. Please Try again")
				break 
		if old_pin == pin_no:
			new_pin = int(input("\n\t\t\t Enter New Pin Number:  "))
			confirm_pin = int(input("\n\t\t\t Please Re-Enter Pin Number : "))
			if new_pin != confirm_pin:
				print('\t\t\t[ Pin Mismatched ]')
				insert.change_pin()
			else:
				new_pin = confirm_pin
				client_accno = str(self.accno)
				client_balance = str(self.balance)
				client_pin = str(confirm_pin)
				client_flag = str(flag)
				driver = open('E:/data.txt','w')
				driver.write(client_accno + client_pin + "\n"+ client_balance + "\n" + client_flag)
				driver.close()
				print("\n\t\t\t Pin number has been successfully changed! ")

	def fast_cash(self):
		choice = 0 
		print('===========================================================')
		print('========                                          =========')
		print('========         F  A  S  T      C  A  S  H       =========')
		print('========                                          =========')
		print('===========================================================')
		print('\n\t\t\t[1] 500  \t\t\t\t [4] 5000 ')
		print('\n\t\t\t[2] 1000 \t\t\t\t [5] 10000')
		print('\n\t\t\t[3] 2000 \t\t\t\t [6] 20000')
		choice = int(input('\n\t\t\t Enter withdrawal amount: '))
		if choice == 1: 
			if self.balance <= 500:
			 	print ("\n\t\t\t [ Insufficient Balance! ] \n\n\n")
			 	import Transaction
			else:
				total = self.balance - 500
				client_accno = str(self.accno)
				client_balance = str(total)
				client_pin = str(self.pin)
				client_flag = str(flag)
				driver = open('E:/data.txt','w')
				driver.write(client_accno + client_pin + "\n"+ client_balance + "\n" + client_flag)
				driver.close()
				print('\n\t\t\t Balance : ', total)
				exit()
		elif choice == 2: 
			if self.balance <= 1000:
			 	print ("\n\t\t\t [ Insufficient Balance! ] \n\n\n")
			 	import Transaction
			else:
				total = self.balance - 1000
				client_accno = str(self.accno)
				client_balance = str(total)
				client_pin = str(self.pin)
				client_flag = str(flag)
				driver = open('E:/data.txt','w')
				driver.write(client_accno + client_pin + "\n"+ client_balance + "\n" + client_flag)
				driver.close()
				print('\n\t\t\t Balance : ', total)
		elif choice == 3: 
			if self.balance <= 2000:
			 	print ("\n\t\t\t [ Insufficient Balance! ] \n\n\n")
			 	import Transaction
			else:
				total = self.balance - 2000
				client_accno = str(self.accno)
				client_balance = str(total)
				client_pin = str(self.pin)
				client_flag = str(flag)
				driver = open('E:/data.txt','w')
				driver.write(client_accno + client_pin + "\n"+ client_balance + "\n" + client_flag)
				driver.close()
				print('\n\t\t\t Balance : ', total)

		elif choice == 4: 
			if self.balance <= 5000:
			 	print ("\n\t\t\t [ Insufficient Balance! ] \n\n\n")
			 	import Transaction
			else:
				total = self.balance - 5000
				client_accno = str(self.accno)
				client_balance = str(total)
				client_pin = str(self.pin)
				client_flag = str(flag)
				driver = open('E:/data.txt','w')
				driver.write(client_accno + client_pin + "\n"+ client_balance + "\n" + client_flag)
				driver.close()
				print('\n\t\t\t Balance : ', total)
		elif choice == 5: 
			if self.balance <= 10000:
			 	print ("\n\t\t\t [ Insufficient Balance! ] \n\n\n")
			 	import Transaction
			else:
				total = self.balance - 10000
				client_accno = str(self.accno)
				client_balance = str(total)
				client_pin = str(self.pin)
				client_flag = str(flag)
				driver = open('E:/data.txt','w')
				driver.write(client_accno + client_pin + "\n"+ client_balance + "\n" + client_flag)
				driver.close()
				print('\n\t\t\t Balance : ', total)
		elif choice == 6: 
			if self.balance <= 20000:
			 	print ("\n\t\t\t [ Insufficient Balance! ] \n\n\n")
			 	import Transaction
			else:
				total = self.balance - 20000
				client_accno = str(self.accno)
				client_balance = str(total)
				client_pin = str(self.pin)
				client_flag = str(flag)
				driver = open('E:/data.txt','w')
				driver.write(client_accno + client_pin + "\n"+ client_balance + "\n" + client_flag)
				driver.close()
				print('\n\t\t\t Balance : ', total)
	
	def login_process(self):

		atm = open("E:\\data.txt", "r")
		line = atm.readline()
		accno = line
		line2 = atm.readline()
		pin = int(line2)
		line3 = atm.readline()
		balance = line3
		line4 = atm.readline()
		flag = int(line4)
		atm.close()
		insert = client_transaction(accno,pin,balance,flag)

		if flag == 1 :
			flag = 0
			print('===========================================================')
			print('========                                          =========')
			print('======== Welcome to Technological University Bank =========')
			print('========                                          =========')
			print('===========================================================')
			print('\t\t\t    You are a new user in the bank  ')
			print('\n\t\t\t You are required to change your pin: ')
			print('===========================================================')
			pin_no = int(self.pin)
			old_pin = int(input("\n\t\t\t Enter Pin Number: "))

			while old_pin != pin_no:
					print("\n\t\t\t [ Pin number invalid. Please Try again ] \n\n\n ")
					insert.login_process()
					break
			
			if old_pin == pin_no:
				new_pin = int(input("\n\t\t\t Enter New Pin :  "))
				confirm_pin = int(input("\n\t\t\t Please Re-Enter Pin Number : "))
				if new_pin != confirm_pin:
					print('\n\t\t\t [ Re-Entered Pin is not correct, Try Again! ] \n\n\n ')
					insert.login_process()
				else:
					client_accno = str(self.accno)
					client_balance = str(self.balance)
					client_pin = str(confirm_pin)
					client_flag = str(flag)
					driver=open('E:/data.txt', 'w')
					driver.write(client_accno + client_pin + "\n"+ client_balance + "\n"+ client_flag )
					print("\n\t\t\t Pin number has been successfully changed! \n\n\n")	
					driver.close()
					import Transaction	


choice = 0
login_pin = 0


while not os.path.exists("E:\\data.txt"):
	print("\n\t\t\t Credit Card not Inserted")
	sleep(1)
if os.path.isfile("E:\\data.txt"):
	atm = open("E:\\data.txt", "r")
	line = atm.readline()
	accno = line
	line2 = atm.readline()
	pin = int(line2)
	line3 = atm.readline()
	balance = line3
	line4 = atm.readline()
	flag = int(line4)
	atm.close()
	insert = client_transaction(accno,pin,balance,flag)

def login():
	print('===========================================================')
	print('========                                          =========')
	print('======== Welcome to Technological University Bank =========')
	print('========                                          =========')
	print('===========================================================')
	print('\n\t\t\t     Account Number:', accno)
	print('===========================================================')
	print('\t\t\t      [ PLEASE LOGIN FIRST ]')
	print('===========================================================')

def menu():
	print('===========================================================')
	print('========                                          =========')
	print('======== Welcome to Technological University Bank =========')
	print('========                                          =========')
	print('===========================================================')
	print('\n\t\t\t     Account Number:', accno)
	print('===========================================================')
	print('\n\t\t\t\t[1] Deposit Money')
	print('\t\t\t\t[2] Withdraw Money')
	print('\t\t\t\t[3] Balance Inquiry ')
	print('\t\t\t\t[4] Change Pin ')
	print('\t\t\t\t[5] Fast Cash ')
	print('\t\t\t\t[6] Exit Program ')

def balance_inquiry():
		print('\n\n===========================================================')
		print('\n\t\t\t Balance Inquiry: ', balance)
		print('===========================================================\n\n\n\n')


while login_pin  != pin :
	insert.login_process()
	login()
	login_pin = int(input('\n\t\t\tEnter 6-Digit PIN number: '))
	if login_pin != pin:
		print ( "\n\t\t\t\t [ Wrong PIN Number ]  \n\n\n")
	else:
		atm = open("E:\\data.txt", "r")
		line = atm.readline()
		accno = line
		line2 = atm.readline()
		pin = int(line2)
		line3 = atm.readline()
		balance = line3
		line4 = atm.readline()
		flag = int(line4)
		atm.close()
		insert = client_transaction(accno,pin,balance,flag)
		print("\n\n\n\n")
		menu()
		choice = int(input("\n\t\t\t\tEnter choice: "))
		if choice == 1:
			insert.deposit()
		elif choice == 2:
			insert.withdraw()
		elif choice == 3:
			balance_inquiry()
		elif choice == 4:
			insert.change_pin()
		elif choice == 5:
			insert.fast_cash()
		elif choice == 6:
			print('===========================================================')
			print('========                                          =========')
			print('======== Thankyou for Banking with us, God Bless! =========')
			print('========                                          =========')
			print('===========================================================')