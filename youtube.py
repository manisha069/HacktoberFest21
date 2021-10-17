from tkinter import *
from pytube import YouTube

root=Tk() #intializing  tkinter

root.geometry("400x350")#setting geometry of GUI

root.title("Youtube Downloader by MADHAV")#setting title of GUI

def download():
    try:
        myVar.set("Downloading...")
        root.update()
        YouTube(link.get()).streams.filter(progressive=True).order_by('resolution').desc().first().download()
        myVar.set("Enter Link Below")
        link.set("Video Downloaded Successfully")
    except Exception as e:
        myVar.set("Mistake")
        root.update()
        link.set("Enter Correct link")

Label(root,text="Welcome to Youtube \nDownloader Application",font="Consolas 15 bold").pack()

myVar=StringVar()
myVar.set("Enter Link Below")
Entry(root,textvariable=myVar,width=40).pack(pady=10)
link=StringVar()
Entry(root,textvariable=link,width=40).pack(pady=10)
Button(root,text="DOWNLOAD VIDEO",command=download).pack()
root.mainloop()
