import os.path
import os
import random
from time import sleep

class bankAccount:
	def __init__(self, fname, lname,age ,address ,contact, accno, pin, balance, flag):
		self.fname = fname
		self.lname = lname
		self.age = age
		self.address = address
		self.contact = contact
		self.accno = accno
		self.pin= pin
		self.balance = balance
		self.flag = flag

	def create_User(self):
		client_fullname = str(self.fname) + ' ' + str(self.lname)
		client_age = str(self.age)
		client_address = str(self.address)
		client_contact = str(self.contact)
		client_accno = str(self.accno)
		client_balance = str(self.balance)
		client_pass = str(self.pin)
		client_flag = str(self.flag)
		database_details = client_fullname + " " + client_age + " " + client_address + " " + client_contact + " " + client_accno + " " + client_pass + " " + client_balance
		details = client_accno + "\n" + client_pass + "\n" + client_balance + "\n" + client_flag
		db = open("database.txt", "a")
		drive = open('E:/data.txt', 'w')
		db.write("%s\n" % database_details)
		drive.write("%s" % details)
		db.close()
		drive.close()


while not os.path.exists("E:"):
	print("\t\t\t\t Credit Card not Inserted")
	sleep(1)

if os.path.exists('E:\\data.txt'):
		print('\n\n\t\t\t    [ ALREADY HAVE AN ACCOUNT ] ')
		print('\t\t\t   [ PROCEEDING TO TRANSACTION ] \n\n\n\n')
		import Transaction	
else:
	print('\n\n===========================================================')
	print('======== Welcome to Technological University Bank =========')
	print('===========================================================')
	print('\n\n\t\t\t\t [  ATM CARD INSERTED! ] \t\t\t')
	print("\n\n -------- Please fill up all the information below -------- \n\n ")
	firstname = input("\t\t Enter First Name: ")
	lastname  = input("\t\t Enter Last Name: ")
	age = input("\t\t Enter Age: ")
	address = input("\t\t Enter Address: ")
	contact_no = input("\t\t Enter Contact Number: ")
	while 1:
		initial_deposit = int(input("\t\t Initial Balance (minimum of 100php) : "))
		if initial_deposit > 100000:
			print("\t\t Maximum of 100,000Php \n")
			print('\t\t Please try again')

		elif initial_deposit % 100:
			print("\t\t Only accepts 100 peso bills \n ")
			print('\t\t Please try again')

		elif initial_deposit < 100:
		    print("\t\t Initial deposit must be more than 100Php \n ")
		    print('\t\t Please try again')

		else:
			ID = 'TUPM-'
			y=random.randint(10000,99999)
			a_no = ID + str(y)
			print("\n\t\t Account No: ", a_no)
			pin_no = random.randint(100000,999999)
			print("\t\t Password: %d" %pin_no)
			flag = '1'
			break

	print ("\n\n\t\t[ ACCOUNT SUCCESSFULLY REGISTERED ] ")
	access = bankAccount(firstname,lastname, age,address,contact_no, a_no, pin_no , initial_deposit,flag)
	access.create_User()

