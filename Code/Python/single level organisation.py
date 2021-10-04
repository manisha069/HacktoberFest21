class Dir:
	def __init__(self,dirname):
		self.dirname = dirname
		self.filelist = []
	def create(self,file):
		if(file not in self.filelist):
			self.filelist.append(file)
			print(f"{file} is CREATED in {self.dirname}")
		else:
			print(f"{file} is already PRESENT")

	def remove(self,file):
		if(file in self.filelist):
			self.filelist.remove(file)
			print(f"{file} is REMOVED from {self.dirname}")
		else:
			print(f"{file} : NOT FOUND")

	def __repr__(self):
		return(f"{dirname}")


dirname = input("Enter a Diretory name:")
d  = Dir(dirname)
print(f" Directory : {d.dirname}\n")
while(1):

        print("\n***MENU***\n1.Create\n2.Remove\n3.Display\n4.Exit")
        ch= int(input("Enter your choice :"))
        if(ch==1):
                 filename = input("Enter the Filename : ")
                 d.create(filename)
                 print("----------------------------------")
        elif(ch==2):
                 filename = input("Enter the Filename : ")
                 d.remove(filename)
                 print("----------------------------------")
        elif(ch==3):
                 print(f"\n\nDirectory : {d.dirname}")
                 for file in d.filelist:
                         print(f"{file}  ")
                 if(d.filelist==[]):
                         print("No files present")
                 print("----------------------------------")
        elif(ch==4):
                 exit(0)
        else:
                 print("Invalid Choice")                                                                                 





